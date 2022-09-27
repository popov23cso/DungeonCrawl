#include "GoblinThief.h"

GoblinThief::GoblinThief() : Entity()
{
	StealAmount = rand() % 15 + 1;
	InstType = GoblinThiefType;
}


GoblinThief::GoblinThief(int health) : Entity(health)
{
	int dice = rand() % 6 + 1;
	if (dice == 1)
	{
		StealAmount = 0;
	}
	else
	{
		StealAmount = rand() % 25 + 1;
	}
	InstType = GoblinThiefType;
}


GoblinThief::~GoblinThief()
{

}


void GoblinThief::Print() const
{
	std::cout << "The goblin thief steals " << StealAmount << " gold" << std::endl;
}


void GoblinThief::PrintType() const
{
	std::cout << "Goblin Thief";
}


int GoblinThief::GetType()
{
	return InstType;
}


int GoblinThief::GetCoins()
{
	int bonus = rand() % 15 + 1;
	return StealAmount + bonus;
}


int GoblinThief::Defend(int DmgTaken)
{
	CurrentHealth -= DmgTaken;
	if (CurrentHealth <= 0)
	{
		std::cout << std::endl << "The goblin died " << std::endl;
		return 0;
	}
	std::cout << " the goblin survives the hit and runs away in fear " << CurrentHealth << std::endl;
	return CurrentHealth;
}