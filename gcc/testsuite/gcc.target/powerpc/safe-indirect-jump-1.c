/* { dg-do compile { target { lp64 } } } */
/* { dg-additional-options "-mno-speculate-indirect-jumps" } */

/* Test for deliberate misprediction of indirect calls.  */

extern int (*f)();

int bar ()
{
  return (*f) ();
}

/* { dg-final { scan-assembler "crset eq" } } */
/* { dg-final { scan-assembler "beqctrl-" } } */
