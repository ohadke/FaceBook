#ifndef __STATUS__
#define __STATUS__
#define _CRT_NONSTDC_NO_DEPRECATE
/*********INCLUDES*************/
#include <string>
#include <stdlib.h>
#include <iostream>
#include<typeinfo.h>
#include"MyDate.h"
#include"Clock.h"

class Status
{
public:
	Status(const string*  owner);//ctor
	virtual ~Status();
	virtual void show()const = 0;//show the satus
	static bool compareStatus(const Status* first ,const Status* second);//an inside function,programmed to sort the latest status
	virtual bool operator==(const Status& other) ;//return true if the status and "other" are the same type 
	virtual bool operator!=(const Status& other) ;//return true if the status and "other" have difrent types
protected:
	Clock time;
	Status(const Status& other); //block the access to the copy c'tor
	const string* owner;
};

#endif 
