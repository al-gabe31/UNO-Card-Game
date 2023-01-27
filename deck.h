#ifndef DECK
#define DECK
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "card.h"
using namespace std;

// Number of decks that will be used in the game (default 2)
// Each deck has a total of 56 cards
// - 40 Number Cards
// - 4 Draw 2 Cards
// - 4 Reverse Cards
// - 4 Skip Cards
// - 2 Wild Cards
// - 2 Wild Draw 4 Cards
const int NUM_DECKS = 2;

// Decks behave differently depending on what "type" of deck it is (i.e. where the deck is located)
// DrawPile - The deck that all players can draw from for more cards
// GraveYard - Where players place their cards as a move
// Player - The deck that each player has
enum deckOwner {DrawPile, Graveyard, Player, NoOwner};

// Returns the string equivalent of getOwner enum values
string getOwner(deckOwner deckOwner);

class Deck {
    public:
        Deck();                                     // Default Constructor
        Deck(deckOwner deckOwner);                  // Constructor
        ~Deck();                                    // Destructor
        Deck(const Deck& otherDeck);                // Copy Constructor
        Deck& operator=(const Deck& otherDeck);     // Overrided Assignment Operator


        // Getter Methods

        vector<Card*>* getCards() const;
        int getDeckSize() const;
        deckOwner getDeckOwner() const;


        // Non Getter Methods

        // Desc: Clears a deck (deallocates memory of all cards in deck)
        // Users:
        // - DrawPile
        void clear();

        // Desc: Restocks a deck
        // Users:
        // - DrawPile
        void restock();
        
        // Desc: Prints all cards in a deck
        // Users:
        // - Graveyard
        // - Player
        void display();

        // Desc: Draws a random card from the deck
        // Users:
        // - DrawPile
        Card* pickRandom();

        // Desc: Receives a random card from the deck (goes with pickRandom())
        // Users:
        // - Player
        void receiveRandom(Deck& otherDeck);

        // Desc: Draws a specified card from the deck and puts it into the graveyard deck
        // Users:
        // - Player
        Card* pick(int index);

        // Desc: Removes all null cards from the deck
        // Users:
        // - DrawPile
        // - Graveyard
        // - Player
        void removeNullCards();
    private:
        vector<Card*>* m_cards;
        deckOwner m_deckOwner;
};

#endif
