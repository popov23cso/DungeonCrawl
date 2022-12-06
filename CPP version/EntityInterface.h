#pragma once
class EntityInterface
{
protected:

	enum Type
	{
		EntityType = 0, HumanType, OrcType, PeasentType, OrcChiefType, GoblinThiefType
	};
	Type InstType;
public:
	virtual int GetType() = 0; //abstract method so every entity must have a method that gets its type
	virtual void PrintType()  const = 0; //abstract method so every entity has a method that prints its type 


};
