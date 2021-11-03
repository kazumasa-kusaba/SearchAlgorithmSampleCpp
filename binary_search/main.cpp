#include <iostream>
#include <vector>

typedef struct {
  int key;
  int value;
} DATA;

int binary_search(const std::vector<DATA>& data, int key)
{
  int low, mid, high;

  low  = 0;
  high = data.size();

  while (low <= high) {
    mid = (low + high) / 2;
    if (key == data[mid].key) {
      return data[mid].value;
    } else if (key < data[mid].key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

int main(void)
{
  int size = 0;
  std::vector<DATA> data;
  int key = 0;
  int ret = 0;

  std::cout << "Input the size of data that you want to register: ";
  std::cin >> size;

  std::cout << "Input the keys and values (The keys are needed to be input in ascending order)" << std::endl;
  for (int i = 0; i < size; i++) {
    int key   = 0;
    int value = 0;

    std::cout << "key, value: ";
    std::cin >> key;
    std::cin >> value;

    data.push_back({key, value});
  }

  std::cout << "Input the key you look for: ";
  std::cin >> key;

  ret = binary_search(data, key);
  if (ret == -1) {
    std::cout << "The key was not found." << std::endl;
  } else {
    std::cout << "The value is " << ret << std::endl;
  }

  return 0;
}

