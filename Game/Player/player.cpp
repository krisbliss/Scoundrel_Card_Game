#include <stdio.h>
#include "player.h"

// constructor 
Player::Player() : hp(20), atk(0){}

// Subtract_ATK after attacking (aka selects) Spade or Club card
void Player::Subtract_ATK(int damage){
  int compare = atk;
  int new_damage = (damage - atk) > 0 ? damage - atk : 0;
  atk = (atk - damage) > 0 ? atk - damage : 0;

  printf("Player's ATK - %d\n", compare - atk);
  
  //player looses all atk power and remining value > 0, then call Subtract_HP(ramining_value)
  if (atk == 0 && new_damage > 0){
      Subtract_HP(new_damage);
  }
}

// Subtract_HP ONLY inside of Subtract_ATK WHEN player atk == 0 
void Player::Subtract_HP(int damage){
  int compare = hp;
    hp = (hp - damage) > 0 ? hp - damage : 0;
  printf("Player's HP - %d\n", compare - hp);
}

// Add_HP when player p
void Player::Add_HP(int value){
  int compare = value;
  while(hp < 20 && value > 0){
    hp ++;
    value --;
  }
  printf("Player's HP + %d\n", compare - value);
}

// Add_ATK when player selects a Diamond card
void Player::Add_ATK(int value){
  atk += value;
  printf("Player's Atk + %d\n", value);
}

// Object interface to print current player atk
int Player::Get_ATK(){
  return atk;
}

// Object interface to print current player hp
int Player::Get_HP(){
  return hp;
}

void Player::ProcessCard(Card *card){
  if(card != nullptr){
    if (card->getSuite() == "diamonds"){
      Add_ATK(card->getValue());
    }  

    else if(card->getSuite() == "hearts"){
      if(hp < 20){
        Add_HP(card->getValue());
      }
    }
    else if(card->getSuite() == "spades"){
      Subtract_ATK(card->getValue());
    }

    else if(card->getSuite() == "clubs"){
      Subtract_ATK(card->getValue());
    }
  }
  // free the memory
  delete card;
}

