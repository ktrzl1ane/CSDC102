#include <iostream>
using namespace std;

void bubbleSort(int* arr, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}


int main() {
    
    int num[5];
    cout << "Enter 5 integers: ";

    for(int i = 0; i < 5; i++) {
        cin >> num[i];
    }

    cout << "\nBefore: ";
    for(int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }

    bubbleSort(num, 5);

    cout << "\nAfter: ";
    for(int i = 0; i < 5; i++) {
        cout << num[i] << " ";
    }
    
    return 0;

}
