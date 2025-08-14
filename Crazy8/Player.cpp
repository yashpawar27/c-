#include<iostream>
#include<sstream>
#include "Player.h"
using std::vector, std::string, std::size_t, std::exception, std::cout, std::cin, std::endl;


bool playerHasCard(string num, string suit, std::vector<Card*> hand);

Player::Player(bool isAI) : isAI(isAI), hand({}) {}

void Player::addToHand(Card* c){
    // TODO: Add the card c to the player's hand
    hand.push_back(c);
}

size_t Player::getHandSize(){
    // TODO: Implement getter
    return hand.size();
}

std::string Player::getHandString(){
    // TODO: Implement getter
    string out = "";

    for (unsigned int i = 0; i < hand.size(); i++){
        out += hand.at(i) -> getRank() + " " + hand.at(i)->getSuit();
        if(i<hand.size()-1) {
            out+=", ";
        }
    }
    return out;
}

Card* Player::playCard(vector<string> const& suits, string& currentRank, string& currentSuit){
    // TODO: Choose a card to play and return the chosen card. Update currentRank and currentSuit.

    Card* out = nullptr;

    if(!isAI) { // Human

        cout << "Your hand contains: " << getHandString() << endl;
        cout << "The next card played must be a " << currentRank << " or " << currentSuit << endl; 
        cout << "What would you like to play? (enter \"draw card\" to draw a card)" << endl;

        string num = "-1";
        string type = "";
        // bool validplay = false;

        while(true) {
            cin >> num >> type;
            if(num == "draw" && type == "card") {
                return nullptr; // (nullptr)
            }
            bool found = false;
            for(unsigned int i = 0; i < hand.size(); i++) { // finds the card in the hand, erases and returns it
                if(hand.at(i)->getRank() == num && hand.at(i)->getSuit() == type) {
                    found = true;
                    out = hand.at(i);
                    if(out->canBePlayed(currentRank, currentSuit)){
                        currentRank = hand.at(i)->getRank();
                        hand.erase(hand.begin() + i);
                        out -> play();

                        if(currentRank == "8") { // checks crazy 8 is played ******** // declare new suit
                            string newSuit = "";
                            cout << "What suit would you like to declare?" << endl;
                            bool validSuit = false;
    
                            while(!validSuit){
                                cin >> newSuit;
                                for(unsigned int j = 0; j < suits.size(); j++) {
                                    if(suits.at(j) == newSuit) {
                                        currentSuit = newSuit;
                                        validSuit = true;
                                    }
                                }
                                if(!validSuit){
                                    cout << "That's not a suit in this deck. Try again." << endl;
                                }
                            }
                            //checks if a valid suit is declared
                        } 
                        else {
                            currentSuit = out->getSuit();
                        }
                        return out;
                    }
                    else{
                        cout << "You can't play that card. Try again." << endl;
                    }
                   
                } 
            }
            if(!found){
                cout << "That's not a card you have. Try again." << endl;
            }
        }

        

    } else { // is AI
        Card* out = nullptr;

        for(unsigned int i = 0; i < hand.size(); i++) { // checks for the next valid card
            if(hand.at(i)->getRank() == currentRank || hand.at(i)->getSuit() == currentSuit ||
             hand.at(i)->getRank() == "8") {
                currentRank = hand.at(i)->getRank();
                currentSuit = hand.at(i)->getSuit();
                out = hand.at(i);
                hand.erase(hand.begin() + i);
                out -> play();
                return out;
            }
        }
    }
    

    return nullptr; // player draws a card (nullptr)
}

bool playerHasCard(string num, string suit, std::vector<Card*> hand) {
    for(unsigned int i = 0; i < hand.size(); i++) {
        if(hand.at(i) -> getRank() == num && hand.at(i) -> getSuit() == suit) {
            return true;
        }
    }
    cout << "That's not a card you have. Try again." << endl;
    return false;
}