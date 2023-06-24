// Name: Patrick Coyne
// Date: 6/1/23
// Assignment: Project Two

#include <iostream>
#include <limits>
#include <string>
using namespace std;

#include "AccountBalance.h"

// Instantiate two account objects. account1 will not have monthly deposits
AccountBalance account1;
AccountBalance account2;
// Function for input validation of doubles
double inputValidationDouble(const string& t_PROMPT, const string& t_ERROR) {
    double tempDouble;
    // Loop until valid input is received
    while (true) {
        cout << t_PROMPT;
        if (cin >> tempDouble && tempDouble >= 0) {
            break;
        }
        // Print error message
        cout << t_ERROR << endl;
        //Clear buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return tempDouble;
}

// Function for input validation of integers
int inputValidationInt(const string& t_PROMPT, const string& t_ERROR) {
    int tempInt;
    // Loop until valid input is received
    while (true) {
        cout << t_PROMPT;
        if (cin >> tempInt && tempInt >= 0) {
            break;
        }
        // Print error message
        cout << t_ERROR << endl;
        // Clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return tempInt;
}

// Function to get input values from user
void getInput() {
    // Print header
    cout << string(30, '/') << endl;
    cout << string(7, ' ') << "Data Input" << endl;
    // Get initial amount from user and use input validation function
    const double INITIAL_AMOUNT = inputValidationDouble("Initial Investment Amount: $",
        "Invalid input. Please enter a valid amount.");
    // Get monthly deposit from user and use input validation function
    const double MONTHLY_DEPOSIT = inputValidationDouble("Monthly Deposit: $",
        "Invalid input. Please enter a valid amount.");
    // Get interest rate from user and use input validation function
    const int INTEREST_RATE = inputValidationInt("Annual Interest: %",
        "Invalid input. Please enter a valid rate.");
    // Get years from user and use input validation function
    const int YEARS = inputValidationInt("Number of Years: ",
        "Invalid input. Please enter a valid amount of years.");

    // Print a new line to seperate user input prompts and tables
    cout << endl;

    // Set values of the two account objects. account1 has no monthly deposit
    account1.setInitialAmount(INITIAL_AMOUNT);
    account1.setMonthlyDeposit(0.0);
    account1.setAnnualInterest(INTEREST_RATE);
    account1.setYears(YEARS);
    // Set account2 to account1 then add a monthly deposit amount to it
    account2 = account1;
    account2.setMonthlyDeposit(MONTHLY_DEPOSIT);
}

int main() {
    // Declare bool for controlling program end
    bool keepGoing = true;

    // Start program loop
    while (keepGoing) {
        // Declare char variable to hold user input at the end of program loop 
        char inputChar;
        // Call getInput function to get user input
        getInput();
        // Print header for account1 and display table for it
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
        account1.displayTable();
        // Print header for account2 and display table for it
        cout << " Balance and Interest With Additional Monthly Deposits" << endl;
        account2.displayTable();
        // Ask user if they want to run the program again or exit
        cout << "Input the letter E to exit or any other key to try different values. ";
        cin >> inputChar;
        if (inputChar == 'E' || inputChar == 'e') {
            // If user chooses to exit, change bool to false to exit loop
            keepGoing = false;
        }
    }
    return 0;
}






