#ifndef __UPDATE_NOTES__
#define __UPDATE_NOTES__

/*********INCLUDES*************/
#include"Noteboard.h"
#include"Status.h"
#include<list>
#include<algorithm>
class UpdateNotes
{
	list<const Status*> newest_status;
	static const int MAX_SIZE = 10;
public:
	UpdateNotes();//c'tor
	void updateNewStatus(const Status* stat);//updating the noteborad of a person
	void show()const;//show the pupdated notes
	void getUpdateFromNewMember(const Noteboard& other);//merge sort(of time) to get the latest upload od a member
};

#endif 