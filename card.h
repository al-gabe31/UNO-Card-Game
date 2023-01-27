#ifndef CARD
#define CARD
#include <iostream>
#include <string>
using namespace std;

const int NO_VALUE = -1; // For cards that don't have a card number

// Determines what type a card is
// NumberCards: Standard card with a color and a number
// Draw2: Makes the next player draw 2 cards from the deck
// Reverse: Reverses the direction of the turn
// Skip: Skips the next person's turn
enum cardType {NumberCards, Draw2, Reverse, Skip, Wild, WildDraw4, NoType};

// Determines what color a card is
enum cardColor {Red, Yellow, Blue, Green, NoColor};

// Returns the string equivalent of cardType enum values
string getType(cardType cardType);

// Returns the string equivalent of cardColor enum values
string getColor(cardColor cardColor);

class Card {
    friend ostream& operator<<(ostream& os, const Card& card);
    
    public:
        Card();                                                     // Default constructor (Creates NULL CARD)
        Card(cardType cardType, cardColor cardColor, int cardNum);  // Universal Constructor for All Cards (parameters must make sense)
        Card(cardColor cardColor, int cardNum);                     // Constructor for NumberCards
        Card(cardType cardType, cardColor cardColor);               // Constructor for Draw2, Reverse, and Skip
        Card(cardType cardType);                                    // Constructor for Wild and WildDraw4
        ~Card();                                                    // Destructor
        Card(const Card &otherCard);                                // Copy Constructor
        Card& operator=(const Card& otherCard);                     // Overloaded Assignment Operator
        
        
        // Getter Methods
        
        cardType getCardType() const;
        cardColor getCardColor() const;
        int getCardNum() const;


        // Non Getter Methods

        // Prints all private values of the card
        void printDescription();
        // Sets a card to a NULL CARD (a card without any meaningful values)
        void setNullCard();
        // FOR DEBUGGING PURPOSES (DELETE ONCE DONE)
        void changeValues(cardType cardType, cardColor cardColor, int cardNum);
    private:
        cardType m_cardType;
        cardColor m_cardColor;
        int m_cardNum; // 0 - 9 for standard cards; -1 for other cards (e.g. Draw 2 card)
};

#endif
