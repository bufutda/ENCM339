// ENCM 339 Fall 2015 Lab 4 Exercise C

#include <stdio.h>

int foo(const int *a, int n);

// This function was not written for easy readability!
// It's a drill exercise related to pointer arithmetic!
int foo(const int *a, int n)
{
  const int *max = a, *min = a + n - 1, *guard = a + n;
  const int *p, *q;
  for (p = a + 1; p != guard; p++) {
    if (*p > *max)
      max = p;
  }
  for (q = guard - 1; q != a; q--) {
    if (q[-1] < *min)
      min = q - 1;
  }

  printf("\nLOCAL::foo\n\t\"const int *max\" => max(%p) *max(%d)\n\t\"const int *min\" => min(%p) *min(%d)\n\t\"const int *guard\" => guard(%p) *guard(%d)\n\t",max,*max,min,*min,guard,*guard);
  printf("\"const int *p\" => p(%p) *p(%d)\n\t\"const int *q\" => q(%p) *q(%d)\n",p,*p,q,*q);
  printf("ARGS::foo\n\t\"const int *a\" => a(%p) *a(%d)\n\t\"int n\" => n(%d)\n\n", a, *a, n);
  // point one (after the 2nd loop has finished)

  return min - max;
}

int main(void)
{
  int w;
  int x[] = { 10, 5, 15, 20, 25 };
  int y[] = { -10, -40, -50, -30, -20 };
  // printf("\nLOCAL::main\n\t\"int w\" => w(\?\?)\n\t\"int x[]\" => x(%p) *x(%d) x[0](%d) x[1](%d) x[2](%d) x[3](%d) x[4](%d)\n\t",x,*x,x[0],x[1],x[2],x[3],x[4]);
  // printf("\"int y[]\" => y(%p), *y(%d), y[0](%d) y[1](%d) y[2](%d) y[3](%d) y[4](%d)\n",y,*y,y[0],y[1],y[2],y[3],y[4]);
  // printf("ARGS::main\n\t\033[37mno args\033[0m\n\n");
  w = foo(x, sizeof(x) / sizeof(int));
  printf("1st result: %d.\n", w);
  printf("\nLOCAL::main\n\t\"int w\" => w(%d)\n\t\"int x[]\" => x(%p) *x(%d) x[0](%d){%p} x[1](%d){%p} x[2](%d){%p} x[3](%d){%p} x[4](%d){%p}\n\t",w,x,*x,x[0],&x[0],x[1],&x[1],x[2],&x[2],x[3],&x[3],x[4],&x[4]);
  printf("\"int y[]\" => y(%p), *y(%d), y[0](%d){%p} y[1](%d){%p} y[2](%d){%p} y[3](%d){%p} y[4](%d){%p}\n",y,*y,y[0],&y[0],y[1],&y[1],y[2],&y[2],y[3],&y[3],y[4],&y[4]);
  printf("ARGS::main\n\t\033[37mno args\033[0m\n\n");
  w = foo(y, sizeof(y) / sizeof(int));
  // printf("\nLOCAL::main\n\t\"int w\" => w(%d)\n\t\"int x[]\" => x(%p) *x(%d) x[0](%d) x[1](%d) x[2](%d) x[3](%d) x[4](%d)\n\t",w,x,*x,x[0],x[1],x[2],x[3],x[4]);
  // printf("\"int y[]\" => y(%p), *y(%d), y[0](%d) y[1](%d) y[2](%d) y[3](%d) y[4](%d)\n",y,*y,y[0],y[1],y[2],y[3],y[4]);
  // printf("ARGS::main\n\t\033[37mno args\033[0m\n\n");
  printf("2nd result: %d.\n", w);
  return 0;
}
