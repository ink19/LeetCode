#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int print_int_vector(vector<char>::iterator &iter, int num) {
        int num_len = 0;
        int temp_num = 0;
        while (num) {
            temp_num *= 10;
            temp_num += (num % 10);
            num /= 10;
            num_len++;
        }

        while (temp_num) {
            *iter = '0' + (temp_num % 10);
            temp_num /= 10;
            iter++;
            num_len--;
        }

        while (num_len--) {
            *iter = '0';
            iter++;
        }

        return 0;
    }
    int compress(vector<char>& chars) {
        const int chars_len = chars.size();
        char a = chars[0];
        int zu_len = 0;
        vector<char>::iterator chars_iter = chars.begin();
        for (int loop_i = 0; loop_i < chars_len; ++loop_i) {
            if (a == chars[loop_i]) {
                zu_len++;
            } else {
                *chars_iter = a;
                chars_iter++;
                if (zu_len > 1) {
                    print_int_vector(chars_iter, zu_len);
                }
                a = chars[loop_i];
                zu_len = 1;
            }
        }
        
        *chars_iter = a;
        chars_iter++;
        if (zu_len > 1) {
            print_int_vector(chars_iter, zu_len);
        } 

        return chars_iter - chars.begin();
    }
};

int main() {

    return 0;
}