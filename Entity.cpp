#include "Entity.h"


Entity::Entity()
{
	MaxHealth = 0;
	CurrentHealth = MaxHealth;
	InstType = EntityType;
}

Entity::Entity(int health)
{
	this->MaxHealth = health;
	this->CurrentHealth = this->MaxHealth;
	InstType = EntityType;

}

Entity::~Entity()
{
	std::cout << "Deleted entity" << std::endl;
}

void Entity::Print() const
{
	std::cout << "This entity has " << CurrentHealth << " HP" << std::endl;
}



int Entity::Attack()
{
	return 0;
}

int Entity::Defend(int DmgTaken)
{
	CurrentHealth -= DmgTaken;
	return CurrentHealth;
}

void Entity::Heal(int amount)
{
	CurrentHealth += amount;
	if (CurrentHealth > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
}

void Entity::PrintType() const
{
	std::cout << "Im an entity!" << std::endl;

}

int Entity::GetCoins()
{
	return 0;
}

void Entity::AddCoins(int Amount)
{
	return;
}

int Entity::GetType()
{
	return InstType;
}

void Entity::UseItem(int ItemID, int Effect)
{
	if (ItemID == 1)
	{
		CurrentHealth += Effect;
		if (CurrentHealth  > MaxHealth)
		{
			CurrentHealth = 100;
			return;

		}
	}

}
