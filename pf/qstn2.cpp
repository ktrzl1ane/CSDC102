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

struct Product {
    string name;
    int quantity;
    float price;
};

int main() {

    Product productDetails[5];

    cout << "======= SMALL STORE INVENTORY ======" << endl;
    int n;
    cout << "Products to enter (5 max): ";
    cin >> n;
    
    cin.ignore();

    if (n <= 5) {
        for(int i = 0; i < n; i++) {
            cout << "\nEnter product name: ";
            getline(cin, productDetails[i].name);

            cout << "Enter quantity: ";
            cin >> productDetails[i].quantity;

            cout << "Enter price: ";
            cin >> productDetails[i].price;

            cin.ignore();
        }

        clearScreen();

        cout << "======= SMALL STORE INVENTORY ======" << endl;
        cout << "Products with their Total Value:" << endl;

        string mostExpName = productDetails[0].name;
        float mostExpPrice = productDetails[0].price;

        for(int i = 0; i < n; i++) {
            cout << i + 1 << ". " << productDetails[i].name << " - Php " << productDetails[i].quantity * productDetails[i].price << endl;

            if(productDetails[i].price > mostExpPrice) {
                mostExpName = productDetails[i].name;
                mostExpPrice = productDetails[i].price;
            }
        }
        cout << "\nMost Expensive Product: " << endl;
        cout << mostExpName << " - Php " << mostExpPrice;
    }   

    else {
        cout << "Exceeds the maximum number of products to enter. Please try again.";
    }

    return 0;
}
