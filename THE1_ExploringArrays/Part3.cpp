#include <iostream>

int main() {
    
    int n;
    
    std::cout << "Enter number of elements: ";
    std::cin >> n;
    
    std::cout << "Enter numbers: ";
    int arr[n];
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
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
    
    float average;
    average = (float)sum/n;
    std::cout << "\nAverage: " << average << std::endl;
    
    std::cout << "\nElement Classification by Average: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " - ";
        if(arr[i] > average) {
            std::cout << "Above Average" << std:: endl;
        }
        else {
            std::cout << "Below or Equal Average" << std:: endl;
        }
    }
    
    // Optional Challenge
    std::cout<< "-------------------------------" << std::endl;
    std::cout << "Reversing Array..." << std::endl;
    
    /* reverse array through a loop iterating until the first half then 
    swapping each element w/ corresponding element on the other half */
    for(int i = 0; i < n / 2; i++) { 
        int temp = arr[i]; // store the value of the element at index i in a temporary variable
        arr[i] = arr[n - 1 - i]; // assign the element from the other half (index n-1-i) to the first half (index i)
        arr[n - 1 - i] = temp; // place the stored first half value into the other half position to complete the swap
    }

    // Repeat the analysis on the reversed array
    largest = arr[0];
    smallest = arr[0];
    sum = 0;
    
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
    
    average = (float)sum/n;
    std::cout << "\nAverage: " << average << std::endl;
    
    std::cout << "\nElement Classification by Average: " << std::endl;
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " - ";
        if(arr[i] > average) {
            std::cout << "Above Average" << std:: endl;
        }
        else {
            std::cout << "Below or Equal Average" << std:: endl;
        }
    }

    return 0;
}
