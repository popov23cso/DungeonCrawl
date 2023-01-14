public class Orc extends Entity{

    private int Club;
	private int CoinDrop;


    public Orc(int Club, int CoinDrop, int MaxHealth) {
        super(Type.Orc, MaxHealth);
        this.Club = Club;
        this.CoinDrop = CoinDrop;
    }


    //text output methods
    public void PrintType() {
        System.out.println("orc");
    }


    public void Print() {
        System.out.println("This orc's club deals " + Club + 
        " damage and he has " + MaxHealth + " maximum HP");
    }

    //getters and setters
    public Type GetType() {
        return InstType;
    }


    public int GetCoins() {
        return CoinDrop;
    }

    public void AddCoins(int Amount) {
        return;
    }

    
    //gameplay methods
    public int Attack() {
        System.out.println("The orc hits for: " + Club);
        return Club;
    }


    public int Defend(int Dmgtaken) {
        CurrentHealth -= Dmgtaken;
        if (CurrentHealth <= 0) {
            System.out.println("The orc died ");
            return 0;
        }
        System.out.println(" and the orc's HP is now " + CurrentHealth);
        return CurrentHealth;
    }


    public void UseItem(int ItemID, int Effect) {

    }

}
