public class HealthStone extends Item {
    protected int IncreaseAmount;

    HealthStone(int IncreaseAmount) {
        super(ItemType.MaxHPIncreaseItem ,"Health Stone");
        this.IncreaseAmount = IncreaseAmount;
    }


    //text output methods
    public void PrintEffect() {
        System.out.println("Increases your max HP by " + IncreaseAmount);
    }

    //gameplay methods
    public int GetEffect() {
        return IncreaseAmount;
    }


    public ItemType GetType() {
        return InstType;
    }
}
