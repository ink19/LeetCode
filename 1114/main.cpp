#include <functional>
#include <mutex>

using namespace std;

class Foo {
public:
    mutex tex1;
    mutex tex2;
    Foo() {
        tex1.lock();
        tex2.lock();
    }
    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        tex1.unlock();
    }

    void second(function<void()> printSecond) {
        tex1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        tex2.unlock();
    }

    void third(function<void()> printThird) {
        tex2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};