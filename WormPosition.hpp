#ifndef WormPosition_hpp
#define WormPosition_hpp

#include <stdio.h>
#include "worm.hpp"

class WormMovement
{
public:
	Point updatePosition(Worm w);
	WormMovement(float,float,float,float);
	
private:
	Point x0;			//donde inicia el movimiento. es necesario para los calculos
	float jumpV0;		//velocidad inicial del salto
	float jumpAngle;	//angulo inicial del salto
	float gravity;		//gravedad durante el salto
	float walkingV0;	//velocidad inicial de la caminata
};

#endif /* WormPosition_hpp */
