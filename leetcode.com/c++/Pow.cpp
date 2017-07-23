/*
 * Problem: http://leetcode.com/onlinejudge#question_50
 */

class Solution
{
public:
	double pow(double x, int n)
	{
		unsigned int unsignedN = n;
		if(n<0)
			unsignedN = ~(unsignedN-1);

		double result = 1.0;

		// x^0x1010 = (x^0x1000) * (x^0x0010)
		// x^(-n) = 1 / x^n
		double resultPowerOf2 = x;
		while( unsignedN )
		{
			// current bit
			if( unsignedN & 0x1 )
				result *= resultPowerOf2;
			resultPowerOf2 *= resultPowerOf2;
			unsignedN >>= 1;
		}

		return (n>=0) ? result : 1.0/result;
	}
};
