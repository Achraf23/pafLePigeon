#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include "bird.h"
#include "Pipe.h"
#include <vector>
#include "constantes.h"

using namespace  std;

//const int dimx=350;
//const int dimy=480;


int main(int argc, char *argv[])
{
    vector<int> a;
    a.push_back(1);
    cout << a.at(0);

    SDL_Window *window=NULL;
    SDL_Renderer *renderer=NULL;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "Error: " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window=SDL_CreateWindow("test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                        dimx, dimy,SDL_WINDOW_RESIZABLE);

    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    //auto init=IMG_Init(IMG_INIT_PNG);


    // objects & positions
    double x_initial_position=(double)dimx/2-30;
    double y_initial_position=(double)dimy/2-30;

    bird flappy(renderer,x_initial_position,y_initial_position);

    double x_pipe=(double)dimx;
    double y_pipe=(double)dimy-200;

    Pipe pipe1(renderer,x_pipe,y_pipe,false);
    Pipe pipe2(renderer,x_pipe+250 ,0,true);

    //events & time
    SDL_Event events;
    bool run=true;

    unsigned int lastTime = 0, currentTime;

    Uint32 timeout_jump=0;


    while(run)
    {
        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000) {
            //cout << currentTime << endl;
            lastTime = currentTime;
        }


        SDL_PollEvent(&events);
        if(events.type==SDL_QUIT)
            run=false;
        else
        {
            if(events.key.keysym.scancode==SDL_SCANCODE_SPACE && flappy.pos_y<=dimy-flappy.height)
            {
                flappy.velocity=0.1;
                flappy.setState(true);

                timeout_jump = SDL_GetTicks() + 100;
            }
            else
            {
                if(flappy.getState()==true && SDL_TICKS_PASSED(currentTime,timeout_jump))
                {
                    flappy.setState(false);
                    flappy.velocity=0.0001;
                    //cout << 2;
                }
            }

        }



        //move objects

        if(flappy.pos_y<=dimy-flappy.height && !flappy.collision(pipe1) && !flappy.collision(pipe2))
        {
            flappy.movement(0.0002);
            pipe1.movement();
            pipe2.movement();
            //cout << flappy.pos_y << endl;
            //cout << velocity << endl;
        }





        //UPDATE SCREEN
        SDL_SetRenderDrawColor(renderer,
                   0,0,0,0);
        SDL_RenderClear(renderer);

        flappy.updateDisplay();
        pipe1.updateDisplay();
        pipe2.updateDisplay();


        SDL_SetRenderDrawColor(renderer,
                   255,0,0,0);
        SDL_RenderDrawPoint(renderer,pipe2.pos_x,pipe2.pos_y);
        SDL_RenderDrawLine(renderer,flappy.pos_x,flappy.pos_y,flappy.pos_x+width_bird,flappy.pos_y);
        SDL_RenderDrawLine(renderer,flappy.pos_x,flappy.pos_y,flappy.pos_x,flappy.pos_y+height_resize);
        SDL_RenderDrawLine(renderer,flappy.pos_x,flappy.pos_y+height_resize,flappy.pos_x+width_bird,flappy.pos_y+height_resize);
        SDL_RenderDrawLine(renderer,flappy.pos_x+width_bird,flappy.pos_y,flappy.pos_x+width_bird,flappy.pos_y+height_resize);





        SDL_RenderPresent(renderer);


    }

    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
