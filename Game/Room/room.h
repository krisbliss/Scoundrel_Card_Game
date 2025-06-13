#ifndef ROOM_H
#define ROOM_H
#include "../Card/card.h"
#include "../Player/player.h"

/***************************************************************************************************************************************************
 * Room to hold Player() and Deck() objects. Will facilitate player actions, taking cards of top of deck, and place cards back into deck.
 *  1) take in pointers for Deck() and Player() objects + 1 card 
 *      -- first instatiation will be first card off top of deck
 *      -- rest of the instatiations will take last remaining card from previous Room() object
 *
 *  2) 
***************************************************************************************************************************************************/

class Room{
  private:
    int roomNum;
    Card* fieldCards[4];
    Player *player; // Passing in player from main.cpp (To delete this object before deconstructor, set p = nullptr first)

  public:
    Room(int value, Card *lastCard, Player *p);
    int GetRoomNum();
    Card *GetLastCard();
    int CardsRemainig();
    void Print_fieldCards();
    // ~Room();
    
    void Deal(Card **topCards, int size); // entering new room deals cards (aka fills fieldCards[] array)
    void Select_Card_Loop(int comp); // loop to allow player to select card (will use Player.getCard() to store card in players hand)
};

#endif
