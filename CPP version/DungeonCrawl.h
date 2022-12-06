#pragma once
#include "Game.h"
#include "Entity.h"
#include "Orc.h"
#include "Human.h"
#include "HealingPotion.h"
#include "OrcChief.h"
#include "GoblinThief.h"
#include <ctime>


class DungeonCrawl :
	public Game
{
private:
	Entity *PlayerUnit;
	std::list<Entity> Enemies;
	std::list<Item*> Inventory;
	int score;
	int floor;

public:
	//constructors and destructors
	DungeonCrawl();
	~DungeonCrawl();

	//text output
	static void PrintRules();
	void ManageInventory();

	//gameplay methods
	void InsertPlayer(Entity *ob);
	int Step();
	void Run() override;
	int OneVsOne(Entity &Enemy);
	void UseItem(int InventorySlot);
	void MerchantEncounter(); //every 5 floors you encounter a merchant


};