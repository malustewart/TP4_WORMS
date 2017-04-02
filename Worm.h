#ifndef WORM_H
#define WORM_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define LOOKLEFT -1
#define LOOKRIGHT 1
#define IMGSXMOVEMENT 50

typedef unsigned int imgID;	//estaria bueno limitarlo a IMGSXMOVEMENT


typedef struct{	
	float jumpV0;		//velocidad inicial del salto
	float jumpAngle;	//angulo inicial del salto
	float gravity;		//gravedad durante el salto
	float walkingV0;	//velocidad inicial de la caminata
}movingInfo_t;

typedef struct{
	ALLEGRO_BITMAP* wormImgs[IMGSXMOVEMENT+1];	//contiene todas las imagenes necesarias del movimiento.
												//se deja libre la posicion cero para poder apuntar a la posicion 0 en caso de error
	unsigned int nextImgPosition;	
	imgID imgOrder[IMGSXMOVEMENT];				//orden de los bitmaps
}graphInfo_t;

typedef enum {STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING} wormState;
typedef enum {RIGHTKEY, UPKEY, LEFTKEY} keyCode; //no deberia estar aca sino en otro archivo, pero momentaneamente esta aca loco

class Worm
{
private:
	unsigned int tickCounter;
	wormState currentState;
	int direction;				//solo puede valer LOOKLEFT (-1) o LOOKRIGHT (1)
	
	movingInfo_t movement;
	graphInfo_t walkGraph;
	graphInfo_t jumpGraph;
	
	void move();		//mueve el worm de acuerdo a la informacion que tenga
	void draw();		//dibuja el worm de acuerdo a la informacion que tenga
	
public:
	Worm (graphInfo_t wGraph, graphInfo_t jumpGraph)
	void update();		//mueve y redibuja cada vez que se reciba un evento de timer
	void calcNewState();	//recalcula toda la informacion cada vez que se recibe un evento de teclado
};

#endif /* WORM_H */