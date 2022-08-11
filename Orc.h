#pragma once
#include "Entity.h"
#include "EntityInterface.h"

//Orcs are monster type that has no armor and any damage dealt to it has no reducing modifiers they are armed with clubs and drop coins on death


class Orc :
	public Entity
{
	int club;
	int CoinDrop;
public:
	//constructors and destructors
	Orc();
	Orc(int club, int CoinDrop, int health);
	~Orc() override;

	//text output methods
	void Print() const override;
	void PrintType() const override;

	//getters / setters
	int GetType() override;
	int GetCoins() override;


	//combat methods 
	int Attack() override;
	int Defend(int DmgTaken) override;
};

