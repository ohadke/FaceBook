#include"Photo_stat.h"

/******************IMPLEMENTATION_OF_PHOTO_STAT_METHOD************************/
Photo_stat::Photo_stat(const string*  owner) : Status(owner) {}
void Photo_stat::show()const
{
	Status::show();
	cout << "this is the Photo" << endl;
}