#include "WormMovement.hpp"
#include "worm.hpp"

class Worm; 

WormMovement::WormMovement(float _jumpV0, float _jumpAngle, float _gravity, float _walkingV0)
{
    jumpV0 = _jumpV0;
    jumpAngle = _jumpAngle;
    gravity = _gravity;
    walkingV0 = _walkingV0;
}
void WormMovement::updatePosition(Worm* w)
{
    //aca es donde se calcula la nueva posicion
}
