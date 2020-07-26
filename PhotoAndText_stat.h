#ifndef __PHOTO_AND_TEXT_STAT__
#define __PHOTO_AND_TEXT_STAT__
/*********INCLUDES*************/
#include"Text_stat.h"
#include"Photo_stat.h"
#pragma warning(disable:4250)

class PhotoAndText_stat :public Photo_stat,public Text_stat
{
public:
	PhotoAndText_stat(const string*  owner);//ctor
	void show()const override final;//print the status to the console
private:
	PhotoAndText_stat(const PhotoAndText_stat& other);//block the access to the copy c'tor

};

#endif 