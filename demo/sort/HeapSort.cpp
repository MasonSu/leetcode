#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class MinHeap {
public:
  MinHeap(): nums{-1}, index(0) {}
  void buildHeap(vector<int>& vec);
  void insert(int value);
  int deleteMin(void);
  void heapSort(void);
  int getMin(void) {return nums.at(1);}
  int left(int parent) {return nums[2 * parent];}
  int right(int parent) {return nums[2 * parent + 1];}
  void print(void);

private:
  vector<int> nums;
  int index;
};

void MinHeap::buildHeap(vector<int> &vec)
{
  for (int i : vec)
    insert(i);
}

void MinHeap::insert(int value)
{
  if (index == 0) {
    index++;
    nums.push_back(value);
    return;
  }
  int tmpindex = ++index;
  nums.push_back(-1);
  while (tmpindex >= 2 && value < nums[tmpindex / 2]) {
    nums[tmpindex] = nums[tmpindex / 2];
    tmpindex /= 2;
  }
  nums[tmpindex] = value;
}

int MinHeap::deleteMin(void)
{
  int i = 1, top = getMin();
  while (2 * i <= index && 2 * i + 1 <= index) {
    if (left(i) < right(i)) {
      nums[i] = left(i);
      i = 2 * i;
    } else {
      nums[i] = right(i);
      i = 2 * i + 1;
    }
  }
  nums[i] = nums.back();
  nums.pop_back();
  index--;
  return top;
}

void MinHeap::heapSort(void)
{
  while (index)
    cout << deleteMin() << ' ';
}

void MinHeap::print(void)
{
  for (int i = 1; i <= index; ++i)
    cout << nums.at(i) << ' ';
}

int main(int argc, char const *argv[])
{
  MinHeap heap;
  vector<int> test {7,5,1,8,2,4,9,10,3,6};
  heap.buildHeap(test);
  cout << "heap: ";
  heap.print();
  cout << '\n';
  cout << "heapSort: ";
  heap.heapSort();
  cout << '\n';
  return 0;
}