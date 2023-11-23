#include<iostream>
#include<vector>
using namespace std;

void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index的左子节点
	int right = 2 * index + 2;// index的右子节点

	int max = index;
	if (left<len && arr[left] > arr[max]) {
		max = left;
	}
	if (right<len && arr[right] > arr[max]) {
		max = right;
	}

	if (max != index)
	{
		swap(arr[max], arr[index]);
		adjust(arr, len, max);
	}

}

// 堆排序
void heapSort(vector<int>& arr, int size)
{
	// 构建大根堆（从最后一个非叶子节点向上）
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}

	// 调整大根堆
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
		adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
	}
}

int main()
{
	vector<int> arr = { 8,6,7,4,100,108,2,1 };
	heapSort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	return 0;
}
