#include <string>
#include <iostream>
#include <vector>
#include "Investment.h"

using namespace std;
//Getters and Setters that access private varaibles
double Investment::GetInitialAmount(){
	return initialInvestmentAmount;

}

void Investment::SetInitialAmount(double initialAmount)
{
	initialInvestmentAmount = initialAmount;

}

double Investment::GetMonthlyDeposit() {
	return monthlyDeposit;

}

void Investment::SetMonthlyDeposit(double monthDeposit)
{
	monthlyDeposit = monthDeposit;
}

int Investment::GetInterestAmount()
{
	return interestAmount;
}

void Investment::SetInterestAmount(int interest)
{
	interestAmount = interest;
}

int Investment::GetNumYears()
{
	return numYears;
}

void Investment::SetNumYears(int years)
{
	numYears = years;
}

vector<vector<double>> Investment::GetYearsAgg() {
	return yearEndInfo;
}

//YearEndCalc takes in the monthly projects and aggregates them every 12 months
void Investment::YearEndCalc(vector<vector<double>> monthlyBreakdown) {
	//Last known totals for w monthly deposit and w/o monthly deposit
	double lastTotal= monthlyBreakdown[0][0];
	double lastTotalWithoutMonthly = monthlyBreakdown[0][1];
	//Keep the last index in a variable to reference months as needed
	int lastIndex=0;
	//Iterate over the number of years and add previous values together if needed
	for (int i = 0; i < numYears; i++) {
		double initialYearlyInvestment;
		double initialYearlyInvestmentWithoutMonthly;
		double yearlyDeposit=0;
		double yearlyInterest=0;
		double yearlyInterestWithoutMonthly = 0;
		//Create a temp vector to push_back to the yearEndInfo vector
		vector<double> tempVector;

		//Iterater ever 12 to add  previous values together
		for (int j = 0; j < 12; j++) {
			yearlyDeposit += monthlyBreakdown[lastIndex][2];
			yearlyInterest += monthlyBreakdown[lastIndex][4];
			yearlyInterestWithoutMonthly += monthlyBreakdown[lastIndex][5];
			lastIndex += 1;
		}

		//push_back values to the tempVecor
		tempVector.push_back(lastTotal);
		tempVector.push_back(lastTotalWithoutMonthly);
		
		tempVector.push_back(yearlyDeposit);
		tempVector.push_back(yearlyInterest);
		tempVector.push_back(yearlyInterestWithoutMonthly);
		tempVector.push_back(lastTotal);
		tempVector.push_back(lastTotalWithoutMonthly);
		//push back the tempVector to the yearEndInfo vector
		yearEndInfo.push_back(tempVector);

		//Update the last known totals to the lastIndex
		lastTotal = monthlyBreakdown[lastIndex-1][6];
		lastTotalWithoutMonthly = monthlyBreakdown[lastIndex-1][7];
	}


}
//Calculate starts with converting numYears to months
//Then it uses the user data to project future earnings
//That get stored in a tempVector before being pushed to
//The breakdown vector
void Investment::Calculate() {
	yearsToMonths = numYears * 12;
	for (int i = 0; i < yearsToMonths; i++) {
		vector<double> tempVector;

		if (i == 0) {
			//Comments for headers
			//0. Initial Monthly Investment
			tempVector.push_back(initialInvestmentAmount);

			//1. Initial Monthly Investment Without Monthly Deposit
			tempVector.push_back(initialInvestmentAmount);

			//2. Monthly Deposit Amount
			tempVector.push_back(monthlyDeposit);

			//3. Total Monthly Investment
			tempVector.push_back(tempVector[0] + tempVector[2]);

			//4. Monthly Interest Earned with Monthly Deposit
			tempVector.push_back(tempVector[3] * ((interestAmount / static_cast<double>(100)) / 12));
			
			//5. Monthly Interest Earned without Monthly Deposit
			tempVector.push_back(tempVector[1] * ((interestAmount / static_cast<double>(100)) / 12));

			//6. Monthly Total with Monthly Deposit
			tempVector.push_back(tempVector[3] + tempVector[4]);

			//7. Monthly Total without Monthly Deposit
			tempVector.push_back(tempVector[1] + tempVector[5]);
			breakdown.push_back(tempVector);
		}
		else {

			//Comments for headers
			//0. Initial Monthly Investment
			tempVector.push_back(breakdown[i - 1][6]);

			//1. Initial Monthly Investment Without Monthly Deposit
			tempVector.push_back(breakdown[i - 1][7]);

			//2. Monthly Deposit Amount
			tempVector.push_back(monthlyDeposit);

			//3. Total Monthly Investment
			tempVector.push_back(tempVector[0] + tempVector[2]);

			//4. Monthly Interest Earned with Monthly Investment
			tempVector.push_back(tempVector[3] * ((interestAmount / static_cast<double>(100)) / 12));

			//5. Monthly Interest Earned without Monthly Investment
			tempVector.push_back(tempVector[1] * ((interestAmount / static_cast<double>(100)) / 12));

			//6. Monthly Total with Monthly Investment
			tempVector.push_back(tempVector[3] + tempVector[4]);

			//7. Monthly Total without Monthly Investment
			tempVector.push_back(tempVector[1] + tempVector[5]);
			breakdown.push_back(tempVector);
		}

	}
	Investment::YearEndCalc(breakdown);


}



	
