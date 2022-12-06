#pragma once
#include "Entity.h"
class OrcChief :
	public Entity
{
	int mace;
	int stomp;
	int rage;
	int CoinDrop;
public:
	//constructors and destructors
	OrcChief();
	virtual ~OrcChief();

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