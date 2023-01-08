
public class HealthPotion extends Item{
    protected int HealAmount;

    HealthPotion(int HealAmount) {
        super(ItemType.HealingItem ,"Healing Potion");
        this.HealAmount = HealAmount;
    }


    //text output methods
    public void PrintEffect() {
        System.out.println("Heals for " + HealAmount + " HP");
    }


    //gameplay methods
    public int GetEffect() {
        return HealAmount;
    }


    public ItemType GetType() {
        return InstType;
    }
}
