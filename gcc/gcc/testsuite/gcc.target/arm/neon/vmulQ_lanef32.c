/* Test the `vmulQ_lanef32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vmulQ_lanef32 (void)
{
  float32x4_t out_float32x4_t;
  float32x4_t arg0_float32x4_t;
  float32x2_t arg1_float32x2_t;

  out_float32x4_t = vmulq_lane_f32 (arg0_float32x4_t, arg1_float32x2_t, 1);
}

/* { dg-final { scan-assembler "vmul\.f32\[ 	\]+\[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+, \[dD\]\[0-9\]+\\\[\[0-9\]+\\\]!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
