#include"PhotoAndText_stat.h"

/******************IMPLEMENTATION_OF_PHOTO_AND_TEXT_STAT_METHOD************************/
PhotoAndText_stat::PhotoAndText_stat(const string*  owner) : Status(owner), Text_stat(owner), Photo_stat(owner) {}
void PhotoAndText_stat::show()const
{
	Photo_stat::show();
	cout << insertedtext << endl;
}