//
// The Persper License
//
// Copyright (c) 2016 Persper Technologies Co., Ltd.
//

#include "gtest/gtest.h"

#include "log/primitive_log.h"

#include <cstdlib>
#include <cstring>
#include <queue>

namespace persper {

class PrimitiveLogTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    data_ = malloc(size_);
    memset(data_, 0, size_);
  }

  virtual void TearDown() { free(data_); }

  PrimitiveLog log_;
  void *data_;
  const size_t size_ = 1000;
};

TEST_F(PrimitiveLogTest, Init) {
  ASSERT_EQ(log_.Init(data_, size_), 0);
  ASSERT_EQ((void *)log_.head(), data_);
  memset(data_, 1, size_);
  ASSERT_NE(log_.Init(data_, size_), 0);
}

TEST_F(PrimitiveLogTest, AppendTruncate) {
  ASSERT_EQ(log_.Init(data_, size_), 0);
  for (int i = 0; i < 9; ++i) {
    ASSERT_NE(log_.Append(100), nullptr) << "i = " << i;
  }
  ASSERT_EQ(log_.Append(100), nullptr);
  for (int i = 0; i < 9; ++i) {
    ASSERT_NE(log_.head()->size, 0) << "i = " << i;
    ASSERT_NE(log_.Truncate(), nullptr) << "i = " << i;
  }
  ASSERT_EQ(log_.head()->size, 0);
  ASSERT_EQ(log_.Truncate(), nullptr);
}

TEST_F(PrimitiveLogTest, ExtendRewind) {
  ASSERT_EQ(log_.Init(data_, size_), 0);
  LogEntry *entry = log_.Append(100);
  ASSERT_NE(entry, nullptr);
  for (int i = 0; i < 8; ++i) {
    ASSERT_EQ(log_.Extend(entry, 100), 0) << "i = " << i;
  }
  ASSERT_NE(log_.Extend(entry, 100), 0);
  ASSERT_EQ(log_.Rewind(entry), nullptr);
  ASSERT_NE(log_.Truncate(), nullptr);
  ASSERT_NE(log_.Rewind(), nullptr);

  ASSERT_NE(log_.Append(300), nullptr);
  ASSERT_NE(log_.Append(300), nullptr);
  entry = log_.Append(200);
  ASSERT_NE(entry, nullptr);
  ASSERT_EQ(log_.Extend(entry, 100), 0);
  ASSERT_NE(log_.Extend(entry, 100), 0);
  ASSERT_NE(log_.Truncate(), nullptr);
  ASSERT_NE(log_.Truncate(), nullptr);
  ASSERT_EQ(log_.Rewind(entry)->size, 300);
}

TEST_F(PrimitiveLogTest, Comprehensive) {
  ASSERT_EQ(log_.Init(data_, size_), 0);
  std::queue<size_t> entries;
  for (int i = 0; i < 100000; ++i) {
    if (i % 100 == 88) log_.Init(data_, size_);
    size_t s = rand() % (size_ / 2);
    LogEntry *entry = log_.Append(s);
    if (!s) {
      ASSERT_EQ(entry, nullptr);
      continue;
    }
    if (!entry) {
      while (!entries.empty()) {
        ASSERT_EQ(log_.head()->size, entries.front()) << "i = " << i;
        ASSERT_NE(log_.Truncate(), nullptr) << "i = " << i;
        entries.pop();
      }
      ASSERT_NE(log_.Rewind(), nullptr) << "i = " << i;
      ASSERT_NE(entry = log_.Append(s), nullptr) << "i = " << i;
      ASSERT_EQ(log_.Extend(entry, 100), 0) << "i = " << i;
      s += 100;
    }
    entries.push(s);
  }
}

} // namespace persper
