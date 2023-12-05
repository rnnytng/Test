#include<iostream>
using namespace std;

class Sort {
public:
    void merge(int a[], int start, int mid, int end) {
        int i, j, k;
        int b[100] = { 0 };//辅助数组
        for (i = start; i <= end; i++) {
            b[i] = a[i];
        }
        for (j = start, k = mid + 1, i = start; j <= mid && k <= end; i++) {
            if (b[j] <= b[k]) {
                a[i] = b[j++];
            }
            else {
                a[i] = b[k++];
            }
        }
        while (j <= mid) {
            a[i++] = b[j++];
        }
        while (k <= end) {
            a[i++] = b[k++];
        }
    }

    void mergeSort(int a[], int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(a, start, mid);//左区域
            mergeSort(a, mid + 1, end);//右区域
            merge(a, start, mid, end);
        }
    }
};

int main() {
    int a[] = { 100, 2, 50, 36, 18, 20,1000,500 };
    int x = size(a);
    Sort p;
    p.mergeSort(a, 0, x-1);

    for (int i = 0; i < x; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
