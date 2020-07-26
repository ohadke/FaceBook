#include"UpdateNotes.h"
/******************IMPLEMENTATION_OF_UPDATE_NOTES_METHOD************************/
UpdateNotes::UpdateNotes(){}
void UpdateNotes::updateNewStatus(const Status *stat)
{
	newest_status.push_front(stat);
	if (newest_status.size() > MAX_SIZE)
		newest_status.pop_back();
}
void UpdateNotes::show()const
{
	list<const Status*>::const_iterator itr ;
	cout << endl << "the newest notes of your friends and pages:" << endl;
	for (itr = newest_status.begin(); itr != newest_status.end(); ++itr)
		(*itr)->show();
}
void UpdateNotes::getUpdateFromNewMember(const Noteboard& other)
{
	const unsigned int SIZE_POSSIBLE_VALUES = 20;
	int numOfItr;
	const vector<Status*>* other_board = other.getBoard();
	vector<const Status*> temp;
	temp.reserve(SIZE_POSSIBLE_VALUES);
	list<const Status*>::const_iterator itr1 ;
	for (itr1 = newest_status.begin(); itr1 != newest_status.end(); ++itr1)
		temp.push_back(*itr1);
	vector<Status*>::const_iterator itr2=other_board->end();
	numOfItr = other_board->size();
	if (numOfItr > MAX_SIZE)
		numOfItr = MAX_SIZE;
	for (int i = 0; i < numOfItr; i++)
	{
		--itr2;
		temp.push_back(*itr2);
	}
	sort(temp.begin(), temp.end(),Status::compareStatus);
	newest_status.clear();
	temp.resize(MAX_SIZE);
	for(const Status* p : temp)
	{
		if(p)
			newest_status.push_back(p);
	}
}