#ifndef WormMovement_hpp
#define WormMovement_hpp

#include <stdio.h>
#include "worm.hpp"
#include "Point.hpp"


class WormMovement
{
public:
	void updatePosition(Worm* w);
	WormMovement(float,float,float,float);
	
private:
	float jumpV0;		//velocidad inicial del salto
	float jumpAngle;	//angulo inicial del salto
	float gravity;		//gravedad durante el salto
	float walkingV0;	//velocidad inicial de la caminata
};

#endif /* WormMovement_hpp */
