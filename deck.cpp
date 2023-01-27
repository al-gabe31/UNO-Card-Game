#include "deck.h"

// Returns the string equivalent of getOwner enum values
string getOwner(deckOwner deckOwner) {
    switch(deckOwner) {
        case DrawPile:
            return "Draw Pile";
        case Graveyard:
            return "Graveyard";
        case Player:
            return "Player";
        default:
            return "No Owner";
    }
}

// Default Constructor
Deck::Deck() {
    cout << "DEFAULT CONSTRUCTOR CALLED" << endl; // DELETE ONCE DONE
    m_deckOwner = NoOwner;
}

// Constructor
Deck::Deck(deckOwner deckOwner) : m_deckOwner(deckOwner) {
    cout << "CONTSTRUCTOR CALLED" << endl; // DELETE ONCE DONE
}

// Destructor
Deck::~Deck() {
    cout << "DECK DESTRUCTOR CALLED" << endl; // DELETE ONCE DONE
    // Deletes all cards in the deck
    for(int i = 0; i < m_cards->size(); i++) {
        delete (*m_cards)[i];
    }
    m_cards->clear();

    delete m_cards;
}

// Copy Constructor
Deck::Deck(const Deck& otherDeck) : m_deckOwner(otherDeck.getDeckOwner()) {
    cout << "DECK COPY CONSTRUCTOR CALLED" << endl; // DELETE ONCE DONE
    // Copies all decks from one to another
    for(Card* card : *(otherDeck.getCards())) {
        Card* newCard = new Card(card->getCardType(), card->getCardColor(), card->getCardNum());
        m_cards->push_back(newCard);
    }
}

// Overrided Assignment Operator
Deck& Deck::operator=(const Deck& otherDeck) {
    cout << "DECK OVERRIDED ASSIGNMENT OPERATOR CALLED" << endl; // DELETE ONCE DONE
    // Checks for self assignment
    if(this == &otherDeck) {
        return *this;
    }

    // First, deletes all dynamic memory before copying data
    // Deletes all cards in the deck
    for(int i = 0; i < m_cards->size(); i++) {
        delete (*m_cards)[i];
    }
    m_cards->clear();
    
    m_deckOwner = otherDeck.getDeckOwner();
    // Copies all decks from one to another
    for(Card* card : *(otherDeck.getCards())) {
        Card* newCard = new Card(card->getCardType(), card->getCardColor(), card->getCardNum());
        m_cards->push_back(newCard);
    }

    return *this;
}

vector<Card*>* Deck::getCards() const {
    return m_cards;
}

int Deck::getDeckSize() const {
    return m_cards->size();
}

deckOwner Deck::getDeckOwner() const {
    return m_deckOwner;
}

// Desc: Clears a deck (deallocates memory of all cards in deck)
// Users:
// - DrawPile
void Deck::clear() {
    if(m_deckOwner == DrawPile) {
        for(int i = 0; i < m_cards->size(); i++) {
            delete m_cards->at(i);
        }
        m_cards->clear();
    } else {
        cout << "ERROR - CANNOT CLEAR WITH DECK OWNER: " + getOwner(m_deckOwner) << endl;
    }
}

// Desc: Restocks a deck
// Users:
// - DrawPile
void Deck::restock() {
    if(m_deckOwner == DrawPile) {
        clear(); // Clears current cards in the deck first
        Card* newCard;

        // Adds the following for each deck:
        // - 40 Number Cards
        // - 4 Draw 2 Cards
        // - 4 Reverse Cards
        // - 4 Skip Cards
        // - 2 Wild Cards
        // - 2 Wild Draw 4 Cards
        for(int i = 0; i < NUM_DECKS; i++) {
            // First adds the number cards first from 0 - 9 for all 4 colors
            for(int j = 0; j < 40; j++) {
                switch(j % 4) {
                    case 0: // Red
                        newCard = new Card(Red, j % 10);
                        m_cards->push_back(newCard);
                        break;
                    case 1: // Yellow
                        newCard = new Card(Yellow, j % 10);
                        m_cards->push_back(newCard);
                        break;
                    case 2: // Blue
                        newCard = new Card(Blue, j % 10);
                        m_cards->push_back(newCard);
                        break;
                    case 3: // Green
                        newCard = new Card(Green, j % 10);
                        m_cards->push_back(newCard);
                        break;
                    default: // Unexpected Error
                        cout << "ERROR - UNEXPECTED EVENT OCCURRED" << endl;
                }
            }

            // Then adds the rest
            // There just isn't an easier way to do this TT_TT
            // Draw2 Cards
            newCard = new Card(Draw2, Red);
            m_cards->push_back(newCard);
            newCard = new Card(Draw2, Yellow);
            m_cards->push_back(newCard);
            newCard = new Card(Draw2, Blue);
            m_cards->push_back(newCard);
            newCard = new Card(Draw2, Green);
            m_cards->push_back(newCard);
            
            // Reverse Cards
            newCard = new Card(Reverse, Red);
            m_cards->push_back(newCard);
            newCard = new Card(Reverse, Yellow);
            m_cards->push_back(newCard);
            newCard = new Card(Reverse, Blue);
            m_cards->push_back(newCard);
            newCard = new Card(Reverse, Green);
            m_cards->push_back(newCard);
            
            // Skip Cards
            newCard = new Card(Skip, Red);
            m_cards->push_back(newCard);
            newCard = new Card(Skip, Yellow);
            m_cards->push_back(newCard);
            newCard = new Card(Skip, Blue);
            m_cards->push_back(newCard);
            newCard = new Card(Skip, Green);
            m_cards->push_back(newCard);

            // Wild & Wild Draw 4 Cards
            newCard = new Card(Wild);
            m_cards->push_back(newCard);
            newCard = new Card(Wild);
            m_cards->push_back(newCard);
            newCard = new Card(WildDraw4);
            m_cards->push_back(newCard);
            newCard = new Card(WildDraw4);
            m_cards->push_back(newCard);
        }
    } else {
        cout << "ERROR - CANNOT RESTOCK WITH DECK OWNER: " + getOwner(m_deckOwner) << endl;
    }
}

// Desc: Prints all cards in a deck
// Users:
// - Graveyard
// - Player
void Deck::display() {
    if(m_deckOwner == Graveyard || m_deckOwner == Player) {
        // EDGE CASE: Deck is empty
        if(m_cards->size() == 0) {
            cout << "DECK IS EMPTY" << endl;
        } else {
            // Goes through each card in the deck and prints their description
            for(int i = 0; i < m_cards->size(); i++) {
                cout << "[" << (i + 1) << "] - " << *((*m_cards)[i]) << endl;
            }
        }
    } else {
        cout << "ERROR - CANNOT DISPLAY WITH DECK OWNER: " + getOwner(m_deckOwner) << endl;
    }
}

// Desc: Draws a random card from the deck
// Users:
// - DrawPile
Card* Deck::pickRandom() {
    if(m_deckOwner == DrawPile) {
        srand(time(NULL));
        int randNum = (rand() % m_cards->size());
        Card* chosenCard = (*m_cards)[randNum];
        cout << "Picked up: " << (*chosenCard) << endl;
        m_cards->erase(m_cards->begin() + randNum); // Deletes chosen card form the deck
        return chosenCard;
    } else {
        cout << "ERROR - CANNOT PICKRANDOM WITH DECK OWNER: " + getOwner(m_deckOwner) << endl;
        Card* nullCard = new Card();
        nullCard->setNullCard();
        return nullCard;
    }
}

// Desc: Receives a random card from the deck (goes with pickRandom())
// Users:
// - Player
void Deck::receiveRandom(Deck& otherDeck) {
    if(m_deckOwner == Player && otherDeck.getDeckOwner() == DrawPile) {
        Card* chosenCard = otherDeck.pickRandom();  // Draws a random card from the DrawPile
        m_cards->push_back(chosenCard);             // Adds the card to the player's deck
    } else {
        if(m_deckOwner != Player) {
            cout << "ERROR - DECK OWNER MUST BE Player (" + getOwner(m_deckOwner) << " istead)" << endl;
        }

        // Message below might get double printed
        // if(otherDeck.getDeckOwner() != DrawPile) {
        //     cout << "ERROR - OTHER DECK MUST BE DrawPile (" + getOwner(otherDeck.getDeckOwner()) << " istead)" << endl;
        // }
    }
}

// Desc: Draws a specified card from the deck and puts it into the graveyard deck
// Users:
// - Player
Card* Deck::pick(int index) {
    if(m_deckOwner == Player) {
        // EDGE CASE: m_cards is empty
        if(m_cards->size() == 0) {
            cout << "ERROR - UNEXPECTED EVENT OCCURRED" << endl; // Error you would've already won in this case
           Card* nullCard = new Card();
            nullCard->setNullCard();
            return nullCard;
        } else {
            // First displays all available cards the player can choose from
            display();

            // The player then has to keep choosing a valid number to use a card from their deck
            int chosenNum = -1;

            while(chosenNum < 0 || chosenNum >= m_cards->size()) {
                cout << "Pick which card to use: ";
                cin >> chosenNum;

                // Invalid number chosen
                if(chosenNum < 0 || chosenNum >= m_cards->size()) {
                    cout << "ERROR - CHOICE MUST BE BETWEEN [0, " << (m_cards->size() - 1) << "]" << endl;
                }
            }

            Card* chosenCard = (*m_cards)[chosenNum];
            cout << "Chose: " << (*chosenCard) << endl;
            m_cards->erase(m_cards->begin() + chosenNum); // Deletes chosen card from the deck
            return chosenCard;
        }
    } else {
        cout << "ERROR - CANNOT PICK WITH DECK OWNER: " + getOwner(m_deckOwner) << endl;
        Card* nullCard = new Card();
        nullCard->setNullCard();
        return nullCard;
    }
}

// Desc: Removes all NULL CARDs from the deck
// Users:
// - DrawPile
// - Graveyard
// - Player
void Deck::removeNullCards() {
    // Only remove cards if m_cards even has any cards
    if(m_cards->size() > 0) {
        int index = 0;
        while(index < m_cards->size()) {
            if((*m_cards)[index]->isNullCard()) {
                delete (*m_cards)[index];
                m_cards->erase(m_cards->begin() + index);
            } else {
                index++;
            }
        }
    }
}
