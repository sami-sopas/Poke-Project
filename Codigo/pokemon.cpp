#include "pokemon.h"

Pokemon::Pokemon(){}

Pokemon::Pokemon(const Pokemon& p):totalHealth(p.totalHealth),currentHealth(p.currentHealth),attack(p.attack),defense(p.defense),speed(p.speed),status(p.status){}

void Pokemon::setTotalHealth(const int& h){
    this->totalHealth=h;
}

void Pokemon::setCurrentHealth(const int& ch){
    this->currentHealth=ch;
}


void Pokemon::setAttack(const int& a){
    this->attack=a;
}

void Pokemon::setDefense(const int& d){
    this->defense=d;
}

void Pokemon::setSpeed(const int& s){
    this->speed=s;
}

void Pokemon::setStatus(const int& st){
    this->status=st;
}

void Pokemon::setName(const std::string& n){
    name=n;
}


int Pokemon::getTotalHealth(){
    return this->totalHealth;
}

int Pokemon::getCurrentHealth(){
    return this->currentHealth;
}


int Pokemon::getAttack(){
    return this->attack;
}

int Pokemon::getDefense(){
    return this->defense;
}

int Pokemon::getSpeed(){
    return this->speed;
}

int Pokemon::getStatus(){
    return this->status;
}

std::string Pokemon::getName(){
    return this->name;
}


void Pokemon::setTurnsAsleep(const int& ta){
    this->turnsAsleep=ta;
}

int Pokemon::getTurnsAsleep(){
    return this->turnsAsleep;
}


Pokemon& Pokemon::operator=(const Pokemon& p){
    totalHealth=p.totalHealth;
    currentHealth=p.currentHealth;
    attack=p.attack;
    defense=p.defense;
    speed=p.speed;
    status=p.status;

    return *this;
}
