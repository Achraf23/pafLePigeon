#ifndef OBSTACLE_H
#include "Pipe.h"


class obstacle
{
public:
    Pipe pipe_up;
    Pipe pipe_down;

    obstacle();
    ~obstacle();
};

#endif // OBSTACLE_H
