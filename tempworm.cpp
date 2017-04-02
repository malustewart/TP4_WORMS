#include "stdafx.h"
#include "tempworm.h"
void tempworm::setposition(point p) {
	position = p;
}
void tempworm::setdirection(int b) {
	direction=b;
}
void tempworm::setstate(int c) {
	state = c;
}
point tempworm::getposition() {
	return position;
}
int tempworm::getdirection() {
	return direction;
}
int tempworm::getstate() {
	return state;
}
void tempworm::setpositionx(double nx) {
	position.x = nx;
}
void tempworm::setpositiony(double ny) {
	position.y = ny;
}
void tempworm::incframecount() {
	framecount++;
}
int tempworm::getframecount() {
	return framecount;
}
void tempworm::changedirection() {
	direction = -direction;
}
void tempworm::moveworm() {
	position.x += (direction*walkspeed);
	
}
void tempworm::jumpworm() {
	position.x += (direction*jumpspeed*cos(angle));
	position.y = (jumpspeed*sin(angle)*framecount - framecount*framecount*gravity);
	if (position.y <= 0) {
		framecount = 0;
	}
}
void tempworm::initjump() {
	state = JUMPING;
}
void tempworm::initmove() {
	state = WALKING;
}
void tempworm::stopmove() {
	state = STILL;
}