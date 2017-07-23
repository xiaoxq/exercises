/*
 * 19_6.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

#include <string>
using namespace std;

// 1 <= num <= 9
string digitToEnglish( int num )
{
	string ret;
	switch(num)
	{
	case 1: return "One";
	case 2: return "Two";
	case 3: return "Three";
	case 4: return "Four";
	case 5: return "Five";
	case 6: return "Six";
	case 7: return "Seven";
	case 8: return "Eight";
	case 9: return "Nine";
	default: return "ERROR";
	}
};

// 1 <= num <= 99
string tensToEnglish( int num )
{
	// special
	switch(num)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9: return digitToEnglish(num);
	case 10: return "Ten";
	case 11: return "Eleven";
	case 12: return "Twelve";
	case 13: return "Thirteen";
	case 14: return "Fourteen";
	case 15: return "Fifteen";
	case 16: return "Sixteen";
	case 17: return "Seventeen";
	case 18: return "Eighteen";
	case 19: return "Nineteen";
	default: break;
	}

	// 2 <= num/10 <= 9
	string ret;
	switch(num/10)
	{
	case 2: ret = "Twenty"; break;
	case 3: ret = "Thirty"; break;
	case 4: ret = "Forty"; break;
	case 5: ret = "Fifty"; break;
	case 6: ret = "Sixty"; break;
	case 7: ret = "Seventy"; break;
	case 8: ret = "Eighty"; break;
	case 9: ret = "Ninety"; break;
	default: break;
	}

	int bits = num%10;
	if(bits>0)
		return ret + " " + digitToEnglish(bits);
	return ret;
}

// 1 <= num <= 999
string hundredsToEnglish( int num )
{
	int hundreds = num/100, tens = num%100;
	if( hundreds>0 && tens>0 )
		return digitToEnglish(hundreds) + " Hundred and " + tensToEnglish(tens);
	else if( hundreds>0 )
		return digitToEnglish(hundreds) + " Hundred";
	return tensToEnglish(tens);
}

// 0 <= num <= 999,999
string num2English( int num )
{
	if(num==0)
		return "Zero";

	int thousands = num / 1000;
	int hundreds = num % 1000;

	if( thousands>0 && hundreds>0 )
		return hundredsToEnglish(thousands) + " Thousand, " + hundredsToEnglish(hundreds);
	else if( thousands>0 )
		return hundredsToEnglish(thousands) + " Thousand";
	return hundredsToEnglish(hundreds);
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	int num = 0;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 1;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 25;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 325;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 1254;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 31455;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 999999;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 800000;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 870000;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 765000;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 765300;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	num = 765430;
	cout << "num2English(" << num << ") = \"" << num2English(num) << "\"" << endl;
	return 0;
}
