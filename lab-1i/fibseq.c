#include <stdio.h>

extern int fibonacci(int x, int a, int b);

int main(int argc, char **argv)
{
  int number=0;
  int result=0;

  scanf("%d",&number);
  result = fibonacci(number, 1, 0);   
  printf("The fibonacci sequence at %d is: %d\n", number, result);
}

/*
int fib_recursive(int n, int val, int prev){
	
	if(n == 0)
		return prev;
	if(n == 1)
		return val;
	return fib_recursive(n-1, val+prev, val);
}
*/
