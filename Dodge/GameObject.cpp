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

	Update();
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