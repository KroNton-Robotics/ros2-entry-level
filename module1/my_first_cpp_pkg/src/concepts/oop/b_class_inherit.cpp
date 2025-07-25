#include <iostream>
using namespace std;

// The "Apartment" class (blueprint)
class Apartment {

    private:
        int rooms;       // Private: Only accessible inside the class
        string color; // (Like hidden wiring/plumbing in an apartment)

    public:

        // Constructor (like initial construction of the apartment)
        Apartment(int r, string c) {
            rooms = r;
            color = c;
        }

        // Method to display apartment details (like a brochure)
        void displayDetails() {
            cout << "This apartment has " << rooms << " rooms and is " << color << "." << endl;
        }

};

class Studio : public Apartment {
private:
    bool hasKitchenette;
public:
    // Constructor: Calls Apartment's constructor with 1 room
    Studio(string c, bool kitchen):Apartment(1, c){
        
        hasKitchenette  = kitchen;      
        }

    // New method specific to Studio
    void studioFeatures() {

        displayDetails(); // Inherited from Apartment

        cout << "Kitchenette: " << (hasKitchenette ? "Yes" : "No") << endl;
    }
};

class Penthouse : public Apartment {
private:
    bool rooftopPool;
    int floorNumber;
public:
    // Constructor: Calls Apartment's constructor
    Penthouse(int r, string c, bool pool, int floor) :
     Apartment(r, c), rooftopPool(pool), floorNumber(floor) // member initializer list
        {

        }

    // New method specific to Penthouse
    void penthouseFeatures() {
        
        displayDetails(); // Inherited from Apartment
        cout << "Rooftop Pool: " << (rooftopPool ? "Yes" : "No") << endl;
        cout << "Floor: " << floorNumber << endl;
    }
};

int main() {
    // Create a Studio (automatically 1 room)
    Studio studio1("white", true);

    cout << "--- Studio Details ---" << endl;
    studio1.studioFeatures();

    // Create a Penthouse (custom rooms + extras)
    Penthouse penthouse1(4, "gold", true, 10);

    cout << "\n--- Penthouse Details ---" << endl;
    penthouse1.penthouseFeatures();

    return 0;
}