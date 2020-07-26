#ifndef __VIDEO_STAT__
#define __VIDEO_STAT__
/*********INCLUDES*************/
#include"Status.h"
class Video_stat : virtual public Status
{
public:
	Video_stat(const string*  owner);//ctor
	virtual void show()const override;//print the status to the console
protected:
};
#endif 
