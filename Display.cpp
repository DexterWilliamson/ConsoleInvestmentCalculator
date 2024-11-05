#include "Display.h"
using namespace std;


//This is the initial display of the program
void Display::MainMenu()
{
	//Storing the menu options in an array so I can update and access them easier
	vector<string> menuOptions = {"New Investment Calculation", "View Investment Calculation", "Current Initial Investments", "Quit"};

	//Initial greeting
	cout << HeaderTemplate("Welcome to the Investment Calculator!") << endl << endl;
	
	//Iterates over the menuOptions and adds the same format to all the options
	for (int i = 0; i < menuOptions.size();  i++) {
		cout << PrintNTimes(5, ' ') << i+1 << ". " << menuOptions[i] << endl;

	}

	
}

// Displays the yearly investment projections
void Display::InterestScreen(vector<vector<double>> projection)
{
	//Headers stored in a vector for quick updating
	vector<string> headers = {"Year", "Yearly Starting Amount", "Yearly Deposit Total", "Yearly Interest Total", "Yearly End Amount" };
	
	cout << HeaderTemplate("Interest with Monthly!") << endl;

	cout << PrintNTimes(minWidth, '=') << endl;
	
	//Using the setw function to align the headers and the data
	cout << setw(20) << left << headers[0] << setw(30) << left << headers[1] << setw(30) << left << headers[2] << setw(30) << left << headers[3] << setw(20) << left << headers[4] << endl << endl;
	cout << PrintNTimes(minWidth, '-') << endl;

	//Loop through the vector that has the years calculations and align
	for (int i = 0; i < projection.size(); i++) {
		cout << setw(20) << fixed << i+ 1;
		cout << setw(30) << fixed << setprecision(2) << projection[i][0] << setw(30) << left <<  projection[i][2] << setw(30) << left << projection[i][3] << setw(20) << left << projection[i][5];
		cout << endl << endl;
	}

	//Clear out the cin so the user can press a key to move forward
	cin.ignore();
	cout << "Press any button to continue";
	cin.get();
	
	cout << HeaderTemplate("Interest without Monthly!") << endl;
	cout << PrintNTimes(minWidth, '=') << endl;
	cout << setw(20) << left << headers[0] << setw(30) << left << headers[1] << setw(30) << left << headers[2] << setw(30) << left << headers[3] << setw(20) << left << headers[4] << endl << endl;
	cout << PrintNTimes(minWidth, '-') << endl;
	for (int i = 0; i < projection.size(); i++) {
		
		cout << setw(20) << fixed << i + 1;
		cout << setw(20) << "\t\t" << fixed << setprecision(2) << projection[i][1] << "\t\t" << 0.0 << "\t\t" << projection[i][4] << "\t\t" << projection[i][6];
		cout << setw(30) << fixed << setprecision(2) << projection[i][0] << setw(30) << left << projection[i][2] << setw(30) << left << projection[i][3] << setw(20) << left << projection[i][6];
		cout << endl << endl;
	}

}

void Display::InitialInvestmentScreen(Investment& newInvestment)
{
	double tempDouble;
	int tempInt;
	//Storing the menu options in an array so I can update and access them easier
	vector<string> menuOptions = { "Initial Investment Amount", "Monthly Deposit", "Annual Interest", "Number of years"};

	//This goes through each option and gets the user input for that field
	cout << HeaderTemplate("Enter Your Initial Investment!") << endl;

		cout << PrintNTimes(5, ' ') << 1 << ". " << menuOptions[0] << ": $";
		cin >> tempDouble;
		newInvestment.SetInitialAmount(tempDouble);
		cout << PrintNTimes(5, ' ') << 2 << ". " << menuOptions[1] << ": $";
		cin >> tempDouble;
		newInvestment.SetMonthlyDeposit(tempDouble);
		cout << PrintNTimes(5, ' ') << 3 << ". " << menuOptions[2] << ": %";
		cin >> tempInt;
		newInvestment.SetInterestAmount(tempInt);
		cout << PrintNTimes(5, ' ') << 4 << ". " << menuOptions[3] << ": ";
		cin >> tempInt;
		newInvestment.SetNumYears(tempInt);

}
//This function shows the user what data they entered
void Display::CurrentInitialInvestments(Investment newInvestment)
{
	//Storing the menu options in an array so I can update and access them easier
	vector<string> menuOptions = { "Initial Investment Amount", "Monthly Deposit", "Annual Interest", "Number of years" };
	cout << HeaderTemplate("Your Current Initial Investment!") << endl;

	cout << PrintNTimes(5, ' ') << 1 << ". " << menuOptions[0] << ": $" << newInvestment.GetInitialAmount() << endl;
	cout << PrintNTimes(5, ' ') << 2 << ". " << menuOptions[1] << ": $" << newInvestment.GetMonthlyDeposit() << endl;
	cout << PrintNTimes(5, ' ') << 3 << ". " << menuOptions[2] << ": %" << newInvestment.GetInterestAmount() << endl;
	cout << PrintNTimes(5, ' ') << 4 << ". " << menuOptions[3] << ": " << newInvestment.GetNumYears() << endl;
}

//This function helps standarize the headers by returning a string formatted '*' characters
string Display::HeaderTemplate(string title)
{
	size_t headerSection = (width % title.size())/2;
	return PrintNTimes(headerSection, headerSymbol) + " " + title + " " + PrintNTimes(headerSection, headerSymbol);
}

//Takes in a integer for the amount of times the character is to be printed and the character to be repeated
string Display::PrintNTimes(size_t numTimes, char repeatSymbol) {

	return string(numTimes, repeatSymbol);
}
//This was going to be used to add some customization to the headers
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
char Display::GetHeaderSymbol() {
	return headerSymbol;

}

void Display::SetHeaderSymbol(char newChar) {

	headerSymbol = newChar;

}

Display::Display()
{
	maxHeight = 1000;
	maxWidth = 1000;
	minWidth = 150;
	minHeight = 200;
	width = 50;
	height = maxHeight;
	headerSymbol = '*';
}
