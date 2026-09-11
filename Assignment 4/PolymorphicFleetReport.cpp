#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:
    Vehicle(const string& reg, const string& owner, int year, double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const
    {
        cout << "Registration: " << registrationNo << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Year: " << yearOfManufacture << endl;
        cout << "KM Driven: " << kmDriven << endl;
    }

    virtual string vehicleType() const = 0;

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};


class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:
    Car(const string& reg, const string& owner, int year,
        double km, const string& fuel, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double price;

        if (fuelType == "Petrol")
            price = 106;
        else
            price = 93;

        return (kmToTravel / mileageKmpl) * price;
    }

    string vehicleType() const override
    {
        return "Car";
    }

    void describe() const override
    {
        Vehicle::describe();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Mileage: " << mileageKmpl << " km/l" << endl;
    }

    ~Car() override
    {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }
};


class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:
    Truck(const string& reg, const string& owner, int year,
          double km, double payload, double efficiency)
        : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        double efficiency = fuelEfficiencyKmpl;

        // 5% efficiency reduction for every ton
        efficiency = efficiency * (1 - (0.05 * payloadCapacityTons));

        return (kmToTravel / efficiency) * 93;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    void describe() const override
    {
        Vehicle::describe();
        cout << "Payload: "
             << payloadCapacityTons << " tons" << endl;
        cout << "Efficiency: "
             << fuelEfficiencyKmpl << " km/l" << endl;
    }

    ~Truck() override
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;
    double batteryPercent;

public:
    ElectricTruck(const string& reg, const string& owner, int year,
                  double km, double payload, double efficiency,
                  double battery, double range, double batteryStatus)
        : Truck(reg, owner, year, km, payload, efficiency)
    {
        batteryCapacityKWh = battery;
        rangePerChargeKm = range;
        batteryPercent = batteryStatus;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh * 9.50;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    void describe() const override
    {
        Truck::describe();

        cout << "Battery Capacity: "
             << batteryCapacityKWh << " kWh" << endl;

        cout << "Range: "
             << rangePerChargeKm << " km" << endl;

        cout << "Battery Status: "
             << batteryPercent << "%" << endl;
    }

    double getBatteryPercent() const
    {
        return batteryPercent;
    }

    ~ElectricTruck() override
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};


class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:
    Van(const string& reg, const string& owner, int year,
        double km, int seats, double mileage)
        : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seats;
        mileageKmpl = mileage;

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override
    {
        return (kmToTravel / mileageKmpl) * 106;
    }

    string vehicleType() const override
    {
        return "Van";
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seats: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl << " km/l" << endl;
    }

    ~Van() override
    {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// Fleet Report Function
void printFleetReport(const vector<Vehicle*>& fleet, double tripKm)
{
    cout << endl;
    cout << "===== FLEET REPORT - Trip Distance: "
         << tripKm << " km =====" << endl;

    cout << left
         << setw(15) << "Reg"
         << setw(20) << "Type"
         << setw(25) << "Owner"
         << setw(15) << "Km Driven" << endl;

    cout << "------------------------------------------------------------"
         << endl;

    double lowestCost = 999999999;
    Vehicle* efficientVehicle = nullptr;

    for (int i = 0; i < fleet.size(); i++)
    {
        cout << left
             << setw(15) << fleet[i]->getRegNo()
             << setw(20) << fleet[i]->vehicleType()
             << setw(25) << fleet[i]->getOwnerName()
             << setw(15) << fixed << setprecision(0)
             << fleet[i]->getKmDriven()
             << endl;

        double cost = fleet[i]->fuelCost(tripKm);

        if (cost < lowestCost)
        {
            lowestCost = cost;
            efficientVehicle = fleet[i];
        }
    }

    cout << endl;
    cout << "===== FUEL / CHARGE COST ESTIMATE =====" << endl;

    for (int i = 0; i < fleet.size(); i++)
    {
        double cost = fleet[i]->fuelCost(tripKm);

        cout << fleet[i]->getRegNo()
             << " (" << fleet[i]->vehicleType() << ") : Rs. "
             << fixed << setprecision(2)
             << cost;

        // Check if vehicle is ElectricTruck
        ElectricTruck* electricTruck =
            dynamic_cast<ElectricTruck*>(fleet[i]);

        if (electricTruck != nullptr)
        {
            cout << " [Battery: "
                 << electricTruck->getBatteryPercent()
                 << "% charged]";
        }

        cout << endl;
    }

    cout << endl;

    cout << "Most Efficient Vehicle: "
         << efficientVehicle->getRegNo()
         << " (" << efficientVehicle->vehicleType() << ") - Rs. "
         << fixed << setprecision(2)
         << lowestCost
         << " for " << tripKm << " km"
         << endl;
}


int main()
{
    vector<Vehicle*> fleet;

    // Creating vehicles using new
    fleet.push_back(new Car(
        "KA01AA001",
        "Ramesh Kumar",
        2020,
        45200,
        "Petrol",
        18
    ));

    fleet.push_back(new Truck(
        "MH04BB002",
        "Shyam Logistics",
        2019,
        123500,
        2,
        8
    ));

    fleet.push_back(new ElectricTruck(
        "GJ07CC003",
        "Green Fleet Co",
        2023,
        89000,
        2,
        6,
        85,
        300,
        85
    ));

    fleet.push_back(new Van(
        "DL08DD004",
        "City Travels",
        2021,
        67000,
        12,
        15
    ));

    fleet.push_back(new Car(
        "TN09EE005",
        "Priya Shah",
        2022,
        35000,
        "Diesel",
        20
    ));


    // Print fleet report
    printFleetReport(fleet, 200);


    // Delete all heap allocated vehicles
    cout << endl;
    cout << "===== CLEANUP =====" << endl;

    for (int i = 0; i < fleet.size(); i++)
    {
        delete fleet[i];
    }

    return 0;
}
