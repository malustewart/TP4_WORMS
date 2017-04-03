


//CalcNewState();      ver si ponerlo, en caso de que si, donde?
//inicializacion y destruccion de allegro poner en otro archivo.


#include <stdio.h>
#include <allegro5/allegro.h>

#define FPS			50.0
#define LOOKLEFT	-1
#define LOOKRIGHT	 1
#define EXIT		ALLEGRO_KEY_SPACE   //VER SI DEJAR ESO COMO EXIT, Q O QUE
typedef enum { STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING, TOGGLE } wormState; //AGREGUE TOGGLE (ver)
typedef enum { RIGHTKEY, UPKEY, LEFTKEY } keyCode; 


int main(int argc, char **argv) //poner que no reciba nada (AL MENOS QUE queramos que se reciba la cantidad de worms o sus posiciones iniciales, por ej)
{
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	//inicializaciones
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}


	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}


	//JUEGO (logica)
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	Worm w1, w2;
	//llamar aca a los constructores de los DOS worms

	al_start_timer(timer);

	ALLEGRO_EVENT ev;

	do
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)  //REVISAR BIEN ESTO.
		{
			int w1State = w1.getWormState();	// ver en que clase va getWormState
			w1.ContinueAction(w1State);				//ContinueAction tiene que estar adentro de la clase Worms o physics
			
			int w2State = w2.getWormState();	// ver en que clase va getWormState
			w2.ContinueAction(w2State);
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) // Se presionó una tecla
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:					// Flecha izquierda
			{
				switch (w2.currentState)
				{
				case STILL: case FINISHING_WALKING: w2.currentState = WALKING_PENDING; break;
				default: break;
				}
			} break;
			case ALLEGRO_KEY_UP:					//Flecha hacia arriba
			{
				switch (w2.currentState)
				{
				case STILL: w2.currentState = JUMPING; break;
				default: break;
				}
			} break;
			case ALLEGRO_KEY_RIGHT:					//Flecha derecha
			{
				switch (w2.currentState)
				{
				case STILL: case FINISHING_WALKING: w2.currentState = WALKING_PENDING; break;
				default: break;
				}
			} break;
			case ALLEGRO_KEY_A:						//Tecla A
			{
				switch (w1.currentState)
				{
				case STILL: case FINISHING_WALKING: w1.currentState = WALKING_PENDING; break;
				default: break;
				}
			} break;
			case ALLEGRO_KEY_W:						//Tecla W
			{
				switch (w1.currentState)
				{
				case STILL: w1.currentState = JUMPING; break;
				default: break;
				}
			} break;
			case ALLEGRO_KEY_D:						//Tecla D	
			{
				switch (w1.currentState)
				{
				case STILL: case FINISHING_WALKING: w1.currentState = WALKING_PENDING; break;
				default: break;
				}
			} break;
			default: break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_UP)		//Se soltó una tecla
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
			{
				if (w2.currentState == WALKING_PENDING && w2.direction == LOOKLEFT)
				{
					w2.currentState = STILL;
				}
				else if (w2.currentState == WALKING_PENDING && w2.direction == LOOKRIGHT)
				{
					w2.CurrentState = TOGGLE;	//ver si eliminar TOGGLE y que con LOOKLEFT solo se encargue de invertirse!!!!!!!!!!!!!
					w2.direction = LOOKLEFT;
				}
			} break;
			case ALLEGRO_KEY_RIGHT:
			{
				if (w2.currentState == WALKING_PENDING && w2.direction == LOOKRIGHT)
				{
					w2.currentState = STILL;
				}
				else if (w2.currentState == WALKING_PENDING && w2.direction == LOOKLEFT)
				{
					w2.CurrentState = TOGGLE; //ver si eliminar TOGGLE y que con LOOKLEFT solo se encargue de invertirse!!!!!!!!!!!!!
					w2.direction = LOOKRIGHT;
				}
			} break;
			case ALLEGRO_KEY_A:
			{
				if (w1.currentState == WALKING_PENDING && w1.direction == LOOKLEFT)
				{
					w1.currentState = STILL;
				}
				else if (w1.currentState == WALKING_PENDING && w1.direction == LOOKRIGHT)
				{
					w1.CurrentState = TOGGLE;	//ver si eliminar TOGGLE y que con LOOKLEFT solo se encargue de invertirse!!!!!!!!!!!!!
					w1.direction = LOOKLEFT;
				}
			} break;
			case ALLEGRO_KEY_D:
			{
				if (w1.currentState == WALKING_PENDING && w1.direction == LOOKRIGHT)
				{
					w1.currentState = STILL;
				}
				else if (w1.currentState == WALKING_PENDING && w1.direction == LOOKLEFT)
				{
					w1.CurrentState = TOGGLE;	//ver si eliminar TOGGLE y que con LOOKLEFT solo se encargue de invertirse!!!!!!!!!!!!!
					w1.direction = LOOKRIGHT;
				}
			} break;
			default: break;
			}
		}
	} while (ev != EXIT);


	// DESTROYS DE ALLEGRO
	al_destroy_timer(timer);

	al_destroy_event_queue(event_queue);

	return 0;
}

