#include <iostream>
#include <fstream>
using namespace std;

void del(int**& a, int m) {
	for (int i = 0; i < m; i++) {
		delete a[i];
	}
	delete[]a;
}

void convertTextToBinary(const char* filename) {
	int m, n;
	
	ifstream filein(filename);
	filein >> m;
	filein >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; ++i) a[i] = new int[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			filein >> a[i][j];
		}
	}
	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}*/
	fstream filein1("out.bin", ios::out | ios::binary);

	filein1.write((const char*)&m, sizeof(short));
	filein1.write((const char*)&n, sizeof(short));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			filein1.write((const char*)&a[i][j], sizeof(int));
		}
	}
	filein.close();
	filein1.close();
	del(a, m);
}

void convertBinaryToText(const char* filename) {
	short m, n;
	
	fstream filein2("out.bin", ios::in | ios::binary);
	filein2.read((char*)&m, sizeof(short));
	filein2.read((char*)&n, sizeof(short));
	int** a = new int* [m];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			filein2.read((char*)&a[i][j], sizeof(int));
		}
	}
	ofstream filein3("out1.txt");
	filein3 << m << " ";
	filein3 << n << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			filein3 << a[i][j] << " ";
		}
		filein3 << endl;
	}
	filein2.close();
	filein3.close();
	if (!filein2) del(a, m);
}

int main() {
	convertTextToBinary("input.txt");
	convertBinaryToText("out.bin");
	return 0;
}