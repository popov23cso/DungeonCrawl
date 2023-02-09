public class OrcChief extends Entity{

    private int Mace;
    private int Stomp;
    private int Rage;
    private int CoinDrop;


    public OrcChief(int Mace, int Stomp, int Rage, int CoinDrop, int MaxHealth) {
        super(Type.OrcChief, MaxHealth);
        this.Mace = Mace;
        this.Stomp = Stomp;
        this.Rage = Rage;
        this.CoinDrop = CoinDrop;
    }
    

    //text output methods
    public void PrintType() {
        System.out.println("orc chief");
    }

    public void Print() {
        System.out.println("The orc chief's mace deals " + Mace + 
        " damage and he has " + MaxHealth + " HP");
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
        if (Rage % 5 != 0) {
            System.out.print("The chief hits for " + Mace);
            Rage++;
            return Mace;
        }
        else {
            System.out.print("The chief gets really angry and stomps the ground dealing " +
            Stomp + " damage");
            Rage++;
            return Stomp;
        }
    }


    public int Defend(int Dmgtaken) {
        CurrentHealth -= Dmgtaken;
        if (CurrentHealth <= 0) {
            System.out.println(" and the chief dies!");
            return 0;
        }
        System.out.println(" and the chief's HP is now " + CurrentHealth);
        System.out.println("");
        return CurrentHealth;
    }

    public void UseItem(ItemType Type, int Effect) {
        
    }
    
}
