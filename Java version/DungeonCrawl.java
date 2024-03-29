import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Random;

public class DungeonCrawl {
    private Entity PlayerUnit;
    private List<Item> Inventory = new ArrayList<Item>();
    private int Score;
    private int Floor;
    private Scanner SC;

    public DungeonCrawl() {
        PlayerUnit = null;
        Score = 0;
        Floor = 0;
        SC = new Scanner(System.in);
    }

    @Override
    protected void finalize() throws Throwable {
        SC.close();
    }

    //text output methods
	public void PrintRules() {
        System.out.println("Press 1 to advance to the next floor, in each floor you will encounter " + 
        "enemies you must defeat so you can advance");
    }


	public void ManageInventory() {
        if(Inventory.isEmpty() == true) {
            System.out.println("Your inventory is empty!");
            System.out.println("Your gold pouch has " + PlayerUnit.GetCoins() + " gold in it");
            return;
        }
        System.out.println("Theese are the items in your inventory: ");
        int i = 1;
        for (Item item : Inventory) {
            System.out.print(i + " ");
            item.PrintEffect();
            i ++;
        }
        System.out.println("Your gold pouch has " + PlayerUnit.GetCoins() + " gold in it");
        System.out.println("Would you like to use an item?");
        int Command;
        Command = SC.nextInt();
        while (Command != 0) {
            System.out.println("Type the index in inventory of the item: ");
            Command = SC.nextInt();
            if (Command == 0) {
                break;
            }
            else if (Command > Inventory.size()) {
                System.out.println("There is no item with such index in inventory!");
                continue;
            }
            else {
                UseItem(Command - 1);
                System.out.println("Used the item!");
                break;
            }

        }
        System.out.println("Inventory closed !");
    }

    //gameplay methods
	public void InsertPlayer(Entity ob) {
        if (ob.GetType() == Type.Human) {
            PlayerUnit = ob;
            System.out.println("Inserted player character succesfully");
        }
        else {
            System.out.println("The player can only play as a human... for now");
            PlayerUnit = null;
        }
    }

    public void Run() {
        int Command;
        System.out.println("Press 1 to start, anything else to quit!");
        Command = SC.nextInt();
        while (Command != 0) {
            if (Command == 1) {
                System.out.println("Floor " + Floor + " Score " + Score);
                if(Step() == 0) {
                    break;
                }
            }
            else if (Command == 2) {
                ManageInventory();
            }
            else if (Command == 3) {
                PlayerUnit.Print();
            }
            Command = SC.nextInt();
        }
        System.out.println("Game over!");
        System.out.println("Final score:" + Score);

    }

    public int Step() {
        if (Floor == 0 || Floor <= 2) {
            Orc Enemy = new Orc(25, 30, 50);
            System.out.println("An enemy appears!");
            Enemy.Print();
            if(OneVsOne(Enemy) == 0) {
                Score += 2 * PlayerUnit.GetCoins();
                return 0;
            }
        }

        if (Floor > 2) {
            Random Dice = new Random();
            int Roll = Dice.nextInt(20) + 1;
            if (Roll % 5 == 0) {
                System.out.println("You stumble upon a healing potion!");
                HealthPotion tmp = new HealthPotion(25);
                Inventory.add(tmp);
            }
        }

        //Encounter a merchant every 5 floors 
        if (Floor >= 5 && Floor % 5 == 0 && Floor != 10) {
            MerchantEncounter();
            Score += 10 * Floor;
            Floor ++;
            return 1;
        }

        if (Floor == 8) {
            GoblinThief tmp = new GoblinThief(20);
            System.out.println("A sneaky goblin manages to steal " + tmp.GetCoins() + " gold!");
            PlayerUnit.AddCoins(-tmp.GetCoins());
            int FightResult = tmp.Defend(PlayerUnit.Attack());
            if (FightResult > 0) {
                PlayerUnit.AddCoins(FightResult);
                
            }
            Score += 10 * Floor;
            Floor ++;
            return 1;
        }

        if (Floor == 10) {
            OrcChief tmp = new OrcChief(30, 50, 1, 150, 1000);
            System.out.println("You reach the chamber of the mighty orc chief!");
            tmp.Print();
            if (OneVsOne(tmp) == 0) {
                Score += PlayerUnit.GetCoins();
                return 0;
            }
            else {
                System.out.println("Congratulations you beat the game!");
                Score += 3 * PlayerUnit.GetCoins();
                return 0;
            }
        }

        Floor ++;
        return 1;
    }

    public int OneVsOne(Entity Enemy) {
        while (true) {
            if (Enemy.Defend(PlayerUnit.Attack()) <= 0) {
                PlayerUnit.AddCoins(Enemy.GetCoins());
                Score += 2 * PlayerUnit.GetCoins();
                return 1;
            }
            if (PlayerUnit.Defend(Enemy.Attack()) <= 0) {
                return 0;
            }
        }
    }


    public void MerchantEncounter() {
        System.out.println("You encounter the friendly gnome merchant!" + 
        " Theese are his wares: ");
        System.out.println("1. Health potion(heals for 25 HP) - 25 gold");
        System.out.println("2. Health crystal(increases max HP by 25) - 50 gold");
        System.out.println("You have " + PlayerUnit.GetCoins() + " gold");
        if (Floor == 20) {
            System.out.println("3. Steel greatsword(+ 40 strength) - 100 gold");
        }
        System.out.println("Would you like to buy something?");
        int Command = SC.nextInt();
        if (Command == 1) {
            System.out.println("Type the index of the item that you want to buy: ");
            Command = SC.nextInt();
            if (Command == 1) {
                if (PlayerUnit.GetCoins() >= 25) {
                    PlayerUnit.AddCoins(-25);
                    HealthPotion tmp = new HealthPotion(25);
                    Inventory.add(tmp);
                    System.out.println("Bought health potion!");
                }
                else {
                    System.out.println("You dont have enough gold !");
                }
            }
            if (Command == 2) {
                if(PlayerUnit.GetCoins() >= 50) {
                    PlayerUnit.AddCoins(-50);
                    PlayerUnit.UseItem(ItemType.MaxHPIncreaseItem, 25);
                    System.out.println("Increased max HP by 25!");
                }
                else {
                    System.out.println("You dont have enough gold !");
                }
            }
        }
        System.out.println("Left the merchant!");
    }

    public void UseItem(int InventorySlot) {
        PlayerUnit.UseItem(Inventory.get(InventorySlot).GetType(), Inventory.get(InventorySlot).GetEffect());
        Inventory.remove(InventorySlot);
    }
}
