#include <iostream>
using namespace std;

int main() {
    char operate;
    float num1, num2;

    cout << "Masukkan operator \nContoh : +, -, *, / \t: ";
    cin >> operate;
    cout <<endl;

    cout << "Masukkan Dua buah angka : " <<endl;
    cout << "Angka ke-1 : ";
    cin >> num1;
    cout << endl;
    cout << "Angke ke-2 : ";
	cin >> num2;
	cout <<endl;

    switch(operate) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2;
            break;

        case '/':
            cout << num1 << " / " << num2 << " = " << num1 / num2;
            break;

        default:
            cout << "Error! operator is not correct";
            break;
    }
	return 0;
}