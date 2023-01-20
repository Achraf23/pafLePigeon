#include "PipeContainer.h"
#include <iostream>

PipeContainer::PipeContainer()
{
}

PipeContainer::PipeContainer(SDL_Renderer *renderer)
{
    renderer_container=renderer;
}


PipeContainer::~PipeContainer()
{

}

void PipeContainer::move()
{
    //if(*(table.begin()).pos_x<-30)
      //  std::cout << 1;

    if(table.at(0).pos_x<-30)
    {
        table.erase(table.begin()); // enlever tuyau haut
        table.erase(table.begin()+1); // enlever tuyau bas
        addObstacle();
    }

    for(iter=table.begin();iter!=table.end();iter++)
    {
        (*iter).movement();
    }

}

void PipeContainer::addObstacle()
{
    Pipe *p_down=new Pipe(renderer_container,705,280,false);
    Pipe *p_up=new Pipe(renderer_container,705,0,true);

    table.push_back(*p_down);
    table.push_back(*p_up);


}

void PipeContainer::updateDisplay()
{
    //iter=table.cbegin();
    for(iter=table.begin();iter!=table.end();iter++)
    {
        //*(iter).updateDisplay();

    }
}
