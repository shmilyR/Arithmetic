#include <stdio.h>
#include <stdlib.h>

int searchElement(int a[],int n) {
	//此题的思路是：我先把该数组分成前后两个部分，然后再统计前后数组中的数字在数组中出现的次数 
	//但是，分成前后两个部分的前提是：我要遍历这个数组，找出两部分的次数，然后再进行比较
	int start = 1;
	int end = n - 1;

	while (end >= start) {
		int middle = (end - start) / 2 + start;
		int count = 0;

		for (int i = 0; i < n; i++) {
			if (a[i] >= start && a[i] <= middle) {
				++count;
			}
			//前半部分count 后半部分是cout
			//如果前半部分>后半部分 serrch(a[],n/2) 
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

//递归实现
int recursion(int a[],int n,int start,int length) {
	//先遍历数组
	int before = 0;//前半部分出现的次数
	int behind = 0;//后半部分出现的次数
	//判断前后部分出现的次数
	for (int i = 0; i < length;i++) {//是为了遍历所有的数组 比较
		if (a[i] >= start && a[i] <= n / 2) {
			printf("====%d\n",a[i]);
			before++;
		} else if(a[i] > n / 2  && a[i] <= n){
			behind++;
			printf("%d\n", a[i]);
		}
	}
	printf("before=%d,behind=%d\n",before,behind);
	//before 5 behind 3 此时before > behind 
	int result = 0; 
	if (before > behind) {

		result = recursion(a,n/2,start,length);
	} else if (before < behind) {
		result = recursion(a, n, n / 2 + 1,length);
	} else if ( before == behind) {
		return -1;
	}
	//如果此时的before大于此区间的长度 说明这个元素一定是重复元素


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
