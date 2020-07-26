#ifndef __TEXT_STAT__
#define __TEXT_STAT__
/*********INCLUDES*************/
#include"Status.h"
#include<string>
class Text_stat :virtual public Status
{
protected:
	string insertedtext;
	static const int MAXLENGTH = 150;
public:
	Text_stat(const string*  owner);//ctor
	virtual void show()const override;//print the status to the console
	const string*  getText()const;//return the inserted text
	virtual bool operator==(const Status& other) override;//return true if the status and "other" are the same type and the same inserted text
private:
	Text_stat(const Text_stat& other);//block the access to the copy c'tor
};

#endif 