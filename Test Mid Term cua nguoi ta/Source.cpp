#include <iostream>
#include <string>
using namespace std;

struct Students {
	int id;
	string name;
};

void inputInforStudent(Students &st) {
	cout << "Nhap ID: ";
	cin >> st.id;
	cin.ignore(); // nhap so truoc nhap chuoi thi phai co cin.ignore de khoi troi lenh vi ki tu Enter se bi hieu la ki tu
	cout << "Nhap ten sinh vien: ";
	getline(cin, st.name); //doi voi char thi khai bao cin.getline(name, 101).
}

void outputInforStudent(Students st) {
	cout << "ID: " << st.id << endl;
	cout << "Name: " << st.name << endl;
}

void inputStudentsInStruct(Students* st1, int n) {
	for (int i = 0,k = 1; i < n; i++, k++) {
		cout << "Hoc sinh thu " << k << ": " << endl;
		inputInforStudent(*(st1 + i));
	}
}

void outputStudentsInStruct(Students* st1, int n) {
	
	for (int i = 0, k = 1; i < n; i++, k++) {
		cout << "\n\n\t -----Student " << k << "-----\n\n";
		outputInforStudent(*(st1 + i));
	}
}

struct ListNode {
	Students data;
	ListNode* next;
};
ListNode* head;

void init() {
	head = nullptr;
}

ListNode* CreateNode(Students &data) {
	ListNode* p = new ListNode;
	p->data = data;
	p->next = nullptr;
	return p;
}

void InserTail(Students &data) {
	
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

void chuyen(Students* st1, int n) {
	for (int i = 0; i < n; i++) {
		InserTail(*(st1 + i));
	}
}



void printListNode() {
	ListNode* p = head;
	int count = 1;
	while (p != nullptr) {
		cout << "\t\t-----Sinh vien " << count++ << "----- \n\n";
		outputInforStudent(p->data);
		p = p->next;
	}
	cout << "\n\n\n";
}



int main() {
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	Students* student = new Students[n];
	inputStudentsInStruct(student, n);
	cout << "Thong tin can chuyen: " << endl;
	outputStudentsInStruct(student, n);

	cout << "\n\n";
	init();
	chuyen(student, n);
	cout << "Thong tin sinh vien sau khi chuyen \n\n";
	printListNode();
	delete[] student;
	return 0;
}