#ifndef WORM_H
#define WORM_H

#include <stdint.h>
#include "Point.hpp"
#include "WormMovement.hpp"
#include "WormGraphics.h"


#define LOOKLEFT -1
#define LOOKRIGHT 1

#define IMGSxMOVEMENT 50


typedef unsigned int imgID;

typedef enum {STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING} wormState;
typedef enum {RIGHTKEY, UPKEY, LEFTKEY} keyCode; //no deberia estar aca sino en otro archivo, pero momentaneamente esta aca loco

class Worm
{
public:
    Worm();
    void updateWorm();			//hace todos los cambios necesarios en el worm para un tick
    void calcNewState(keyCode);	//de ser necesario, modifica currentState
	
    Point getPosition();
    int getDirection();			//devuele LOOKLEFT o LOOKRIGHT
    wormState getCurrentState();
    int getFrameCount();
    void setPosition(Point);	

private:
    Point position;	
    int direction;		//puede ser LOOKLEFT o LOOKRIGHT
    wormState currentState;
    int frameCount;
	WormMovement* movement;
	WormGraphic* walkGraphic;
	WormGraphic* jumpGraphic;
};

#endif // WORM_H
