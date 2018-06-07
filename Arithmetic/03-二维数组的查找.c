#include<stdio.h>

#define ROW 4
#define COL 4

//任选一个角来实现
int find(int arr[4][4],int m,int n,int num) {
	while (arr[m][n] != num && m >= 0 && n < 4 && n >= 0 && m < 4) {
		if (arr[m][n] > num) {
			n--;
		} else if (arr[m][n] < num) {
			m++;
		}
	}
	if (arr[m][n] == num) {
		return 1;
	}
	return 0;
}
//用二分法来实现二维数组的查找
int search(int arr[ROW][COL],int num) {
	int start = 0;
	int end = ROW - 1;
	int middle = (start + end + 1) / 2;

	//先从行开始找 
	for (int i = 0; i < ROW; ) {

		if (arr[i][middle] > num) {
			end = middle - 1;
		} else if(arr[i][middle] < num){
			start = middle + 1;
		} else if (arr[i][middle] == num) {
			return 1;
		}
		middle = (start + end + 1) / 2;
		//此时说明这一行都已经找完了，但是还没有找到，就应该遍历列，并且将一部分元素可以剔除掉
		if (start > end) {
			for (int j = 0; j < COL;) {
				int start1 = 0;
				int end1 = COL - 1;
				int middle1 = (start1 + end1 + 1) / 2;

				if (arr[middle1][j] > num) {

				}
			}
		}
	}
}


int main(void) {
	int array[4][4] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	int t = find(array,0,3,7);
	//printf("%d\n",t);

	int s = search(array,7);
	printf("%d\n",s);

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4;j++) {
	//		printf("%5d",array[i][j]);
	//	}
	//	printf("\n");
	//}

	return 0;
}