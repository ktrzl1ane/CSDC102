#include <iostream>

int main() {
    
    int arr[10] = {7, 9, 20, 5, 2, 8, 19, 6, 3, 1};
    int sum = 0;
    int largest, secondLargest, smallest, secondSmallest;
    
    std::cout << "Array: ";
    for(int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
        sum += arr[i];
    }
    
    std::cout << std::endl;
    std::cout << "\nSum: "<< sum;
    std::cout << "\nAverage: " << sum / 10;
    
    if(arr[0] < arr[1]) {
        largest = arr[1];
        secondLargest = arr[0];
    }
    
    else {
        largest = arr[0];
        secondLargest = arr[1];
    }
    
    for(int i = 2; i < 10; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
      }
    }
    
    std::cout << "\nSecond Largest: " << secondLargest;
    
    if(arr[0] > arr[1]) {
        smallest = arr[1];
        secondSmallest = arr[0];
    }
    
    else {
        smallest = arr[0];
        secondSmallest = arr[1];
    }
    
    for(int i = 2; i < 10; i++) {
        if(arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    
    std:: cout << "\nSecond Smallest: " << secondSmallest;
    
    std::cout << "\nReversed Array: ";
    for(int i = 9; i >= 0; i--){
        std::cout << arr[i] << " ";
    }
    
    return 0;
}
