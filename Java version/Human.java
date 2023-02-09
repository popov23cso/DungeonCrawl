


public class Human extends Entity {
    private int Weapon;
    private int Armor;
    private int Pouch;
    private String Name;

    public Human(int Weapon, int Armor, String Name, int MaxHealth) {
        super(Type.Human, MaxHealth);
        this.Weapon = Weapon;
        this.Armor = Armor;
        this.Pouch = 0;
        this.Name = Name;
    }


    //text output methods
    public void PrintType() {
        System.out.println("human");
    }

    public void Print() {
        System.out.println(Name + " has " + Weapon + " damage "
         + Armor + " armor " + CurrentHealth + "/" +  MaxHealth + " health");
    }


    //getters and setters
    public Type GetType() {
        return InstType;
    }

    public int GetCoins() {
        return Pouch;
    }

    public void AddCoins(int Amount) {
        if (Pouch == 0 && Amount <= 0) {
            return;
        }
        else {
            Pouch += Amount;
        }
    }


    //gameplay methods
    public int Attack() {
        System.out.print(Name + " hits for: " + Weapon);
        return Weapon;
    }

    public int Defend(int Dmgtaken) {
        if (Armor >= Dmgtaken) {
            System.out.print(" but it is too weak to damage you!");
            System.out.println("");
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

    public void UseItem(ItemType Type, int Effect) {
        if(Type == ItemType.HealingItem) {
            CurrentHealth += Effect;
            if (CurrentHealth > MaxHealth) {
                CurrentHealth = MaxHealth;
                return;
            }
        }
        else if (Type == ItemType.MaxHPIncreaseItem) {
            MaxHealth += Effect;
            return;
        }
    }

}