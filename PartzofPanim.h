#ifndef __PARTZOF_PANIM__
#define __PARTZOF_PANIM__
/******INCLUDES******/
#include<typeinfo.h>
#include"Entity.h"
#include"FanPage.h"
#include"Person.h"
#include<vector>
class PartzofPanim
{
public:
	vector<Entity*> members;

	PartzofPanim();//ctor
	~PartzofPanim();//dtor
	int menu();//prime function to have a menu
private:
	static const int MAXLENGTH = 50;
	static const int NOT_EXIST = -1;
	void AddPerson();//add person to partzofpanim
	void AddPage();// add a fanpgage
	int getindexofMember(const string* name, const type_info& type)const;//check the index of a person for other funcntions
	void AddStatToPerson();//add status for a person
	void AddStatToFanPage();//add status for a fanpage
	void ShowWallOfPerson() const;//show the the personal wall of a person
	void ShowWallOfPage() const;//show the personal wall of a fanpage
	void GetPeopleConnected();//getting peoples together as a freinds
	void AddFanToPage();//adding a person to be a fan of a fanpage
	void ShowAllUsers() const;// show all the users of partzof panim
	void ShowFreindsAndPagesOfPerson() const;//show all the friends and the pages that a person is connected to
	void ShowFansOfPage() const;//showing all the fans of a fanpage
	void ShowHomePageOfPerson() const;//showing the last 10 posts of a fanpage
};

#endif
