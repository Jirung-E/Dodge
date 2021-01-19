#include "GameObject.h"

#include "World.h"
#include "DisplayManager.h"

#include <iostream>


GameObject::GameObject(char shape) : shape { shape }, position { 0, 0 }, is_sleep { true } {

}

GameObject::GameObject(char shape, Position position) :
	shape { shape }, position { position }, is_sleep { true } {

}


void GameObject::Awake() {
	is_sleep = false;
}

void GameObject::Sleep() {
	is_sleep = true;
}

void GameObject::Update() {
	if(is_sleep) {
		return;
	}

	if(x() < World::Min_x || x() > World::Max_x || y() < World::Min_y || y() > World::Max_y) {
		Sleep();
		return;
	}
	
	
	World::world[x()][y()] = this;
	DisplayManager::gotoxy(position);
	std::cout << shape;
}


void GameObject::Move() {
	if(is_sleep) {
		return;
	}

	if(x() < World::Min_x || x() > World::Max_x || y() < World::Min_y || y() > World::Max_y) {
		Sleep();
		return;
	}


	DisplayManager::gotoxy(position);
	std::cout << ' ';


	position.y++;

	if(IsCollide()) {
		if(dynamic_cast<Player*>(World::world[x()][y()])) {
			Sleep();
			return;
		}
	}

	Update();
}

bool GameObject::IsCollide() const {
	if(World::world[x()][y()] != nullptr) {
		return true;
	}

	return false;
}


int GameObject::x() const {
	return position.x;
}

int GameObject::y() const {
	return position.y;
}


char GameObject::Shape() const {
	return shape;
}