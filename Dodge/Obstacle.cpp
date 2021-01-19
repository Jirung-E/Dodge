#include "Obstacle.h"

#include "World.h"
#include "DisplayManager.h"

#include <random>
#include <iostream>


using namespace std;


namespace Random {
	default_random_engine dre;
	uniform_int_distribution<int> spawn_range { World::Min_x, World::Max_x };
	uniform_int_distribution<int> speed_range { 2, 5 };
}


Obstacle::Obstacle() : GameObject(obstacle_shape, { 0, 0 }), move_speed { 1 } {
	shape = obstacle_shape;
}



void Obstacle::randomSpawn() { 
	position.x = Random::spawn_range(Random::dre);
	randomMoveSpeed();
}

void Obstacle::randomMoveSpeed() {
	move_speed = Random::speed_range(Random::dre);
}


void Obstacle::Move() {
	if(is_sleep) {
		return;
	}

	if(x() < World::Min_x || x() > World::Max_x || y() < World::Min_y || y() > World::Max_y) {
		Sleep();
		return;
	}

	// <canMove?>
	const auto move_rate = 1000ms / static_cast<double>(move_speed);
	auto now = std::chrono::system_clock::now();

	if(now - last_move < move_rate) {
		return;
	}

	last_move = chrono::system_clock::now();
	// </canMove?>


	DisplayManager::gotoxy(position);
	std::cout << ' ';
	World::world[x() - World::Min_x][y() - World::Min_y] = nullptr;


	position.y++;

	if(IsCollide()) {
		Interaction(World::world[x()][y()]);
		return;
	}

	Update();
}


void Obstacle::Interaction(GameObject* go) {
	if(is_sleep) {
		return;
	}

	if(dynamic_cast<Player*>(go)) {
		dynamic_cast<Player*>(go)->Interaction(this);
		Sleep();
	}
}