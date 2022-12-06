enum Type {
    Entity,
    Human,
    Orc,
    OrcChief,
    GoblinThief
}

public abstract class Entity {

    protected Type InstType;
    protected int CurrentHealth, MaxHealth, CoinPouch;

    Entity(Type InstType, int MaxHealth) {
        this.InstType = InstType;
        this.MaxHealth = MaxHealth;
        this.CurrentHealth = this.MaxHealth;
    }


    //text output methods
    public abstract void PrintType();
    public abstract void  Print();
    
    //getters and setters
    public abstract int GetType();
    public abstract int GetCoins();
    public abstract void Heal();

    //gameplay methods
    public abstract int Attack();
    public abstract int Defend(int Dmgtaken);
    public abstract void UseItem(int ItemID, int Effect);



}
