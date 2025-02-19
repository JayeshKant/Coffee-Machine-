# ☕ Coffee Machine Simulator

**Version:** 1.0.0  
**Language:** C++ (Modern C++17)  

## 🚀 Overview  
The **Coffee Machine Simulator** is an interactive, text-based simulation of a coffee vending machine built in **C++**. It manages **coffee brewing, payments, inventory, and maintenance** just like a real coffee machine!  

This project is designed to **demonstrate object-oriented programming (OOP) principles** using a **layered architecture** with business logic, logging, and user interface components.

---

## 🎯 Features  
✅ **Order Coffee**: Espresso, Cappuccino, Latte  
✅ **Payment System**: Add funds, process payments  
✅ **Inventory Management**: Track coffee beans, water, and cups  
✅ **Brewing Simulation**: Simulated coffee brewing process  
✅ **Maintenance System**: Automatic & manual maintenance  
✅ **Logging System**: Tracks all events and errors  
✅ **Interactive Console UI**: Simple text-based user interaction  
✅ **Expandable Architecture**: Easily add new coffee types  

---

## 📂 Project Structure  

```
📂 CoffeeMachine/
│── 📜 main.cpp               # Main entry point (Console Interface)
│── 📜 PaymentModel.h/.cpp     # Handles user balance & payments
│── 📜 InventoryModel.h/.cpp   # Manages coffee resources
│── 📜 BrewingModel.h/.cpp     # Simulates brewing process
│── 📜 BrewingEngine.h/.cpp    # Low-level brewing functions
│── 📜 MaintenanceModel.h/.cpp # Tracks & performs maintenance
│── 📜 LoggerModel.h/.cpp      # Logs system events & errors
│── 📜 CoffeeRecipes.h/.cpp    # Defines coffee recipes
│── 📜 CoffeeMachineViewModel.h/.cpp  # Business logic & UI mediator
│── 📜 Config.h                # Global configuration & constants
│── 📜 README.md               # Project Documentation
```

---

## 🛠️ Installation & Setup  

### 1️⃣ **Prerequisites**  
Ensure you have **G++ (MinGW) or any C++17-compatible compiler** installed.  

- **Windows:** Install [MinGW-w64](https://www.mingw-w64.org/downloads/)  
- **Linux/macOS:** Ensure `g++` is installed (`sudo apt install g++` for Ubuntu)  

### 2️⃣ **Clone the Repository**
```sh
git clone https://github.com/waditouil/CoffeeMachine.git
cd CoffeeMachine
```

### 3️⃣ **Compile the Code**  
```sh
g++ -std=c++17 -o CoffeeMachine main.cpp PaymentModel.cpp InventoryModel.cpp BrewingModel.cpp BrewingEngine.cpp MaintenanceModel.cpp LoggerModel.cpp CoffeeMachineViewModel.cpp
```

### 4️⃣ **Run the Program**
```sh
./CoffeeMachine
```

---

## 🎮 How to Use  

### 📜 **Main Menu**  
```
1. Order Espresso ($5.0)
2. Order Cappuccino ($6.0)
3. Order Latte ($7.0)
4. Add Funds
5. Refill Inventory
6. Maintenance Menu
7. Show Log History
0. Exit
```

- **Maintenance triggers automatically after every 2 uses.**  
- **Users cannot order coffee when maintenance is required.**  
- **Log history tracks all actions performed.**

---

## 🔥 Demo (Example Usage)  

```
Welcome to the Coffee Machine Interactive Test!
Initial user balance: $50.0

Main Menu:
1. Order Espresso ($5.0)
2. Order Cappuccino ($6.0)
3. Order Latte ($7.0)
4. Add Funds
5. Refill Inventory
6. Maintenance Menu
7. Show Log History
0. Exit
Enter your choice: 1

[EVENT] Coffee order processed: Espresso
[EVENT] Brewing coffee...
Grinding beans...
Heating water...
Pre-infusing coffee grounds...
Extracting coffee...
Dispensing coffee...
Cleaning up brewing equipment...
[EVENT] Coffee brewing completed.

Main Menu:
Enter your choice: 7

---- Log History ----
[EVENT] Coffee order processed: Espresso
[EVENT] Brewing coffee...
[EVENT] Coffee brewing completed.
---------------------
```

---

## 🛠️ Roadmap / Future Features  
🚀 **Phase 2: Expanding Functionality**  
✅ Console-based UI  
✅ Automatic & manual maintenance  
✅ Interactive logging system  

🔜 **Phase 3: GUI Integration (Qt)**  
- [ ] Implement a graphical UI with Qt  
- [ ] Create UI buttons for orders & maintenance  
- [ ] Add animations for coffee brewing  

🔜 **Phase 4: Machine Learning (Optional)**  
- [ ] Track user preferences & suggest coffees  
- [ ] AI-based maintenance scheduling  

---

## 📜 License  
MIT License - Feel free to modify & distribute!  

## 👨‍💻 Contributing  
Pull requests are welcome! If you’d like to improve the project, feel free to contribute.  

---

## 🌟 Credits  
- **Inspiration:** Real-world coffee machines  
- **Technologies Used:** C++17  Doxygen

---


Stay caffeinated and keep coding! 🚀☕  
