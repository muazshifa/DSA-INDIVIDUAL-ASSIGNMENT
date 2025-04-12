#include <iostream>

// Iterative Binary Search
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        if (arr[mid] == target) {
            return mid; // Target found
        }
        if (arr[mid] < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; // Base case: target not found
    }

    int mid = left + (right - left) / 2; // Avoids overflow
    if (arr[mid] == target) {
        return mid; // Target found
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right); // Right half
    }
    return binarySearchRecursive(arr, target, left, mid - 1); // Left half
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Test Iterative Binary Search
    int iterativeResult = binarySearchIterative(arr, size, target);
    std::cout << "Iterative: Element " << target << " found at index: " 
              << iterativeResult << std::endl;

    // Test Recursive Binary Search
    int recursiveResult = binarySearchRecursive(arr, target, 0, size - 1);
    std::cout << "Recursive: Element " << target << " found at index: " 
              << recursiveResult << std::endl;

    return 0;
}