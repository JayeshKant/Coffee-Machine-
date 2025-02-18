#include "PaymentModel.h"
#include "InventoryModel.h"
#include "BrewingModel.h"
#include "MaintenanceModel.h"
#include "CoffeeRecipes.h"
#include "LoggerModel.h"
#include <iostream>
#include <limits>  // for std::numeric_limits
#include <string>

int main() {
    PaymentModel payment;
    InventoryModel inventory;
    BrewingModel brewing;
    MaintenanceModel maintenance;
    LoggerModel logger;  // Create our logger

    // Add initial funds.
    payment.addBalance(50.0);
    logger.logEvent("Initial funds added: $50.0");
    
    std::cout << "Welcome to the Coffee Machine Interactive Test!\n";
    std::cout << "Initial user balance: $" << payment.getBalance() << "\n";
    
    int orderCount = 0; // Count of coffee orders since last maintenance

    bool running = true;
    while (running) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Order Espresso ($5.0)\n";
        std::cout << "2. Order Cappuccino ($6.0)\n";
        std::cout << "3. Order Latte ($7.0)\n";
        std::cout << "4. Add Funds\n";
        std::cout << "5. Refill Inventory\n";
        std::cout << "6. Maintenance Menu\n";
        std::cout << "7. Show Log History\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        
        int choice;
        std::cin >> choice;
        
        // Handle invalid input.
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            logger.logError("Invalid input entered in main menu.");
            continue;
        }
        
        if (choice == 0) {
            running = false;
            logger.logEvent("Exiting interactive test.");
            continue;
        } else if (choice == 4) {  // Add funds
            double additionalFunds;
            std::cout << "Enter amount to add: $";
            std::cin >> additionalFunds;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for funds.\n";
                logger.logError("Invalid input when adding funds.");
            } else {
                payment.addBalance(additionalFunds);
                std::cout << "New balance: $" << payment.getBalance() << "\n";
                logger.logEvent("Funds added: $" + std::to_string(additionalFunds));
            }
            continue;
        } else if (choice == 5) {  // Refill inventory
            std::cout << "\nRefill Options:\n";
            std::cout << "1. Refill Coffee Beans\n";
            std::cout << "2. Refill Water\n";
            std::cout << "3. Refill Cups\n";
            std::cout << "Enter your refill choice: ";
            int refillChoice;
            std::cin >> refillChoice;
            
            int amount;
            std::cout << "Enter amount to refill: ";
            std::cin >> amount;
            
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for refill amount.\n";
                logger.logError("Invalid input when refilling inventory.");
            } else {
                if (refillChoice == 1) {
                    inventory.refillCoffeeBeans(amount);
                    logger.logEvent("Refilled coffee beans by " + std::to_string(amount));
                } else if (refillChoice == 2) {
                    inventory.refillWater(amount);
                    logger.logEvent("Refilled water by " + std::to_string(amount) + " ml");
                } else if (refillChoice == 3) {
                    inventory.refillCups(amount);
                    logger.logEvent("Refilled cups by " + std::to_string(amount));
                } else {
                    std::cout << "Invalid refill option.\n";
                    logger.logError("Invalid refill option selected.");
                }
            }
            continue;
        } else if (choice == 6) {  // Maintenance menu
            bool maintenanceMenu = true;
            while (maintenanceMenu) {
                std::cout << "\nMaintenance Menu:\n";
                std::cout << "1. Check Maintenance Status\n";
                std::cout << "2. Trigger Maintenance\n";
                std::cout << "3. Perform Maintenance\n";
                std::cout << "0. Return to Main Menu\n";
                std::cout << "Enter your choice: ";
                int mChoice;
                std::cin >> mChoice;
                
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please try again.\n";
                    logger.logError("Invalid input in maintenance menu.");
                    continue;
                }
                
                if (mChoice == 0) {
                    maintenanceMenu = false;
                    break;
                } else if (mChoice == 1) {
                    std::cout << "Maintenance Status: " 
                              << (maintenance.needsMaintenance() ? "Required" : "Not required")
                              << "\n";
                    logger.logEvent("Checked maintenance status.");
                } else if (mChoice == 2) {
                    maintenance.triggerMaintenance();
                    logger.logEvent("Maintenance triggered by user.");
                } else if (mChoice == 3) {
                    maintenance.performMaintenance();
                    logger.logEvent("Maintenance performed by user.");
                } else {
                    std::cout << "Invalid maintenance option.\n";
                    logger.logError("Invalid option selected in maintenance menu.");
                }
            }
            continue;
        } else if (choice == 7) {  // Show log history
            logger.showLogs();
            continue;
        }
        
        // Before processing a coffee order, check maintenance status.
        if (maintenance.needsMaintenance()) {
            std::cout << "\nMaintenance is required. Please perform maintenance before ordering coffee.\n";
            logger.logEvent("Attempted to order coffee while maintenance was required.");
            continue;
        }
        
        // Process coffee orders.
        double price = 0.0;
        CoffeeType selectedType;
        if (choice == 1) {
            selectedType = CoffeeType::Espresso;
            price = 5.0;
        } else if (choice == 2) {
            selectedType = CoffeeType::Cappuccino;
            price = 6.0;
        } else if (choice == 3) {
            selectedType = CoffeeType::Latte;
            price = 7.0;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
            logger.logError("Invalid coffee order option selected.");
            continue;
        }
        
        // Retrieve the recipe for the selected coffee type.
        CoffeeRecipe recipe = getCoffeeRecipe(selectedType);
        
        // Check inventory.
        if (!inventory.hasSufficientResources(recipe)) {
            std::cout << "Insufficient resources to brew your coffee.\n";
            logger.logError("Insufficient inventory for selected coffee.");
            continue;
        }
        
        // Process payment.
        if (!payment.processPayment(price)) {
            std::cout << "Payment failed. Not enough funds.\n";
            logger.logError("Payment failed due to insufficient funds.");
            continue;
        }
        
        // Update inventory and simulate brewing.
        inventory.updateResources(recipe);
        std::cout << "Order processed. Brewing your coffee...\n";
        logger.logEvent(std::string("Coffee order processed: ") +
                        (selectedType == CoffeeType::Espresso ? "Espresso" :
                         selectedType == CoffeeType::Cappuccino ? "Cappuccino" : "Latte"));
        brewing.startBrewing();
        brewing.handleBrewStateChange();
        brewing.stopBrewing();
        
        // Increment the order counter.
        orderCount++;
        // Automatically trigger maintenance after every 2 orders.
        if (orderCount >= 2) {
            std::cout << "\n** Automatic Maintenance Triggered due to usage **\n";
            maintenance.triggerMaintenance();
            logger.logEvent("Automatic maintenance triggered after 2 orders.");
            // Reset the counter.
            orderCount = 0;
        }
        
        // Display updated status.
        std::cout << "\nUpdated Status:\n";
        std::cout << "Remaining Balance: $" << payment.getBalance() << "\n";
        std::cout << "Total Revenue: $" << payment.getRevenue() << "\n";
        std::cout << "Inventory:\n";
        std::cout << "  Coffee Beans: " << inventory.getCoffeeBeans() << "\n";
        std::cout << "  Water Level: " << inventory.getWaterLevel() << " ml\n";
        std::cout << "  Cups: " << inventory.getCups() << "\n";
        std::cout << "Maintenance Status: " 
                  << (maintenance.needsMaintenance() ? "Required" : "Not required") 
                  << "\n";
    }
    
    std::cout << "\nExiting. Thank you for using the Coffee Machine Interactive Test.\n";
    logger.logEvent("Interactive test ended.");
    
    // Optionally, show full log history before exiting.
    logger.showLogs();
    
    return 0;
}
