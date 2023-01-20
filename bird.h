#ifndef BIRD_H
#define BIRD_H

#include <SDL2/SDL.h>
#include "Pipe.h"

class bird
{
private:
    bool is_up;
    SDL_Texture *texture_bird;
    SDL_Renderer *renderer_bird;

public:

    double pos_x;
    double pos_y;
    int width;
    int height;
    double velocity;

    bird(SDL_Renderer *renderer,double x,double y);
    ~bird();
    void updateDisplay();
    void setState(bool state);
    bool getState();
    void getPosition(double &x,double &y);
    void movement(double acceleration);
    bool collision(Pipe p);
};
#endif // BIRD_H

