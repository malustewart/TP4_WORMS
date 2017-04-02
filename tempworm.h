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
	double gravity;
	double angle;
	double jumpspeed;
	double walkspeed;
public:
	tempworm() {
		point start;
		start.x = 0;
		start.y = 0;
		position = start;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
		gravity = G;
		angle = ANG;
		jumpspeed = JUMPV;
		walkspeed = WALKINGX;
	}
	tempworm(point start) {
		position = start;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
		gravity = G;
		angle = ANG;
		jumpspeed = JUMPV;
		walkspeed = WALKINGX;
	}
	tempworm(double _x, double _y) {
		position.x = _x;
		position.y = _y;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
		gravity = G;
		angle = ANG;
		jumpspeed = JUMPV;
		walkspeed = WALKINGX;
	}
	tempworm(double m, double n,int dir, double gr,double alfa,double js, double ws) {
		position.x = m;
		position.y = n;
		direction = RIGHT;
		framecount = 0;
		state = STILL;
		gravity = gr;
		angle = alfa;
		jumpspeed = js;
		walkspeed = ws;
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