# 🚗 Vehicle Registry System (C++)


https://onlinegdb.com/TYHF7N91A

## 📌 Project Description

The **Vehicle Registry System** is a C++ console-based application that allows users to manage different types of vehicles using Object-Oriented Programming (OOP) concepts.

This system supports adding, viewing, and searching vehicles with various categories like Car, Electric Car, Flying Car, Sports Car, Sedan, and SUV.

---

## 🎯 Features

* Add different types of vehicles
* View all registered vehicles
* Search vehicle by ID
* Track total number of vehicles
* Demonstrates OOP concepts like:

  * Inheritance
  * Polymorphism
  * Encapsulation
  * Abstraction

---

## 🏗️ Class Structure

### 🔹 Base Class

**Vehicle**

* Attributes: ID, Manufacturer, Model, Year
* Static member: Total vehicles count
* Virtual functions: `display()`, `vehicleType()`

---

### 🔹 Derived Classes

* **Car** → Adds fuel type
* **ElectricCar** → Adds battery capacity
* **Aircraft** → Adds flight range
* **FlyingCar** → Combines Car + Aircraft (Multiple Inheritance)
* **SportsCar** → Adds top speed
* **Sedan** → Type of Car
* **SUV** → Type of Car

---

### 🔹 Management Class

**VehicleRegistry**

* Stores up to 100 vehicles
* Functions:

  * `addVehicle()`
  * `displayAll()`
  * `searchById()`

---

## 🧠 OOP Concepts Used

| Concept       | Usage                                            |
| ------------- | ------------------------------------------------ |
| Inheritance   | Car, ElectricCar, etc. inherit from Vehicle      |
| Polymorphism  | Virtual functions (`display()`, `vehicleType()`) |
| Encapsulation | Private & protected data members                 |
| Abstraction   | Base class Vehicle hides implementation          |

---

## ▶️ How to Run

1. Install a C++ compiler (like GCC)
2. Save the code in a `.cpp` file
3. Compile:

   ```bash
   g++ filename.cpp -o output
   ```
4. Run:

   ```bash
   ./output
   ```

---

## 📋 Menu Options

1. Add a Vehicle
2. View All Vehicles
3. Search by ID
4. Exit

---

## ⚠️ Known Issues / Errors

* ❌ Missing commas in function calls:

  ```cpp
  new FlyingCar(id, manu, mdl, yr, fuel range); // error
  ```

  ✔ Fix:

  ```cpp
  new FlyingCar(id, manu, mdl, yr, fuel, range);
  ```

* ❌ Constructor call mistake:

  ```cpp
  ElectricCar(id, manu, mdl, yr, battery); // wrong inside body
  ```

  ✔ Fix using initializer list:

  ```cpp
  SportsCar(int id, string manu, string mdl, int yr, double battery, double speed)
      : ElectricCar(id, manu, mdl, yr, battery)
  {
      topSpeed = speed;
  }
  ```

* ❌ Infinite recursion:

  ```cpp
  FlyingCar::display(); // calls itself
  ```

  ✔ Fix:

  ```cpp
  Car::display();
  ```

* ❌ Multiple inheritance ambiguity may occur (Vehicle base appears twice)

---

## 🚀 Future Improvements

* Use dynamic containers (like `vector`)
* Add file storage (save/load data)
* Add delete/update vehicle feature
* Fix multiple inheritance using **virtual inheritance**

---

## 👩‍💻 Author

Disha Mehta
B.Sc. Data Science & Analytics
Full Stack Development Student

---

## 📄 License

This project is for educational purposes.
