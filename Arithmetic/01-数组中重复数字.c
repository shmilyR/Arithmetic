#include<stdio.h>
#include<stdlib.h>

int duplicate(int a[],int n,int *p) {
	//˼·��������Ŀ���Ѿ�˵������Ԫ�صķ�Χ��0~n-1��������һ�㣬���ǿ�����һ�����Ӷ�Ϊo(n)���㷨��
	//��ÿ�ζ�������Ԫ�طŵ����Ӧ���±��λ�ã������������±�λ�õ�Ԫ�ؾ���������Ҫ�ҵ����ظ����֡�
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