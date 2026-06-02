#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "./Deck/deck.h"
#include "./Room/room.h"
#include "./Card/card.h"
#include "./Player/player.h"

int main(int argc, char *argv[]){

/*
 *  1) make Deck() obj
 *  2) make Player() obj
 *  3) make Room(1) obj
 *
 * 4) while(!deck.isEmpty()){
 *    
 *   
 *      //continue with core gameplay loop
 *      while(room.CardsRemainig() > 1){
 *        // player selects cards
 *            -- player selecting cards can do 1 of 3 things
 *              1) get health (grabing a hearts)
 *              2) fight monster (grabing a club OR spade)
 *              3) pickup weapon (grabing a diamond)
 *      }
 *
 *    // after room is complete, prep next room for gameplay loop
 *    Room newRoom = new Room(room.GetRoomNum(),room.getLastCard());
 *    delete room;
 *    room = newRoom;
 *   }
 *
 */

  Deck d;
  Player p;

  bool win_state = false;
  int roomNum = 0;
  Card *lastCard = d.Dequeue(); // pre-populate holding var with top card from deck
 
  while (!d.IsEmpty() && p.Get_HP() > 0 && roomNum < 10){
    // init room
    Room r(++roomNum,lastCard,&p);
    
    // populate fieldCards
    r.Deal(d.GetTopCards(3),3);

    // player driver
    r.Select_Card_Loop(1);

    // save last card player did NOT select in holding var
    lastCard = r.GetLastCard();
  }
  
  // fence post for last room when deck is isEmpty
  if(p.Get_HP() > 0 && d.IsEmpty()){
    Room r(++roomNum,lastCard,&p);
    r.Select_Card_Loop(0);
    if(p.Get_HP() > 0){
      win_state = true;
    }
  }
  

  // check win state
  if (win_state){
    printf(" \n YOU WIN! \n");
  }
  else{
    printf("Game Over :(\nBetter luck nextime!");
  }

  return 0;
}
