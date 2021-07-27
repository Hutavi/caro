#include <iostream>
#include <string>
#include <fstream>
#pragma pack(1)
using namespace std;

struct Student {
	char name[31]; //31byte
	char MS[8]; //8byte
	short namsinh; //2 byte
	char lop[8]; //10byte
	float TB; // ep ve 2byte sau
};

void binaryToText(char* binFile, char* textFile) {
	fstream outfile;
	outfile.open(binFile, ios::in | ios::binary);
	outfile.seekg(0, ios::end);
	int pos = outfile.tellg();
	int n = pos / sizeof(Student);
	Student* stu = new Student[n];
	outfile.seekg(0, ios::beg);
	outfile.read((char*)stu, pos);
	for (int i = 0; i < n; i++) {
		cout << stu[i].name << " " << stu[i].MS << " " << stu[i].namsinh <<" " << stu[i].lop << " " << stu[i].TB << endl;
	}
	ofstream outfile1(textFile); 
	for (int i = 0; i < n; i++) {
		outfile1 << stu[i].MS << "-" << stu[i].name << "-" << stu[i].namsinh << "-" << stu[i].lop << "-" << stu[i].TB << endl;
	}
	
	outfile.close();
}




int main() {

	binaryToText((char*)"binFile.bin", (char*)"textFile.txt");
	
	return 0;
}