#include <stdio.h>

//递归实现斐波那契数列
int recursion(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	return recursion(n - 1) + recursion(n - 2);
}
//通过自下而上的方式求得第n项
int Fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	int f1 = 1;
	int f0 = 0;
	int fi = 0;

	for (int i = 2; i <= n; i++) {
		fi = f0 + f1;
		f0 = f1;
		f1 = fi;
	}
	return fi;
}


int main(void) {
	int n = 0;
	printf("请输入数列的项数n:");
	scanf("%d",&n);
	printf("%d\n", Fibonacci(n));
	//printf("%d\n",recursion(n));
	return 0;
}