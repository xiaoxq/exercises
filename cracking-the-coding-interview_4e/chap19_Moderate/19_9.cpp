/*
 * 19_9.cpp
 *
 *  Created on: 2013-5-20
 *      Author: beet
 */

// compile with: g++ -g -o main.exe `xml2-config --libs` `xml2-config --cflags` 19_9.cpp
// but it's strange that I got link error as the xmlParseFile/xmlDocGetRootElement/xmlFreeDoc cannot be found

#include <libxml/parser.h>
#include <fstream>
using namespace std;

// For simple, let's assume that the tag's code is its address
#define GetCode(ptr) (size_t)ptr

void encodeXml( xmlNodePtr root, ofstream& fout )
{
	const char END[] = "\000\001";

	fout << GetCode(root->name);
	printf("<%s", root->name);

	// write attributes
	xmlAttrPtr attr = root->properties;
	while(attr!=NULL)
	{
		fout << GetCode(attr->name) << attr->children->content;
		printf(" %s=%s", attr->name, attr->children->content );
		attr = attr->next;
	}
	printf(">\n");
	fout << END[0] << END[1];

	// write children
	xmlNodePtr child = root->children;
	while(child!=NULL)
	{
		encodeXml( child, fout );
		child = child->next;
	}
	fout << END[0] << END[1];
}

void encodeXml( char* xmlFile )
{
	const char resultFilename[] = "encoded.xml";

	xmlDocPtr doc = xmlParseFile(xmlFile);
	if (doc == NULL)
	{
		printf ("Cannot open %s!\n", xmlFile);
		return;
	}

	xmlNodePtr root = xmlDocGetRootElement(doc);
	if (root!=NULL)
	{
		ofstream fout( resultFilename, ios::binary );
		if(fout)
			encodeXml( root, fout );
		else
			printf("Cannot open %s to write!\n", resultFilename);
		fout.close();
	}
	else
		printf("Cannot parse %s!\n", xmlFile);

	xmlFreeDoc(doc);
}

///////////////// TEST /////////////////
#include <iostream>
int main()
{
	encodeXml( "19_9_testcase.xml" );
	return 0;
}
