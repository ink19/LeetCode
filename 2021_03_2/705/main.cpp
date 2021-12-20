#include <vector>
#include <iostream>

class MyHashSet {
public:
  std::vector<int> data;
  const int data_size = 100007;
  MyHashSet() { data = std::vector<int>(data_size, -1); }

  int hashIt(int key) { return key * 541 % data_size; }

  int nextHash(int key, int time) {
    return (key + time * time * 541) % data_size;
  }

  void add(int key) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (data[hask_key] != -1 && data[hask_key] != key)
      hask_key = nextHash(hask_key, hash_time++);
    data[hask_key] = key;
  }

  void remove(int key) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (data[hask_key] != -1 && data[hask_key] != key)
      hask_key = nextHash(hask_key, hash_time++);
    if (data[hask_key] == key) {
      data[hask_key] = -2;
    }
  }

  bool contains(int key) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (data[hask_key] != -1 && data[hask_key] != key)
      hask_key = nextHash(hask_key, hash_time++);
    if (data[hask_key] == key) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  MyHashSet myHashSet = MyHashSet();
  myHashSet.add(1);      // set = [1]
  myHashSet.add(2);      // set = [1, 2]
  myHashSet.contains(1); // 返回 True
  myHashSet.contains(3); // 返回 False ，（未找到）
  myHashSet.add(2);      // set = [1, 2]
  myHashSet.contains(2); // 返回 True
  myHashSet.remove(2);   // set = [1]
  myHashSet.contains(2); // 返回 False ，（已移除）
  return 0;
}