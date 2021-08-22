#include <unordered_map>
#include <list>

class LFUCache {
public:
    LFUCache(int capacity) :capacity(capacity) {
        memory_data = new listItem[capacity + 1];
        for (int loop_i = 0; loop_i < capacity + 1; ++loop_i) {
            memory_alloc.push_back(memory_data + loop_i);
        }
    }
    ~LFUCache() {
        delete [] memory_data;
    }
    int get(int key) {
        if (capacity == 0) return -1;
        if (map_data.find(key) == map_data.end()) {
            return -1;
        }
        auto item = map_data[key];
        auto item_list = freq_map_data[(*item)->freq];
        auto pitem = *item;
        item_list.erase(item);
        if (item_list.size() == 0) {
            freq_map_data.erase(pitem->freq);
            if (min_freq == pitem->freq) {
                min_freq++;
            }
        }
        pitem->freq += 1;
        freq_map_data[pitem->freq].push_front(pitem);
        map_data[key] = freq_map_data[pitem->freq].begin();
        return pitem->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (map_data.find(key) == map_data.end()) {
            auto item = memory_alloc.front();
            memory_alloc.pop_front();
            *item = {
                1, key, value
            };
            freq_map_data[1].push_front(item);
            auto it = freq_map_data[1].begin();
            map_data[key] = it;
            if (map_data.size() > capacity) {
                auto it = freq_map_data[min_freq].back();
                map_data.erase(it->key);
                freq_map_data[min_freq].pop_back();
                
                if (freq_map_data[min_freq].size() == 0) {
                    freq_map_data.erase(min_freq);
                } 
                memory_alloc.push_back(it);
            }
            min_freq = 1;
        } else {
            get(key);
            (*map_data[key])->value = value;
        }
    }
private:
    int capacity;
    typedef struct {
        int freq;
        int key;
        int value;
    } listItem;
    int min_freq = 1;
    std::unordered_map<int, std::list<listItem*>::iterator> map_data;
    std::unordered_map<int, std::list<listItem*>> freq_map_data;
    std::list<listItem*> memory_alloc;
    listItem *memory_data;
};

int main() {
    LFUCache *lFUCache = nullptr;
    char cmd[1000];
    int key, value;

    while (std::scanf("%s", cmd) != EOF) {
        if (cmd[0] == 'L') {
            std::scanf("%d", &key);
            lFUCache = new LFUCache(key);
        }
        if (cmd[0] == 'p') {
            std::scanf("%d%d", &key, &value);
            lFUCache->put(key, value);
        }
        if (cmd[0] == 'g') {
            std::scanf("%d", &key);
            lFUCache->get(key);
        }
    }

    delete lFUCache;
    return 0;
}