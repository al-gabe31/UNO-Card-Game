#include "card.h"

// Returns the string equivalent of cardType enum values
string getType(cardType cardType) {
    switch(cardType) {
        case NumberCards:
            return "Number Card";
        case Draw2:
            return "Draw 2 Card";
        case Reverse:
            return "Reverse Card";
        case Skip:
            return "Skip Card";
        case Wild:
            return "Wild Card";
        case WildDraw4:
            return "Wild Draw 4 Card";
        default: // NoType
            return "No Type";
    }
}

// Returns the string equivalent of cardColor enum
string getColor(cardColor cardColor) {
    switch(cardColor) {
        case Red:
            return "Red";
        case Yellow:
            return "Yellow";
        case Blue:
            return "Blue";
        case Green:
            return "Green";
        default: // NoColor
            return "None";
    }
}

// Overloaded Insertion Operator
ostream& operator<<(ostream& os, const Card& card) {
    // Basically just another way to call printDescription()

    // Card description despends on its card type
    switch(card.m_cardType) {
        case NumberCards:
            os << getColor(card.m_cardColor) << " " << card.m_cardNum << " Card";
            break;
        case Draw2:
            os << getColor(card.m_cardColor) << " Draw 2 Card";
            break;
        case Reverse:
            os << getColor(card.m_cardColor) << " Reverse Card";
            break;
        case Skip:
            os << getColor(card.m_cardColor) << " Skip Card";
            break;
        case Wild:
            os << "Wild Card";
            break;
        case WildDraw4:
            os << "Wild Draw 4 Card";
            break;
        default:
            os << "NULL CARD";
    }

    return os;
}

// Default constructor (Creates NULL CARD)
Card::Card() {
    setNullCard();
}

// Universal Constructor for All Cards (parameters must make sense)
// e.g. Wild cards cannot have a number
Card::Card(cardType cardType, cardColor cardColor, int cardNum) {
    switch(cardType) {
        case NumberCards:
            // Invalid Combinations
            // 1. cardColor == NoColor
            // 2. cardNum <= -1
            // 3. cardNum >= 10
            if(cardColor == NoColor) {
                cout << "ERROR - NUMBER CARDS MUST HAVE A COLOR" << endl;
                setNullCard();
            } else if(cardNum <= -1 || cardNum >= 10) {
                cout << "ERROR - CARD NUMBER MUST BE WITHIN [0, 9] (NUMBER GIVEN: " + to_string(cardNum) + ")" << endl;
                setNullCard();
            }

            // Valid Combination
            m_cardType = cardType;
            m_cardColor = cardColor;
            m_cardNum = cardNum;

            break;
        case Draw2: case Reverse: case Skip:
            // Invalid Combinations
            // 1. cardColor == NoColor
            // 2. cardNum != NO_VALUE
            if(cardColor == NoColor) {
                cout << "ERROR - ACTION CARD MUST HAVE A COLOR" << endl;
                setNullCard();
            } else if(cardNum != NO_VALUE) {
                cout << "ERROR - ACTION CARD CANNOT HAVE A CARD NUMBER (NUMBER GIVEN: " + to_string(cardNum) + ")" << endl;
                setNullCard();
            }

            // Valid Combination
            m_cardType = cardType;
            m_cardColor = cardColor;
            m_cardNum = cardNum;

            break;
        case Wild: case WildDraw4:
            // Invalid Combinations
            // 1. cardType != NoColor
            // 2. cardNum != NO_VALUE
            if(cardColor != NoColor) {
                cout << "ERROR - WILD CARD CANNOT HAVE A COLOR (COLOR GIVEN: " + getColor(cardColor) + ")" << endl;
                setNullCard();
            } else if(cardNum != NO_VALUE) {
                cout << "ERROR - WILD CARD CANNOT HAVE A CARD NUMBER (NUMBER GIVEN: " + to_string(cardNum) + ")" << endl;
                setNullCard();
            }

            // Valid Combination
            m_cardType = cardType;
            m_cardColor = cardColor;
            m_cardNum = cardNum;

            break;
        default: // NoType
            setNullCard();
    }
}

// Constructor for NumberCards
Card::Card(cardColor cardColor, int cardNum) {
    // Invalid Combinations
    // 1. cardColor == NoColor
    // 2. cardNum <= -1
    // 3. cardNum >= 10
    if(cardColor == NoColor) {
        cout << "ERROR - NUMBER CARDS MUST HAVE A COLOR" << endl;
        setNullCard();
    } else if(cardNum <= -1 || cardNum >= 10) {
        cout << "ERROR - CARD NUMBER MUST BE WITHIN [0, 9] (NUMBER GIVEN: " + to_string(cardNum) + ")" << endl;
        setNullCard();
    }

    // Valid Combination
    m_cardType = NumberCards;
    m_cardColor = cardColor;
    m_cardNum = cardNum;
}

// Constructor for Draw2, Reverse, and Skip
Card::Card(cardType cardType, cardColor cardColor) {
    // Invalid Combinations
    // 1. cardType isn't either Draw2, Reverse, or Skip
    // 2. cardColor == NoColor
    if(cardType == NumberCards || cardType == Wild || cardType == WildDraw4 || cardType == NoType) {
        cout << "ERROR - CARD TYPE FOR THIS CONSTRUCTOR MUST EITHER BE Draw2, Reverse, or Skip (TYPE GIVEN: " + getType(cardType) + ")" << endl;
        setNullCard();
    } else if(cardColor == NoColor) {
        cout << "ERROR - ACTION CARD MUST HAVE A COLOR" << endl;
        setNullCard();
    }

    // Valid Combination
    m_cardType = cardType;
    m_cardColor = cardColor;
    m_cardNum = NO_VALUE;
}

// Constructor for Wild and WildDraw4
Card::Card(cardType cardType) {
    // Invalid Combinations
    // 1. cardType isn't either Wild or WildDraw4
    if(cardType == NumberCards || cardType == Draw2 || cardType == Reverse || cardType == Skip || cardType == NoType) {
        cout << "ERROR - CARD TYPE FOR THIS CONSTRUCTOR MUST EITHER BE Wild or WildDraw4 (TYPE GIVEN: " + getType(cardType) + ")" << endl;
        setNullCard();
    }

    // Valid Combination
    m_cardType = cardType;
    m_cardColor = NoColor;
    m_cardNum = NO_VALUE;
}


// Getter Methods

// Destructor
Card::~Card() {
    // No deallocation necessary
}

// Copy Constructor
Card::Card(const Card &otherCard) {
    m_cardType = otherCard.getCardType();
    m_cardColor = otherCard.getCardColor();
    m_cardNum = otherCard.getCardNum();
}

// Overloaded Assignment Operator
Card& Card::operator=(const Card& otherCard) {
    // Checks for self assignment
    if(this == &otherCard) {
        return *this;
    }
    
    m_cardType = otherCard.getCardType();
    m_cardColor = otherCard.getCardColor();
    m_cardNum = otherCard.getCardNum();

    return *this;
}

cardType Card::getCardType() const {
    return m_cardType;
}

cardColor Card::getCardColor() const {
    return m_cardColor;
}

int Card::getCardNum() const {
    return m_cardNum;
}


// Non Getter Methods

// Prints all private values of the card
void Card::printDescription() {
    // Card description despends on its card type
    switch(m_cardType) {
        case NumberCards:
            cout << getColor(m_cardColor) << " " << m_cardNum << " Card" << endl;
            break;
        case Draw2:
            cout << getColor(m_cardColor) << " Draw 2 Card" << endl;
            break;
        case Reverse:
            cout << getColor(m_cardColor) << " Reverse Card" << endl;
            break;
        case Skip:
            cout << getColor(m_cardColor) << " Skip Card" << endl;
            break;
        case Wild:
            cout << "Wild Card" << endl;
            break;
        case WildDraw4:
            cout << "Wild Draw 4 Card" << endl;
            break;
        default:
            cout << "NULL CARD" << endl;
    }
}

// Sets a card to a NULL_CARD (a card without any meaningful values)
void Card::setNullCard() {
    m_cardType = NoType;
    m_cardColor = NoColor;
    m_cardNum = NO_VALUE;
}

// FOR DEBUGGING PURPOSES (DELETE ONCE DONE)
void Card::changeValues(cardType cardType, cardColor cardColor, int cardNum) {
    m_cardType = cardType;
    m_cardColor = cardColor;
    m_cardNum = cardNum;
}
