#include <vector>
#include <iostream>
#include <tuple>

class MyHashMap {
public:
  std::vector<std::tuple<int, int>> data;
  const int data_size = 100007;
  MyHashMap() { data = std::vector<std::tuple<int, int>>(data_size, std::make_tuple(-1, -1)); }

  int hashIt(int key) { return key * 541 % data_size; }

  int nextHash(int key, int time) {
    return (key + time * time * 7) % data_size;
  }

  void put(int key, int value) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (std::get<0>(data[hask_key]) != -1 && std::get<0>(data[hask_key]) != key)
      hask_key = nextHash(hask_key, hash_time++);
    data[hask_key] = {key, value};
  }

  void remove(int key) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (std::get<0>(data[hask_key]) != -1 && std::get<0>(data[hask_key]) != key)
      hask_key = nextHash(hask_key, hash_time++);
    if (std::get<0>(data[hask_key]) == key) {
      data[hask_key] = {-2, 0};
    }
  }

  int get(int key) {
    int hask_key = hashIt(key);
    int hash_time = 1;
    while (std::get<0>(data[hask_key]) != -1 && std::get<0>(data[hask_key]) != key)
      hask_key = nextHash(hask_key, hash_time++);
    if (std::get<0>(data[hask_key]) == key) {
      return std::get<1>(data[hask_key]);
    } else {
      return -1;
    }
  }
};