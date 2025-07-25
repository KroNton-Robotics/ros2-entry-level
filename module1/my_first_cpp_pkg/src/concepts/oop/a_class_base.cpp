#include <iostream>
using namespace std;

// The "Apartment" class (blueprint)
class Apartment {

    private: //Access Specifier

        int rooms;       // Private: Only accessible inside the class
        string color; // (Like hidden wiring/plumbing in an apartment)

    public:

        // Constructor (like initial construction of the apartment)
        Apartment(int r, string c) {
            rooms = r;
            color = c;
            cout << "New apartment constructed" << "." << endl;
        }

        // Method to display apartment details (like a brochure)
        void displayDetails() {
            cout << "This apartment has " << rooms << " rooms and is " << color << "." << endl;
        }

};

int main()
{
    Apartment apartment1(3,"white");

    apartment1.displayDetails();
  
    return 0;
}
