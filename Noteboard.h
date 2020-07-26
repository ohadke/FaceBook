#ifndef __NOTEBOARD__
#define __NOTEBOARD__
/*********INCLUDES*************/
#include"Status.h"
#include"Text_stat.h"
#include"Video_stat.h"
#include"Photo_stat.h"
#include"PhotoAndText_stat.h"
#include"VideoAndText_stat.h"
#include<vector>
#include<string>
#include<algorithm>
class Noteboard
{
	vector<Status*> Board;
	const string*  owner;
public:
	Noteboard(const string*  owner);//c'tor
	~Noteboard();//d'tor
	void showBoard() const;//show the noteboard of a person
	const Status* addstat();//add status
	const vector<Status*>* getBoard() const;

};
#endif 