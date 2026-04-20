#include <iostream>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Rectangle {

private:
    double width;
    double height;

public:
    
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    bool isSquare() {
        return width == height;
    }

};

int main() {

    cout << "======== SHAPE CALCULATOR =======" << endl;
    cout << "Please enter dimensions for 3 rectangles..." << endl;
    
    double firstW, firstH;
    cout << "Rectangle 1: " << endl;
    cout << "Width - ";
    cin >> firstW;
    cout << "Height - ";
    cin >> firstH;
    Rectangle one(firstW, firstH);
    
    double secondW, secondH;
    cout << "\nRectangle 2: " << endl;
    cout << "Width - ";
    cin >> secondW;
    cout << "Height - ";
    cin >> secondH;
    Rectangle two(secondW, secondH);

    double thirdW, thirdH;
    cout << "\nRectangle 3: " << endl;
    cout << "Width - ";
    cin >> thirdW;
    cout << "Height - ";
    cin >> thirdH;
    Rectangle three(thirdW, thirdH);

    clearScreen(); 

    cout << "======== SHAPE CALCULATOR =======" << endl;

    cout << "\nRECTANGLE 1 " << "(" << firstW << " x " << firstH << "):" << endl;
    cout << "Area = " << one.getArea() << endl;
    cout << "Perimeter = " << one.getPerimeter() << endl;
    cout << "Square? " << (one.isSquare() ? "Yes" : "No");

    cout << "\n--------------------------------" << endl;
    cout << "RECTANGLE 2 " << "(" << secondW << " x " << secondH << "):" << endl;
    cout << "Area = " << two.getArea() << endl;
    cout << "Perimeter = " << two.getPerimeter() << endl;
    cout << "Square? " << (two.isSquare() ? "Yes" : "No");

    cout << "\n--------------------------------" << endl;
    cout << "RECTANGLE 3 " << "(" << thirdW << " x " << thirdH << "):" << endl;
    cout << "Area = " << three.getArea() << endl;
    cout << "Perimeter = " << three.getPerimeter() << endl;
    cout << "Square? " << (three.isSquare() ? "Yes" : "No");    

    return 0;
}
