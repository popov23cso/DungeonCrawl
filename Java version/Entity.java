enum Type {
    Entity,
    Human,
    Orc,
    OrcChief,
    GoblinThief
}

public abstract class Entity {

    protected Type InstType;
    protected int CurrentHealth;
    protected int MaxHealth;
    protected int CoinPouch;

    public Entity(Type InstType, int MaxHealth) {
        this.InstType = InstType;
        this.MaxHealth = MaxHealth;
        this.CurrentHealth = this.MaxHealth;
    }


    //text output methods
    public abstract void PrintType();
    public abstract void Print();
    
    //getters and setters
    public abstract Type GetType();
    public abstract int GetCoins();
    public abstract void AddCoins(int Amount);

    //gameplay methods
    public abstract int Attack();
    public abstract int Defend(int Dmgtaken);
    public abstract void UseItem(ItemType Type, int Effect);



}
