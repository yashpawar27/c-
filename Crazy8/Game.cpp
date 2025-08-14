#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "Game.h"
using std::string, std::vector, std::endl, std::getline, std::cout, std::cin
,std::istringstream, std::stringstream, std::ifstream;

bool validSuit(string s, vector<string> suit);
bool validRank(string r, vector<string> rank);
void reverseCardPile(std::vector<Card*> &pile);

Game::Game(): players({}), suits({}), ranks({}), 
    deck({}), drawPile({}), discardPile({}) {}

void Game::loadDeckFromFile(string filename){
    // TODO: initialize suits, ranks, deck, and drawPile from the given file

    ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Invalid File");
    }

    string line;
    getline(file, line); // read a line from file & assign it to line

    string str;
    stringstream ss(line); //enter the line into a stringstream

    bool eight = false;

    while (ss >> str) { // while there's more words in the stream, set the word to str
        // Process each word
        suits.push_back(str); //push str
    }
    
    getline(file, line); // Read a line from file and assign it to line
    ss.clear(); // clears input
    ss.str(line); // enter the line into a stringstream

    //checks if an 8 is present
    while (ss >> str) {
        // Process each word
        ranks.push_back(str);
        if(str == "8") {
            eight = true;
        }
    }

    // throws error is 8 isn't present
    if(!eight) { // If there is no 8 in the deck, throw an error
        throw std::runtime_error("No 8 in the deck");
    }

    //creates cards
    string r, s, g;
    int cards = 0;
    while(getline(file, line)) { // Read a line from file and assign it to line
        ss.clear(); // clears ss
        ss.str(line); // enter the line into a stringstream
        if(!(ss >> r >> s)){
            throw std::runtime_error("Missing Data");
        }

        if(r == "" || s == "") {
            throw std::runtime_error("Missing Data");
        }

        if(!validRank(r, ranks)) {
            throw std::runtime_error("Invalid Rank");
        }
        if(!validSuit(s, suits)) {
            throw std::runtime_error("Invalid Suit");
        }

        if(ss >> g) {
            throw std::runtime_error("Extra Data");
        }

        //tries to create the card and push it into a deck
        try {
        deck.push_back(new Card(r, s));
        } catch(std::exception &e) {
            throw std::runtime_error("bad card");
        }
        
        //adds the new card to the drawPile
        drawPile.insert(drawPile.begin()+0, deck.at(cards));
        cards++; // increases card count

    }
    // reverseCardPile(drawPile);
}

void Game::addPlayer(bool isAI){
    // TODO: add a new player to the game
    players.push_back(new Player(isAI));
}

void Game::drawCard(Player* p){
    // TODO: Move the top card of the draw pile to Player p's hand
    // If the draw pile is empty, flip the discard pile to create a new one

    if(drawPile.size() == 0) {

        if(discardPile.size() < 2) {
            throw std::runtime_error("Hello World");
        }

        cout << "Draw pile, empty, flipping the discard pile." << endl;
        Card* top = discardPile.back();
        discardPile.pop_back();
        
        for(unsigned int i = discardPile.size()-1; true; i--) {
            drawPile.push_back(discardPile.at(i));
            if(i==0) {
                break;
            }
        }
        discardPile.clear();
        discardPile.push_back(top);
        top = nullptr;
    }

    p->addToHand(drawPile.at(drawPile.size()-1));
    drawPile.erase(drawPile.begin()+drawPile.size()-1);
}

Card* Game::deal(int numCards){
    // TODO: Flip the top card of the draw pile to be the initial discard
    // then deal numCards many cards to each player
    discardPile.push_back(drawPile.back());
    drawPile.pop_back();
    
    for(int j = 0; j < numCards; j++) { // goes through the players vector
         for(unsigned int i = 0; i < players.size(); i++){ // adds the number of cards to each player
            drawCard(players.at(i));
        }
    }

    return discardPile.back(); // return the last pushed card from the discardPile
}

string Game::mostPlayedSuit(){
    // TODO: Return the suit which has been played the most times
    // if there is a tie, choose any of the tied suits

    vector<int> s(suits.size()); //vector containing numbers per suit

    for(unsigned int i = 0; i < deck.size(); i++) {
        for(unsigned int j = 0; j < suits.size(); j++) {
            if(deck.at(i) -> getSuit() == suits.at(j)) {
                s.at(j) += deck.at(i) -> getTimesPlayed();
            }
        }
    }
    
    int highestIdxSuit = 0;

    for(unsigned int i = 0; i < s.size(); i++) {
        if(s.at(i) > s.at(highestIdxSuit)) {
            highestIdxSuit = i;
        }
    }

    return suits.at(highestIdxSuit);
}

int Game::runGame(){
    // TODO: Run the game and return the number of the winning player
    // string file;
    int numPlayers = players.size();
    // int numCards = players.at(0)->getHandSize();

    // cout << "Enter number of players: " << endl;

    // bool validPlayers = false;
    // while (!validPlayers) {
    //     try {
    //         cin >> numPlayers;
    //         validPlayers = true;
    //     } catch (std::exception e) {
    //         cout << "Please enter a positive number" << endl;
    //     }
    // }

    // string playerType = "na";
    // for(unsigned int i = 0; i < numPlayers; i++) {
    //     cout << "Is player " << i << " an AI? (y/n)" << endl;
    //     while(playerType != "y" || playerType != "n") {
    //         try {
    //             cin >> playerType;
    //         } catch (std::exception e) {
    //             playerType = "na";
    //             cout << "Please enter y or n" << endl;
    //         }
    //     }
    //     addPlayer(playerType == "y");
    //     playerType = "na";
    // }
    
    // numCards = -1;
    // cout << "How many cards should each player start with?" << endl;
    // while (!(numCards > 0)) {
    //     try {
    //         cin >> numCards;
    //     } catch (std::exception e) {
    //         numCards = -1;
    //         cout << "Please enter a positive number" << endl;
    //     }
    // }
    
    // Card* played = deal(numCards); //discarded

    
    string cRank = discardPile.back()->getRank();
    string cSuit = discardPile.back()->getSuit();
    Card* temp = nullptr;
    string prevSuit = cSuit;
    // cout << "The initial discard is " << cRank << " " << cSuit << endl;

    int playerTurn = 0;
    while(true) {
        cout << "Player " << playerTurn%numPlayers <<"'s turn!" << endl;
        // cout << "playerTurnnumPlayers: " << playerTurn%numPlayers << endl;
        temp = players.at(playerTurn%numPlayers) -> playCard(suits, cRank, cSuit);


        if(temp != nullptr) {
            discardPile.push_back(temp);
        }

        // cout << "Player " << playerTurn%numPlayers <<" played a card" << endl;  //Delete later
        if(temp != nullptr) {
            cout << "Player " << playerTurn%numPlayers << " plays " << temp->getRank() << " " << temp->getSuit();

            if(temp->getRank() == "8") {
                cout << " and changes the suit to " << cSuit;
            }
            cout << "." << endl;
        }

        if(players.at(playerTurn%numPlayers)->getHandSize() == 0) {
            // cout << "Player " << playerTurn%numPlayers << " wins!" << endl;
            // cout << "The most played suit was " << mostPlayedSuit() << endl;
            temp = nullptr;
            return playerTurn%numPlayers;
        }

        if(temp == nullptr) {

            try {
                drawCard(players.at(playerTurn%numPlayers));
            } catch(std::exception &e) {
                cout << "Player " << playerTurn%numPlayers<< " cannot draw a card." << endl;
                // cout << "The game is a draw!" << endl;
                return -1;
            }
            
            cout << "Player " << playerTurn%numPlayers << " draws a card." << endl;
            
        }

        playerTurn++;
        prevSuit = cSuit;
    }
}

//Destructor--Deallocates all the dynamic memory we allocated
//You shouldn't touch this
Game::~Game(){
    for (unsigned int i = 0; i < deck.size(); i++){
        delete deck.at(i);
    }
    for (unsigned int i = 0; i < players.size(); i++) {
        delete players.at(i);
    }
}


bool validSuit(string suit, vector<string> suits) {
    for (unsigned int i = 0; i < suits.size(); i++) {
        if (suits.at(i) == suit) {
            return true;
        }
    }
    return false;
}  // Check if the suit is valid

bool validRank(string rank, vector<string> ranks) {
    for (unsigned int i = 0; i < ranks.size(); i++) {
        if (ranks.at(i) == rank) {
            return true;
        }
    }
    return false;
}  // Check if the rank is valid

void reverseCardPile(std::vector<Card*> &pile) { 
    Card* b = nullptr;
    for(unsigned int i = 0; i < pile.size(); i++) {

        b = pile.at(i);
        pile.at(i) = pile.at(pile.size()-i-1);
        pile.at(pile.size()-i-1) = b;
       
    }
    b = nullptr;
}