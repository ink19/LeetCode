#include <iostream>
#include <vector>

#define MOD_DATA 1000000007

class Solution {
public:
  std::vector<std::vector<long long>> pow_vec(const std::vector<std::vector<long long>> &data) {
    std::vector<std::vector<long long>> result(3, std::vector<long long>(3, 0));
    result[0][0] = ((data[0][0] * data[0][0]) % MOD_DATA + (data[0][1] * data[1][0]) % MOD_DATA + (data[0][2] * data[2][0]) % MOD_DATA) % MOD_DATA;
    result[0][1] = ((data[0][0] * data[0][1]) % MOD_DATA + (data[0][1] * data[1][1]) % MOD_DATA + (data[0][2] * data[2][1]) % MOD_DATA) % MOD_DATA;
    result[0][2] = ((data[0][0] * data[0][2]) % MOD_DATA + (data[0][1] * data[1][2]) % MOD_DATA + (data[0][2] * data[2][2]) % MOD_DATA) % MOD_DATA;
    
    result[1][0] = ((data[0][0] * data[1][0]) % MOD_DATA + (data[1][1] * data[1][0]) % MOD_DATA + (data[1][2] * data[2][0]) % MOD_DATA) % MOD_DATA;
    result[1][1] = ((data[0][1] * data[1][0]) % MOD_DATA + (data[1][1] * data[1][1]) % MOD_DATA + (data[1][2] * data[2][1]) % MOD_DATA) % MOD_DATA;
    result[1][2] = ((data[0][2] * data[1][0]) % MOD_DATA + (data[1][1] * data[1][2]) % MOD_DATA + (data[1][2] * data[2][2]) % MOD_DATA) % MOD_DATA;
    
    result[2][0] = ((data[0][0] * data[2][0]) % MOD_DATA + (data[2][1] * data[1][0]) % MOD_DATA + (data[2][2] * data[2][0]) % MOD_DATA) % MOD_DATA;
    result[2][1] = ((data[0][1] * data[2][0]) % MOD_DATA + (data[2][1] * data[1][1]) % MOD_DATA + (data[2][2] * data[2][1]) % MOD_DATA) % MOD_DATA;
    result[2][2] = ((data[0][2] * data[2][0]) % MOD_DATA + (data[2][1] * data[1][2]) % MOD_DATA + (data[2][2] * data[2][2]) % MOD_DATA) % MOD_DATA;
    return result;
  }

  std::vector<std::vector<long long>> mul_vec(const std::vector<std::vector<long long>> &data1, const std::vector<std::vector<long long>> &data2) {
    std::vector<std::vector<long long>> result(3, std::vector<long long>(3, 0));
    result[0][0] = ((data1[0][0] * data2[0][0]) % MOD_DATA + (data1[0][1] * data2[1][0]) % MOD_DATA + (data1[0][2] * data2[2][0]) % MOD_DATA) % MOD_DATA;
    result[0][1] = ((data1[0][0] * data2[0][1]) % MOD_DATA + (data1[0][1] * data2[1][1]) % MOD_DATA + (data1[0][2] * data2[2][1]) % MOD_DATA) % MOD_DATA;
    result[0][2] = ((data1[0][0] * data2[0][2]) % MOD_DATA + (data1[0][1] * data2[1][2]) % MOD_DATA + (data1[0][2] * data2[2][2]) % MOD_DATA) % MOD_DATA;
    
    result[1][0] = ((data1[1][0] * data2[0][0]) % MOD_DATA + (data1[1][1] * data2[1][0]) % MOD_DATA + (data1[1][2] * data2[2][0]) % MOD_DATA) % MOD_DATA;
    result[1][1] = ((data1[1][0] * data2[0][1]) % MOD_DATA + (data1[1][1] * data2[1][1]) % MOD_DATA + (data1[1][2] * data2[2][1]) % MOD_DATA) % MOD_DATA;
    result[1][2] = ((data1[1][0] * data2[0][2]) % MOD_DATA + (data1[1][1] * data2[1][2]) % MOD_DATA + (data1[1][2] * data2[2][2]) % MOD_DATA) % MOD_DATA;
    
    result[2][0] = ((data1[2][0] * data2[0][0]) % MOD_DATA + (data1[2][1] * data2[1][0]) % MOD_DATA + (data1[2][2] * data2[2][0]) % MOD_DATA) % MOD_DATA;
    result[2][1] = ((data1[2][0] * data2[0][1]) % MOD_DATA + (data1[2][1] * data2[1][1]) % MOD_DATA + (data1[2][2] * data2[2][1]) % MOD_DATA) % MOD_DATA;
    result[2][2] = ((data1[2][0] * data2[0][2]) % MOD_DATA + (data1[2][1] * data2[1][2]) % MOD_DATA + (data1[2][2] * data2[2][2]) % MOD_DATA) % MOD_DATA;
    return result;
  }

  int waysToStep(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    int n_data = n - 2;
    std::vector<std::vector<long long>> result_vec = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<long long>> temp_result = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    while (n_data != 0) {
      if (n_data & 1) {
        result_vec = mul_vec(result_vec, temp_result);
      }
      n_data >>= 1;
      temp_result = pow_vec(temp_result);
    }
    return (result_vec[0][0] * 2 + result_vec[0][1] + result_vec[0][2]) % MOD_DATA;
  }
};

int main() {
  for (int loop_i = 3; loop_i < 6; ++loop_i) {
    std::cout << Solution().waysToStep(loop_i) << std::endl;
  }
  
  return 0;
}