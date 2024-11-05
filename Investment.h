#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Investment {

public: 
	//Getters and Setter for the private variables
	double GetInitialAmount();
	void SetInitialAmount(double initialAmount);
	double GetMonthlyDeposit();
	void SetMonthlyDeposit(double monthDeposit);
	int GetInterestAmount();
	void SetInterestAmount(int interest);
	int GetNumYears();
	void SetNumYears(int years);

	//Method that returns the yearEndInfo nested vector
	vector<vector<double>> GetYearsAgg();
	
	//Calculate uses the input from the user and then runs the 
	// YearEndCalc to aggregate the months into chuncks of 12
	void YearEndCalc(vector<vector<double>> monthlyBreakdown);
	void Calculate();

private:
	//Two vectors for storing the calculation in month form
	// and in year form
	vector<vector<double>> breakdown;
	vector<vector<double>> yearEndInfo;


	//Initial variables from the user initialized with 0
	double initialInvestmentAmount=0.0;
	double monthlyDeposit=0.0;
	int interestAmount=0;
	int numYears=0;
	int yearsToMonths=0;

};

#endif