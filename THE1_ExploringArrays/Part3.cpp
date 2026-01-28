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
    
    int average;
    average = sum/n;
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
