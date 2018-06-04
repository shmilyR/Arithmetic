#include <stdio.h>
#include <stdlib.h>

int searchElement(int a[],int n) {
	//�����˼·�ǣ����ȰѸ�����ֳ�ǰ���������֣�Ȼ����ͳ��ǰ�������е������������г��ֵĴ��� 
	//���ǣ��ֳ�ǰ���������ֵ�ǰ���ǣ���Ҫ����������飬�ҳ������ֵĴ�����Ȼ���ٽ��бȽ�
	int start = 1;
	int end = n - 1;

	while (end >= start) {
		int middle = (end - start) / 2 + start;
		int count = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] >= start && a[i] <= middle) {
				++count;
			}
			//ǰ�벿��count ��벿����cout
			//���ǰ�벿��>��벿�� serrch(a[],n/2) 
			//count == cout return
		}
		
		if (end == start) {
			if (count > 1) {
				return start;
			}else {
				break;
			}
		}
		if (count > (middle - start + 1)) {
			end = middle;
		}else {
			start = middle + 1;
		}
	}
	return -1;
}

//�ݹ�ʵ��
int recursion(int a[],int n,int start,int length) {
	//�ȱ�������
	int before = 0;//ǰ�벿�ֳ��ֵĴ���
	int behind = 0;//��벿�ֳ��ֵĴ���
	//�ж�ǰ�󲿷ֳ��ֵĴ���
	for (int i = 0; i < length;i++) {//��Ϊ�˱������е����� �Ƚ�
		if (a[i] >= start && a[i] <= n / 2) {
			printf("====%d\n",a[i]);
			before++;
		} else if(a[i] > n / 2  && a[i] <= n){
			behind++;
			printf("%d\n", a[i]);
		}
	}
	printf("before=%d,behind=%d\n",before,behind);
	//before 5 behind 3 ��ʱbefore > behind 
	int result = 0; 
	if (before > behind) {

		result = recursion(a,n/2,start,length);
	} else if (before < behind) {
		result = recursion(a, n, n / 2 + 1,length);
	} else if ( before == behind) {
		return -1;
	}
	//�����ʱ��before���ڴ�����ĳ��� ˵�����Ԫ��һ�����ظ�Ԫ��


	return result;
	
}

int main(int argc, char *argv[]) {
	int a[8] = {2,3,5,4,3,2,6,7};
	//int i = searchElement(a,8);
	//printf("%d\n",i);
	int i = recursion(a,8,1,8);
	printf("%d\n",i);
	return 0;
}
