#include "airgeadbanking.h"
#include <iomanip>
#include <vector>
#include <cctype>
#include <limits>
#include <iostream>
#include <stdexcept>


using namespace std;
//Title line with bank name and prompts to get user input
int BankingProjections::userMenu() {

	cout << setw(53) << setfill('-') << "-" << endl;
	cout << setw(18) << setfill('-') << "-";
	cout << " AIRGEAD BANKING ";
	cout << setw(18) << setfill('-') << "-" << endl;  //Border and title of bank along with instructions that user sees on the screen.
	cout << setw(53) << setfill('-') << "-" << endl;
	cout << "     Follow the prompts below using only numbers" << endl;
	cout << "                     Thank you! " << endl;
	cout << setw(53) << setfill(' ') << " " << endl;
	
	//Ask the user for their initial investment amount
	cout << setw(28) << setfill(' ') << left << "Please enter your initial investment amount: ";//output the user sees on screen
	InitInvest = checkInput();//puts users input to InitInvest variable and calls function used to check the users input for validness
	cout << "$";
	cout << fixed << setprecision(2) << InitInvest << endl; //outputs users input to screen with added $ 
	
	//Ask the user for their monthly deposit amount
	cout << setw(28) << setfill(' ') << left << "Please enter your monthly deposit amount:";//output the user sees on screen
	MonthlyAmount = checkInput();//adds what user enters to monthly amount and also checks their input for validness
	cout << "$";
	cout << fixed << setprecision(2) << MonthlyAmount << endl;//outputs users input to screen with added $
	
	// Ask the user for their annual interest rate
	cout << setw(32) << setfill(' ') << left << "Please enter your annual interest rate:";//output the user sees on screen
	Interest = checkInput();//adds what user enters to interest variable and checks input for validnesss
	cout << "%" << Interest << endl;//outputs users input to the screen with added %
	
	//Ask the user for the set amount of years they want to report
	cout << setw(32) << setfill(' ') << left << "Please enter the number of years:";//output the user sees on screen
	NumYears = checkInput();//adds what the user enters to numyears variable and checks input for validness
	cout << NumYears << endl;//outputs to screen their input
	system("pause"); /*used to pause the program and user sees press any key to continue after adding their inputs
						after pressing any key the user will be taken to the*/
	return 0;

}
void BankingProjections::finalCalculationScreen() {
	//Display screen for users final calculations with monthly deposits
	cout << "   Balance and Interest with Additional Monthly Deposits" << endl; //headline text and border for calculations
	cout << setw(60) << setfill('=') << "=" << endl;
	cout << "Year\t" << "    Year End Balance\t" << "    Year end Earned Interest" << endl; //calculations
	//calling function to get calculations for output
	CalculateInterest(this->InitInvest, this->MonthlyAmount, this->Interest, this->NumYears);

	cout << endl;//extra lines for spacing
	cout << endl;

	//output for final calculations without added monthly deposits
	cout << "   Balance and Interest without Additional Monthly Deposits" << endl; //headline text and border for these calculations
	cout << setw(60) << setfill('=') << "=" << endl;
	cout << "Year\t" << "    Year End Balance\t" << "    Year end Earned Interest" << endl; //calculations
	//calling function to get calculations for output
	CalculateInterest(this->InitInvest, 0, this->Interest, this->NumYears);

}
//function to calculate interest based on users inputs
void BankingProjections::CalculateInterest(double InitInvest, double MonthlyAmount, int Interest, int NumYears) {
	int i,
		j,
		k;
	double newAmount = InitInvest;
	double interest = Interest; 
	double totalInterest = 0;
	const int NUM_OF_MONTHS = 12; // Months in a year
	double compoundInterest;
	vector<double> interests; // vector to add up year end interest
	//Calculations for interest using users inputs
	for (i = 1; i <= NumYears; i++) { //loops through the number of years the user inputs and outputs
		for (j = 1; j <= NUM_OF_MONTHS; j++) { //loops through 12 months in a year to add monthly amount selected by user
			newAmount = (newAmount + MonthlyAmount); //adds monthly amount
			compoundInterest = newAmount * ((interest / 100) / NUM_OF_MONTHS);//finds compound interest using the interest selected by user 
			newAmount = newAmount + compoundInterest;//adds compound interest to make new amount
			interests.push_back(compoundInterest);//add compound interest to interest vector
		}
		//loop that adds up all the interest payments
		for (k = 0; k < interests.size(); k++) {
			totalInterest = interests.at(k) + totalInterest;
		}
		//output calculations to screen
		cout << i << "\t    $" << newAmount << "\t\t     $" << totalInterest << endl;;

		totalInterest = 0; //reset values for interest so they are not saved
		compoundInterest = 0;//reset values for compound interest so they are not saved
		interests.resize(0);//reset vector so they are not saved 
	}
}
//function to check users input for negative numbers or letters
double BankingProjections::checkInput() {
	double userInput;
	cin >> userInput;
	while (!cin.good() || userInput < 0) { //if user enter letter or negative number it will output a certain message depending
		cout << endl;
		if (!cin.good()) {//output message if user enters letters
			cout << "Please enter only number, not letters. Thank you!" << endl;
		}
		if (userInput < 0) {//output message if user enter negative number
			cout << "Please enter only positive numbers. Thank you!" << endl;
		}
		cin.clear(); //clear what user entered to try again
		cin.ignore(LC_MAX, '\n');//since I have usersInput as a double had to add this because I kept getting an error
		//ask for the users input again after the error
		cin >> userInput;
	}
	return userInput;
}
BankingProjections::BankingProjections() {
}
