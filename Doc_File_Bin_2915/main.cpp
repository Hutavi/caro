#include <iostream>
#include <fstream>
using namespace std;
#pragma pack(1)
struct infCir {
	short X;
	short Y;
	short R;
};
//inf infor[3]{ { 1,2,3 }, { 4,5,7 }, { 5,7,3 } };

void Write(infCir inf[], int& n) {
	fstream outfile;
	outfile.open("CIRCLE.BIN", ios::out | ios::binary);
	outfile.write((const char*)inf, (long long)n * sizeof(infCir));
	outfile.close();
}

void Read_Bin(const char* filename) {
	fstream outfile;
	outfile.open("CIRCLE.BIN", ios::in | ios::binary);
	outfile.seekg(0, ios::end);
	int pos = outfile.tellg();
	int n = pos / sizeof(infCir);
	infCir* cir = new infCir[n];
	outfile.seekg(0, ios::beg);
	outfile.read((char*) cir, pos);
	outfile.close();
	/*for (int i = 0; i < n; i++) {
		cout << cir[i].X << " " << cir[i].Y << " " << cir[i].R << endl;
	}*/
}

int main() {
	/*int n;
	
	cout << "Nhap so duong tron: ";
	cin >> n;
	infCir* cir = new infCir[n];
	for (int i = 0; i < n; i++) {
		cin >> cir[i].X >> cir[i].Y >> cir[i].R;
	}
	Write(cir, n);*/
	Read_Bin("CIRCLE.BIN");
	return 0;
}