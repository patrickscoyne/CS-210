// Name: Patrick Coyne
// Date: 6/1/23
// Assignment: Project Two

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "AccountBalance.h"

// Setter function for setting initial amount
void AccountBalance::setInitialAmount(const double& t_INITIAL_AMOUNT) {
    m_initialAmount = t_INITIAL_AMOUNT;
}

// Setter function for setting monthly deposit
void AccountBalance::setMonthlyDeposit(const double& t_MONTHLY_DEPOSIT) {
    m_monthlyDeposit = t_MONTHLY_DEPOSIT;
}

// Setter function for setting annual interest
void AccountBalance::setAnnualInterest(const int& t_ANNUAL_INTEREST) {
    m_annualInterest = t_ANNUAL_INTEREST;
}

// Setter function for setting number of years
void AccountBalance::setYears(const int& t_YEARS) {
    m_years = t_YEARS;
}

// Function to display account balance table
void AccountBalance::displayTable() const {
    // Initialize balance to initial amount of account
    double balance = m_initialAmount;
    // Calculate interest rate per month
    double monthlyInterestRate = m_annualInterest / 12.0 / 100.0;
    // Print header for table
    cout << string(56, '/') << endl;
    cout << "Year\t\tEnd Balance\t\t  Total Interest" << endl;
    cout << string(56, '/') << endl;

    // Loop through each year
    for (int year = 1; year <= m_years; ++year) {
        double totalInterest = 0.0;  // Initialize total interest for the current year

        // Loop through each month
        for (int month = 1; month <= 12; ++month) {
            // Calculate interest for the current month
            double interest = (balance + m_monthlyDeposit) * monthlyInterestRate;
            // Update balance with monthly deposit and interest
            balance += m_monthlyDeposit + interest;
            // Update total interest for the current year
            totalInterest += interest;
        }

        // Create a stringstream for use in formatting balance
        ostringstream balanceStream;
        // Set decimals of balance to 2 places
        balanceStream << fixed << setprecision(2) << balance;
        // Convert balance to string
        string strBalance = balanceStream.str();
        // Create a stringstream for use in formatting total interest
        ostringstream interestStream;
        // Set decimals of total interest to 2 places
        interestStream << fixed << setprecision(2) << totalInterest;
        // Convert total interest to string
        string strTotalInterest = interestStream.str();

        // Print values for the year
        cout << right << setw(4) << year << "\t\t" << right << setw(11) << "$" + strBalance
            << "\t\t" << right << setw(16) << "$" + strTotalInterest << endl;
    }
    cout << endl;
}
