#include <iostream>
#include <stdio.h>


int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int temp_n = 0;
        scanf("%d", &temp_n);
        if (temp_n / 100 == 4 || temp_n / 100 == 5) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}