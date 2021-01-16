#include "Player.h"

#include "World.h"


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


char Player::character() const {
	return shape;
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