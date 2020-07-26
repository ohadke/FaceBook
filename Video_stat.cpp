#include"Video_stat.h"
/******************IMPLEMENTATION_OF_VIDEO_STAT_METHOD************************/
Video_stat::Video_stat(const string*  owner) :Status(owner) {}

void Video_stat::show()const
{
	Status::show();
	cout << "this is the Video" << endl;
}