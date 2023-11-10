#include<iostream>
#include<vector>
using namespace std;
class select {
public:
    void up(vector<int>a) {
        int n = a.size();
        int i = 0;
        while (i != n-1) {
            for (int j = i+1; j < n ; j++) {
                
                if (a[i]>a[j]) {
                    int t = 0;
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }

            }
          
            i++;
        }
        for (auto it = a.begin(); it != a.end(); it++) {
            cout << (*it) << endl;
        }
    }
};
int main() {
    int x = 0;
    select c;
    vector<int>b;
    for (int i = 0; i < 6; i++) {
        cin >> x;
        b.push_back(x);
    }
    c.up(b);
}