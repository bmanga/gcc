/* { dg-do run { target aarch64_sve_hw } } */
/* { dg-options "-O2 -ftree-vectorize --save-temps" } */

#define TYPE unsigned long
#define ITYPE long
#include "struct_vect_7_run.c"
