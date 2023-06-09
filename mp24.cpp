#include <iostream>

using namespace std;

void print_asterisk(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        for (int k = 0; k < n - i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    char choice;
    do {
        int n;
        cout << "Enter the number of asterisk per line: ";
        cin >> n;
        print_asterisk(n);
        cout << "Try again? [Y/N or y/n]: ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return 0;
}