#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    cout << "Hello, World!" << endl;

    int x;
    cout << "Enter an integer: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    int a = 5, b = 7;
    int sum = add(a, b);
    cout << "Sum of " << a << " and " << b << " is " << sum << endl;

    cout << "Counting from 0 to 4:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "  i = " << i << endl;
    }

    if (x % 2 == 0) {
        cout << x << " is even." << endl;
    }
    else {
        cout << x << " is odd." << endl;
    }

    return 0;
}
