#include <iostream>

#include "Display.h"
#include "Investment.h"
using namespace std;


int main() {

	Display newDisplay;
	Investment newInvestment;
	
	
	int userInput = 0;
	while (userInput != 4) {
		newDisplay.MainMenu();
		cin >> userInput;
		switch (userInput) {

		case (1):
			newDisplay.InitialInvestmentScreen(newInvestment);
			newInvestment.Calculate();
			break;

		case (2):
			newDisplay.InterestScreen(newInvestment.GetYearsAgg());
			break;
		case (3):
			newDisplay.CurrentInitialInvestments(newInvestment);
			break;
		
		case (4):
			break;

		default:
			cout << "Input not recognized" << endl;
			break;
		}
	}

	return 0;
}