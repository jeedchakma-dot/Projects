#include <iostream>
#include <limits>
#include <string>

using namespace std;

double GetValidDouble(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input! Please enter a number.\n";
    }
}

class BankCalculation {
private:
    string account;
    double balance = 0;
    double lastDeposit = 0;
    double lastWithdraw = 0;

public:

    BankCalculation() {}

    void OpenAccount() {
        cout << "Please enter the name you want to give your account : ";
        cin >> account;

        cout << "\nAccount created Successfully!" << endl;
        cout << "Dear customer your account name is : " << account << endl;
    }

    void ShowBalance() {
        cout << "\nDear customer your balance is : " << balance << endl;
    }

    void Deposit() {

        double amount =
            GetValidDouble("Enter your deposit amount : ");

        if (amount < 500) {
            cout << "\nThe minimum deposit must be at least 500." << endl;
            return;
        }

        balance += amount;
        lastDeposit = amount;

        cout << "\nDear customer you deposited : "
             << amount << endl;

        cout << "Your current balance is : "
             << balance << endl;
    }

    void Withdraw() {

        double amount =
            GetValidDouble("Enter the amount you want to withdraw : ");

        if (amount < 500) {
            cout << "\nThe minimum withdrawal must be at least 500."
                 << endl;
            return;
        }

        if (amount > balance) {
            cout << "\nYour account balance is insufficient for this withdrawal amount."
                 << endl;
            return;
        }

        balance -= amount;
        lastWithdraw = amount;

        cout << "\nDear customer you have withdrawn : "
             << amount << endl;

        cout << "Your current account balance is : "
             << balance << endl;
    }

    void LastDeposit() {
        cout << "\nYour last deposit amount is : "
             << lastDeposit << endl;
    }

    void LastWithdraw() {
        cout << "\nYour last withdrawal amount is : "
             << lastWithdraw << endl;
    }
};

int main() {

    char option;
    BankCalculation b1;

    do {

        cout << "\n------------------------------------------------------------\n";
        cout << "For Account Opening Type : A\n";
        cout << "For Checking Balance Type : B\n";
        cout << "For Deposit Type : C\n";
        cout << "For Money Withdrawal Type : D\n";
        cout << "To See Last Deposit Type : W\n";
        cout << "To See Last Withdrawal Type : X\n";
        cout << "For Exiting Type : E\n";
        cout << "Type your desired option : ";

        cin >> option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input!" << endl;
            continue;
        }

        switch (toupper(option)) {

            case 'A':
                b1.OpenAccount();
                break;

            case 'B':
                b1.ShowBalance();
                break;

            case 'C':
                b1.Deposit();
                break;

            case 'D':
                b1.Withdraw();
                break;

            case 'W':
                b1.LastDeposit();
                break;

            case 'X':
                b1.LastWithdraw();
                break;

            case 'E':
                cout << "\nExited" << endl;
                break;

            default:
                cout << "\nInvalid input! Please try again."
                     << endl;
        }

    } while (toupper(option) != 'E');

    return 0;
}
