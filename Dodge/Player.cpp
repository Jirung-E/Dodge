#include "Player.h"

#include "World.h"
#include "DisplayManager.h"
#include "Obstacle.h"
#include "Coin.h"
#include "HealPack.h"

#include <iostream>


Player::Player() :
	GameObject(player_shape, { World::Min_x + World::Width / 2, World::Min_y + World::Height / 2 }),
	hp { 10 }, max_hp { 10 }, coin { 0 } {
	shape = player_shape;
}

Player::Player(int max_hp) :
	GameObject(player_shape, { World::Min_x + World::Width / 2, World::Min_y + World::Height / 2 }),
	hp { max_hp }, max_hp { max_hp }, coin { 0 } {
	shape = player_shape;
}


void Player::getDmg(int dmg) {
	hp -= dmg;
	if(hp <= 0) {
		hp = 0;
		Sleep();
	}
}



void Player::Move(char dir) {
	if(is_sleep) {
		return;
	}

	if(x() < World::Min_x || x() > World::Max_x || y() < World::Min_y || y() > World::Max_y) {
		Sleep();
		return;
	}


	DisplayManager::gotoxy(position);
	std::cout << ' ';
	World::world[x() - World::Min_x][y() - World::Min_y] = nullptr;


	switch(dir) {
		case 'w':
			position.y--;
			break;
		case 'a':
			position.x--;
			break;
		case 's':
			position.y++;
			break;
		case 'd':
			position.x++;
			break;
		default:
			std::cout << "An Error Occurred - Invalid input" << std::endl;
	}


	if(x() < World::Min_x) {
		position.x++;
	}
	else if(x() > World::Max_x) {
		position.x--;
	}
	
	if(y() < World::Min_y) {
		position.y++;
	}
	else if(y() > World::Max_y) {
		position.y--;
	}


	Update();
}


Position Player::Pos() const {
	return position;
}

int Player::HP() const {
	return hp;
}

int Player::MaxHP() const {
	return max_hp;
}

int Player::Coins() const {
	return coin;
}


void Player::Interaction(GameObject* go) {
	if(is_sleep) {
		return;
	}

	if(dynamic_cast<Coin*>(go)) {
		coin++;
	}
	else if(dynamic_cast<HealPack*>(go)) {
		hp++;
		if(hp > max_hp) {
			hp = max_hp;
		}
	}
	else if(dynamic_cast<Obstacle*>(go)) {
		getDmg(1);
	}
}