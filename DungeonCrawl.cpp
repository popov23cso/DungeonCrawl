#include "DungeonCrawl.h"


DungeonCrawl::DungeonCrawl()
{
	srand(time(NULL));
	PlayerUnit = nullptr;
	score = 0;
	floor = 0;
}

DungeonCrawl::~DungeonCrawl()
{
	delete PlayerUnit;

	for (Item *tmp : Inventory)
	{
		delete tmp;
	}
	Inventory.clear();
}


void DungeonCrawl::InsertPlayer(Entity *ob)
{
	if (ob->GetType() == 1)
	{
		PlayerUnit = ob;
		std::cout << "Inserted player character succesfully" << std::endl;
	}
	else
	{
		std::cout << "The player can only play as a human... for now ...!" << std::endl;
	}
}


int DungeonCrawl::OneVsOne(Entity &Enemy)
{
	while (1)
	{
		if (Enemy.Defend(PlayerUnit->Attack()) <= 0)
		{
			PlayerUnit->AddCoins(Enemy.GetCoins());
			score += 2 * PlayerUnit->GetCoins();
			return 1;
		}
		if (PlayerUnit->Defend(Enemy.Attack()) <= 0)
		{
			return 0;
		}
	}
}


int DungeonCrawl::Step()
{
	if (floor == 0 || floor <= 2)
	{
		Orc tmp(25, 30, 50); //dmg , coins , health
		std::cout << "Enemies appear:" << std::endl;
		tmp.Print();
		if (!OneVsOne(tmp))
		{
			score += 2 * PlayerUnit->GetCoins();
			return 0;
		}
	}

	if (floor > 2)
	{
		int dice = rand() % 20 + 1;
		if (dice % 5 == 0)
		{
			std::cout << "you receive a healing potion" << std::endl;
			HealingPotion *tmp = new HealingPotion(25);
			Inventory.push_back(tmp);
		}
	}

	if (floor >= 5 && floor % 5 == 0 && floor != 10)
	{
		MerchantEncounter();
		score += 10 * floor;
		floor++;
		return 1;
	}

	if (floor == 8)
	{
		GoblinThief tmp(20);
		std::cout << "A sneaky goblin thief attacks you, he steals " << tmp.GetCoins() << "gold from you" << std::endl;
		PlayerUnit->AddCoins(-tmp.GetCoins());
		score += 10 * floor;
		floor++;
		int result = tmp.Defend(PlayerUnit->Attack());
		if (result < 0)
		{
			return 1;
		}
		else
		{
			PlayerUnit->AddCoins(result);
			return 1;
		}
	}

	if (floor == 10)
	{
		OrcChief tmp;
		std::cout << "You reach the chamber of the mighty orc chief!" << std::endl;
		tmp.Print();
		if (!OneVsOne(tmp))
		{
			score += 2 * PlayerUnit->GetCoins();
			return 0;
		}
		else
		{
			std::cout << "Congratulations you beat the game!" << std::endl;
			return 0;
		}
	}

	score += 10 * floor;
	floor++;
	return 1;
}

void DungeonCrawl::Run()
{
	int command;
	std::cout << "Press 1 to start, anything else to quit!" << std::endl;
	std::cin >> command;
	while (command){

		if (command == 1)
		{
			std::cout << "Floor " << floor << " Score " << score << std::endl;
			if (!Step())
			{
				break;
			}

		}
		else if (command == 2)
		{
			ManageInventory();
		}
		else if (command == 3)
		{
			PlayerUnit->Print();
		}
		std::cin >> command;
	}

	std::cout << "Game over!" << std::endl;
	std::cout << "Final score:" << score << std::endl;

}


void DungeonCrawl::PrintRules()
{
	std::cout << "Press 1 to advance to the next floor, in each floor you will encounter enemies you must defeat so you can advance" << std::endl;
}

void DungeonCrawl::ManageInventory()
{
	if (Inventory.empty())
	{
		std::cout << "Your inventory is empty" << std::endl;
		std::cout << "Your gold pouch has " << PlayerUnit->GetCoins() << " gold in it" << std::endl;
		return;
	}
	std::cout << "Theese are the items in your inventory:" << std::endl;

	int i = 1;
	for (Item *tmp : Inventory)
	{
		std::cout << i << ". ";
		tmp->PrintEffect();
		i++;
	}
	std::cout << "Your gold pouch has " << PlayerUnit->GetCoins() << " gold in it" << std::endl;
	std::cout << "Would you like to use an item 1=yes 0=close inventory" << std::endl;

	int command;
	do
	{
		std::cin >> command;
	} while (command != 1 && command != 0);

	while (command)
	{
		std::cout << "Type the index in inventory of the item" << std::endl;
		std::cin >> command;
		if (command == 0)
		{
			break;
		}
		else if (command > i)
		{
			std::cout << "There is no item with such index in the inventory!" << std::endl;
			continue;
		}
		else
		{
			UseItem(command);
			std::cout << "Consumed the item!" << std::endl;
			break;
		}
	}
	std::cout << "Inventory Closed" << std::endl;

}



void DungeonCrawl::UseItem(int InventorySlot)
{

	std::list<Item*>::iterator i;
	i = Inventory.begin();
	std::advance(i, InventorySlot - 1);
	PlayerUnit->UseItem(i._Ptr->_Myval->GetType(), i._Ptr->_Myval->GetEffect());
	delete i._Ptr->_Myval;
	Inventory.erase(i);
}


void DungeonCrawl::MerchantEncounter()
{
	std::cout << "You encounter the friendly gnome merchant! Theese are his wares:" << std::endl;
	std::cout << "1.Health potion(heals 25 HP) - price 25g" << std::endl;
	std::cout << "2.Heart crystal(increases max health by 25) - price 50g" << std::endl;
	if (floor == 20)
	{
		std::cout << "3.Steel greatsword(+40 strength) - price 100g" << std::endl;
	}
	int command;
	std::cout << "Would you like to buy something?" << std::endl;
	std::cin >> command;
	if (command == 1)
	{
		std::cout << "Type the index of the item that you want to buy" << std::endl;
		std::cin >> command;
		if (command == 1)
		{
			if (PlayerUnit->GetCoins() >= 25)
			{
				PlayerUnit->AddCoins(-25);
				HealingPotion *tmp = new HealingPotion(25);
				Inventory.push_back(tmp);
				std::cout << "Bought health potion!" << std::endl;
			}
			else
			{
				std::cout << "You dont have enough gold!" << std::endl;
			}
		}
		else if (command == 2)
		{
			if (PlayerUnit->GetCoins() >= 50)
			{
				PlayerUnit->AddCoins(-50);
				PlayerUnit->UseItem(3, 25);
				std::cout << "Increased your max health!" << std::endl;
			}
			else
			{
				std::cout << "You dont have enough gold!" << std::endl;
			}
		}
	}
	std::cout << "Left the merchant" << std::endl;
}