#include <iostream>
using namespace std;

// Ternary Search (Recursive)
int ternarySearchRecursive(int arr[], int key, int l, int r) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1]) {
            return ternarySearchRecursive(arr, key, l, mid1 - 1);
        } else if (key > arr[mid2]) {
            return ternarySearchRecursive(arr, key, mid2 + 1, r);
        } else {
            return ternarySearchRecursive(arr, key, mid1 + 1, mid2 - 1);
        }
    }
    return -1;
}

// Ternary Search (Iterative)
int ternarySearchIterative(int arr[], int n, int key) {
    int l = 0, r = n - 1;

    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;

        if (key < arr[mid1]) {
            r = mid1 - 1;
        } else if (key > arr[mid2]) {
            l = mid2 + 1;
        } else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Estimate position
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    int key;
    cout << "Enter key to search: ";
    cin >> key;

    // Ternary Search tests
    cout << "\nTernary Search Results:\n";
    int result = ternarySearchRecursive(arr, key, 0, n - 1);
    cout << "Recursive: ";
    (result == -1) ? cout << "Element not found" : cout << "Element found at index " << result;
    cout << endl;

    result = ternarySearchIterative(arr, n, key);
    cout << "Iterative: ";
    (result == -1) ? cout << "Element not found" : cout << "Element found at index " << result;
    cout << endl;

    // Interpolation Search test
    cout << "\nInterpolation Search Result:\n";
    result = interpolationSearch(arr, n, key);
    (result == -1) ? cout << "Element not found" : cout << "Element found at index " << result;
    cout << endl;

    return 0;
}