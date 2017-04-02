#pragma once
#ifndef TEMPWORM_H
#define TEMPWORM_H
#include "point.h"
#define STILL 0
#define WALKING 1
#define JUMPING 2
#define RIGHT 1
#define LEFT -1
#define WALKINGX 27
#define JUMPV 4.5
#define PI 3.14159265359
#define ANG PI/3
#define G 0.24

class tempworm {
	point position;
	int direction;
	int framecount;
	int state;
public:
	tempworm() {
		point start;
		start.x = 0;
		start.y = 0;
		position = start;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
	}
	tempworm(point start) {
		position = start;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
	}
	tempworm(double _x, double _y) {
		position.x = _x;
		position.y = _y;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
	}
	void setposition(point p); //setters
	void setdirection(int b);
	void setstate(int c);
	void setpositionx(double nx);
	void setpositiony(double ny);
	void incframecount();
	point getposition(); //getters
	int getdirection();
	int getstate();
	int getframecount();
	void changedirection(); //cambia el sentido del worm
	void moveworm(); //mueve el worm en el suelo dependiendo de la dirección
	void jumpworm(); //mueve el worm saltando dependiendo de la dirección
	void initjump();
	void initmove();
	void stopmove();
};
#endif