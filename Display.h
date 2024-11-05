#ifndef DISPLAY_H
#define DISPLAY_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
//Including Investment.h so we can use it in our display parameters
#include "Investment.h"
using namespace std;
class Display {
public:
	//Defining the different screens in the application
	void MainMenu();
	void InterestScreen(vector<vector<double>> projection);
	void InitialInvestmentScreen(Investment& newInvestment);
	void CurrentInitialInvestments(Investment newInvestment);

	//These are more for helping
	string HeaderTemplate(string title);
	string PrintNTimes(size_t numTimes, char repeatSymbol);
	char GetHeaderSymbol();
	void SetHeaderSymbol(char newChar);
	Display();
//Display variables to adjust size
//(not implemented currently) 
private:

	int width;
	int height;
	int minWidth;
	int maxWidth;
	int minHeight;
	int maxHeight;
	char headerSymbol;
};






#endif
