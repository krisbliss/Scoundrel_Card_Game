#ifndef PLAYER_H
#define PLAYER_H
#include "../Card/card.h"

class Player{
  private:
    int hp;
    int atk;
    
  public:
    Player();
    void ProcessCard(Card *card);
    void Subtract_ATK(int value);
    void Subtract_HP(int value);
    void Add_HP(int value);
    void Add_ATK(int value);
    int Get_ATK();
    int Get_HP();
};

#endif
