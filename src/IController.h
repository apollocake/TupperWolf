#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H
#include "IMovement.h"
class IController
{
public:
    IController(){};
    IController(IMovement*& wm){}
    virtual ~IController(){}
    virtual void left()=0;
    virtual void right()=0;
    virtual void backward()=0;
    virtual void forward()=0;
};
#endif
