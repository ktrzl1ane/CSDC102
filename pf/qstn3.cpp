#include <iostream>
#include <string>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class BankAccount {

private: 
    string accountHolder;
    double balance;

public:

    BankAccount(string name, double deposit) {
        accountHolder = name;
        balance = deposit;
    }

    void deposit(double amount) {
       
        balance += amount;

        cout << "\nYour deposit of Php " << amount << " has been successfully processed. Thank you!"; 
        cout << "\nCurrent Balance: Php " << balance << endl;
    }

    void withdraw(double amount) {
        
        if(amount <= balance) {
            balance -= amount;
            cout << "\nYour withdrawal of Php " << amount << " has been successfully processed. Thank you!";
            cout << "\nCurrent Balance: Php " << balance << endl;   
        }

        else {
            cout << "\nError: Insufficient funds. Please try again." << endl;
        }
    }

    void displayBalance() {
        cout << "Your current balance is Php " << balance << endl;
    }

};

int main() {

    BankAccount Octeza("Katrize Octeza", 10000);
    
    int userChoice;
    double amount;

    do {
        cout << "\n[1] Deposit    [2] Withdraw    [3] Check Balance     [4] Exit";
        cout << "\nEnter your choice: ";
        cin >> userChoice;

        clearScreen();

        if (userChoice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            Octeza.deposit(amount);
        }
        
        else if (userChoice == 2) {
            cout << "Enter withdraw amount: ";
            cin >> amount;
            Octeza.withdraw(amount);
        }
        
        else if (userChoice == 3) {
            Octeza.displayBalance();
        }

        else if (userChoice == 4) {
            break;
        }
    
        else {
            cout << "Invalid choice. Try again." << endl;
        }

    } while (userChoice != 4);

    return 0;
}
