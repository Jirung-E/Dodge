#include "Player.h"

#include "World.h"
#include "DisplayManager.h"

#include <iostream>


Player::Player() :
	GameObject(player_shape, { World::Min_x + World::Width / 2, World::Min_y + World::Height / 2 }),
	hp { 10 }, max_hp { 10 } {
	shape = player_shape;
}

Player::Player(int max_hp) :
	GameObject(player_shape, { World::Min_x + World::Width / 2, World::Min_y + World::Height / 2 }),
	hp { max_hp }, max_hp { max_hp } {
	shape = player_shape;
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