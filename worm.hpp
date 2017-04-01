#ifndef WORM_H
#define WORM_H

#include <cstdint>
#include "Point.hpp"


#define LOOKLEFT -1
#define LOOKRIGHT 1

typedef enum {STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING} wormState;
typedef enum {RIGHTKEY, UPKEY, LEFTKEY} keyCode; //no deberia estar aca sino en otro archivo, pero momentaneamente esta aca loco

class Worm
{
public:
    Worm();
    void updateWorm();			//hace todos los cambios necesarios en el worm para un tick
    void calcNewState(keyCode);	//de ser necesario, modifica currentState
	
    Point getPosition();
    int getDirection();				//devuele LOOKLEFT o LOOKRIGHT
    wormState getCurrentState();
    int getFrameCount();
    void setPosition(Point);	//NO RECIBE UN INT, RECIBE UN OBJETO DE LA CLASE POINT PERO ME DA PAJA INCLUIRLA AHORA

private:
    Point position;  //deberia ser del tipo Point, despues cambiar.
    int direction; //puede ser LOOKLEFT o LOOKRIGHT
    wormState currentState;
    int frameCount;
};

#endif // WORM_H
