#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
#pragma pack(1)
struct Staff {
	short ID;
	char name[30];
	double value;
};


void Write_Bin(Staff staffs[], int& n) {
	fstream filein;
	filein.open("input.bin", ios::out | ios::binary);
	filein.write((const char*)staffs, (long long)n * sizeof(Staff));
	filein.close();
}

void readAndShow(const char* filename) {
	fstream fileout;
	fileout.open(filename, ios::in | ios::binary);
	fileout.seekg(0, ios::end);
	long int pos = fileout.tellg();
	int n = pos / sizeof(Staff);
	Staff* stf = new Staff[n];
	fileout.seekg(0, ios::beg);
	fileout.read((char*)stf, pos);
	fileout.close();
	map<short, map <string, double>> listStaffs;
	//de chac chan cho value = 0 ta them 1 dong for nua:
	for (int i = 0; i < n; i++) {
		listStaffs[stf[i].ID].emplace(stf[i].name, 0);
	}
	///----------------------------
	for (int i = 0; i < n; i++) {
		listStaffs[stf[i].ID][stf[i].name] += stf[i].value;
	}
	cout << "ID\t" << "Name\t" << "Total Sales \n";
	for (auto e : listStaffs) {
		cout << e.first << "\t";
		for (auto e1 : e.second) {
			cout << e1.first << "\t" << e1.second << endl;
		}
	}
	delete[] stf;
}

int main() {
	/*int n;
	cin >> n;
	Staff* staffs = new Staff[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap ID: ";
		cin >> staffs[i].ID;
		cout << "nhap ten: ";
		cin >> staffs[i].name;
		cout << "Nhap gia tri: ";
		cin >> staffs[i].value;
	}
	Write_Bin(staffs, n);*/
	readAndShow("input.bin");
	//delete[] staffs;
	return 0;
}