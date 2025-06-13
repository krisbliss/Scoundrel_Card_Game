#ifndef CARD_H
#define CARD_H
#include <string>

/***************************************************************************************************************************************************
 * Card declerations
***************************************************************************************************************************************************/

/*** Base Card class and Suites that will inherate based Card ***/ 
class Card{
  protected: // MUST use protected instead of `private` in order to allow for sub classes to have a version on the variable `int value`
    int value;
    std::string suite;
    std::string face;

  public:
    Card(int value, std::string suite);
    int getValue();
    std::string getSuite();
    std::string getFace();
};

/***************************************************************************************************************************************************
 * Subclasses to handel suites and values
***************************************************************************************************************************************************/

// Hearts == Health Cards
class Hearts : public Card{
  public:
    Hearts(int x, std::string s); 
    int Player_HP_Plus();
};

// Clubs == Enemie Cards
class Clubs : public Card{
  public:
    Clubs(int x, std::string s);
    int Player_ATK_Minus();
};

// Spades == Enemie Cards
class Spades : public Card{
  public:
    Spades(int x, std::string s);
    int Player_ATK_Minus();
};

// Diamonds == Player Weapon Cards
class Diamonds : public Card{
  public:
    Diamonds(int x, std::string s); 
    int Player_ATK_Plus();
};

#endif // !CARD_H
