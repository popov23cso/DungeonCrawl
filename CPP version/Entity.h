#pragma once

#include <iostream>
#include "EntityInterface.h"
#include <string>
#include <random>
#include <list>


class Entity :public EntityInterface
{
protected:
	int CurrentHealth;
	int MaxHealth;


public:
	//constructors and destructors
	Entity();
	Entity(int health);
	virtual ~Entity();

	//text output methods
	void PrintType() const override;
	virtual void Print() const;

	//getters and setters
	int GetType() override;
	virtual int GetCoins();
	virtual void AddCoins(int Amount);
	void Heal(int amount);


	//gameplay methods
	virtual int Attack();
	virtual int Defend(int DmgTaken);
	virtual void UseItem(int ItemID, int Effect);



};