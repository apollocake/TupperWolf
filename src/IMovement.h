#ifndef I_MOVEMENT_H
#define I_MOVEMENT_H
class IMovement
{
public:
    IMovement(){}
    virtual ~IMovement(){}
    virtual void left()=0;
    virtual void right()=0;
    virtual void backward()=0;
    virtual void forward()=0;
    virtual void setPower(byte power)=0;
};
#endif
