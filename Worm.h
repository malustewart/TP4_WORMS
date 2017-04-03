
#ifndef WORM_H
#define WORM_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "Point.hpp"
#include "Background.hpp"
#include <math.h>
#include <allegro5/allegro_acodec.h> //no
#include <allegro5/allegro_primitives.h> //

#define LOOKLEFT -1.0
#define LOOKRIGHT 1.0


#define IMGSXMOVEMENT 50
#define PI 3.14159265358979323846 //usar, sino: M_PI de la libreria math.

typedef unsigned int imgID;	

typedef struct{	
	double jumpV0;		//velocidad inicial del salto
	double jumpAngle;	//angulo inicial del salto
	double gravity;		//gravedad durante el salto
	double walkingV0;	//velocidad inicial de la caminata
}movingInfo_t;

typedef struct{
	ALLEGRO_BITMAP* wormImgs[IMGSXMOVEMENT+1];	//contiene todas las imagenes necesarias del movimiento.
												//se deja libre la posicion cero para poder apuntar a la posicion 0 en caso de error
	unsigned int nextImgPosition;	
	imgID imgOrder[IMGSXMOVEMENT];				//orden de los bitmaps
	}graphInfo_t;

typedef enum {STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING} wormState_t;
typedef enum{LEFT_PRESSED, LEFT_RELEASED, UP_PRESSED, UP_RELEASED, RIGHT_PRESSED, RIGHT_RELEASED}userAction_t;	//PARA HACER: mover de lugar

class Worm
{
private:
	bool valid;
	
	unsigned int tickCounter;
	Point position;
	wormState_t currentState;
	int direction;				//solo puede valer LOOKLEFT (-1) o LOOKRIGHT (1)
	
	movingInfo_t movement;
	graphInfo_t walkGraph;
	graphInfo_t jumpGraph;
	
	void move();		//mueve el worm de acuerdo a la informacion que tenga
	void draw();		//dibuja el worm de acuerdo a la informacion que tenga
	
public: 
	//Worm(graphInfo_t wGraph, graphInfo_t jGraph, double x0, int dir, movingInfo_t mov);
	Worm (graphInfo_t wGraph, graphInfo_t jGraph, double X0 = (XMIN + XMAX)/2, int dir = LOOKRIGHT, movingInfo_t mov = {4.5, PI/3, 0.4, 27});
	void update();						//mueve y redibuja cada vez que se reciba un evento de timer
	void calcNewState(userAction_t action);	//recalcula toda la informacion cada vez que se recibe un evento de teclado
	bool isValid();						//indica si hubo error o no en su inicializacion
};

#endif /* WORM_H */
/*
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
	*/