/* Test __builtin_{add,sub,mul}_overflow.  */
/* { dg-do run } */
/* { dg-skip-if "" { ! run_expensive_tests }  { "*" } { "-O0" "-O2" } } */

#include "builtin-arith-overflow-12.h"

TESTS (long long, LLONG_MIN, LLONG_MAX)

#undef T
#define T(n, t1, t2, tr, v1, v2, vr, b, o) t##n##b ();

int
main ()
{
  TESTS (long long, LLONG_MIN, LLONG_MAX)
  return 0;
}
