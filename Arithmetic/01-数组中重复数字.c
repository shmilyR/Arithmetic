#include<stdio.h>
#include<stdlib.h>

int duplicate(int a[],int n,int *p) {
	//思路：由于题目中已经说明数组元素的范围在0~n-1，根据这一点，我们可以有一个复杂度为o(n)的算法，
	//即每次都将数组元素放到其对应的下标的位置，这样，不在下标位置得元素就是我们所要找到的重复数字。
	for (int i = 0; i < n; i++) {
		while (a[i] != i) {
			int tmp = a[i];
			if (a[i] != a[tmp]) {
				int temp = a[i];
				a[i] = a[tmp];
				a[tmp] = temp;
			} else {
				*p = a[i];
				return 0;
			}
			i++;
		}
		
	}
	return 1;
}

int main(void) {
	int a[7] = {2,3,1,0,2,5,3};
	int *p = (int *)malloc(sizeof(int));

	duplicate(a,7,p);
	printf("%d\n",p[0]);

	return 0;
}