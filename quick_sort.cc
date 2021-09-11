
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * 快速排序算法：
 * 1. 设置一个哨兵值。
 * 2. 从左到右边找小于哨兵的值，
 * 3. 从右到左找大于哨兵的值。
 * 4. 找到之后交换。
 *
 *
 **/

using namespace std;

/// 划分函数
int partition(vector<int> &a, int left, int right) {
  int i = left - 1;
  int j = right;
  int flag = a[right];

  while (1) {
    /// 像右边移动，找比基准小的值
    while (a[++i] < flag);
    while (a[--j] > flag);
    if (i < j) {
      swap(a[i], a[j]);
    } else {
      break;
    }
  }

  ///循环结束之后，需要更新基准值的位置
  swap(a[i], a[right]);

  return i;
}

void _qsort(vector<int> &a, int left, int right) {

  if (left < right) {
    int middle = partition(a, left, right);
    _qsort(a, left, middle - 1);
    _qsort(a, middle + 1, right);
  }

}
void qsort(vector<int> &a) {
  _qsort(a, 0, a.size() - 1);
}

void print_vector(const vector<int> &v) {

  for (auto const &vv: v) {
    cout << vv << " ";
  }
  cout << "\n";

}
int main() {

  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  print_vector(a);
  qsort(a);
  print_vector(a);

  return 0;
}

