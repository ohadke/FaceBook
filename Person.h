#ifndef __PERSON__
#define __PERSON__
/*******INCLUDES***********/
#include"Entity.h"

class Person : public Entity
{
	Date birthday;
	UpdateNotes homePage;
public:
	Person(string name, const Date birthday);//c'tor
	~Person();//d'tor
	void showUpdatesNotes()const;//show all the uploads of the friends and fanpage of a person
	void showInterestingEntities()const;//show all the freinds of a person
	void stayTuned(const Status * stat);//sharing the status to all of the member friends
	void operator+=(Entity& cool_ent);//to add a new interesting Entity
	virtual void show()const;
private:
	Person(const Person& other);//block the access to the copy c'tor
};
#endif
