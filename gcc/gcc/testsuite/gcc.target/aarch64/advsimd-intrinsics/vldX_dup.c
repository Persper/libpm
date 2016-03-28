#include <arm_neon.h>
#include "arm-neon-ref.h"
#include "compute-ref-data.h"

/* Expected results.  */

/* vld2_dup/chunk 0.  */
VECT_VAR_DECL(expected_vld2_0,int,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
				       0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_0,int,16,4) [] = { 0xfff0, 0xfff1, 0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_0,int,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld2_0,int,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld2_0,uint,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
					0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_0,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_0,uint,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld2_0,uint,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld2_0,poly,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
					0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_0,poly,16,4) [] = { 0xfff0, 0xfff1, 0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_0,hfloat,32,2) [] = { 0xc1800000, 0xc1700000 };
VECT_VAR_DECL(expected_vld2_0,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					0x33, 0x33, 0x33, 0x33,
					0x33, 0x33, 0x33, 0x33,
					0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_0,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_0,int,32,4) [] = { 0x33333333, 0x33333333,
					0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld2_0,int,64,2) [] = { 0x3333333333333333,
					0x3333333333333333 };
VECT_VAR_DECL(expected_vld2_0,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_0,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					 0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_0,uint,32,4) [] = { 0x33333333, 0x33333333,
					 0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld2_0,uint,64,2) [] = { 0x3333333333333333,
					 0x3333333333333333 };
VECT_VAR_DECL(expected_vld2_0,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33,
					 0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_0,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					 0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_0,hfloat,32,4) [] = { 0x33333333, 0x33333333,
					   0x33333333, 0x33333333 };

/* vld2_dup/chunk 1.  */
VECT_VAR_DECL(expected_vld2_1,int,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
					      0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_1,int,16,4) [] = { 0xfff0, 0xfff1, 0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_1,int,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld2_1,int,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld2_1,uint,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
					       0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_1,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_1,uint,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld2_1,uint,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld2_1,poly,8,8) [] = { 0xf0, 0xf1, 0xf0, 0xf1,
					       0xf0, 0xf1, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld2_1,poly,16,4) [] = { 0xfff0, 0xfff1,
						0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld2_1,hfloat,32,2) [] = { 0xc1800000, 0xc1700000 };
VECT_VAR_DECL(expected_vld2_1,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_1,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_1,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld2_1,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld2_1,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_1,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_1,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld2_1,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld2_1,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld2_1,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld2_1,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld3_dup/chunk 0.  */
VECT_VAR_DECL(expected_vld3_0,int,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf0,
					      0xf1, 0xf2, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld3_0,int,16,4) [] = { 0xfff0, 0xfff1,
					       0xfff2, 0xfff0 };
VECT_VAR_DECL(expected_vld3_0,int,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld3_0,int,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld3_0,uint,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf0,
					       0xf1, 0xf2, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld3_0,uint,16,4) [] = { 0xfff0, 0xfff1,
						0xfff2, 0xfff0 };
VECT_VAR_DECL(expected_vld3_0,uint,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld3_0,uint,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld3_0,poly,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf0,
					       0xf1, 0xf2, 0xf0, 0xf1 };
VECT_VAR_DECL(expected_vld3_0,poly,16,4) [] = { 0xfff0, 0xfff1,
						0xfff2, 0xfff0 };
VECT_VAR_DECL(expected_vld3_0,hfloat,32,2) [] = { 0xc1800000, 0xc1700000 };
VECT_VAR_DECL(expected_vld3_0,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_0,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_0,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_0,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_0,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_0,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_0,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_0,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_0,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_0,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_0,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld3_dup/chunk 1.  */
VECT_VAR_DECL(expected_vld3_1,int,8,8) [] = { 0xf2, 0xf0, 0xf1, 0xf2,
					      0xf0, 0xf1, 0xf2, 0xf0 };
VECT_VAR_DECL(expected_vld3_1,int,16,4) [] = { 0xfff1, 0xfff2,
					       0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld3_1,int,32,2) [] = { 0xfffffff2, 0xfffffff0 };
VECT_VAR_DECL(expected_vld3_1,int,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld3_1,uint,8,8) [] = { 0xf2, 0xf0, 0xf1, 0xf2,
					       0xf0, 0xf1, 0xf2, 0xf0 };
VECT_VAR_DECL(expected_vld3_1,uint,16,4) [] = { 0xfff1, 0xfff2,
						0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld3_1,uint,32,2) [] = { 0xfffffff2, 0xfffffff0 };
VECT_VAR_DECL(expected_vld3_1,uint,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld3_1,poly,8,8) [] = { 0xf2, 0xf0, 0xf1, 0xf2,
					       0xf0, 0xf1, 0xf2, 0xf0 };
VECT_VAR_DECL(expected_vld3_1,poly,16,4) [] = { 0xfff1, 0xfff2,
						0xfff0, 0xfff1 };
VECT_VAR_DECL(expected_vld3_1,hfloat,32,2) [] = { 0xc1600000, 0xc1800000 };
VECT_VAR_DECL(expected_vld3_1,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_1,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_1,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_1,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_1,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_1,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_1,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_1,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_1,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_1,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_1,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld3_dup/chunk 2.  */
VECT_VAR_DECL(expected_vld3_2,int,8,8) [] = { 0xf1, 0xf2, 0xf0, 0xf1,
					      0xf2, 0xf0, 0xf1, 0xf2 };
VECT_VAR_DECL(expected_vld3_2,int,16,4) [] = { 0xfff2, 0xfff0,
					       0xfff1, 0xfff2 };
VECT_VAR_DECL(expected_vld3_2,int,32,2) [] = { 0xfffffff1, 0xfffffff2 };
VECT_VAR_DECL(expected_vld3_2,int,64,1) [] = { 0xfffffffffffffff2 };
VECT_VAR_DECL(expected_vld3_2,uint,8,8) [] = { 0xf1, 0xf2, 0xf0, 0xf1,
					       0xf2, 0xf0, 0xf1, 0xf2 };
VECT_VAR_DECL(expected_vld3_2,uint,16,4) [] = { 0xfff2, 0xfff0,
						0xfff1, 0xfff2 };
VECT_VAR_DECL(expected_vld3_2,uint,32,2) [] = { 0xfffffff1, 0xfffffff2 };
VECT_VAR_DECL(expected_vld3_2,uint,64,1) [] = { 0xfffffffffffffff2 };
VECT_VAR_DECL(expected_vld3_2,poly,8,8) [] = { 0xf1, 0xf2, 0xf0, 0xf1,
					       0xf2, 0xf0, 0xf1, 0xf2 };
VECT_VAR_DECL(expected_vld3_2,poly,16,4) [] = { 0xfff2, 0xfff0,
						0xfff1, 0xfff2 };
VECT_VAR_DECL(expected_vld3_2,hfloat,32,2) [] = { 0xc1700000, 0xc1600000 };
VECT_VAR_DECL(expected_vld3_2,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_2,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_2,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_2,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_2,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_2,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_2,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld3_2,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld3_2,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld3_2,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld3_2,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld4_dup/chunk 0.  */
VECT_VAR_DECL(expected_vld4_0,int,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					      0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_0,int,16,4) [] = { 0xfff0, 0xfff1,
					       0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_0,int,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld4_0,int,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld4_0,uint,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_0,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_0,uint,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld4_0,uint,64,1) [] = { 0xfffffffffffffff0 };
VECT_VAR_DECL(expected_vld4_0,poly,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_0,poly,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_0,hfloat,32,2) [] = { 0xc1800000, 0xc1700000 };
VECT_VAR_DECL(expected_vld4_0,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_0,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_0,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_0,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_0,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_0,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_0,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_0,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_0,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_0,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_0,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld4_dup/chunk 1.  */
VECT_VAR_DECL(expected_vld4_1,int,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					      0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_1,int,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_1,int,32,2) [] = { 0xfffffff2, 0xfffffff3 };
VECT_VAR_DECL(expected_vld4_1,int,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld4_1,uint,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_1,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_1,uint,32,2) [] = { 0xfffffff2, 0xfffffff3 };
VECT_VAR_DECL(expected_vld4_1,uint,64,1) [] = { 0xfffffffffffffff1 };
VECT_VAR_DECL(expected_vld4_1,poly,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_1,poly,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_1,hfloat,32,2) [] = { 0xc1600000, 0xc1500000 };
VECT_VAR_DECL(expected_vld4_1,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_1,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_1,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_1,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_1,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_1,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_1,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_1,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_1,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_1,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_1,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld4_dup/chunk 2.  */
VECT_VAR_DECL(expected_vld4_2,int,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					      0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_2,int,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_2,int,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld4_2,int,64,1) [] = { 0xfffffffffffffff2 };
VECT_VAR_DECL(expected_vld4_2,uint,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_2,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_2,uint,32,2) [] = { 0xfffffff0, 0xfffffff1 };
VECT_VAR_DECL(expected_vld4_2,uint,64,1) [] = { 0xfffffffffffffff2 };
VECT_VAR_DECL(expected_vld4_2,poly,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_2,poly,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_2,hfloat,32,2) [] = { 0xc1800000, 0xc1700000 };
VECT_VAR_DECL(expected_vld4_2,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_2,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_2,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_2,int,64,2) [] = { 0x3333333333333333,
					       0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_2,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_2,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_2,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_2,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_2,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_2,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_2,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

/* vld4_dup/chunk3.  */
VECT_VAR_DECL(expected_vld4_3,int,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					      0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_3,int,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_3,int,32,2) [] = { 0xfffffff2, 0xfffffff3 };
VECT_VAR_DECL(expected_vld4_3,int,64,1) [] = { 0xfffffffffffffff3 };
VECT_VAR_DECL(expected_vld4_3,uint,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_3,uint,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_3,uint,32,2) [] = { 0xfffffff2, 0xfffffff3 };
VECT_VAR_DECL(expected_vld4_3,uint,64,1) [] = { 0xfffffffffffffff3 };
VECT_VAR_DECL(expected_vld4_3,poly,8,8) [] = { 0xf0, 0xf1, 0xf2, 0xf3,
					       0xf0, 0xf1, 0xf2, 0xf3 };
VECT_VAR_DECL(expected_vld4_3,poly,16,4) [] = { 0xfff0, 0xfff1, 0xfff2, 0xfff3 };
VECT_VAR_DECL(expected_vld4_3,hfloat,32,2) [] = { 0xc1600000, 0xc1500000 };
VECT_VAR_DECL(expected_vld4_3,int,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33,
					       0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_3,int,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
					       0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_3,int,32,4) [] = { 0x33333333, 0x33333333,
					       0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_3,int,64,2) [] = { 0x3333333333333333, 0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_3,uint,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_3,uint,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_3,uint,32,4) [] = { 0x33333333, 0x33333333,
						0x33333333, 0x33333333 };
VECT_VAR_DECL(expected_vld4_3,uint,64,2) [] = { 0x3333333333333333,
						0x3333333333333333 };
VECT_VAR_DECL(expected_vld4_3,poly,8,16) [] = { 0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33,
						0x33, 0x33, 0x33, 0x33 };
VECT_VAR_DECL(expected_vld4_3,poly,16,8) [] = { 0x3333, 0x3333, 0x3333, 0x3333,
						0x3333, 0x3333, 0x3333, 0x3333 };
VECT_VAR_DECL(expected_vld4_3,hfloat,32,4) [] = { 0x33333333, 0x33333333,
						  0x33333333, 0x33333333 };

void exec_vldX_dup (void)
{
  /* In this case, input variables are arrays of vectors.  */
#define DECL_VLDX_DUP(T1, W, N, X)					\
  VECT_ARRAY_TYPE(T1, W, N, X) VECT_ARRAY_VAR(vector, T1, W, N, X);	\
  VECT_VAR_DECL(result_bis_##X, T1, W, N)[X * N]

  /* We need to use a temporary result buffer (result_bis), because
     the one used for other tests is not large enough. A subset of the
     result data is moved from result_bis to result, and it is this
     subset which is used to check the actual behaviour. The next
     macro enables to move another chunk of data from result_bis to
     result.  */
#define TEST_VLDX_DUP(Q, T1, T2, W, N, X)				\
  VECT_ARRAY_VAR(vector, T1, W, N, X) =					\
    vld##X##Q##_dup_##T2##W(&VECT_VAR(buffer_dup, T1, W, N)[0]);	\
									\
  vst##X##Q##_##T2##W(VECT_VAR(result_bis_##X, T1, W, N),		\
		      VECT_ARRAY_VAR(vector, T1, W, N, X));		\
  memcpy(VECT_VAR(result, T1, W, N), VECT_VAR(result_bis_##X, T1, W, N), \
	 sizeof(VECT_VAR(result, T1, W, N)));


  /* Overwrite "result" with the contents of "result_bis"[Y].  */
#define TEST_EXTRA_CHUNK(T1, W, N, X,Y)			\
  memcpy(VECT_VAR(result, T1, W, N),			\
	 &(VECT_VAR(result_bis_##X, T1, W, N)[Y*N]),	\
	 sizeof(VECT_VAR(result, T1, W, N)));

#define DECL_ALL_VLDX_DUP(X)			\
  DECL_VLDX_DUP(int, 8, 8, X);			\
  DECL_VLDX_DUP(int, 16, 4, X);			\
  DECL_VLDX_DUP(int, 32, 2, X);			\
  DECL_VLDX_DUP(int, 64, 1, X);			\
  DECL_VLDX_DUP(uint, 8, 8, X);			\
  DECL_VLDX_DUP(uint, 16, 4, X);		\
  DECL_VLDX_DUP(uint, 32, 2, X);		\
  DECL_VLDX_DUP(uint, 64, 1, X);		\
  DECL_VLDX_DUP(poly, 8, 8, X);			\
  DECL_VLDX_DUP(poly, 16, 4, X);		\
  DECL_VLDX_DUP(float, 32, 2, X)

#define TEST_ALL_VLDX_DUP(X)			\
  TEST_VLDX_DUP(, int, s, 8, 8, X);		\
  TEST_VLDX_DUP(, int, s, 16, 4, X);		\
  TEST_VLDX_DUP(, int, s, 32, 2, X);		\
  TEST_VLDX_DUP(, int, s, 64, 1, X);		\
  TEST_VLDX_DUP(, uint, u, 8, 8, X);		\
  TEST_VLDX_DUP(, uint, u, 16, 4, X);		\
  TEST_VLDX_DUP(, uint, u, 32, 2, X);		\
  TEST_VLDX_DUP(, uint, u, 64, 1, X);		\
  TEST_VLDX_DUP(, poly, p, 8, 8, X);		\
  TEST_VLDX_DUP(, poly, p, 16, 4, X);		\
  TEST_VLDX_DUP(, float, f, 32, 2, X)

#define TEST_ALL_EXTRA_CHUNKS(X, Y)		\
  TEST_EXTRA_CHUNK(int, 8, 8, X, Y);		\
  TEST_EXTRA_CHUNK(int, 16, 4, X, Y);		\
  TEST_EXTRA_CHUNK(int, 32, 2, X, Y);		\
  TEST_EXTRA_CHUNK(int, 64, 1, X, Y);		\
  TEST_EXTRA_CHUNK(uint, 8, 8, X, Y);		\
  TEST_EXTRA_CHUNK(uint, 16, 4, X, Y);		\
  TEST_EXTRA_CHUNK(uint, 32, 2, X, Y);		\
  TEST_EXTRA_CHUNK(uint, 64, 1, X, Y);		\
  TEST_EXTRA_CHUNK(poly, 8, 8, X, Y);		\
  TEST_EXTRA_CHUNK(poly, 16, 4, X, Y);		\
  TEST_EXTRA_CHUNK(float, 32, 2, X, Y)


  DECL_ALL_VLDX_DUP(2);
  DECL_ALL_VLDX_DUP(3);
  DECL_ALL_VLDX_DUP(4);

  /* Special input buffers of suitable size are needed for vld2/vld3/vld4.  */
  /* Input buffers for vld2, 1 of each size */
  VECT_ARRAY_INIT2(buffer_vld2, int, 8, 8);
  PAD(buffer_vld2_pad, int, 8, 8);
  VECT_ARRAY_INIT2(buffer_vld2, int, 16, 4);
  PAD(buffer_vld2_pad, int, 16, 4);
  VECT_ARRAY_INIT2(buffer_vld2, int, 32, 2);
  PAD(buffer_vld2_pad, int, 32, 2);
  VECT_ARRAY_INIT2(buffer_vld2, int, 64, 1);
  PAD(buffer_vld2_pad, int, 64, 1);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 8, 8);
  PAD(buffer_vld2_pad, uint, 8, 8);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 16, 4);
  PAD(buffer_vld2_pad, uint, 16, 4);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 32, 2);
  PAD(buffer_vld2_pad, uint, 32, 2);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 64, 1);
  PAD(buffer_vld2_pad, uint, 64, 1);
  VECT_ARRAY_INIT2(buffer_vld2, poly, 8, 8);
  PAD(buffer_vld2_pad, poly, 8, 8);
  VECT_ARRAY_INIT2(buffer_vld2, poly, 16, 4);
  PAD(buffer_vld2_pad, poly, 16, 4);
  VECT_ARRAY_INIT2(buffer_vld2, float, 32, 2);
  PAD(buffer_vld2_pad, float, 32, 2);

  VECT_ARRAY_INIT2(buffer_vld2, int, 8, 16);
  PAD(buffer_vld2_pad, int, 8, 16);
  VECT_ARRAY_INIT2(buffer_vld2, int, 16, 8);
  PAD(buffer_vld2_pad, int, 16, 8);
  VECT_ARRAY_INIT2(buffer_vld2, int, 32, 4);
  PAD(buffer_vld2_pad, int, 32, 4);
  VECT_ARRAY_INIT2(buffer_vld2, int, 64, 2);
  PAD(buffer_vld2_pad, int, 64, 2);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 8, 16);
  PAD(buffer_vld2_pad, uint, 8, 16);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 16, 8);
  PAD(buffer_vld2_pad, uint, 16, 8);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 32, 4);
  PAD(buffer_vld2_pad, uint, 32, 4);
  VECT_ARRAY_INIT2(buffer_vld2, uint, 64, 2);
  PAD(buffer_vld2_pad, uint, 64, 2);
  VECT_ARRAY_INIT2(buffer_vld2, poly, 8, 16);
  PAD(buffer_vld2_pad, poly, 8, 16);
  VECT_ARRAY_INIT2(buffer_vld2, poly, 16, 8);
  PAD(buffer_vld2_pad, poly, 16, 8);
  VECT_ARRAY_INIT2(buffer_vld2, float, 32, 4);
  PAD(buffer_vld2_pad, float, 32, 4);

  /* Input buffers for vld3, 1 of each size */
  VECT_ARRAY_INIT3(buffer_vld3, int, 8, 8);
  PAD(buffer_vld3_pad, int, 8, 8);
  VECT_ARRAY_INIT3(buffer_vld3, int, 16, 4);
  PAD(buffer_vld3_pad, int, 16, 4);
  VECT_ARRAY_INIT3(buffer_vld3, int, 32, 2);
  PAD(buffer_vld3_pad, int, 32, 2);
  VECT_ARRAY_INIT3(buffer_vld3, int, 64, 1);
  PAD(buffer_vld3_pad, int, 64, 1);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 8, 8);
  PAD(buffer_vld3_pad, uint, 8, 8);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 16, 4);
  PAD(buffer_vld3_pad, uint, 16, 4);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 32, 2);
  PAD(buffer_vld3_pad, uint, 32, 2);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 64, 1);
  PAD(buffer_vld3_pad, uint, 64, 1);
  VECT_ARRAY_INIT3(buffer_vld3, poly, 8, 8);
  PAD(buffer_vld3_pad, poly, 8, 8);
  VECT_ARRAY_INIT3(buffer_vld3, poly, 16, 4);
  PAD(buffer_vld3_pad, poly, 16, 4);
  VECT_ARRAY_INIT3(buffer_vld3, float, 32, 2);
  PAD(buffer_vld3_pad, float, 32, 2);

  VECT_ARRAY_INIT3(buffer_vld3, int, 8, 16);
  PAD(buffer_vld3_pad, int, 8, 16);
  VECT_ARRAY_INIT3(buffer_vld3, int, 16, 8);
  PAD(buffer_vld3_pad, int, 16, 8);
  VECT_ARRAY_INIT3(buffer_vld3, int, 32, 4);
  PAD(buffer_vld3_pad, int, 32, 4);
  VECT_ARRAY_INIT3(buffer_vld3, int, 64, 2);
  PAD(buffer_vld3_pad, int, 64, 2);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 8, 16);
  PAD(buffer_vld3_pad, uint, 8, 16);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 16, 8);
  PAD(buffer_vld3_pad, uint, 16, 8);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 32, 4);
  PAD(buffer_vld3_pad, uint, 32, 4);
  VECT_ARRAY_INIT3(buffer_vld3, uint, 64, 2);
  PAD(buffer_vld3_pad, uint, 64, 2);
  VECT_ARRAY_INIT3(buffer_vld3, poly, 8, 16);
  PAD(buffer_vld3_pad, poly, 8, 16);
  VECT_ARRAY_INIT3(buffer_vld3, poly, 16, 8);
  PAD(buffer_vld3_pad, poly, 16, 8);
  VECT_ARRAY_INIT3(buffer_vld3, float, 32, 4);
  PAD(buffer_vld3_pad, float, 32, 4);

  /* Input buffers for vld4, 1 of each size */
  VECT_ARRAY_INIT4(buffer_vld4, int, 8, 8);
  PAD(buffer_vld4_pad, int, 8, 8);
  VECT_ARRAY_INIT4(buffer_vld4, int, 16, 4);
  PAD(buffer_vld4_pad, int, 16, 4);
  VECT_ARRAY_INIT4(buffer_vld4, int, 32, 2);
  PAD(buffer_vld4_pad, int, 32, 2);
  VECT_ARRAY_INIT4(buffer_vld4, int, 64, 1);
  PAD(buffer_vld4_pad, int, 64, 1);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 8, 8);
  PAD(buffer_vld4_pad, uint, 8, 8);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 16, 4);
  PAD(buffer_vld4_pad, uint, 16, 4);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 32, 2);
  PAD(buffer_vld4_pad, uint, 32, 2);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 64, 1);
  PAD(buffer_vld4_pad, uint, 64, 1);
  VECT_ARRAY_INIT4(buffer_vld4, poly, 8, 8);
  PAD(buffer_vld4_pad, poly, 8, 8);
  VECT_ARRAY_INIT4(buffer_vld4, poly, 16, 4);
  PAD(buffer_vld4_pad, poly, 16, 4);
  VECT_ARRAY_INIT4(buffer_vld4, float, 32, 2);
  PAD(buffer_vld4_pad, float, 32, 2);

  VECT_ARRAY_INIT4(buffer_vld4, int, 8, 16);
  PAD(buffer_vld4_pad, int, 8, 16);
  VECT_ARRAY_INIT4(buffer_vld4, int, 16, 8);
  PAD(buffer_vld4_pad, int, 16, 8);
  VECT_ARRAY_INIT4(buffer_vld4, int, 32, 4);
  PAD(buffer_vld4_pad, int, 32, 4);
  VECT_ARRAY_INIT4(buffer_vld4, int, 64, 2);
  PAD(buffer_vld4_pad, int, 64, 2);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 8, 16);
  PAD(buffer_vld4_pad, uint, 8, 16);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 16, 8);
  PAD(buffer_vld4_pad, uint, 16, 8);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 32, 4);
  PAD(buffer_vld4_pad, uint, 32, 4);
  VECT_ARRAY_INIT4(buffer_vld4, uint, 64, 2);
  PAD(buffer_vld4_pad, uint, 64, 2);
  VECT_ARRAY_INIT4(buffer_vld4, poly, 8, 16);
  PAD(buffer_vld4_pad, poly, 8, 16);
  VECT_ARRAY_INIT4(buffer_vld4, poly, 16, 8);
  PAD(buffer_vld4_pad, poly, 16, 8);
  VECT_ARRAY_INIT4(buffer_vld4, float, 32, 4);
  PAD(buffer_vld4_pad, float, 32, 4);

  /* Check vld2_dup/vld2q_dup.  */
  clean_results ();
#define TEST_MSG "VLD2_DUP/VLD2Q_DUP"
  TEST_ALL_VLDX_DUP(2);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld2_0, "chunk 0");

  TEST_ALL_EXTRA_CHUNKS(2, 1);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld2_1, "chunk 1");

  /* Check vld3_dup/vld3q_dup.  */
  clean_results ();
#undef TEST_MSG
#define TEST_MSG "VLD3_DUP/VLD3Q_DUP"
  TEST_ALL_VLDX_DUP(3);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld3_0, "chunk 0");

  TEST_ALL_EXTRA_CHUNKS(3, 1);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld3_1, "chunk 1");

  TEST_ALL_EXTRA_CHUNKS(3, 2);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld3_2, "chunk 2");

  /* Check vld4_dup/vld4q_dup */
  clean_results ();
#undef TEST_MSG
#define TEST_MSG "VLD4_DUP/VLD4Q_DUP"
  TEST_ALL_VLDX_DUP(4);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld4_0, "chunk 0");

  TEST_ALL_EXTRA_CHUNKS(4, 1);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld4_1, "chunk 1");

  TEST_ALL_EXTRA_CHUNKS(4, 2);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld4_2, "chunk 2");

  TEST_ALL_EXTRA_CHUNKS(4, 3);
  CHECK_RESULTS_NAMED (TEST_MSG, expected_vld4_3, "chunk 3");
}

int main (void)
{
  exec_vldX_dup ();
  return 0;
}
