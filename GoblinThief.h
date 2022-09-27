#pragma once
#include "Entity.h"
#include "EntityInterface.h"

//GoblinThieves have a chance to steal some of the players gold, but if you manage to one shot him you can get your gold back plus extra


class GoblinThief :
	public Entity
{
	int StealAmount;
public:
	//constructors and destructors
	GoblinThief();
	GoblinThief(int health);
	~GoblinThief() override;

	//text output methods
	void Print() const override;
	void PrintType() const override;

	//getters / setters
	int GetType() override;
	int GetCoins() override;

	//combat methods 
	int Defend(int DmgTaken) override;
};