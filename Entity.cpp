#include"Entity.h"
#include"Person.h"
/******************IMPLEMENTATION_OF_ENTITY_METHOD************************/
Entity::Entity(string insertedName):personalWall(Noteboard(&name))
{
	name = insertedName;
}
Entity::~Entity(){}
bool Entity::checkduplicate(Entity* cool_ent)const
{
	for (Entity* p : Interesting_entities)
		if (p == cool_ent)
			return false;
	return true;
}
void Entity::insertToEntitiesArr(Entity* cool_ent)
{

	if (Interesting_entities.size() == Interesting_entities.capacity())
		Interesting_entities.reserve((Interesting_entities.size() * 2) + 1);
	Interesting_entities.push_back(cool_ent);
}
void Entity::letEverybodyKnow(const Status * stat)const
{
	Person* current_ent;

	for (Entity* p : Interesting_entities)
	{
		current_ent = dynamic_cast<Person*>(p);
		if(current_ent)
			current_ent->stayTuned(stat);
	}
}
void Entity::uploadStatus()
{
	const Status * stat = personalWall.addstat();
	letEverybodyKnow(stat);
}
const string* Entity::getName()const { return &name; }
void Entity::showWalls()const { personalWall.showBoard(); }
void Entity::showInterestingEntities()const
{
	for(Entity* p :Interesting_entities)
	{
		p->show();
	}
}
bool Entity::checkIfHaveInterestingEntities() const{return Interesting_entities.empty();}
const Noteboard& Entity::getpersonalwall() const { return personalWall; }
bool Entity::operator>(const Entity& cool_ent)
{
	return (Interesting_entities.size() > cool_ent.Interesting_entities.size());
}
