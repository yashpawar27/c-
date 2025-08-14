#include<cctype>
#include<stdexcept>
#include "Card.h"
using std::string, std::isalnum;


bool alphaNum(string str);
Card::Card(string rank, string suit) : rank(rank), suit(suit), timesPlayed(0) {

    if(! alphaNum(rank) || !alphaNum(suit) || rank.size() == 0 || suit.size() == 0) {
        throw std::invalid_argument("bad rank or suit");
    }

    this -> rank = rank;
    this -> suit = suit;
    this -> timesPlayed = 0;
}

string Card::getRank(){
    return rank;
}

string Card::getSuit(){
    return suit;
}

int Card::getTimesPlayed(){
    // TODO: implement getter
    return timesPlayed;
}

bool Card::canBePlayed(string currentRank, string currentSuit){
    // TODO: return whether or not this card can legally be played given that the previous card
    //  played had rank currentRank and suit currentSuit
    return rank == currentRank || suit == currentSuit || rank == "8";
}

bool alphaNum(string str) {
    for(unsigned int i = 0; i < str.size(); i++) {
        if(!isalnum(str.at(i))) {
            return false;
        }
    }
    return true;
}

//You don't need to modify this
void Card::play(){
    timesPlayed++;
}