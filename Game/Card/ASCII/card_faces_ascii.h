#pragma once
#define ASCII_ROW_MAX 7
#define ASCII_COL_MAX 9
#include<utility>
#include<iostream>
#include <vector>

// locations that need the value changed based on the card
const std::pair<int,int> SUITE_PLACEMENT(3,4);
const std::pair<int,int> TOP_NUM(1,1);
const std::pair<int,int> BOT_NUM(5,7);
// --- A of Spades ---
// +-------+
// |A      |
// |       |
// |   S   |
// |       |
// |      A|
// +-------+
const std::vector<std::vector<char>> ASCII_Template =
{
    {'+', '-', '-', '-', '-', '-', '-', '-', '+'},
    {'|', '#', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', '*', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
    {'|', ' ', ' ', ' ', ' ', ' ', ' ', '#', '|'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+'} 
};

enum class e_SUITE{
  spades,
  hearts,
  clubs,
  diamonds
};
