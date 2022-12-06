#include "Orc.h"


Orc::Orc() :Entity()
{
	club = 0;
	CoinDrop = 0;
	InstType = OrcType;
}

Orc::Orc(int club, int CoinDrop, int health) :Entity(health)
{
	this->club = club;
	this->CoinDrop = CoinDrop;
	InstType = OrcType;
}

Orc::~Orc()
{

}



int Orc::GetType()
{
	return InstType;
}

void Orc::PrintType() const
{
	std::cout << "orc";
}

int Orc::Attack()
{
	std::cout << "The orc hits for:" << club;
	return club;
}

void Orc::Print() const
{
	std::cout << "This orcs club deals " << club << " damage and he has " << MaxHealth << "HP" << std::endl;
}


int Orc::Defend(int DmgTaken)
{
	CurrentHealth -= DmgTaken;
	if (CurrentHealth <= 0)
	{
		std::cout << std::endl << "The orc died " << std::endl;
		return 0;
	}
	std::cout << " and the orcs hp now is " << CurrentHealth << std::endl;
	return CurrentHealth;
}

int Orc::GetCoins()
{
	return CoinDrop;
}