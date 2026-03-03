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
        cout << "4. Exit" << endl;
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
                            cout << "Insufficient. Please enter at least " << total;
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

        cout << endl;
        
    } while(choice != 4);
    
}

void adminMenu(vector<string>& menuItems,
               vector<double>& menuPrices, 
               string& ADMIN_PASSCODE) {

	int choice;
	
	do {
		cout << "\n1. View Menu\n";
		cout << "2. Add New Menu Item\n";
		cout << "3. Change Admin Passcode\n";
		cout << "4. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		
		clearScreen();
		
		if(choice == 1) {
		    displayMenu(menuItems, menuPrices);
		}

		if(choice == 2) {
            string newItem; double newPrice;
            cin.ignore();
            cout << "Enter item name: ";
            getline(cin, newItem);
            cout << "Enter price: ";
            cin >> newPrice;
            menuItems.push_back(newItem);
            menuPrices.push_back(newPrice);
		}
		
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
		
	} while(choice != 4);
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

