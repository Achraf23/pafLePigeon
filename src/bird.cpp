#include "bird.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include "constantes.h"



bird::bird(SDL_Renderer *renderer,double x,double y)
{
    renderer_bird=renderer;
    pos_x=x;
    pos_y=y;
    velocity=0.0001;
    is_up=false;
    width=60;
    height=60;

    SDL_Surface *surface=IMG_Load("flappy.png");
    texture_bird=SDL_CreateTextureFromSurface(renderer_bird,surface);
    //free(surface);
}

bird::~bird()
{

}

void bird::updateDisplay()
{
    //SDL_RenderClear(renderer_bird);

    SDL_Rect position={(int)pos_x,(int)pos_y,width_bird,height_bird};
    SDL_RenderCopy(renderer_bird,texture_bird,NULL,&position);

}

void bird::setState(bool state){is_up=state;}

bool bird::getState(){return is_up;}

void bird::getPosition(double &x,double &y)
{
    x=pos_x;
    y=pos_y;
}

void bird::movement(double acceleration)
{
    velocity+=acceleration;

    if(is_up)
        pos_y-=velocity;
    else
        pos_y+=velocity;


}

bool bird::collision(Pipe p)
{


    if(p.getState())
    {
        double x=pos_x+width_bird;
        double y=pos_y;

        if(y<p.pos_y+height_pipe && x>p.pos_x && x<(p.pos_x)+width_pipe)
            return true;

    }
    else
    {
        double x=pos_x+width_bird;
        double y=pos_y+height_bird;
        // y_flappy sup a y_pipe et x_flappy sup a x_pipe et inf a x_pipe+x_pipe+width_pipe
        if(y>p.pos_y && x>p.pos_x && x<(p.pos_x)+width_pipe)
            return true;

    }

    return false;


}
