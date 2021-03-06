
#include "Worm.h"



//////////////////////////////////// Worm::Worm //////////////////////////////////////
//
// Constructor para un worm.
//
//////////////////////////////////////////////////////////////////////////////////////

Worm::Worm (graphInfo_t wGraph, graphInfo_t jGraph, double x0, int dir, movingInfo_t mov)
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


/////////////////////////////// Worm::calcNewState ///////////////////////////////////
//
// Una vez que llega un evento del teclado, se llama a esta funcion. Actualiza la 
// información de un worm que debe ser modificada de acuerdo al evento recibido.
//
//////////////////////////////////////////////////////////////////////////////////////

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
				currentState = STILL;
			direction =  LOOKLEFT;
			break;
		case UP_RELEASED:
			if (currentState == WALKING_PENDING && direction == LOOKLEFT)
				currentState = STILL;
			direction =  LOOKLEFT;
			break;
		case RIGHT_RELEASED:
			break;
		default: break;
	}
}

//////////////////////////////////// Worm::update ////////////////////////////////////
//
// Una vez que llega un evento del timer, se llama a esta funcion. Actualiza la 
// información de un worm que debe ser modificada luego de transcurrido un frame.
//
//////////////////////////////////////////////////////////////////////////////////////

void Worm::update() 
{
	if (currentState != STILL)
		tickCounter++;			//Aumentar el tickCounter cada vez que se reciba un evento de timer

	switch (currentState)
	{
	case WALKING_PENDING:
	{
		if (tickCounter >= 5)
		{
			currentState = WALKING;
		}
	} break;

	case WALKING:
	{
		if (tickCounter >= 49)
		{
			currentState = FINISHING_WALKING;
		}
		else move();
	} break;

	case JUMPING:
	{
		if (tickCounter >= 19)
		{
			currentState = FINISHING_JUMPING;
		}
		else move();
	} break;

	case FINISHING_WALKING: case FINISHING_JUMPING:
	{
		move();
		currentState = STILL;
		tickCounter = 0;
	} break;

	default: break;
	}

	draw();
}



////////////////////////////////// Worm::move ////////////////////////////////////////
//
// Se calcula la nueva posicion de un worm, de acuerdo a su estado.
//
//////////////////////////////////////////////////////////////////////////////////////

void Worm::move()
{
	if(currentState == WALKING)
	{
		if(!((tickCounter-6)%14) && tickCounter>8)			//nueva posicion del gusano
			position.setX(position.getX()+direction*9);		//para la derecha se suma, para la izquierda se resta
	}
	else if(currentState = JUMPING)	
	{
		position.setX(position.getX()+(direction*movement.jumpV0*cos(movement.jumpAngle))); //ver el +
		position.setY(movement.jumpV0*sin(movement.jumpAngle)*tickCounter - tickCounter*tickCounter*movement.gravity);
	}
}



/////////////////////////////////// Worm::draw ///////////////////////////////////////
//
// Dibuja en pantalla la imagen que corresponde al movimiento actual de un worm, en 
// la posicion correcta.
//
//////////////////////////////////////////////////////////////////////////////////////

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


//////////////////////////////////// Worm::isValid ///////////////////////////////////
//
// Verifica la creacion de un worm.
//
//////////////////////////////////////////////////////////////////////////////////////
bool Worm::isValid()
{
	return valid;
}