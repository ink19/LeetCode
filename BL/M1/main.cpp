#include <iostream>
#include <rand>

using namespace std;

double f(double x) {
    return x;
}

int main() {
    double y_m[1001];
    for (int loop_i = 0; loop_i < 1001; ++loop_i) {
        y_m[loop_i] = f(loop_i/1000.0);
    }

	for (int i = 1; i < 1000000; i++) {
        double temp_x = 
    } 
}