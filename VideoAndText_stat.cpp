#include"VideoAndText_stat.h"

/******************IMPLEMENTATION_OF_VIDEO_AND_TEXT_STAT_METHOD************************/
VideoAndText_stat::VideoAndText_stat(const string*  owner) :Status(owner), Text_stat(owner), Video_stat(owner) {}
void VideoAndText_stat::show()const
{
	Video_stat::show();
	cout << insertedtext << endl;
}
