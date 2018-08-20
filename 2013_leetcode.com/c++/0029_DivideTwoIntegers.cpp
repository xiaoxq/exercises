#include <climit>
using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    // record pos or neg
    const bool neg = (dividend ^ divisor) < 0;

    // transform to positive
    unsigned int ulDividend = dividend, ulDivisor = divisor;
    if (dividend < 0) {
      ulDividend = ~(ulDividend - 1);
    }
    if (divisor < 0) {
      ulDivisor = ~(ulDivisor - 1);
    }

    unsigned int maxExp = 0, temp = ulDividend;
    while (temp >= ulDivisor) {
      temp >>= 1;
      ++maxExp;
    }

    int result = 0;
    for (int i = maxExp - 1; i >= 0; --i) {
      const int exp = 1 << i;
      const int component = exp * ulDivisor;
      if (ulDividend >= component) {
        result |= exp;
        ulDividend -= component;
      }
    }

    result = neg ? -result : result;
    if (result < 0 && !neg) {
      return INT_MAX;
    }
    return result;
  }
};
