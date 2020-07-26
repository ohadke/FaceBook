#include "PartzofPanim.h"


PartzofPanim::PartzofPanim(){}

PartzofPanim::~PartzofPanim()
{
	for (Entity* p : members)
	{
		delete p;
	}
}

void PartzofPanim::AddPerson()
{
	int check,y;
	short int m,  d;
	string name;
	cout << "please enter member name:";
	getline(cin, name);
	check = getindexofMember(&name,typeid(Person));
	if (check==NOT_EXIST)
	{
		cout << "Please Enter Your Birthday (dd mm yyyy)" << endl;
		cin >> d >> m >> y;
		Entity* person = new Person(name, Date(d, m, y));
		if (members.size() == members.capacity())
			members.reserve(members.size() * 2 + 1);
		members.push_back(person);
	}
	else
		cout << "Error: this name already taken!" << endl;	
}
void PartzofPanim::AddPage()
{
	int check;
	string name;
	cout << "please enter page name:";
	getline(cin, name);
	check = getindexofMember(&name, typeid(FanPage));
	if (check==NOT_EXIST)
	{
		Entity* wall = new FanPage(name);
		if (members.size() == members.capacity())
			members.reserve(members.size() * 2 + 1);
		members.push_back(wall);
	}
	else
		cout << "Error: this name already taken!" << endl;
}



int  PartzofPanim::getindexofMember( const string* name, const type_info& type) const
{
	int result = NOT_EXIST;
	unsigned int numOfItr = members.size();
	for ( unsigned int i = 0; i < numOfItr && result == NOT_EXIST; i++)
	{
		if (*(members[i]->getName())==*name && type==typeid(*members[i]) )
			result = i;
	}
	return result;
}

void PartzofPanim::AddStatToPerson()
{
	string name;
	int indexname;
	cout << "Please enter the name of the person you want to add the status" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(Person));
	if (indexname != NOT_EXIST)
		members[indexname]->uploadStatus();
	else
		cout << "The name could not be found" << endl;
}
void PartzofPanim::AddStatToFanPage()
{
	string name;
	int indexname;
	cout << "Please enter the name of the page you want to add the status" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(FanPage));
	if (indexname != NOT_EXIST)
		members[indexname]->uploadStatus();
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::ShowWallOfPerson() const
{
	string name;
	int indexname;
	cout << "Please enter the name of the person you want to see the great wall" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(Person));
	if (indexname != NOT_EXIST)
		members[indexname]->showWalls();
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::ShowWallOfPage() const
{
	string name;
	int indexname;
	cout << "Please enter the name of the page you want to see the great wall" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(FanPage));
	if (indexname != NOT_EXIST)
		members[indexname]->showWalls();
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::GetPeopleConnected()
{
	Person* first;
	string name1, name2;
	int indexname1,indexname2;
	cout << "Please enter the name of the first person you want to connect:";
	getline(cin, name1);
	cout << "Please enter the name of the second person you want to connect:"  ;
	getline(cin, name2);
	indexname1 = getindexofMember(&name1, typeid(Person));
	indexname2 = getindexofMember(&name2, typeid(Person));
	if (indexname1 != NOT_EXIST && indexname2 != NOT_EXIST)
	{
		first = dynamic_cast<Person*>(members[indexname1]);
		(*first) += *(members[indexname2]);
	}
	else
		cout << "The name could not be found" << endl;
}

void  PartzofPanim::AddFanToPage()
{
	string name1, name2;
	int indexname1, indexname2;
	cout << "Please enter the name of the  person you want to connect" << endl;
	getline(cin, name1);
	cout << "Please enter the name of the page you want to connect" << endl;
	getline(cin, name2);
	indexname1 = getindexofMember(&name1, typeid(Person));
	indexname2 = getindexofMember(&name2, typeid(FanPage));
	if (indexname1 != NOT_EXIST && indexname2 != NOT_EXIST)
		(*(Person*)(members[indexname1]))+=(*members[indexname2]);
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::ShowAllUsers() const
{
	cout << "The members of PartzofPanim:" << endl;
	for (Entity* p : members)
		p->show();
}
void  PartzofPanim::ShowFreindsAndPagesOfPerson() const
{
	string name;
	int indexname;
	cout << "Please enter the name of the person:" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(Person));
	if (indexname != NOT_EXIST)
	{
		members[indexname]->showInterestingEntities();
	}
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::ShowFansOfPage() const
{
	string name;
	int indexname;
	cout << "Please enter the name of the page:" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(FanPage));
	if (indexname != NOT_EXIST)
	{
		members[indexname]->showInterestingEntities();
	}
	else
		cout << "The name could not be found" << endl;
}
void  PartzofPanim::ShowHomePageOfPerson() const
{
	string name;
	int indexname;
	cout << "Please enter the name of the person:" << endl;
	getline(cin, name);
	indexname = getindexofMember(&name, typeid(Person));;
	if (indexname != NOT_EXIST)
		((Person*)(members[indexname]))->showUpdatesNotes();
	else
		cout << "The name could not be found" << endl;
}

int PartzofPanim::menu()
{
	int selection;
	cout <<endl<<"welcome to Partzof Panim" << endl << "please enter your selection:" <<endl<< "1 for add a member." << endl;
	cout << "2 for add a fan page" << endl << "3 for add status for a person" << endl << "4 for add status for a page" << endl << "5 for show the wall of a person" << endl;
	cout << "6 for show the wall of a page" << endl << "7 for connecting bewteen people" << endl << "8 for adding a fan to a page " << endl << "9 showing all the users of PartzofPanim" << endl;
	cout << "10 for showing all the freinds and pages of a person" << endl << "11 for showing all the fans of a page" <<endl<<"12 for showing the home page of a person"<< endl << "0 For Exit" << endl;
	cin >> selection;
	cin.ignore(); 
	if (selection >= 0 && selection <= 12)
		switch (selection)
		{
		case 1:
			AddPerson();
			break;
		case 2:
			AddPage();
			break;
		case 3:
			AddStatToPerson();
			break;
		case 4:
			AddStatToFanPage();
			break;
		case 5:
			ShowWallOfPerson();
			break;
		case 6:
			ShowWallOfPage();
			break;
		case 7:
			GetPeopleConnected();
			break;
		case 8:
			AddFanToPage();
			break;
		case 9:
			ShowAllUsers();
			break;
		case 10:
			ShowFreindsAndPagesOfPerson();
			break;
		case 11:
			ShowFansOfPage();
			break;
		case 12:
			ShowHomePageOfPerson();
			break;
		default:
			break;
		}
	else
		cout << "wrong number" << endl;
	return selection;
}
