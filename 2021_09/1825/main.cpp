#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <tuple>

struct DataStruct {
  int data;
  std::multimap<int, DataStruct *> inlist;
  std::multimap<int, DataStruct *>::iterator inlist_iter;
};

class MKAverage {
public:

  MKAverage(int m, int k): m(m), k(k) {
    
  }

  void addElement(int num) {
    DataStruct *idata = nullptr;
    if (mqueue.size() == m) {
      idata = out_item();
    } else {
      idata = new DataStruct{};
    }

    idata->data = num;

    en_item(idata);
  }

  int calculateMKAverage() {
    if (mqueue.size() < m) {
      return -1;
    } else {
      return (sum_m_data)/(m - 2 * k);
    }
  }

private:
  int m, k;
  std::queue<DataStruct *> mqueue;
  std::multimap<int, DataStruct *> s_data;
  std::multimap<int, DataStruct *> m_data;
  std::multimap<int, DataStruct *> l_data;
  int sum_m_data = 0;
  DataStruct *out_item() {
    DataStruct *out_data = mqueue.back();
    mqueue.pop();

    out_data->inlist.erase(out_data->inlist_iter);

    return out_data;
  }

  void en_item(DataStruct *idata) {
    
  }
};