#include <iostream>

using namespace std;

// 手写单链表
struct LinkedList
{
	double value;
	LinkedList* next;
};

int main() {
	LinkedList* head = new LinkedList;
	head->value = 1;
	head->next = nullptr;
	LinkedList* secondPtr = new LinkedList;
	secondPtr->value = 13.5;
	secondPtr->next = nullptr;
	head->next = secondPtr;
	cout << head->value << endl;
	cout << head->next->value << endl;
	return 0;
}