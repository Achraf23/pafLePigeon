#ifndef PIPE_H
#define PIPE_H

#include <SDL2/SDL.h>

class Pipe
{
private:
    SDL_Texture *texture_pipe;
    bool up;


public:

    SDL_Renderer *renderer_pipe;
    double pos_x;
    double pos_y;
    int width;
    int height;

    Pipe();
    Pipe(SDL_Renderer *renderer,double x,double y,bool up);
    ~Pipe();
    void movement();
    void updateDisplay();
    bool getState();

};

#endif // PIPE_H

