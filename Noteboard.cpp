#include"Noteboard.h"

/******************IMPLEMENTATION_OF_NOTEBOARD_METHOD************************/
Noteboard::Noteboard(const string*  owner) :owner(owner){}
Noteboard::~Noteboard()
{
	if (!Board.empty())
		for (Status* p:Board)
		{
			delete p;
		}
}

const Status* Noteboard::addstat()
{
	Status* stat = nullptr;
	int type;
	cout << "Ladies and Gentleman Please insert the type of status you would like to use" << endl << "For Text press 1." << endl << "For Video Press 2." << endl << "For Photo Press 3." << endl << "For Photo with text press 4." << endl << "For Video with text press 5." << endl;
	cin >> type;
	cin.ignore();
	switch (type)
	{
	case 1: stat = new Text_stat(owner);   break;
	case 2: stat = new Video_stat(owner);   break;
	case 3: stat = new Photo_stat(owner);   break;
	case 4: stat = new PhotoAndText_stat(owner);   break;
	case 5: stat = new VideoAndText_stat(owner);   break;
	default: cout << "Invalid option!\n";  break;
	}
	if (Board.size() == Board.capacity())
		Board.reserve(Board.size() * 2 + 1);
	Board.push_back(stat);
	return stat;
}
void Noteboard::showBoard() const
{
	cout << endl << "the noteboard of " << *owner << ':' << endl;
	for (Status* p:Board)
	{
		p->show();
	}
}
const vector<Status*>* Noteboard::getBoard() const { return &Board; }
