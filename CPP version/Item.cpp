#include "Item.h"


Item::Item()
{
	name.assign("Base item");
	InstType = BaseItem;
}

Item::Item(std::string name)
{
	this->name.assign(name);
	InstType = BaseItem;

}

Item::~Item()
{
	std::cout << "base item destroyed" << std::endl;
}


void Item::PrintEffect()
{
	std::cout << "This item has no effect" << std::endl;
}

int Item::GetType()
{
	return InstType;
}



int Item::GetEffect()
{
	return 0;
}