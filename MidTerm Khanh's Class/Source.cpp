#include <iostream>
#include <string>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
struct infor{
	Date date;
	double height;
	double weight;
};


void inputDate(Date& st1) {
	cout << "Enter day: ";
	cin >> st1.day;
	cout << "Enter month: ";
	cin >> st1.month;
	cout << "Enter year: ";
	cin >> st1.year;
}

void inputInfor(infor& st) {
	inputDate(st.date);
	cout << "Enter height: ";
	cin >> st.height;
	cout << "Enter weight: ";
	cin >> st.weight;
}

void outputInfor(infor inf) {
	cout << "Date: " << inf.date.day << " - " << inf.date.month << " - " << inf.date.year << endl;
	cout <<"Height: " << inf.height << endl;
	cout << "Weight: "<< inf.weight << endl;
}

struct ListNode {
	infor data;
	ListNode* next;
};
ListNode* head;

void init() {
	head = nullptr;
}

ListNode* CreateNode(infor& data) {
	ListNode* p = new ListNode;
	p->data = data;
	p->next = nullptr;
	return p;
}

void InserTail(infor& data) {

	ListNode* p = CreateNode(data);
	if (head == nullptr) {
		head = p;
	}
	else {
		ListNode* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = p;
		p->next = nullptr;
	}
}

void printListNode() {
	ListNode* p = head;
	int count = 1;
	while (p != nullptr) {
		cout << "\t\t-----Children's information " << count++ << "----- \n\n";
		outputInfor(p->data);
		p = p->next;
	}
	cout << "\n\n\n";
}

void Sort() {
	for (ListNode* p = head; p != nullptr; p = p->next) {
		for (ListNode* q = p->next; q != nullptr; q = q->next) {
			if (p->data.date.year < q->data.date.year) {
				swap(p->data, q->data);
			}
			else if (p->data.date.year == q->data.date.year) {
				if (p->data.date.month < q->data.date.month) {
					swap(p->data, q->data);
				}
				else if (p->data.date.day < q->data.date.day) {
					swap(p->data, q->data);
				}
			}
		}
	}
}

int main() {
	init();
	int n;
	infor a;
	cout << "So ngay kiem tra: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		inputInfor(a);
		InserTail(a);
	} 
	printListNode();
	cout << "Sap xep theo thu tu ngay kiem tra gan nhat: " << endl;
	Sort();
	printListNode();
	return 0;
}


