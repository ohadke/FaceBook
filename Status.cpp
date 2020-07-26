#include"Status.h"
/******************IMPLEMENTATION_OF_STATUS_METHOD************************/
Status::Status(const string*  owner) :owner(owner) {}
Status::~Status(){}
void Status::show()const
{
	cout << endl;
	cout << *owner << ": ";
	time.show();
	cout << endl;
}
bool Status::compareStatus(const Status* const first, const Status*const second)
{
	return (compareTime(first->time, second->time) == Date::FIRST);
}
bool Status::operator==(const Status& other)
{
	bool res = false;
	if (typeid(*this) == typeid(other))
		res = true;
	return res;
}
bool Status::operator!=(const Status& other)
{
	return !((*this) == other);
}