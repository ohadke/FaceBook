#ifndef __PHOTO_STAT__
#define __PHOTO_STAT__
/*********INCLUDES*************/
#include"Status.h"
class Photo_stat : virtual public Status
{
public:

	Photo_stat(const string*  owner); //ctor
	virtual void show()const override;//print the status to the console
protected:
};
#endif 