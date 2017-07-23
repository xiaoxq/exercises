/*
 * 20_8.cpp
 *
 *  Created on: 2013-5-27
 *      Author: beet
 */

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

const int ChildrenNum = ('z' - 'a' + 1) * 2;
const vector<int> EmptyIntVec;

inline int CharToIndex( char c )
{
	// upper case
	if( c<='Z' )
		return c - 'A';

	// lower case
	return c-'a' + ('Z'-'A'+1);
}

class Node
{
public:
	Node(const string& suffix, int startPos)
	{
		data = suffix;
		startPoss.push_back(startPos);
		memset(child, 0, ChildrenNum * sizeof(Node*));
	}

	Node(const string& suffix, const vector<int>& startPos)
		: startPoss(startPos)
	{
		data = suffix;
		memset(child, 0, ChildrenNum * sizeof(Node*));
	}

	void merge( string& suffix, int startPos )
	{
		int len_data = data.length();
		int len_suff = suffix.length();

		// find the length of common head
		int i = 0;
		for(; i<len_data && i<len_suff; ++i )
			if( data[i] != suffix[i] )
				break;

		// data is suffix's prefix
		if( i==len_data && i<len_suff )
		{
			suffix = suffix.substr( i );
			int index = CharToIndex( suffix[0] );
			if( child[index]==NULL )
				child[index] = new Node( suffix, startPos );
			else
				child[index]->merge( suffix, startPos );
		}
		// current node should be split
		else if(i<len_data)
		{
			// copy current node to old_node
			Node* old_node = new Node( data.substr(i), startPoss );
			for( int j=0; j<ChildrenNum; ++j )
			{
				old_node->child[j] = child[j];
				child[j] = NULL;
			}
			// update the common part
			child[ CharToIndex( data[i] ) ] = old_node;
			data = data.substr(0,i);

			if( i<len_suff )
			{
				// create the sibling new node
				Node* new_node = new Node( suffix.substr(i), startPos );
				child[ CharToIndex( suffix[i] ) ] = new_node;
			}
		}

		startPoss.push_back(startPos);
	}

	Node* child[ChildrenNum];
	string data;
	vector<int> startPoss;
};

Node* buildSuffixTree( const string& str )
{
	Node* root = new Node("",0);
	// from short to long, not so many splits
	for( int i=str.length()-1; i>=0; --i )
	{
		string suffix = str.substr( i );
		int index = CharToIndex( suffix[0] );
		if( root->child[index]==NULL )
			root->child[index] = new Node( suffix, i );
		else
			root->child[index]->merge( suffix, i );
	}
	return root;
}

const vector<int>& searchTinS( Node* root, const string& strT )
{
	string prefix = strT;
	while(root!=NULL)
	{
		// compare the prefix with myself
		int i=0;
		for( ; i<root->data.length() && i<prefix.length(); ++i )
			if( root->data[i] != prefix[i] )
				return EmptyIntVec;
		// strT is my prefix
		if( i==prefix.length() )
			return root->startPoss;

		prefix = prefix.substr( i );
		root = root->child[ CharToIndex( prefix[0] ) ];
	}
	return EmptyIntVec;
}

///////////////// TEST /////////////////
// root is constructed by strS
void test( Node* root, const string& strS, const string& strT )
{
	const vector<int>& startPos = searchTinS(root, strT);
	if( startPos.empty() )
		cout << strS << " doesn't contain " << strT << endl;
	else
	{
		int start = 0;
		for( vector<int>::const_reverse_iterator it=startPos.rbegin(); it!=startPos.rend(); ++it )
		{
			cout << strS.substr( start, *it - start ) << "[";
			start = *it;
		}
		cout << strS.substr( start ) << " contains " << strT << endl;
	}
}

int main()
{
	string testString("mississippi");
	Node* root = buildSuffixTree( testString );
	test( root, testString, "ssi" );
	test( root, testString, "is" );
	test( root, testString, "sip" );
	test( root, testString, "hi" );
	test( root, testString, "sis" );
	test( root, testString, "issi" );
	// delete the tree here
	return 0;
}
