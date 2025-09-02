#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    string x;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    cout << "Sum is: " << a+b << "\n";
    cin.ignore(); // this clears the leftover newline

    cout << "Enter a full line: ";
    getline(cin, x);
    cout << "the line is: " << x << "\n";

    return 0;
}