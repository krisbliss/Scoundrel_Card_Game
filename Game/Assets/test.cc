#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "card_faces.h"

int main(int argc, char *argv[]){
  for(int i=0; i < ROW; i++){
    for(int j=0; j < COL; j++){
      printf("%c",S_A[i][j]);
    }
    std::cout << std::endl;
  } 
  return 0; 
}

