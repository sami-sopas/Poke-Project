#ifndef MOVEMENT_H_INCLUDED
#define MOVEMENT_H_INCLUDED

class Movement{
private:
    int power;
    int status;

public:
    Movement();
    Movement(const Movement&);
    void setPower(const int&);
    void setStatus(const int&);

    int getPower();
    int getStatus();

    Movement& operator = (const Movement&);

};

#endif // MOVEMENT_H_INCLUDED
