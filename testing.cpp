// For testing and debugging

#include <iostream>
#include <string>
#include <vector>
#include "testHeader.h"
#include "card.h"
#include "deck.h"
using namespace std;

int main() {
    // TESTING DECK CLASS
    
    // Sample Cards
    Card* c1 = new Card(Red, 8);
    Card* c2 = new Card(Green, 2);
    Card* c3 = new Card(Draw2, Yellow);
    Card* c4 = new Card(Reverse, Blue);
    Card* c5 = new Card(Skip, Red);
    Card* c6 = new Card(Wild);
    Card* c7 = new Card(WildDraw4);
    
    cout << "TESTING CONSTRUCTORS" << endl;
    Deck d1;                // Default Constructor
    Deck d2(Graveyard);     // Constructor
    d2.put(c1);
    d2.put(c2);                 // d2: c1, c2
    Deck d3(d2);            // Copy Constructor
    d3.put(c3);                 // d3: c1, c2, c3
    Deck d4;
    d4 = d3;                // Overrided Assignment Operator
    d4.put(c4);                 // d4: c1, c2, c3, c4

    cout << endl;
    cout << "TESTING GETTER METHODS" << endl;
    vector<Card*>* thing = d4.getCards(); // d4: c1, c2, c3, c4
    for(unsigned int i = 0; i < thing->size(); i++) {
        cout << *((*thing)[i]) << endl;
    }
    cout << d4.getDeckSize() << endl; // Should be 4
    if(d4.getDeckOwner() == Graveyard) {
        cout << "D4 correct deck owner" << endl;
    } else {
        cout << "D4 wrong deck owner" << endl;
    }

    // Don't forget to delete all sample cards if they weren't already
    cout << endl;
    cout << "DELETING ANY REMAINING SAMPLE CARDS" << endl;
    if(c1 != nullptr) {
        delete c1;
        c1 = nullptr;
    }
    if(c2 != nullptr) {
        delete c2;
        c2 = nullptr;
    }
    if(c3 != nullptr) {
        delete c3;
        c3 = nullptr;
    }
    if(c4 != nullptr) {
        delete c4;
        c4 = nullptr;
    }
    if(c5 != nullptr) {
        delete c5;
        c5 = nullptr;
    }
    if(c6 != nullptr) {
        delete c6;
        c6 = nullptr;
    }
    if(c7 != nullptr) {
        delete c7;
        c7 = nullptr;
    }
    
    
    
    cout << "Looks good!" << endl;
    
    return 0;
}
