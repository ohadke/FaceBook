#include"Text_stat.h"

/******************IMPLEMENTATION_OF_TEXT_STAT_METHOD************************/
Text_stat::Text_stat(const string*  owner) : Status(owner)
{
	cout << "What you gonna say hommie ,Please dont talk too much only 150 chars" << endl;
	getline(cin, insertedtext);
}
void Text_stat::show()const
{
	Status::show();
	cout << insertedtext << endl;
}
const string* Text_stat::getText()const
{
	return &insertedtext;
}
bool Text_stat::operator==(const Status& other)
{
	const Text_stat  *st=nullptr;
	bool res = Status::operator==(other);
	if (res)
	{
		st = dynamic_cast<const Text_stat*>(&other);
		res = insertedtext==*(st->getText());
	}
	return res;
}