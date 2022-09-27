#include "Entity.h"
#include "Human.h"
#include "DungeonCrawl.h"



int main()
{
	DungeonCrawl::PrintRules();
	Human *A = new Human(20, 25, "Conan", 10000);
	DungeonCrawl D;
	D.InsertPlayer(A);
	D.Run();

}