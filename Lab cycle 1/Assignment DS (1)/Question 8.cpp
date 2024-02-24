#include <iostream>
#include <unordered_map>


int countDuplicates(const char arr[], int size) {
    std::unordered_map<char, int> frequencyMap;
    int duplicateCount = 0;
    
    for (int i = 0; i < size; i++) {
        frequencyMap[arr[i]]++;
    }
    
    for (const auto& pair : frequencyMap) {
        if (pair.second > 1) {
            duplicateCount++;
        }
    }
    
    return duplicateCount;
}

int main() {
    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    
    char arr[size];
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    
    int duplicateCount = countDuplicates(arr, size);
    std::cout << "Total number of duplicate elements: " << duplicateCount << std::endl;
    
    return 0;
}

/* output: 
enter the sizw of array : 10
enter the elements of the array : 1 1 1 44 3 5 6 44 6 7
total number of duplicate elements : 2
*/
