// #include <stdio.h>
// #include <stdlib.h>
// #include <iostream>
// #include <vector>
#include <random>
#include <algorithm>
#include "deck.h"

/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

Deck::Deck() : size(0){ 
  const int MIN_CARD_VALUE = 2; // Smallest possible number card for standard 52 card deck 
  const int MAX_CARD_VALUE = 14; // 14 == Ace
  
  // generate size of deck while creating deck vector
  std::cout << std::endl <<"Generated Deck of Card" << std::endl;
  for(int i = MIN_CARD_VALUE; i <= MAX_CARD_VALUE; i++){ // static numbers for 2 - ace cards (11-14 == jack - ace)
    toShuffle.push_back( new Hearts(i,"hearts") );
    toShuffle.push_back( new Spades(i,"spades") );
    toShuffle.push_back( new Clubs(i,"clubs") );
    toShuffle.push_back( new Diamonds(i,"diamonds") );
    size += 4;
  }

  // final array where cards will be stored
  deck = new Card*[size];
  printf("\n\n"); // spacer print (can be deleted later)
/* NOTE : Random functions copied from internet.... read more about how random and mt19937 work
    * classes imported from <random> header 
  */
  std::random_device rd;  // creates seed in form of class (will be a new seed every time)
  std::mt19937 g(rd());   // Mersenne Twister 19937 genertaor which take a class seed as arg

  // using built in shuffle functions of vector
  std::shuffle(toShuffle.begin(), toShuffle.end(), g);

  std::cout << "shuffled numbers" << std::endl; 
  // TEST print deck of cards
  int i = 0;
  for(Card *n : toShuffle){
    deck[i] = n;
    std::cout << deck[i]->getValue() << " of " << deck[i]->getSuite() <<std::endl; // test print statment for proof that deck is getting shuffled
    i++;
  }
  printf("\nsize of deck = %d\n",i); // test print to see size of test deck generated

  // init values for queue
  rear = size-1;
  front = 0;

  printf("Front == %d , Rear == %d\n",front, rear);
}

void Deck::Enqueue(Card *card){
  if((rear+1) % size == front){
    printf("\nQueue is full\n");
  }

  else{
    rear = (rear+1)%size;
    deck[rear] = card;
  }
}

Card *Deck::Dequeue(){
  Card *res = nullptr;
  if(front == rear){
    printf("\n\nDeck is empty\n\n");
  }

  else{
    res = deck[front];
    front = (front+1) % size; 
  }
  return res;
}

int Deck::IsEmpty(){
  return(front == rear);
}

Card **Deck::GetTopCards(int size){
  Card **topCards = (Card**)malloc(sizeof(Card*)*size); 
  for(int i=0; i<size; i++){

    // NOTE: Need to assgin nullptr 
    topCards[i] = Dequeue();
  }
  return topCards;
}

/***************************************************************************************************************************************************/
/***************************************************************************************************************************************************/

