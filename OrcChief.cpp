#include "OrcChief.h"


OrcChief::OrcChief() :Entity()
{
	mace = 40;
	stomp = 60;
	MaxHealth = 200;
	rage = 0;
	CurrentHealth = MaxHealth;
	CoinDrop = 1000;
	InstType = OrcChiefType;
}


OrcChief::~OrcChief()
{
	std::cout << "Deleted the chief" << std::endl;
}


int OrcChief::GetType()
{
	return InstType;
}

void OrcChief::PrintType() const
{
	std::cout << "orc chief";
}

void OrcChief::Print() const
{
	std::cout << "This orc chief`s mace deals " << mace << " damage and he has " << MaxHealth << "HP" << std::endl;
}


int OrcChief::Attack()
{
	if (rage % 5 != 0)
	{
		std::cout << "The chief hits for:" << mace;
		rage++;
		return mace;
	}
	else
	{
		std::cout << "The chief gets really angry and does a ground-breaking stomp dealing " << stomp << " damage";
		rage++;
		return stomp;
	}
}


int OrcChief::Defend(int DmgTaken)
{
	CurrentHealth -= DmgTaken;
	if (CurrentHealth <= 0)
	{
		std::cout << std::endl << "The Chief died " << std::endl;
		return 0;
	}
	std::cout << " and the chiefs hp now is " << CurrentHealth << std::endl;
	return CurrentHealth;
}



int OrcChief::GetCoins()
{
	return CoinDrop;
}