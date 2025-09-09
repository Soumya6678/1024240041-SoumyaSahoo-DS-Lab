#include <iostream>
#include <stack>
using namespace std;

bool canBeSorted(int A[], int n) {
    int sortedA[100];  
    for (int i = 0; i < n; i++)
        sortedA[i] = A[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sortedA[j] > sortedA[j + 1]) {
                int temp = sortedA[j];
                sortedA[j] = sortedA[j + 1];
                sortedA[j + 1] = temp;
            }
        }
    }

    stack<int> st;
    int j = 0;

    for (int i = 0; i < n; i++) {
        st.push(A[i]);
        while (!st.empty() && st.top() == sortedA[j]) {
            st.pop();
            j++;
        }
    }

    return j == n;
}

int main() {
    int n;
    cin >> n;
    int A[100];  

    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (canBeSorted(A, n))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}


