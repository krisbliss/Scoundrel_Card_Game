#ifndef DECK_h
#define DECK_h
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../Card/card.h"

/***************************************************************************************************************************************************
 * Deck class and declaration
 *
***************************************************************************************************************************************************/

/*** Queue for deck vector ***/
class Deck{
  private:
    int size;
    int front, rear;
    Card **deck;
    std::vector<Card *> toShuffle;

  public:
    Deck();
    void Enqueue(Card *card); // aka put at bottom of deck
    Card *Dequeue(); // used to fill getTop3
    int IsEmpty();
    Card **GetTopCards(int size); // getter function to return arr[] of 3 cards 

};

/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

#endif
