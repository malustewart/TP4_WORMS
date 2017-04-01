#include "Worm.h"

    Worm::Worm()
	{
		position = LOOKRIGHT
	}
	void Worm::updateWorm()          //se llama en respuesta a eventos de timer
	{
		if(currentState == WALKING)
		{
			//position = getNewPosition(); //esta función todavía no existe pero ya va a existir
			//al_draw_bitmap(bitmap correspondiente a walking en el tick counter indicado, position)
			break;
		}
		else if(currentState == JUMPING)
		{
			//position = getNewPosition(); //esta función todavía no existe pero ya va a existir
			//al_draw_bitmap(bitmap correspondiente a jumping en el tick counter indicado, position)	
			break;
		}
		if(currentState != STILL)// en still no hace falta incrementar tickCounter
		{
			tickCounter++;
		}
	}
	void Worm::calcNewState(keyCodes) //se llama en respuesta a eventos de teclado
	{
		switch (keyCodes)	 //actualizar el state si lo corresponde

			case:RIGHTKEY
			{
				
			}
			case:UPKEY
			{}
			case:LEFTKEY
			{}
	}

