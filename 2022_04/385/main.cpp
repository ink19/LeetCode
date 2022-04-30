#include <vector>
#include <string>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution {
public:
  int getNumber(string::iterator& s_begin, const string::iterator& s_end) {
    int result = 0;
    bool isNeg = false;
    while (s_begin != s_end) {
      if ((*s_begin > '9' || *s_begin < '0') && *s_begin != '-') break;
      if (*s_begin == '-') {
        isNeg = true;
        s_begin++;
        continue;
      }
      result *= 10;
      result += *s_begin - '0';
      s_begin++;
    }
    if (isNeg) return -result;
    return result;
  }
  NestedInteger deserialize(string::iterator& s_begin, const string::iterator& s_end) {
    NestedInteger result;
    bool isArray = false;
    while (s_begin != s_end) {
      switch (*s_begin) {
        case '[':
          if (isArray == false) {
            isArray = true;
            s_begin++;
          } else {
            result.add(
              deserialize(s_begin, s_end)
            );
          }
        break;
        case ']':
          s_begin++;
          return result;
        break;
        case ',':
          s_begin++;
          result.add(
            deserialize(s_begin, s_end)
          );
        break;
        default:
          if (isArray) {
            result.add(
              deserialize(s_begin, s_end)
            );
          } else {
            return NestedInteger(getNumber(s_begin, s_end));
          }
        break;
      }
    }
    return result;
  }

  NestedInteger deserialize(string s) {
    string::iterator s_b = s.begin();
    return deserialize(s_b, s.end());
  }
};
