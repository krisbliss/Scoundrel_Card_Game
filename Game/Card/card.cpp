#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "card.h"

/*********************************************************************
 *  Definition of Card classes and functions
*********************************************************************/

 /*** Base class constructor and other functions ***/
Card::Card(int value, std::string suite) : value(value), suite(suite){
  // Constructor switch case to determine if current card object needs to have non-null face str value
  switch(value){
    case 11:
      face = "jack";
      break;
    case 12:
      face = "queen";
      break;
    case 13:
      face = "king";
      break;
    case 14:
      face = "ace";
      break;
    default: // default value of face will be null-str if value < 11
      face = "\0"; 
  }
}

int Card::getValue(){
  return value; 
}

std::string Card::getSuite(){
  return suite;
}

std::string Card::getFace(){
  return face; 
}

/*******************************************************************************
* Sub Class  constructors 
  * NOTE: MUST call the Base class' constructor inorder to compile (beacuse there is no paramterless constructor and a the Base class constructor MUST run before the Sub class constructor) 
  * && has added benifit of directly assigning value to `int value` (via Card(int) constructor) in same line as Subclass constructor 
*******************************************************************************/
Diamonds::Diamonds(int x, std::string s) : Card(x,s){
  // Test print durring constructor in Deck object 
  if(value > 10){
    printf("%s of %s\n",face.c_str(),suite.c_str());
  }
  else{
    printf("%d of %s\n",value,suite.c_str());
  }
}

Spades::Spades(int x, std::string s) : Card(x,s){  // Example, to use initializer list to assign to `int value` (variable member of base class Card)... We can the constructor function of Card. i.e. `Card(int value)`
  // Test print durring constructor in Deck object 
  if(value > 10){
    printf("%s of %s\n",face.c_str(),suite.c_str());
  }
  else{
    printf("%d of %s\n",value,suite.c_str());
  }
}

Clubs::Clubs(int x, std::string s) : Card(x,s){
  // Test print durring constructor in Deck object 
   if(value > 10){
    printf("%s of %s\n",face.c_str(),suite.c_str());
  }
  else{
    printf("%d of %s\n",value,suite.c_str());
  }
}

Hearts::Hearts(int x, std::string s) : Card(x,s) {
  // Test print durring constructor in Deck object 
   if(value > 10){
    printf("%s of %s\n",face.c_str(),suite.c_str());
  }
  else{
    printf("%d of %s\n",value,suite.c_str());
  }
}

/*********************************************************************
 * Player_ATK_Minus()
 *  - Will just return negative number, will be up to PLAYER class to determine if atk or hp will be minused
*********************************************************************/
int Clubs::Player_ATK_Minus(){
  return (-1 * value);
}

int Spades::Player_ATK_Minus(){
  return (-1 * value);
}

/*********************************************************************
 * Player_ATK_Plus()
 *  - Will just return negative number, will be up to PLAYER class to determine if atk power
*********************************************************************/
int Diamonds::Player_ATK_Plus(){
  return (value);
}

/*********************************************************************
 * Player_HP_Plus()
 *  - Will just return positive number, will be up to PLAYER class to determine hp restore
*********************************************************************/
int Hearts::Player_HP_Plus(){
  return (value);
}

