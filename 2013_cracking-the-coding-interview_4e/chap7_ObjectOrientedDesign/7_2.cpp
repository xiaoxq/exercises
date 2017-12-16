/*
 * 7_2.cpp
 *
 *  Created on: 2013-4-30
 *      Author: beet
 */

#define NULL 0
typedef int Call;

class Employee
{
public:
	Employee( Employee* superior );
	Employee* getCallHandler( Call c )
	{
		if( canHandle(c) )
			return this;
		if( superior!=NULL )
			return superior->getCallHandler(c);
		return NULL;
	}
private:
	Employee* superior;
	bool canHandle( Call c );
};

class ProductManager : public Employee
{
public:
	ProductManager() : Employee(NULL) {}
};

class TechnicalLead : public Employee
{
public:
	TechnicalLead( ProductManager* superior = NULL ) : Employee(superior) {}
};

class Fresher : public Employee
{
public:
	Fresher( TechnicalLead* superior = NULL ) : Employee(superior) {}
};


