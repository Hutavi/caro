#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

#pragma pack(1)

using namespace std;

vector<vector<float>> as = {
	{3, 4},
	{5, 6, 7, 8},
	{3, 3, 1}
};

void writeArrays(const char* filename, vector<vector<float>> as) {
	fstream outfile;
	outfile.open(filename, ios::out | ios::binary);
	for (auto a : as) {
		short n = a.size();
		outfile.write((const char*)&n, sizeof(short));
		for (int i = 0; i < n; i++)
			outfile.write((const char*)&a[i], sizeof(float));
	}
	outfile.close();
}


void readArrays(const char* filename) {
	vector<vector<float>> a;
	ifstream infile(filename, ios::binary);
	
	
	while(1){
		short n;
		float e;
		infile.read((char*)&n, sizeof(short));
		if (infile.fail()) 
			break;
		vector<float> c;
		for (int i = 0; i < n; i++) {
			infile.read((char*)&e, sizeof(float));
			c.push_back(e);
		}
		a.push_back(c);
	}

	infile.close();

	vector<float> s;
	int sum = 0;
	for (auto item : a) {
		sum = 0;
		for (auto i : item)
			sum += i;
		s.push_back(sum);
	}
	//tim tong lon nhat 
	//m la chi so vi tri cua vecto con
	int m = max_element(s.begin(), s.end()) - s.begin(); //ham cho ra vi tri cua vector chua tong cac phan tu max
	for (auto j : a[m])
		cout << j << " ";

}

//liet ke tong cua so phan tu trong mang max


int main() {
	//writeArrays("data.bin", as);
	vector<vector<float>> a;

	readArrays("data.bin");

	

	return 0;
}