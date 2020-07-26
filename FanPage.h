#ifndef __FAN_PAGE__
#define __FAN_PAGE__
/*******INCLUDES***********/
#include"Entity.h"

class FanPage : public Entity
{
public:
	FanPage(string name);//ctor
	~FanPage();//dtor
	void showInterestingEntities()const;//showing all the fans of a fanpage
	virtual void show() const;//show the data of the fan page
private:
	FanPage(const FanPage& other);//block the access to the copy c'tor
};

#endif
