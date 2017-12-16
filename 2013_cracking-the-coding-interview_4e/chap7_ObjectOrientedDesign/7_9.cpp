/*
 * 7_9.cpp
 *
 *  Created on: 2013-4-30
 *      Author: beet
 *
 * File system in memory
 */

#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int Capacity = 8192;

struct DataBlock
{
	DataBlock()
	{
		currentLength = 0;
		next = NULL;
	}
	char data[Capacity];
	int currentLength;
	DataBlock* next;
};

class File
{
public:
	~File()
	{
		while( data!=NULL )
		{
			DataBlock* next = data->next;
			delete data;
			data = next;
		}
	}
	void write( const char* buffer, int length )
	{
		if(length<=0)
			return;

		// init
		if( data==NULL )
			data = new DataBlock();

		// goto the last data block
		DataBlock* tail = data;
		while( tail->next!=NULL )
			tail = tail->next;

		while( length>0 )
		{
			// the last block has been full, create a new one
			if( tail->currentLength == Capacity )
			{
				tail->next = new DataBlock();
				tail = tail->next;
			}
			// write
			int writeLength = Capacity - tail->currentLength;
			if( writeLength>length )
				writeLength = length;
			memcpy( tail->data + tail->currentLength, buffer, writeLength );
			// update cursors
			tail->currentLength += writeLength;
			buffer += writeLength;
			length -= writeLength;
		}
	}

	int size()
	{
		if( data==NULL )
			return 0;

		DataBlock* block = data;
		int result = 0;
		while( block->next!=NULL )
		{
			result += Capacity;
			block = block->next;
		}
		result += block->currentLength;
		return result;
	}

	int read( char* buffer, int pos, int maxLength )
	{
		// invalid
		if(pos<0 || maxLength<0 || data==NULL)
			return 0;

		DataBlock* block = data;
		while( pos>Capacity )
		{
			// invalid
			if( block->next==NULL )
				return 0;
			pos -= Capacity;
			block = block->next;
		}

		// invalid
		if( pos > block->currentLength )
			return 0;

		int remainLength = maxLength;
		while( remainLength>0 )
		{
			// read
			int readLength = block->currentLength - pos;
			if( readLength>remainLength )
				readLength = remainLength;
			memcpy( buffer, block->data + pos, readLength );
			// update cursors
			remainLength -= readLength;
			buffer += readLength;
			if( remainLength>0 && block->next!=NULL )
			{
				block = block->next;
				pos = 0; // to the head of next
			}
		}

		return maxLength-remainLength;
	}
private:
	DataBlock* data;
};

class Dir
{
public:
	~Dir()
	{
		for( map<string, Dir*>::iterator it=subDirs.begin(); it!=subDirs.end(); ++it )
			delete it->second;
		for( map<string, File*>::iterator it=subFiles.begin(); it!=subFiles.end(); ++it )
			delete it->second;
	}
	bool hasChild( string name )
	{
		return (subDirs.find(name)!=subDirs.end()
				|| subFiles.find(name)!=subFiles.end() );
	}
	Dir* createDir( string name )
	{
		Dir* target = NULL;
		if( !hasChild(name) )
		{
			target = new Dir();
			subDirs.insert( make_pair(name, target) );
		}
		return target;
	}
	File* createFile( string name )
	{
		File* target = NULL;
		if( !hasChild(name) )
		{
			target = new File();
			subFiles.insert( make_pair(name, target) );
		}
		return target;
	}
	void removeChild( string name )
	{
		map<string, Dir*>::iterator dir = subDirs.find(name);
		map<string, File*>::iterator file = subFiles.find(name);
		if( dir!=subDirs.end() )
		{
			delete dir->second;
			subDirs.erase(dir);
		}
		else if( file!=subFiles.end() )
		{
			delete file->second;
			subFiles.erase( file );
		}
	}
	Dir* getSubDir( string name )
	{
		map<string, Dir*>::iterator it = subDirs.find(name);
		if( it!=subDirs.end() )
			return it->second;
		return NULL;
	}
	File* getSubFile( string name )
	{
		map<string, File*>::iterator it = subFiles.find(name);
		if( it!=subFiles.end() )
			return it->second;
		return NULL;
	}
	void getSubDirs( map<string, Dir*>& dirs )
	{
		dirs.insert( subDirs.begin(), subDirs.end() );
	}
	void getSubFiles( map<string, File*>& files )
	{
		files.insert( subFiles.begin(), subFiles.end() );
	}
private:
	map<string, Dir*> subDirs;
	map<string, File*> subFiles;
};

class FileSystem
{
public:
	FileSystem()
	{
		root = new Dir();
	}
	~FileSystem()
	{
		delete root;
	}
	Dir* getDir( const vector<string>& path )
	{
		Dir* targetDir = root;
		for( vector<string>::const_iterator it=path.begin(); it!=path.end(); ++it )
		{
			targetDir = targetDir->getSubDir( *it );
			if( targetDir==NULL )
				return NULL;
		}
		return targetDir;
	}
	File* getFile( const vector<string>& path, const string& name )
	{
		Dir* targetDir = getDir(path);
		if(targetDir)
			return targetDir->getSubFile( name );
		return NULL;
	}
	void list( const vector<string>& path, map<string, Dir*>& dirs, map<string, File*>& files )
	{
		Dir* targetDir = getDir(path);
		if(targetDir)
		{
			targetDir->getSubDirs( dirs );
			targetDir->getSubFiles( files );
		}
	}
	void remove( const vector<string>& path, const string& name )
	{
		Dir* targetDir = getDir(path);
		if(targetDir)
			targetDir->removeChild( name );
	}
	Dir* createDir( const vector<string>& path )
	{
		Dir* targetDir = root;
		for( vector<string>::const_iterator it=path.begin(); it!=path.end(); ++it )
		{
			Dir* child = targetDir->getSubDir( *it );
			if(child==NULL)
				child = targetDir->createDir( *it );
			targetDir = child;
		}
		return targetDir;
	}
	File* createFile( const vector<string>& path, const string& name )
	{
		Dir* targetDir = createDir(path);
		return targetDir->createFile(name);
	}
private:
	Dir* root;
};

///////////////// TEST /////////////////
void printDir( FileSystem& fs, const vector<string>& path )
{
	map<string, Dir*> subDirs;
	map<string, File*> subFiles;

	fs.list( path, subDirs, subFiles );
	cout << "====================" << endl;
	for( map<string, Dir*>::iterator it = subDirs.begin(); it!=subDirs.end(); ++it )
		cout << "<DIR>	" << it->first << endl;
	for( map<string, File*>::iterator it = subFiles.begin(); it!=subFiles.end(); ++it )
		cout << "<FILE>	" << it->first << endl;
}

int main()
{
	FileSystem fs;

	/* file system tree:
	 *
	 * /home/
	 * 		root/
	 * 			a.zip
	 * 			b.txt
	 * 		user1/
	 * 			c.wmv
	 */
	vector<string> path;
	path.push_back("home");
	path.push_back("root");
	fs.createDir( path );
	fs.createFile( path, "a.zip" );
	fs.createFile( path, "b.txt" );
	path.push_back( "user1" );
	fs.createFile( path, "c.wmv" );

	/* list /home/root:
	 *
	 * <DIR>	user1
	 * <FILE>	a.zip
	 * <FILE>	b.txt
	 */
	path.resize( 2 );
	printDir( fs, path );

	/* list /home/root:
	 *
	 * <FILE>	b.txt
	 * <FILE>	user1
	 */
	fs.remove( path, "a.zip" );
	fs.remove( path, "user1" );
	fs.createFile( path, "user1" );
	printDir( fs, path );

	// print hello, world!
	File* f = fs.getFile( path, "b.txt" );
	char data[9999];
	f->write( "abcdef", 6 );
	f->read( data, 3, 2 ); // read "de";
	cout << data[0] << data[1] << endl;
	f->write( data, 9999 );
	f->write( "hello,", 6 );
	f->write( data, 9999 );
	f->write( data, 9999 );
	f->write( " world!\0", 8 );
	f->write( data, 9999 );
	// 50001 bytes have been written = 6 * 8192 +
	f->read( data, 10005, 6 ); // read "hello,";
	f->read( data+6, 30009, 8 ); // read " world!\0";
	cout << data << endl;
	return 0;
}

