#include <stdio.h>
#include "linked.h"

struct Linked {
	int element;
	linked *next;
};

//�õݹ�ʵ��������������
void printWithRecursion(Linked *list) {
	//��list->next != nullʱ����ѡ���ٴε��ô˺��������ݹ顣

	if (list != NULL) {
		printWithRecursion(list->next);
		printf("%5d", list->element);
	}
}

int main() {
	linked *li = NULL;
	li = createLinked();
	//��ʱ�������������£�
	//1 3 4 5 7 8 4 3 2 
	//��ʱ����Ҫ������ǣ�2 3 4 8 7 5 4 3 1
	//printLinked(li);
	printWithRecursion(li->next);
	return 0;
}