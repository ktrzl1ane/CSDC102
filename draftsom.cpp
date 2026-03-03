#include <iostream>
#include <vector>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMenu(const vector<string>& menuItems,
                 const vector<double>& menuPrices) {
	cout << "=============================\n";
	cout << "            MENU\n";
	cout << "=============================\n";
	for(int i = 0; i < menuItems.size(); i++) {
		cout << i << ". "
		     << menuItems[i]
		     << " - \u20b1"
		     << menuPrices[i] << endl;
	}
}

int login(string& ADMIN_PASSCODE) {
	int role;
	string passcode;

	cout << "[1] User   [2] Admin   [3] Shutdown\n";
	cout << "Enter choice: ";
	cin >> role;

	if(role == 2) {
		cout << "Enter Admin Passcode: ";
		cin >> passcode;
		if(passcode != ADMIN_PASSCODE) return 0; // invalid
	}
	return role;  // 1, 2, or 3
}

void userMenu(vector<string>& menuItems,
              vector<double>& menuPrices) {
                  
    
    vector<string> receiptItems;
    vector<double> receiptPrices;
    vector<int> receiptQuantities;
    
    int choice;
    
    do {
        cout << "==== SELF-ORDERING MACHINE ===" << endl;
        cout << "1. View Menu" << endl;
        cout << "2. Add Item to Receipt" << endl;
        cout << "3. View Receipt / Checkout" << endl;
        cout << "4. Clear Receipt" << endl;
        cout << "5. Remove Item from Receipt" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        clearScreen();
        
        if(choice == 1) {
            displayMenu(menuItems, menuPrices);
        }
        
        else if(choice == 2) {
            int index;
            int quantity;
            
            displayMenu(menuItems, menuPrices);
            
            cout << "\nEnter item number to add: ";
            cin >> index;
            
            if(index >= 0 && index < menuItems.size()) {
                cout << "Enter quantity: ";
                cin >> quantity;
                
                bool found = false;

                for(int i = 0; i < receiptItems.size(); i++) {
                    if(receiptItems[i] == menuItems[index]) {
                        receiptQuantities[i] += quantity;
                        found = true;
                        break;
                    }
                }

                if(!found) {
                    receiptItems.push_back(menuItems[index]);
                    receiptPrices.push_back(menuPrices[index]);
                    receiptQuantities.push_back(quantity);
                }

                cout << "Item added successfully.\n";
            }
            
            else {
                cout << "Invalid item index.\n";
            }
        }
        
        else if(choice == 3) {
            
            if(receiptItems.empty()) {
                cout << "No items ordered yet." << endl;
            }
            
            else {
                double total = 0;
                
                cout << "========= RECEIPT =========" << endl;
                for(int i = 0; i < receiptItems.size(); i++) {
                    double subtotal = receiptPrices[i] * receiptQuantities[i];
                    cout << i + 1 << ". " << receiptItems[i] << " x" << receiptQuantities[i] << " - Php" << subtotal << endl;
                    total += subtotal;
                }
                
                cout << "Total Price: " << total << endl;
                cout << "===========================" << endl;

                cout << "Do you want to checkout and pay? (Y/N): ";
                char checkout;
                cin >> checkout;
                
                if(checkout == 'Y' || checkout == 'y') {
                    double payment;
                    do {
                        cout << "Enter payment amount: ";
                        cin >> payment;
                        if(payment < total)
                            cout << "Insufficient. Please enter at least " << total << ".\n";
                    } while(payment < total);
                
                    double change = payment - total;
                    cout << "Change: " << change << endl;
                
                    // Clear receipt after successful payment
                    receiptItems.clear();
                    receiptPrices.clear();
                    receiptQuantities.clear();
                    
                    cout << "Payment successful." << endl;
                 }
            }
        }
        
        else if(choice == 4) {
            
            if(receiptItems.empty()) {
                cout << "Receipt is already empty.\n";
            }
            
            else {
                receiptItems.clear();
                receiptPrices.clear();
                receiptQuantities.clear();
                cout << "Receipt cleared successfully.\n";
            }
        }
        
        
        // Task 4:
        else if(choice == 5) {
            int index;
            
            if(receiptItems.empty()) {
                cout << "Receipt is empty.\n";
            }
            
            else {
                cout << "=== CURRENT ITEMS IN RECEIPT ===" << endl;
                for(int i = 0; i < receiptItems.size(); i++) {
                    cout << i << ". " << receiptItems[i] << " x" << receiptQuantities[i] <<" - Php" << receiptPrices[i] << endl;
                }
                cout << "================================" << endl;
            
                cout << "Enter receipt index to remove: ";
                cin >> index;
            
                if(index >= 0 && index < receiptItems.size()) {
                    
                    int quantity = receiptQuantities[index];
                    int decision;
                    
                    if(quantity > 1) {
                        cout << "Press: 1 - Reduce quantity by 1.\n";
                        cout << "       0 - Remove item entirely.\n";
                        cout << "Enter choice: ";
                        cin >> decision;
                        
                        if (decision == 1) {
                            receiptQuantities[index]--;
                            cout << "Successfully reduced quantity by 1.\n";
                        }
                        
                        else if(decision == 0) {
                            receiptItems.erase(receiptItems.begin() + index);
                            receiptPrices.erase(receiptPrices.begin() + index);
                            receiptQuantities.erase(receiptQuantities.begin() + index);
                            cout << "Item removed successfully.\n";
                        }
                        
                        else {
                            cout << "Invalid input.\n";
                        }
                    }
                    
                    else if(quantity == 1) {
                        receiptItems.erase(receiptItems.begin() + index);
                        receiptPrices.erase(receiptPrices.begin() + index);
                        receiptQuantities.erase(receiptQuantities.begin() + index);
                        cout << "Item removed successfully.\n";
                    }
                    
                    else {
                        cout << "Invalid input.\n";
                    }
                }
            
                else {
                    cout << "Invalid input.\n";
                }
            }
        }

        cout << endl;
        
    } while(choice != 6);
    
}

void adminMenu(vector<string>& menuItems,
               vector<double>& menuPrices, 
               string& ADMIN_PASSCODE) {

	int choice;
	
	do {
		cout << "\n1. View Menu\n";
		cout << "2. Add New Menu Item\n";
		cout << "3. Change Admin Passcode\n";
		cout << "4. Edit Existing Menu Item\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		
		clearScreen();
		
		if(choice == 1) {
		    displayMenu(menuItems, menuPrices);
		}

		else if(choice == 2) {
            string newItem; double newPrice;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, newItem);
            cout << "Enter price: ";
            cin >> newPrice;
            menuItems.push_back(newItem);
            menuPrices.push_back(newPrice);
		}
		
		//Task 3:
		else if(choice == 3) {
		    
		    string currPass, newPass;
		    
		    cout << "Enter Current Passcode: ";
		    cin >> currPass; 
		    
		    if(currPass == ADMIN_PASSCODE) { //check current passcode to confirm
		        cout << "Enter New Passcode: "; 
		        cin >> newPass;
		        
		        ADMIN_PASSCODE = newPass; //update passcode
		        
		        cout << "Admin Passcode changed successfully.\n";
		    }
		    else {
		        cout << "Incorrect current passcode.\n";
		    }
		}
		
		//Task 5:
		else if(choice == 4) {
		    
            displayMenu(menuItems, menuPrices);
		    
            int index;
            cout << "\nEnter what item index to edit: ";
            cin >> index;
            
            if(index >= 0 && index < menuItems.size()) {
                
                int decision;
                cout << "Edit: 1 - Name\n";
                cout << "      2 - Price\n";
                cout << "      3 - Both\n";
                cout << "Enter choice: ";
                cin >> decision;
                
                if(decision == 1) {
                    string newName;
                    cin.ignore();
                    cout << "Enter New Name: ";
                    getline(cin, newName);
                    menuItems[index] = newName;
                    cout << "Successfully edited item name.\n";
                }
                
                else if(decision == 2) {
                    double newPrice;
                    cout << "Enter New Price: ";
                    cin >> newPrice;
                    menuPrices[index] = newPrice;
                    cout << "Successfully edited item price.\n";
                }
                
                else if(decision == 3) {
                    string newName;
                    cin.ignore();
                    cout << "Enter New Name: ";
                    getline(cin, newName);
                    menuItems[index] = newName;
                    
                    double newPrice;
                    cout << "Enter New Price: ";
                    cin >> newPrice;
                    menuPrices[index] = newPrice;
                    
                    cout << "Successfully edited item name and price.\n";
                }
                
                else {
                    cout << "Invalid input.\n";
                }
            }
            
            else {
                cout << "Invalid input.\n";
            }
		}
		
	} while(choice != 5);
}

int main() {
	vector<string> menuItems = {"Burger","Fries","Coke","Chicken"};
	vector<double> menuPrices = {99, 49, 39, 129};
	
	string ADMIN_PASSCODE = "6767";

	while(true) {
		int role = login(ADMIN_PASSCODE);
		if(role == 1) userMenu(menuItems, menuPrices);
		else if(role == 2) adminMenu(menuItems, menuPrices, ADMIN_PASSCODE);
		else if(role == 3) {
			break;    // shutdown
		}
		else {
			cout << "Access Denied.\n";
			break;
		}
	}
	return 0;
}

