
enum ItemType {
    HealingItem,
    DmgIncreaseItem,
    MaxHPIncreaseItem
}


public abstract class Item {

    protected String Name;
    ItemType InstType;

    Item(ItemType InstType, String Name) {
        this.Name = Name;
        this.InstType = InstType;
    }

    //text output methods
    public abstract void PrintEffect();

    //gameplay methods
    public abstract int GetEffect();
    public abstract ItemType GetType();

}
