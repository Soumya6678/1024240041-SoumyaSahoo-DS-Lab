#include <iostream>
using namespace std;

// Linear Search: O(n)
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;
}

// Binary Search: O(log n)

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 5, 7, 9, 13, 21, 34, 55, 89}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter element to search: ";
    cin >> target;

    // Linear Search
    int resultLinear = linearSearch(arr, n, target);
    if (resultLinear != -1)
        cout << "Linear Search: Element found at index " << resultLinear << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Binary Search
    int resultBinary = binarySearch(arr, n, target);
    if (resultBinary != -1)
        cout << "Binary Search: Element found at index " << resultBinary << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
