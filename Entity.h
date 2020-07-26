#ifndef __ENTITY__
#define __ENTITY__
/*******INCLUDES***********/
#include<typeinfo.h>
#include"MyDate.h"
#include"Clock.h"
#include"Noteboard.h"
#include"UpdateNotes.h"
#include<string>
#include<vector>

class Entity//a class that will be the base for information that common to a person and a fanpage
{
protected:
	string name;
	vector<Entity*> Interesting_entities;
	Noteboard personalWall;
	bool checkduplicate(Entity* cool_ent)const;//check if  the Entity is already connected to the Entity
	void letEverybodyKnow(const Status * stat)const;//inside function that sharing the status with the friends/fans

public:
	Entity(string insertedName);//c'tor with name
	virtual ~Entity();//dtor
	void uploadStatus();//uploading status
	const string* getName()const;//get the name of the entity
	void insertToEntitiesArr(Entity* cool_ent);//insert a new Entity to the arr of Interesting Entities
	void showWalls()const;//show the personal wall of an entity
	virtual void showInterestingEntities()const = 0;//show all the friends/fans of an entity
	bool checkIfHaveInterestingEntities() const;//a functions that checks if the the entity have friend/fans to show
	const Noteboard& getpersonalwall() const;//just return the personal noteboard as a const reference
	virtual void show() const =0;//every inherits class have to implement
	bool operator>(const Entity& cool_ent);//return true if this entity have more interesting entities the other
private:
	Entity(const Entity& other);//block the access to the copy c'tor
};



#endif