#include <iostream>
using namespace std;

class InsufficientFundsException {};

class BankAccount {
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    void withdraw(double amount) {
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
    }
    double getBalance() { return balance; }
};

int main() {
    BankAccount acc(500);
    cout << "Current Balance: $" << acc.getBalance() << endl;
    
    try {
        cout << "Enter withdrawal amount: $";
        double amount;
        cin >> amount;
        acc.withdraw(amount);
        cout << "Withdrawal successful! New Balance: $" << acc.getBalance() << endl;
    } catch (InsufficientFundsException) {
        cout << "Error: Insufficient funds to complete withdrawal!" << endl;
    }

    return 0;
}