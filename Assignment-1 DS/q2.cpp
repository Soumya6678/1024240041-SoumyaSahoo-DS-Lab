#include <iostream>
using namespace std;

int main() {
    const int MAX = 1000;
    int arr[MAX];
    int n;

    
    cout << "Enter size n: ";
    cin >> n;
    if (n < 0 || n > MAX) {
        cout << "Invalid size.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[j] == arr[i]) {
               
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;          
            } else {
                j++;          
            }
        }
    }

   
    cout << "Array with unique elements (" << n << "): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i + 1 == n ? '\n' : ' ');
    }

    return 0;
}
