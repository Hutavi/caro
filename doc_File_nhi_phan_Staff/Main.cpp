#include <iostream> 
#include <fstream>
#include <map>
using namespace std;

struct Staff {
	short id;
	char name[30];
	double value;
};



void Write_Bin(Staff staffs[],int& n) {
	fstream outfile;
	outfile.open("out.bin", ios::out | ios::binary);
	outfile.write((const char*)staffs, (long long)n * sizeof(Staff));
	outfile.close();
}

void readAndShow(const char* filename) {
	fstream infile;
	infile.open(filename, ios::in | ios::binary);
	infile.seekg(0,ios::end);
	int pos = infile.tellg();
	int n = pos / sizeof(Staff);
	Staff* stf = new Staff[n];
	infile.seekg(0, ios::beg);
	infile.read((char*)stf, pos);
	infile.close();
	map<int, map<string, double>> staffss;
	for (int i = 0; i < n; i++) {
		staffss[stf[i].id][stf[i].name] += stf[i].value; //
	}
	cout << "ID\t" << "Name\t" << "Total Sales \n";
	for (auto e : staffss) {
		cout << e.first << "\t";
		for (auto e1 : e.second) {
			cout << e1.first << "\t" << e1.second << "\n";
		}
	}
	delete[] stf;
}

void Read_Bin(Staff* &stf, int& n) {
	fstream infile;
	infile.open("out.bin", ios::in | ios::binary);
	infile.seekg(0, ios::end);
	int pos = infile.tellg();
	infile.seekg(0, ios::beg);
	n = pos / sizeof(Staff);
	stf = new Staff[n];
	infile.read((char*)stf, pos);
	infile.close();
}

int main() {
	/*int n;

	cout << "Enter staff: ";
	cin >> n;
	Staff staffs[3]{
	{1, "vinh", 11},
	{2, "minh", 12},
	{3, "khoa", 13} };
	Write_Bin(staffs, n);*/
	//Staff* stf; int n;
	//Read_Bin(stf, n);
	readAndShow("out.bin");
	
	
	return 0;
}