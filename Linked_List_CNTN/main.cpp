#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head;

void init() {
	head = nullptr;
}

Node* CreateNode(int data) {
	Node* p = new Node;
	p->data = data;
	p->next = nullptr;
	return p;
}

//chen dau
void insertHead(int& data) {
	Node* p = CreateNode(data);
	if (head == nullptr) {
		head = p;
	}
	else {
		p->next = head;
		head = p;
	}
}

//chen cuoi
void insertTail(int& data) {
	Node* p = CreateNode(data);
	if (head == nullptr) {
		head = p;
	}
	else {
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = p;
		p->next = nullptr;
	}
}\

//xoa dau
//void deleteHead() {
//	Node* p = head;
//	if (p == nullptr) {
//		cout << "K co cai chi mo ma xoa.";
//	}
//	else {
//		head = head->next;
//	}
//}


//xoa cuoi
//void deleteTail() {
//	Node* p = head;
//	if (head == nullptr || head->next == nullptr) {
//		deleteHead();
//	}
//	else {
//		while (p->next != nullptr) {
//			p = p->next;
//		}
//		p->next = nullptr;
//	}
//
//}
void deleteRightDuplicates(Node* &head) {
	Node* cur = head;
	Node* ne = head;
	for (cur; cur != nullptr; cur = cur->next)
		for (ne = cur; ne->next != nullptr;) // 1 2 3 4 3 2 
			if (cur->data == ne->next->data) {
				Node* tmp = ne->next;
				ne->next = ne->next->next;
				delete tmp;
			}
			else {
				ne = ne->next; // buoc nhay
			}
}
void printList() {
	Node* p = head;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
}


int main() {
	int n;

	init();
	int data;
	cout << "Nhap so node: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data;
		insertTail(data);
	}
	printList();
	cout << endl;
	deleteRightDuplicates(head);
	printList();

	return 0;
}