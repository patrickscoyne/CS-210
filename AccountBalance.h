// Name: Patrick Coyne
// Date: 6/1/23
// Assignment: Project Two

// #define guard to prevent multiple inclusion
#ifndef ACCOUNTBALANCE_ACCOUNTBALANCE_H_
#define ACCOUNTBALANCE_ACCOUNTBALANCE_H_

class AccountBalance {
public:
    // Setter functions for setting account values
    void setInitialAmount(const double& t_INITIAL_AMOUNT);
    void setMonthlyDeposit(const double& t_MONTHLY_DEPOSIT);
    void setAnnualInterest(const int& t_ANNUAL_INTEREST);
    void setYears(const int& t_YEARS);

    // Function to display account balance table
    void displayTable() const;

private:
    // Private variables
    double m_initialAmount;
    double m_monthlyDeposit;
    int m_annualInterest;
    int m_years;
};

#endif // ACCOUNTBALANCE_ACCOUNTBALANCE_H_