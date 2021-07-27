#include <iostream>
using namespace std;

void inputArr(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]: ";
		cin >> *(a + i);
	}
}

void output(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << *(a + i);
	}
}

void sort(int a[], int b[], int c[], int n, int pos) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			b[cnt++] = a[i];
			pos = i + 1;
			if (a[i + 1] <= 0) {
				break;
			}
		}
		else continue;
	}
	int tmp = 0;
	for (int j = pos; j < n; j++) {
		if (a[j] > 0) {
			c[tmp++] = a[j];
		}
		if (a[j + 1] <= 0 || j == n - 1) {
			if (tmp > cnt) {
				cnt = tmp;
				for (int k = 0; k < tmp; k++) {
					b[k] = c[k];
				}
			}
			tmp = 0;
		}
	}
	output(b, cnt);
}

int main() {
	int n;
	int pos = 0;
	int cnt = 0;
	int b[101], c[101];
	cout << "Nhap so phan tu: ";
	cin >> n;
	int* a = new int[n];
	inputArr(a, n);
	sort(a, b, c, n, pos);
	cout << endl;
	delete[] a;
	return 0;
}