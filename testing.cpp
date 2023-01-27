// For testing and debugging

#include <iostream>
#include "testHeader.h"
#include "card.h"
using namespace std;

int main() {
    // TESTING CARD CLASS
    Card c1(Red, 5);                                // Number Card
    Card c2(Draw2, Yellow);                         // Draw 2 Card
    Card c3(Reverse, Blue);                         // Reverse Card
    Card c4(Skip, Green);                           // Skip Card
    Card c5(Wild);                                  // Wild Card
    Card c6(WildDraw4);                             // Wild Draw 4

    Card c7;                                        // Default Constructor
    Card* c8 = new Card(Yellow, 2);
    delete c8;                                      // Calling Destructor
    Card c9(c1);                                    // Copy Constructor
    c1.changeValues(NumberCards, Green, 8);
    Card c10;
    c10 = c2;                                       // Overloaded Assignment Operator
    c2.changeValues(Reverse, Red, NO_VALUE);

    c1.printDescription();
    c2.printDescription();
    c3.printDescription();
    c4.printDescription();
    c5.printDescription();
    c6.printDescription();
    c7.printDescription();
    c9.printDescription();
    c10.printDescription();
    
    
    cout << "Looks good!" << endl;
    
    return 0;
}
