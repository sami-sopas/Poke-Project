#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include<string>

class Pokemon{
private:
    int totalHealth;
    int currentHealth;
    int attack;
    int defense;
    int speed;
    int status;
    int turnsAsleep;
    std::string name;

public:
    Pokemon();
    Pokemon(const Pokemon&);

    void setTotalHealth(const int& );
    void setCurrentHealth(const int& );
    void setAttack(const int& );
    void setDefense(const int& );
    void setSpeed(const int& );
    void setStatus(const int& );
    void setTurnsAsleep(const int&);
    void setName(const std::string&);

    int getTotalHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
    int getSpeed();
    int getStatus();
    int getTurnsAsleep();
    std::string getName();

    Pokemon& operator = (const Pokemon&);

};

#endif // POKEMON_H_INCLUDED
