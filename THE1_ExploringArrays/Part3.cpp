#include <iostream>

int main() {
    
    int n;
    std::cin >> n;
    
    std::cout << "Enter values: ";
    int arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        std::cout << arr[i] << " ";
    }
    
    int largest = arr[0];
    int smallest = arr[0];
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
    }
    
    std::cout << "\nLargest: " << largest;
    std::cout << "\nSmallest: " << smallest;
    std::cout << "\nSum: " << sum;

    return 0;
}
