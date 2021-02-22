#include <string.h>
#include <vector>
#include <iostream>
#include <mutex>
#include <functional>

using std::function;

class ZeroEvenOdd {
private:
    int n;
    int now = 0;
    std::mutex zero_lock;
    std::mutex even_lock;
    std::mutex odd_lock;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        even_lock.lock();
        odd_lock.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        zero_begin:
        zero_lock.lock();
        if (now != -1) {
            printNumber(0);
            now++;
        }
        if (now % 2) odd_lock.unlock();
        else even_lock.unlock();
        if (now != -1) {
            goto zero_begin;
        } else {
            even_lock.unlock();
            odd_lock.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        even_begin:
        even_lock.lock();
        if (now != -1) printNumber(now);
        if (now == n) now = -1;
        zero_lock.unlock();
        if (now != -1) goto even_begin;
    }

    void odd(function<void(int)> printNumber) {
        odd_begin:
        odd_lock.lock();
        if (now != -1) printNumber(now);
        if (now == n) now = -1;
        zero_lock.unlock();
        if (now != -1) goto odd_begin;
    }
};