
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_classpath_jdwp_JdwpConstants$CommandSet$VirtualMachine__
#define __gnu_classpath_jdwp_JdwpConstants$CommandSet$VirtualMachine__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace classpath
    {
      namespace jdwp
      {
          class JdwpConstants$CommandSet$VirtualMachine;
      }
    }
  }
}

class gnu::classpath::jdwp::JdwpConstants$CommandSet$VirtualMachine : public ::java::lang::Object
{

public:
  JdwpConstants$CommandSet$VirtualMachine();
  static const jbyte CS_VALUE = 1;
  static const jbyte VERSION = 1;
  static const jbyte CLASSES_BY_SIGNATURE = 2;
  static const jbyte ALL_CLASSES = 3;
  static const jbyte ALL_THREADS = 4;
  static const jbyte TOP_LEVEL_THREAD_GROUPS = 5;
  static const jbyte DISPOSE = 6;
  static const jbyte IDSIZES = 7;
  static const jbyte SUSPEND = 8;
  static const jbyte RESUME = 9;
  static const jbyte EXIT = 10;
  static const jbyte CREATE_STRING = 11;
  static const jbyte CAPABILITIES = 12;
  static const jbyte CLASS_PATHS = 13;
  static const jbyte DISPOSE_OBJECTS = 14;
  static const jbyte HOLD_EVENTS = 15;
  static const jbyte RELEASE_EVENTS = 16;
  static const jbyte CAPABILITIES_NEW = 17;
  static const jbyte REDEFINE_CLASSES = 18;
  static const jbyte SET_DEFAULT_STRATUM = 19;
  static const jbyte ALL_CLASSES_WITH_GENERIC = 20;
  static ::java::lang::Class class$;
};

#endif // __gnu_classpath_jdwp_JdwpConstants$CommandSet$VirtualMachine__
