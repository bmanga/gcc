! { dg-do run }
! Test maxloc for strings for different code paths

program main
  implicit none
  integer, parameter :: n=4
  character(len=4), dimension(n,n) :: c
  integer, dimension(n,n) :: a
  integer, dimension(2) :: res1, res2
  real, dimension(n,n) :: r
  logical, dimension(n,n) :: amask
  logical(kind=8) :: smask
  integer :: i,j
  integer, dimension(n) :: q1, q2
  character(len=4,kind=4), dimension(n,n) :: c4
  character(len=4), dimension(n*n) :: e
  integer, dimension(n*n) :: f
  logical, dimension(n*n) :: cmask

  call random_number (r)
  a = int(r*100)
  do j=1,n
     do i=1,n
        write (unit=c(i,j),fmt='(I4.4)') a(i,j)
        write (unit=c4(i,j),fmt='(I4.4)') a(i,j)
     end do
  end do
  res1 = maxloc(c)
  res2 = maxloc(a)

  if (any(res1 /= res2)) call abort
  res1 = maxloc(c4)
  if (any(res1 /= res2)) call abort

  amask = a < 50
  res1 = maxloc(c,mask=amask)
  res2 = maxloc(a,mask=amask)

 if (any(res1 /= res2)) call abort

 amask = .false.
 res1 = maxloc(c,mask=amask)
 if (any(res1 /= 0)) call abort

 amask(2,3) = .true.
 res1 = maxloc(c,mask=amask)
 if (any(res1 /= [2,3])) call abort

 res1 = maxloc(c,mask=.false.)
 if (any(res1 /= 0)) call abort

 res2 = maxloc(a)
 res1 = maxloc(c,mask=.true.)
 if (any(res1 /= res2)) call abort

 q1 = maxloc(c, dim=1)
 q2 = maxloc(a, dim=1)
 if (any(q1 /= q2)) call abort

 q1 = maxloc(c, dim=2)
 q2 = maxloc(a, dim=2)
 if (any(q1 /= q2)) call abort

 q1 = maxloc(c, dim=1, mask=amask)
 q2 = maxloc(a, dim=1, mask=amask)
 if (any(q1 /= q2)) call abort

 q1 = maxloc(c, dim=2, mask=amask)
 q2 = maxloc(a, dim=2, mask=amask)
 if (any(q1 /= q2)) call abort

  amask = a < 50

 q1 = maxloc(c, dim=1, mask=amask)
 q2 = maxloc(a, dim=1, mask=amask)
 if (any(q1 /= q2)) call abort

 q1 = maxloc(c, dim=2, mask=amask)
 q2 = maxloc(a, dim=2, mask=amask)
 if (any(q1 /= q2)) call abort

 e = reshape(c, shape(e))
 f = reshape(a, shape(f))
 if (maxloc(e,dim=1) /= maxloc(f,dim=1)) call abort

 cmask = .false.
 if (maxloc(e,dim=1,mask=cmask) /= 0) call abort

 cmask = f > 50
 if ( maxloc(e, dim=1, mask=cmask) /= maxloc (f, dim=1, mask=cmask)) call abort
end program main
