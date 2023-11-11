#include "Pipe.h"
#include <SDL2/SDL_image.h>
#include<iostream>
#include "constantes.h"


Pipe::Pipe()
{
}

Pipe::Pipe(SDL_Renderer *renderer,double x,double y,bool state)
{
    pos_x=x;
    pos_y=y;
    up=state;

    renderer_pipe=renderer;
    SDL_Surface *surface=NULL;

    if(up)
        surface=IMG_Load("pipeUp.png");
    else
        surface=IMG_Load("pipe.png");

    if(!surface)
        std::cout << "problem pipe";
    else
    {
        texture_pipe=SDL_CreateTextureFromSurface(renderer_pipe,surface);
        //free(surface);
    }



}

bool Pipe::getState(){return up;}

Pipe::~Pipe()
{

}

void Pipe::movement()
{
    pos_x-=0.05;
    if(pos_x<=0)
        pos_x=dimx;

}


void Pipe::updateDisplay()
{

    SDL_Rect position={(int)pos_x,(int)pos_y,width_pipe,height_pipe};
    SDL_RenderCopy(renderer_pipe,texture_pipe,NULL,&position);
}



