import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DungeonCrawl {
    private Entity PlayerUnit;
    private List<Item> Inventory = new ArrayList<Item>();
    private int Score;
    private int Floor;
    private Scanner SC;

    DungeonCrawl() {
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
        //TODO after implementing adding items to inventory
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
        //TODO implement step method
        return 0;
    }
}
