#include"Person.h"

/******************IMPLEMENTATION_OF_PERSON_METHOD************************/
Person::Person(string name, const Date birthday) :Entity(name), birthday(birthday) {}
Person::~Person() {}
void Person::showUpdatesNotes()const
{
	homePage.show();
}
void Person::showInterestingEntities()const
{
	if (!checkIfHaveInterestingEntities())
	{
		cout << *getName() << " like:" << endl;
		Entity::showInterestingEntities();
	}
	else
		cout << *getName() << " doesn't like anybody :(" << endl;
}

void Person::stayTuned(const Status * stat)
{
	homePage.updateNewStatus(stat);
}
void Person::show()const
{
	cout << "Person " << *getName() << " ";
	birthday.show();
	cout << endl;
}
void Person::operator+=(Entity& cool_ent)
{
	Person* temp = dynamic_cast<Person*>(&cool_ent);
	if (this != &cool_ent)
	{
		if (checkduplicate(&cool_ent))
		{
			insertToEntitiesArr(&cool_ent);
			homePage.getUpdateFromNewMember(cool_ent.getpersonalwall());
			cool_ent.insertToEntitiesArr(this);
			if (temp)
				temp->homePage.getUpdateFromNewMember(this->personalWall);
			cout << "connection successed" << endl;
		}
		else
		{
			if (temp)
				cout << *getName() << " and " << *(cool_ent.getName()) << " are already good freinds why you are trying to fool me?:(" << endl;
			else
				cout << *getName() << " already like " << *(cool_ent.getName()) << endl;
		}
	}
	else
		cout << "a person can not be a friend of himself" << endl;
}