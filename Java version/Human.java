


class Human extends Entity {
    private int Weapon;
    private int Armor;
    private int Pouch;
    private String Name;

    Human(int Weapon, int Armor, String Name, int MaxHealth) {
        super(Type.Human, MaxHealth);
        this.Weapon = Weapon;
        this.Armor = Armor;
        this.Pouch = 0;
        this.Name = Name;
    }


    //text output methods
    public void PrintType() {
        System.out.println("Im a Human!");
    }

    public void Print() {
        System.out.println(Name + " has" + Weapon + " damage "
         + Armor + " armor" + MaxHealth + " health");
    }


    //getters and setters
    public Type GetType() {
        return InstType;
    }

    public int GetCoins() {
        return Pouch;
    }


    //gameplay methods
    public int Attack() {
        System.out.println(Name + "hits for: " + Weapon);
        return Weapon;
    }

    public int Defend(int Dmgtaken) {
        if (Armor >= Dmgtaken) {
            System.out.println(" but it is too weak to damage you!");
            return CurrentHealth;
        }
        CurrentHealth -= (Dmgtaken - Armor);
        if (CurrentHealth <= 0) {
            System.out.println(Name + " died!");
            return 0;
        }
        System.out.println(" and " + Name + "'s hp is now " + CurrentHealth);
        return CurrentHealth;
    }

    public void UseItem(int ItemID, int Effect) {

    }

}