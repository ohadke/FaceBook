#include"FanPage.h"

/******************IMPLEMENTATION_OF_PAGE_METHOD************************/
FanPage::FanPage(string name) :Entity(name) {}
FanPage::~FanPage() {}
void FanPage::showInterestingEntities()const
{
	if (!checkIfHaveInterestingEntities())
	{
		cout << "Those People Really Like " << *getName() << endl;
		Entity::showInterestingEntities();
	}
	else
		cout << *getName() << " doesn't have fans :(" << endl;
}
void FanPage::show()const
{
	cout << "Fan Page " << *getName() << endl;
}
