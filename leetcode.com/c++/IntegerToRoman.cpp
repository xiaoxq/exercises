/*
 * Problem: http://leetcode.com/onlinejudge#question_12
 */

#include <string>
using namespace std;

string digits[4][10] =
{
		{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"", "M", "MM", "MMM", "", "", "", "", "", ""},
};

class Solution
{
public:
	// 1<=num<=3999
	string intToRoman(int num)
	{
		int digits1000 = num / 1000;
		int digits100 = (num / 100) % 10;
		int digits10 = (num / 10) % 10;
		int digits1 = num % 10;
		return digits[3][digits1000]+digits[2][digits100]+digits[1][digits10]+digits[0][digits1];
	}
};
