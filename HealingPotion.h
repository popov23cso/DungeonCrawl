#pragma once
#include "Item.h"
class HealingPotion :
	public Item
{
	int HealAmount;
public:
	//constructors and destructors
	HealingPotion(int HealAmount);
	~HealingPotion() override;

	//text output methods
	void PrintEffect() override;

	//gameplay methods
	int GetEffect() override;
	int GetType() override;
};

