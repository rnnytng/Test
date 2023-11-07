#include<iostream>
using namespace std;
int main() {
	int a[] = { 9,1,5,6,7,8,20,16 };
	int n = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			int temp = 0;
			if (a[j] > a[j + 1]) {
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
}