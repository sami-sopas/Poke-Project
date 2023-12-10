#include "movement.h"

Movement::Movement(){}

Movement::Movement(const Movement& m): power(m.power),status(m.status){}

void Movement::setPower(const int& p){
    this->power=p;
}

void Movement::setStatus(const int& st){
    this->status=st;
}

int Movement::getPower(){
    return this->power;
}

int Movement::getStatus(){
    return this->status;
}

Movement& Movement::operator=(const Movement& m){
    power = m.power;
    status = m.status;

    return *this;
}
