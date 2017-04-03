#include "Worm.h"


Worm::Worm (graphInfo_t wGraph, graphInfo_t jGraph, float x0, int dir, movingInfo_t mov)
{
	if((dir != LOOKLEFT && dir != LOOKRIGHT) || x0 < XMIN || XMAX < x0)
		valid = false;	//si hubo algun error en los parametros recibidos, indicarlo en valid
	else
	{
		valid = true;	//indicar que no hubo error y cargar los valores de los parametros recibidos
		tickCounter = 0;
		currentState = STILL;
		movement = mov;
		walkGraph = wGraph;
		jumpGraph = jGraph;	
		position.setX(x0);
	}
}

void Worm::calcNewState(userAction_t action)
{
	switch(action)
	{
		case LEFT_PRESSED:
			if (currentState == STILL || currentState == FINISHING_WALKING )		
				currentState = WALKING_PENDING; //entrar en el periodo de espera para caminar
			direction = LOOKLEFT;			//asegurarse de que ese mirando a la derecha
			break;
		case UP_PRESSED:
			if(currentState == STILL)
				currentState = JUMPING;
			break;
		case RIGHT_PRESSED:
			if (currentState == STILL || currentState == FINISHING_WALKING )		
				currentState = WALKING_PENDING; //entrar en el periodo de espera para caminar
			direction = LOOKRIGHT;
			break;
		case LEFT_RELEASED:
			if (currentState == WALKING_PENDING && direction == LOOKLEFT)
				currentState == STILL;
			direction =  LOOKLEFT;
			break;
		case UP_RELEASED:
			if (currentState == WALKING_PENDING && direction == LOOKLEFT)
				currentState == STILL;
			direction =  LOOKLEFT;
			break;
		case RIGHT_RELEASED:
			break;
	}
}

void Worm::update()
{
	if (currentState != STILL)
		tickCounter++;			//aumentar el tickCounter cada vez que se reciba un evento de timer
	if (tickCounter == 10 && currentState == WALKING_PENDING)
	{
		currentState == WALKING;
		int a;
		printf("rwrae");
		int b;
	}
	if (currentState == WALKING || currentState == JUMPING)
		move();	
	draw();
}

void Worm::move()
{
	if(currentState == WALKING)
	{
		if(!((tickCounter-6)%14) && tickCounter>8)	//nueva posicion del gusano
			position.setX(position.getX()+direction*9);	//para la derecha se suma, para la izquierda se resta
	}
	else if(currentState = JUMPING)	
	{}
}

void Worm::draw()
{	
	ALLEGRO_BITMAP* currentImg;
	if(currentState == WALKING)
		currentImg = walkGraph.wormImgs[walkGraph.imgOrder[tickCounter]];
	else if(currentState == JUMPING)
		currentImg = jumpGraph.wormImgs[jumpGraph.imgOrder[tickCounter]];
	else 
		currentImg = walkGraph.wormImgs[4];	//imagen default para el worm quieto 
											//PARA HACER: encontrar una manera no MAGIC NUMBER de escribir la linea anterior
	
	//dibujar, dependiendo de la direccion, se pone en 0 o en 1 la flag para invertir horizontalmente la imagen
	al_draw_bitmap(currentImg, position.getX(), position.getY(), direction == LOOKLEFT ? 0 : 1);
//	tickCounter++;
}

bool Worm::isValid()
{
	return valid;
}