#pragma once
#include "Entity.h"
#include "EntityInterface.h"

class Human : public Entity
{
	int weapon;
	int armor;
	std::string name;
	int pouch;
public:
	//constructors and destructors
	Human();
	Human(int weapon, int armor, char* name, int health);
	~Human() override;

	//text output methods
	void PrintType() const override;
	void Print()  const override;

	//getters and setters
	int GetType() override;
	void AddCoins(int Amount) override;
	int GetCoins() override;



	//gameplay methods
	int Attack() override;
	int Defend(int DmgTaken) override;
	void UseItem(int ItemID, int Effect) override;
};
