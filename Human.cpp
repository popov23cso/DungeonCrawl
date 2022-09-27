#include "Human.h"
#include "EntityInterface.h"

Human::Human() :Entity()
{
	InstType = HumanType;
	weapon = 0;
	armor = 0;
	name.assign("Default human");
	pouch = 0;
}

Human::Human(int weapon, int armor, char* name, int health) :Entity(health)
{
	InstType = HumanType;
	this->weapon = weapon;
	this->armor = armor;
	this->name.assign(name);
	this->pouch = 0;
}


Human::~Human()
{
	std::cout << "Deleted Human" << std::endl;
}

void Human::Print() const
{
	std::cout << name << " has " << weapon << "damage " << armor << "armor " << MaxHealth << "health " << std::endl;
}

int Human::GetType()
{
	return InstType;
}

void Human::PrintType() const
{
	std::cout << "Im a Human!" << std::endl;
}


int Human::Attack()
{
	std::cout << name << " hits for:" << weapon;
	return weapon;
}

int Human::Defend(int DmgTaken)
{
	if (armor >= DmgTaken)
	{
		std::cout << " but it is too weak to damage you" << std::endl;
		return CurrentHealth;
	}
	CurrentHealth -= (DmgTaken - armor);
	if (CurrentHealth <= 0)
	{
		std::cout << std::endl << name << " died!" << std::endl;
		return 0;
	}
	std::cout << " and " << name << "'s hp now is " << CurrentHealth << std::endl;
	return CurrentHealth;
}


void Human::AddCoins(int Amount)
{
	if (pouch == 0 && Amount <= 0)
	{
		return;
	}
	else
	{
		pouch += Amount;
	}
}

int Human::GetCoins()
{
	return pouch;
}

void Human::UseItem(int ItemID, int Effect)
{
	if (ItemID == 1)
	{
		CurrentHealth += Effect;
		if (CurrentHealth  > MaxHealth)
		{
			CurrentHealth = MaxHealth;
			return;

		}
	}
	else if (ItemID == 3)
	{
		MaxHealth += Effect;
		return;
	}
}

