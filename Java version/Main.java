public class Main {
    public static void main(String[] args) {
        DungeonCrawl DC = new DungeonCrawl();
        Human Conan = new Human(100, 100, "Conan", 150);
        DC.InsertPlayer(Conan);
        DC.Run();
    }
}
