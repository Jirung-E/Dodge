#pragma once

#include "Position.h"


class GameObject {
protected:
	char shape;
	Position position;
	bool is_sleep;

public:
	GameObject(char shape);
	GameObject(char shape, Position position);

	void Awake();
	void Sleep();
	void Update();


	void Move();

	virtual bool IsCollide() const;


	int x() const;
	int y() const;

	char Shape() const;
};