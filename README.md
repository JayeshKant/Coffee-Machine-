☕ Coffee Machine Simulator
Version: 1.0.0
Language: C++ (Modern C++17)

🚀 Overview
The Coffee Machine Simulator is a realistic, interactive simulation of a coffee vending machine built in C++. It manages coffee brewing, payment processing, inventory, and maintenance—just like a real coffee machine!

This project is designed for learning, experimenting, and demonstrating object-oriented programming (OOP) principles, featuring a layered architecture with separate business logic, logging, and user interface layers.

🎯 Features
✔️ Order Coffee: Espresso, Cappuccino, Latte ☕
✔️ Payment System: Add funds, process payments 💰
✔️ Inventory Management: Track coffee beans, water, and cups 📦
✔️ Brewing Simulation: Simulated coffee brewing with step-by-step process 🔥
✔️ Maintenance System: Automatic & manual maintenance check-ups 🛠️
✔️ Logging System: Tracks all events and errors with timestamped logs 📜
✔️ Interactive Console UI: User-friendly text-based interface 💻
✔️ Expandable Architecture: Easily add new coffee types and features 🔧

🏗️ Project Structure
bash
Copy
Edit
📂 CoffeeMachine/
│── 📜 main.cpp               # Main entry point (Console Interface)
│── 📜 PaymentModel.h/.cpp     # Handles user balance & payments
│── 📜 InventoryModel.h/.cpp   # Manages coffee resources
│── 📜 BrewingModel.h/.cpp     # Simulates brewing process
│── 📜 BrewingEngine.h/.cpp    # Low-level brewing functions
│── 📜 MaintenanceModel.h/.cpp # Tracks & performs maintenance
│── 📜 LoggerModel.h/.cpp      # Logs all system events & errors
│── 📜 CoffeeRecipes.h/.cpp    # Defines coffee recipes (Espresso, Cappuccino, etc.)
│── 📜 CoffeeMachineViewModel.h/.cpp  # Business logic & UI mediator
│── 📜 Config.h                # Global configuration & constants
│── 📜 README.md               # Project Documentation (this file!)
🛠️ Installation & Setup
1️⃣ Prerequisites
Ensure you have G++ (MinGW) or any C++17-compatible compiler installed.

Windows: Install MinGW-w64
Linux/macOS: Ensure g++ is installed (sudo apt install g++ for Ubuntu)
2️⃣ Clone the Repository
sh
Copy
Edit
git clone https://github.com/waditouil/CoffeeMachine.git
cd CoffeeMachine
3️⃣ Compile the Code
sh
Copy
Edit
g++ -std=c++17 -o CoffeeMachine main.cpp PaymentModel.cpp InventoryModel.cpp BrewingModel.cpp BrewingEngine.cpp MaintenanceModel.cpp LoggerModel.cpp CoffeeMachineViewModel.cpp
4️⃣ Run the Program
sh
Copy
Edit
./CoffeeMachine
🎮 How to Use
Main Menu:
pgsql
Copy
Edit
1. Order Espresso ($5.0)
2. Order Cappuccino ($6.0)
3. Order Latte ($7.0)
4. Add Funds
5. Refill Inventory
6. Maintenance Menu
7. Show Log History
0. Exit
Maintenance triggers automatically after every 2 uses.
Users cannot order coffee when maintenance is required.
Log history tracks all actions performed.
🔥 Demo (Example Usage)
vbnet
Copy
Edit
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

[EVENT 2025-02-18 14:35:02] Coffee order processed: Espresso
[EVENT 2025-02-18 14:35:03] Brewing coffee...
Grinding beans...
Heating water...
Pre-infusing coffee grounds...
Extracting coffee...
Dispensing coffee...
Cleaning up brewing equipment...
[EVENT 2025-02-18 14:35:08] Coffee brewing completed.

Main Menu:
Enter your choice: 7

---- Log History ----
[EVENT 2025-02-18 14:35:02] Coffee order processed: Espresso
[EVENT 2025-02-18 14:35:03] Brewing coffee...
[EVENT 2025-02-18 14:35:08] Coffee brewing completed.
---------------------
🛠️ Roadmap / Future Features
🚀 Phase 2: Expanding Functionality
✅ Implemented console-based UI
✅ Automatic & manual maintenance
✅ Interactive logging system

🔜 Phase 3: GUI Integration (Qt)

 Implement a graphical UI with Qt
 Create UI buttons for orders & maintenance
 Add animations for coffee brewing
🔜 Phase 4: Machine Learning (Optional)

 Track user preferences & suggest coffees
 AI-based maintenance scheduling
📜 License
MIT License - Feel free to modify & distribute!

👨‍💻 Contributing
Pull requests are welcome! If you’d like to improve the project, feel free to contribute.

🌟 Credits
Inspiration: Real-world coffee machines ☕
Technologies Used: C++17
💡 Final Thoughts
The Coffee Machine Simulator is a perfect beginner-friendly project to understand OOP, system design, and user interaction while keeping the fun factor high. Stay caffeinated and keep coding! 🚀
