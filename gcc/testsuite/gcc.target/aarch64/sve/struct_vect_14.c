/* { dg-do assemble { target aarch64_asm_sve_ok } } */
/* { dg-options "-O2 -ftree-vectorize -msve-vector-bits=256 --save-temps" } */

#define TYPE unsigned char
#define NAME(X) qi_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE unsigned short
#define NAME(X) hi_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE unsigned int
#define NAME(X) si_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE unsigned long
#define NAME(X) di_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE _Float16
#define NAME(X) hf_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE float
#define NAME(X) sf_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

#define TYPE double
#define NAME(X) df_##X
#include "struct_vect_1.c"
#undef NAME
#undef TYPE

/* { dg-final { scan-assembler-times {\tld2b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7]/z, \[x[0-9]+\]\n} 1 } } */
/* { dg-final { scan-assembler-times {\tld3b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7]/z, \[x[0-9]+\]\n} 1 } } */
/* { dg-final { scan-assembler-times {\tld4b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7]/z, \[x[0-9]+\]\n} 1 } } */
/* { dg-final { scan-assembler-times {\tst2b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7], \[x[0-9]+\]\n} 1 } } */
/* { dg-final { scan-assembler-times {\tst3b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7], \[x[0-9]+\]\n} 1 } } */
/* { dg-final { scan-assembler-times {\tst4b\t{z[0-9]+.b - z[0-9]+.b}, p[0-7], \[x[0-9]+\]\n} 1 } } */

/* { dg-final { scan-assembler-times {\tld2h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld3h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld4h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst2h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst3h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst4h\t{z[0-9]+.h - z[0-9]+.h}, p[0-7], \[x[0-9]+\]\n} 2 } } */

/* { dg-final { scan-assembler-times {\tld2w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld3w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld4w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst2w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst3w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst4w\t{z[0-9]+.s - z[0-9]+.s}, p[0-7], \[x[0-9]+\]\n} 2 } } */

/* { dg-final { scan-assembler-times {\tld2d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld3d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tld4d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7]/z, \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst2d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst3d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7], \[x[0-9]+\]\n} 2 } } */
/* { dg-final { scan-assembler-times {\tst4d\t{z[0-9]+.d - z[0-9]+.d}, p[0-7], \[x[0-9]+\]\n} 2 } } */
