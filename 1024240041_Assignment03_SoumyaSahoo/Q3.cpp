#include <iostream>
#include <stack>
using namespace std;

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    stack<char> s;
    bool balanced = true; 

    for (char c: expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                balanced = false;
                break;
            }
            char top = s.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                balanced = false;
                break;
            }
            s.pop();
        }
    }

    if (!s.empty()) balanced = false;

    if (balanced)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}



