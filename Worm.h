#ifndef WORM_H
#define WORM_H

#include <cstdint>

#define LOOKLEFT -1
#define LOOKRIGHT 1

typedef enum {STILL, WALKING_PENDING, WALKING, FINISHING_WALKING, JUMPING, FINISHING_JUMPING} wormStates;
typedef enum {RIGHTKEY, UPKEY, LEFTKEY} keyCode; //no deberia estar aca sino en otro archivo, pero momentaneamente esta aca loco

class Worm
{
    public:
        Worm();
        void updateWorm();
        void calcNewState(keyCodes);
    protected:
    private:
        uint position;  //deberia ser del tipo Point, despues cambiar
        uint direction; //puede ser LOOKLEFT o LOOKRIGHT
        wormStates currentState;
        uint frameCount;
};

#endif // WORM_H
