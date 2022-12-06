#pragma once
#include <iostream>
#include <string>
class Item
{
protected:
	std::string name;
	enum Type
	{
		BaseItem = 0, HealingItem, IncreaseDmgItem, IncreaseMaxHP
	};
	Type InstType;
public:
	//constructors and destructors
	Item();
	Item(std::string name);
	virtual ~Item();

	//text output methods
	virtual void PrintEffect();

	//gameplay methods
	virtual int GetEffect();
	virtual int GetType();
};

