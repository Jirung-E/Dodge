#include "DisplayManager.h"

#include "World.h"

#include <iostream>


//using namespace World;
using namespace std;


void DisplayManager::gotoxy(SHORT x, SHORT y) {
	//COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD { x, y });
}

void DisplayManager::gotoxy(Position pos) {
	gotoxy(pos.x, pos.y);
}


void seperateLine() {
	for(int i=0; i<World::Width; ++i) {
		cout << '-';
	}
	cout << endl;
}


using namespace DisplayManager;

void DisplayManager::GameScreen::Start(Player p) {
	gotoxy(World::Min_x, World::Max_y + 1);
	seperateLine();
	cout << " HP " << "    " << p.HP() << " / " << p.MaxHP() << endl;
	cout << "Coin" << "    " << p.Coins() << endl;
	seperateLine();
}

void DisplayManager::GameScreen::Update(Player p) {
	gotoxy(World::Min_x + 8, World::Max_y + 2);
	cout << p.HP() << " / " << p.MaxHP() << endl;
	cout << p.Coins() << endl;
}

void DisplayManager::Spawn(GameObject* go) {
	gotoxy(go->x(), go->y());
	cout << go->Shape();
}