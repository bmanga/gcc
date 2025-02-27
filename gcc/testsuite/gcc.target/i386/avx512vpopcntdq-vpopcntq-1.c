/* { dg-do run } */
/* { dg-options "-O2 -mavx512vpopcntdq" } */
/* { dg-require-effective-target avx512vpopcntdq } */

#include "avx512f-helper.h"

#define AVX512VPOPCNTDQ
#define SIZE (AVX512F_LEN / 64)

#include "avx512f-mask-type.h"

#define TYPE long long

int
CALC (TYPE v)
{
  int ret;
  int i;

 ret = 0;
 for (i = 0; i < sizeof(v) * 8; i++)
   if ((v & ((TYPE)1 << (TYPE) i)))
     ret++;

 return ret;
}

void
TEST (void)
{
  UNION_TYPE (AVX512F_LEN, i_q) res1, res2, res3, src, src0;
  MASK_TYPE mask = MASK_VALUE;
  TYPE res_ref[SIZE];
  src.x = INTRINSIC (_set1_epi8) (0x3D);
  int i;

  for (i = 0; i < SIZE; i++)
  {
    res_ref[i] = CALC (src.a[i]);
    src0.a[i] = DEFAULT_VALUE;
  }

  res1.x = INTRINSIC (_popcnt_epi64)       (src.x);
  res2.x = INTRINSIC (_mask_popcnt_epi64)  (src.x, mask, src0.x);
  res3.x = INTRINSIC (_maskz_popcnt_epi64) (mask, src.x);

  if (UNION_CHECK (AVX512F_LEN, i_q) (res1, res_ref))
    abort ();

  MASK_MERGE (i_q) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_q) (res2, res_ref))
    abort ();

  MASK_ZERO (i_q) (res_ref, mask, SIZE);
  if (UNION_CHECK (AVX512F_LEN, i_q) (res3, res_ref))
    abort ();
}
