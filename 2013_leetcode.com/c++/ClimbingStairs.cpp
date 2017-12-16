/*
 * Problem: http://leetcode.com/onlinejudge#question_70
 */

class Solution
{
public:
	int climbStairs(int n)
	{
		if( n<1 )
			return 0;

		// the last step has 1 choice
		int nextStepChoice=1, nextNextStepChoice=1;
		// n-1 steps
		while( --n )
		{
			int curStepChoice = nextStepChoice + nextNextStepChoice;
			nextNextStepChoice = nextStepChoice;
			nextStepChoice = curStepChoice;
		}
		return nextStepChoice;
	}
};
