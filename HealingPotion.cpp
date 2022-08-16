#include "HealingPotion.h"


HealingPotion::HealingPotion(int HealAmount) :Item("HealingPotion"), HealAmount(HealAmount)
{
	InstType = HealingItem;
}

HealingPotion::~HealingPotion()
{
	std::cout << "deleted hp pot" << std::endl;
}


int HealingPotion::GetEffect()
{
	return HealAmount;
}

void HealingPotion::PrintEffect()
{
	std::cout << "Heals you for " << HealAmount << " HP" << std::endl;
}

int HealingPotion::GetType()
{
	return InstType;
}