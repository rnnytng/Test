#include<iostream>
#include<vector>
using namespace std;
class bubble {
public:
	void up(vector<int>a) {
		int n = a.size();
		for(int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				int temp = 0;
				if (a[j + 1] < a[j]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for (auto it = a.begin(); it != a.end(); it++) {
			cout << (*it) << endl;
		}
	}
};
int main() {
	bubble sequence;
	vector<int>b;
	int x = 0;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		b.push_back(x);
	}
	sequence.up(b);
}
