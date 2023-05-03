#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string color;
    string engine_type;
    double km_driven;
public:
    Car(string color, string engine_type, double km_driven);
    double maintenance_cost();
    bool is_km_driven_high();
    void print_info();
};

Car::Car(string color, string engine_type, double km_driven) {
    this->color = color;
    this->engine_type = engine_type;
    this->km_driven = km_driven;
}

double Car::maintenance_cost() {
    double cost_per_km = 0.1; // assume maintenance cost is 10 cents per km
    return cost_per_km * km_driven;
}

bool Car::is_km_driven_high() {
    double km_limit = 50000; // assume 50,000 km is the limit
    return km_driven > km_limit;
}

void Car::print_info() {
    cout << "Color: " << color << endl;
    cout << "Engine type: " << engine_type << endl;
    cout << "Kilometers driven: " << km_driven << endl;
}

int main() {
    Car myCar("Red", "BMW", 750);
    myCar.print_info();
    cout << "Maintenance cost: $" << myCar.maintenance_cost() << endl;
    if (myCar.is_km_driven_high()) {
        cout << "Warning: High kilometers driven" << endl;
    }
    return 0;
}
