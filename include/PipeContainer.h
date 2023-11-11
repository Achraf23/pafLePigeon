#ifndef PIPECONTAINER_H
#define PIPECONTAINER_H

#include <vector>
#include "Pipe.h"



class PipeContainer
{
private:

    std::vector<Pipe> table;
    std::vector<Pipe>::iterator iter;
    SDL_Renderer *renderer_container;


    void addObstacle();

public:

    PipeContainer();
    PipeContainer(SDL_Renderer *renderer);
    ~PipeContainer();
    void move();
    void updateDisplay();

};

#endif // PIPECONTAINER_H

