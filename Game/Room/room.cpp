#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "room.h"
#include "../Card/card.h"


Room::Room(int value, Card *lastCard, Player *p): roomNum(value), player(p){
  // insert last remaining card passed in from previous room into first element of fieldCards[]
  fieldCards[0] = lastCard;

  // fill out fieldCards[] will initial null values
  for (int i=1; i<MAX_CARDS_ON_FIELD; i++){
    fieldCards[i] = nullptr;
  }

  printf("######################################\n  Room #: %d\n#####################################\n",value);
}


// entering new room deals cards (aka fills fieldCards[] array)
void Room::Deal(Card **topCards, int size){
  // value for incrementing topCards[j] ONLY when `if(fieldCards[i]==nullptr)` is true
  int j = 0;

  // loop to search for empty spaces in fieldCards[i] to then place card from topCards[j] into
   for (int i=0; i < size; i++){
    if(fieldCards[i] == nullptr){
      // pull a card from top of deck (using queue) to place into fieldCards[i]
      fieldCards[i] = topCards[j];
      j++;
    } 
    // else if fieldCards[i] already has a card, continue through loop to next index
  }
   // prevents memory leak
   free(topCards);
}

int Room::CardsRemainig(){
  // helper fucntion to help keep track of remaining number of cards on the fieldCards[i]
  int count = 0;
  for(int i=0; i < MAX_CARDS_ON_FIELD; i++){
    if(fieldCards[i] != nullptr){
      count++;
    }
  }
  return count;
}

void Room::Select_Card_Loop(int comp){  // loop to allow player to select card
  while(CardsRemainig() > comp && player->Get_HP() > 0){
    int choice;
    printf("\nPlayer Stats:\n  HP : %d\n  ATK : %d\n",player->Get_HP(), player->Get_ATK());
    printf("\nSelect a card from the field\n");
    Print_fieldCards();
    
    // Only allow numerical number inputs
    if(std::cin >> choice){
      choice --; // convert to 0 index

      // if input == valid index then process the card the user selected
      if(0 <= choice && choice < MAX_CARDS_ON_FIELD && fieldCards[choice] != nullptr){
        player->ProcessCard(fieldCards[choice]);
      
        // free the card from memory
        fieldCards[choice] = nullptr;
      }
      else{
        printf("Error, that option is not allowed");
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad characters
      }
    }

    // message for non-numerical inputs from user
    else{
      printf("Error, you must enter a number");
      std::cin.clear(); // Clear the error flags
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad characters
    }
  }
  printf("\nLAST CARD entering new room!\n");
}

// print out cards to graphicly respresent fieldCards[i] to user
void Room::Print_fieldCards(){
  for (int i=0; i<MAX_CARDS_ON_FIELD; i++){
    if(fieldCards[i] != nullptr){
      switch (fieldCards[i]->getValue()){
        
        case 11:
          printf("%d)  %s of %s\n", i+1, fieldCards[i]->getFace().c_str(), fieldCards[i]->getSuite().c_str());
          break;

        case 12:
          printf("%d)  %s of %s\n", i+1, fieldCards[i]->getFace().c_str(), fieldCards[i]->getSuite().c_str());
          break;

        case 13:
          printf("%d)  %s of %s\n", i+1, fieldCards[i]->getFace().c_str(), fieldCards[i]->getSuite().c_str());
          break;
        
        case 14:
          printf("%d)  %s of %s\n", i+1, fieldCards[i]->getFace().c_str(), fieldCards[i]->getSuite().c_str());
          break;

        default:
          printf("%d)  %d of %s\n", i+1, fieldCards[i]->getValue(), fieldCards[i]->getSuite().c_str());
      }
    } 
  }
  printf("\n\n");
  

// new implemntation to be used for clickable cards in the future
  std::vector<int> card_idx;
  card_idx.reserve(MAX_CARDS_ON_FIELD);
  for (int i=0; i < MAX_CARDS_ON_FIELD; i++){
    if(fieldCards[i] != nullptr){
      card_idx.push_back(i);
    }
  }


    for(int j = 0; j < fieldCards[card_idx[0]]->ascii_vec.size(); j++){
      for(int i : card_idx){
        if(fieldCards[i] != nullptr){
          for(int k=0; k < fieldCards[i]->ascii_vec[0].size(); k++){
            printf("%c",fieldCards[i]->ascii_vec[j][k]);
          }

          printf("   ");
        }
      }
      printf("\n");
    }
  


  printf("\n\n\n");
}

// ONLY call this function AFTER Select_Card_Loop() has finished running
Card *Room::GetLastCard(){
  for(int i=0; i<4; i++){
    if(fieldCards[i] != nullptr){
      return fieldCards[i];
    }
  }
  return nullptr;
}
