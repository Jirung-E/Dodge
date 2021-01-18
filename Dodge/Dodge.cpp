#pragma warning(disable : 4996)

#include "Dodge.h"

#include "World.h"
#include "DisplayManager.h"
#include "Player.h"
#include "Obstacle.h"
#include "Coin.h"

#include <conio.h>
#include <iostream>

#include <thread>
#include <chrono>


using namespace std;


const int fps = 60;

Player p;
Obstacle ob[10];
Coin c[5];


void Start() {
	DisplayManager::GameScreen(p);
	DisplayManager::Spawn(&p);
	p.Awake();

	for(Obstacle& e : ob) {
		e.randomSpawn();
		DisplayManager::Spawn(&e);
		e.Awake();
	}

	for(Coin& e : c) {
		e.randomSpawn();
		DisplayManager::Spawn(&e);
		e.Awake();
	}
}

bool Update() {
	char key = '\0';
	if(kbhit()) {
		key = getch();
	}

	switch(key) {
		case 'w':
		case 'a':
		case 's':
		case 'd':
			p.Move(key);
			break;
		case 'q':
		case 'e':
			return false;
	}

	for(Obstacle& e : ob) {
		e.Move();
	}
	for(Coin& e : c) {
		e.Move();
	}

	return true;
}


void Dodge::Play() {
	Start();

	while(Update() == true) {
		this_thread::sleep_for(chrono::milliseconds(1000 / fps));
	}

	DisplayManager::gotoxy(0, World::Max_y + 4);
	cout << "게임이 종료되었습니다." << endl;
}