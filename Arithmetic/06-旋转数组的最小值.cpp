#include<stdio.h>

//ͨ�����ַ�������ת������Сֵ
int find(int a[],int n) {
	//���ַ�Ӧ����һ��start��end��middle
	int start = 0;
	int end = n - 1;
	int middle = 0;

	while (a[start] >= a[end]) {
		if (end - start == 1) {
			middle = end;
			break;
		}
		middle = (start + end) / 2;
		
		if (a[start] == a[end] && a[end] == a[middle]) {
			int result = a[start];;
			//��ʱֻ�ܽ���˳�����
			for (int i = start + 1; i <= end; i++) {
				
				if (result > a[i]) {
					result = a[i];
				}
			}
			return result;
		}

		if (a[start] >= a[middle]) {
			end = middle;
		}else if (a[start] <= a[middle]) {
			start = middle;
		}
	}
	
	return a[middle];
}

int main(void) {
	int arr[5] = {1,1,1,0,1};
	//int arr[6] = {0,0,0,0,0,0};
	printf("%d\n",find(arr,5));
}