#ifndef __VIDEO_AND_TEXT_STAT__
#define __VIDEO_AND_TEXT_STAT__
/*********INCLUDES*************/
#include"Text_stat.h"
#include"Video_stat.h"
#pragma warning(disable:4250)
class VideoAndText_stat :public Video_stat,public Text_stat
{
public:
	VideoAndText_stat(const string*  owner);//ctor
	void show()const override final;//print the status to the console
protected:
};
#endif 
