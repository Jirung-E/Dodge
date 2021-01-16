#include "Obstacle.h"

#include "World.h"

#include <random>


Obstacle::Obstacle() : GameObject(obstacle_shape, { 0, 0 }) {
	shape = obstacle_shape;
}



std::default_random_engine dre;
std::uniform_int_distribution<int> uid { World::Min_x, World::Max_x };

void Obstacle::randomSpawn() {
	position.x = uid(dre);
}