#include <stdio.h>
#include "linked.h"

struct Linked {
	int element;
	linked *next;
};

//用递归实现链表的逆向输出
void printWithRecursion(Linked *list) {
	//当list->next != null时，就选择再次调用此函数，即递归。

	if (list != NULL) {
		printWithRecursion(list->next);
		printf("%5d", list->element);
	}
}

int main() {
	linked *li = NULL;
	li = createLinked();
	//此时给定的链表如下：
	//1 3 4 5 7 8 4 3 2 
	//此时我需要的输出是：2 3 4 8 7 5 4 3 1
	//printLinked(li);
	printWithRecursion(li->next);
	return 0;
}