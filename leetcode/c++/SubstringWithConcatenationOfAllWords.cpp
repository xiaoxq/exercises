/*
 * Problem: http://leetcode.com/onlinejudge#question_30
 */

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
	vector<int> findSubstring(string S, vector<string> &L)
	{
		vector<int> result;
		if( L.empty() || L[0].empty() )
			return result;

		SuffixTreeNode* head = buildSuffixTree( L );
		int substrNum = L.size();
		int substrLen = L[0].length();

		for( int i=0; i+substrNum*substrLen <= S.length(); ++i )
		{
			// check starting point i, every substr should only be hitted once
			vector<int> hitted( substrNum, -1 );
			// try match every substr
			bool match = true;
			for( int startIndex=0; startIndex<substrNum*substrLen; startIndex+=substrLen )
			{
				// cannot match or matched twice for the same substr
				if( !checkSubstrHit( head, S, i+startIndex, hitted ) )
				{
					match = false;
					break;
				}
			}

			if( match )
				result.push_back( i );
		}

		releaseSuffixTree(head);

		return result;
	}
private:
	struct SuffixTreeNode
	{
		vector<SuffixTreeNode*> child;
		int substrIndex;
		int hitCount;

		SuffixTreeNode()
			: child( 'z'-'a'+1, (SuffixTreeNode*)NULL )
			, substrIndex(-1)
			, hitCount(0)
		{
		}
	};

	SuffixTreeNode* buildSuffixTree( const vector<string> &L )
	{
		SuffixTreeNode *head = new SuffixTreeNode;
		for( int i=0; i<L.size(); ++i )
		{
			SuffixTreeNode *cur = head;
			for( int j=0; j<L[i].length(); ++j )
			{
				if( cur->child[ L[i][j]-'a' ]==NULL )
					cur->child[ L[i][j]-'a' ] = new SuffixTreeNode;
				cur = cur->child[ L[i][j]-'a' ];
			}
			if( cur->substrIndex<0 )
			{
				cur->substrIndex = i;
				cur->hitCount = 1;
			} else
				++cur->hitCount;
		}
		return head;
	}

	void releaseSuffixTree( SuffixTreeNode* head )
	{
		if( head==NULL )
			return;
		for( int i=0; i<'z'-'a'+1; ++i )
			releaseSuffixTree( head->child[i] );
		delete head;
	}

	bool checkSubstrHit( SuffixTreeNode* head, const string& S, int index, vector<int>& hitted )
	{
		while( head!=NULL && head->substrIndex == -1 )
			head = head->child[ S[index++] - 'a' ];
		if(head==NULL)
			return false;

		int &hitCount = hitted[ head->substrIndex ];
		if( hitCount==0 )
			return false; // hit too many times

		if( hitCount < 0 )
			hitCount = head->hitCount - 1; // init
		else
			--hitCount; // hit once
		return true;
	}
};

class AnotherSolution
{
public:
	vector<int> findSubstring(string S, vector<string> &L)
	{
		vector<int> result;
		if( L.empty() || L[0].empty() )
			return result;

		const int strLen = S.length();
		const int substrNum = L.size();
		const int substrLen = L[0].length();

		// store how much hits are needed for a word
		map<string,int> needHits;
		for( vector<string>::const_iterator it=L.begin(); it!=L.end(); ++it )
		{
			if( needHits.find( *it )==needHits.end() )
				needHits.insert( make_pair(*it, 1) );
			else
				++needHits[*it];
		}

		// store every substr of every starting pos of S
		const int substrPosNum = strLen-substrLen+1;
		vector<string> substrs( substrPosNum );
		for( int i=0; i<substrPosNum; ++i )
		{
			const string substr = S.substr( i, substrLen );
			if( needHits.find(substr) != needHits.end() )
				substrs[i] = substr;
		}

		// check every start point
		for( int start=0; start+substrNum*substrLen<=strLen; ++start )
		{
			bool found = true;
			map<string,int> tempHits( needHits );
			const int end = start+substrNum*substrLen;
			for( int i=start; i<end; i+=substrLen )
			{
				// a piece is not in L, or has been hit more than needed
				if( substrs[i].empty() || tempHits[ substrs[i] ]==0 )
				{
					found = false;
					break;
				}
				-- tempHits[ substrs[i] ];
			}
			if( found )
				result.push_back( start );
		}

		return result;
	}
};
