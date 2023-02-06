import java.util.Random;

public class GoblinThief extends Entity{
    private int StealAmount;
    Random Dice;

    public GoblinThief(int MaxHealth) {
        super(Type.GoblinThief, MaxHealth);
        Dice = new Random();
        this.StealAmount = Dice.nextInt(15) + 1;
    }

     //text output methods
     public void PrintType() {
        System.out.println("goblin thief");
    }


    public void Print() {
        System.out.println("This goblin steals " + StealAmount + " gold!");
    }

    //getters and setters
    public Type GetType() {
        return InstType;
    }


    public int GetCoins() {
        return StealAmount;
    }

    public void AddCoins(int Amount) {
        return;
    }

    
    //gameplay methods
    public int Attack() {
        System.out.println("The goblin is too afraid to attack!");
        return 0;
    }


    public int Defend(int Dmgtaken) {
        CurrentHealth -= Dmgtaken;
        if (CurrentHealth <= 0) {
            Dice = new Random();
            int Bonus = Dice.nextInt(15) + 1;
            System.out.println("The goblin died and dropped " + (StealAmount + Bonus) + " gold");
            return StealAmount + Bonus;
        }
        System.out.println(" the goblin survives the attack and runs away in fear");
        return -1;
    }


    public void UseItem(ItemType Type, int Effect) {
    }


}
