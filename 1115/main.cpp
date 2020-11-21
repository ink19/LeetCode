#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <mutex>

using namespace std;

class FooBar {
private:
    int n;
    std::mutex foo_lock;
    std::mutex bar_lock;
public:
    FooBar(int n) {
        this->n = n;
        bar_lock.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            foo_lock.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            bar_lock.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            bar_lock.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            foo_lock.unlock();
        }
    }
};