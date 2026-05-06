#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string manufscture;
    string model;
    int year;

public:
    static int totalVehicle;

    Vehicle()
    {
        vehicleID = 0;
        manufscture = "not set";
        model = "not set";
        year = 0;
        totalVehicle++;
    }

    Vehicle(int id, string manu, string mdl, int yr)
    {

        vehicleID = id;
        manufscture = manu;
        model = mdl;
        year = yr;
    }

    virtual ~Vehicle()
    {
        totalVehicle--;
    }

    void setVehicle(int id, string manu, string mdl, int yr)
    {
        vehicleID = id;
        manufscture = manu;
        model = mdl;
        year = yr;
    }

    int getvehileID() const
    {
        return vehicleID;
    }

    string getmanufacture() const
    {
        return manufscture;
    }

    string getmodel() const
    {
        return model;
    }

    int getyear() const
    {
        return year;
    }

    virtual void display() const
    {

        cout << "Vehicle Id: " << vehicleID << endl;
        cout << "Manufacture: " << manufscture << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    static int getTotalVehicle()
    {
        return totalVehicle;
    }

    virtual string vehicleType() const
    {
        return "Vehicle";
    }
};

int Vehicle::totalVehicle = 0;

class Car : public Vehicle
{

protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        fuelType = "not set";
    }

    Car(int id, string manu, string mdl, int yr, string fuel) : Vehicle(id, manu, mdl, yr)
    {
        fuelType = fuel;
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    string getfueltype()
    {
        return fuelType;
    }
    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }

    string vehicleType() const override
    {
        return "car";
    }
};

class ElectricCar : public Car
{

protected:
    double batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0.0;
    }

    ElectricCar(int id, string manu, string mdl, int yr, double battery) : Car(id, manu, mdl, yr, "Electric")
    {
        batteryCapacity = battery;
    }

    void setBatteryCapacity(double battery)
    {
        batteryCapacity = battery;
    }

    double getBatteryCapacity()
    {
        return batteryCapacity;
    }
    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout<<"Battery Capacity: "<<batteryCapacity<<endl;
    }

    string vehicleType() const override
    {
        return "Electric Car";
    }
};

class Aircraft:ElectricCar{

protected:
    double flightRange;

public:

    Aircraft(){
        flightRange=0.0;

    }
    
    Aircraft(int id, string manu, string mdl, int yr, double range)
    {
        flightRange = range;
    }

    void setBatteryCapacity(double range)
    {
        flightRange = range;
    }

    double getFlightRange()
    {
        return flightRange;
    }
    void display() const override
    {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout<<"Battery Capacity: "<<batteryCapacity<<endl;
        cout<<"Flightrange: "<<flightRange<<endl;
    }

    string vehicleType() const override
    {
        return "AirCraft";
    }


};

class FlyingCar : public Car, public Aircraft
{
protected:
    double range;

public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int id, string manu, string mdl, int yr, string fuel, double range)
        : Car(id, manu, mdl, yr, fuel), Aircraft()
    {
    }

    void display() const override
    {
        FlyingCar::display();
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
    string vehicleType() const override
    {
        return "Flying Car";
    }
};



class SportsCar : public ElectricCar
{
private:
    double topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0.0;
    }
    SportsCar(int id, string manu, string mdl, int yr, double battery, double speed)
    {
        ElectricCar(id, manu, mdl, yr, battery);
        topSpeed = speed;
    }


    void setTopSpeed(double speed)
    {
        topSpeed = speed;
    }
    double getTopSpeed() const
    {
        return topSpeed;
    }

    void display() const override
    {
        ElectricCar::display();
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
    string vehicleType() const override
    {
        return "Sports Car";
    }
};

class Sedan : public Car
{
public:
    Sedan() : Car()
    {
    }

    Sedan(int id, string manu, string mdl, int yr, string fuel)
    {
        Car(id, manu, mdl, yr, fuel);
    }
    void display() const override
    {
        Car::display();
    }
    string vehicleType() const override
    {
        return "Sedan";
    }
};


class SUV : public Car
{
public:
    SUV() : Car()
    {
    }
    SUV(int id, string manu, string mdl, int yr, string fuel)
    {
        Car(id, manu, mdl, yr, fuel);
    }
    void display() const override
    {
        Car::display();
    }
    string vehicleType() const override
    {
        return "SUV";
    }
};



class VehicleRegistry
{
private:
    Vehicle *vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
        for (int i = 0; i < 100; i++)
        {
            vehicles[i] = nullptr;
        }
    }
    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }
    void addVehicle(Vehicle *v)
    {
        if (count < 100)
        {
            vehicles[count++] = v;
            cout << "vehicle added successfully!" << endl;
        }
        else
        {
            cout << "Registry is full!" << endl;
        }
    }   

    void displayAll() const
    {
        if (count == 0)
        {
            cout << "\nNo vehicles in the registry.\n"
                 << endl;
            return;
        }
      

        for (int i = 0; i < count; i++)
        {
            cout << "\n Vehicle " << (i + 1) << endl;
            cout << "Type: " << vehicles[i]->vehicleType() << endl;
            vehicles[i]->display();
            
        }
        cout << "\nTotal Vehicles in Registry: " << count << endl;
    }

    void searchById(int id) const
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getvehileID() == id)
            {
                cout << "\nVehicle Found " << endl;
                cout << vehicles[i]->vehicleType()  << endl;
                vehicles[i]->display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\nVehicle with ID " << id << " not found." << endl;
        }
    }
};

int main()
{
    VehicleRegistry regi;
    int choice;

    do
    {
        cout << "\n.......... VEHICLE REGISTRY SYSTEM.........." << endl;
        cout << "\n1. Add a Vehicle" << endl;
        cout << "\n2.View All Vehicles" << endl;
        cout << "\n3.Search by ID" << endl;
        cout << "\n4.Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int type;
            cout << "\nSelect Vehicle Type:" << endl;
            cout << "1. Car" << endl;
            cout << "2. Electric Car" << endl;
            cout << "3. Flying Car" << endl;
            cout << "4. Sports Car" << endl;
            cout << "5. Sedan" << endl;
            cout << "6. SUV" << endl;
            cout << "Enter type: ";
            cin >> type;

            int id, yr;
            string manu, mdl;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Manufacturer: ";
            getline(cin, manu);
            cout << "Enter Model: ";
            getline(cin, mdl);
            cout << "Enter Year: ";
            cin >> yr;
            if (type == 1)
            {
                string fuel;
                cin.ignore();
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                regi.addVehicle(new Car(id, manu, mdl, yr,fuel));
            }
            else if (type == 2)
            {
                double battery;
                cout << "Enter Battery Capacity (kWh): ";
                cin >> battery;
                regi.addVehicle(new ElectricCar(id, manu, mdl, yr, battery));
            }
            else if (type == 3)
            {
                string fuel;
                double range;
                cin.ignore();
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                cout << "Enter Flight Range (km): ";
                cin >> range;
                regi.addVehicle(new FlyingCar(id, manu, mdl, yr,fuel range));
            }
            else if (type == 4)
            {
                double battery, speed;
                cout << "Enter Battery Capacity: ";
                cin >> battery;
                cout << "Enter Top Speed: ";
                cin >> speed;
                regi.addVehicle(new SportsCar(id, manu, mdl, yr,fuel battery, speed));
            }
            else if (type == 5)
            {
                string fuel;
                cin.ignore();
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                regi.addVehicle(new Sedan(id, manu, mdl, yr,fuel));
            }
            else if (type == 6)
            {
                string fuel;
                cin.ignore();
                cout << "Enter Fuel Type: ";
                getline(cin, fuel);
                regi.addVehicle(new SUV(id, manu, mdl, yr, fuel));
            }
            else
            {
                cout << "\nInvalid vehicle type!" << endl;
            }
        }
        else if (choice == 2)
        {
            regi.displayAll();
        }
        else if (choice == 3)
        {
            int id;
            cout << "\nEnter Vehicle ID to search: ";
            cin >> id;
            regi.searchById(id);
        }
        else if (choice == 4)
        {
            cout << "\nTotal Vehicles Created: " << Vehicle::getTotalVehicle() << endl;
            cout << "Exiting system. Thank you!" << endl;
        }
        else
        {
            cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}




