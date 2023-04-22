#pragma once
#ifndef airgeadbanking_h
#define airgeadbanking_h

class BankingProjections {
public:
	//Default Constructor
	BankingProjections();
	//Menu options
	int userMenu();
	void finalCalculationScreen();
	double checkInput();
	//calculate the interest from user inputs
	void CalculateInterest(double InitInvest, double MonthlyAmount, int Interest, int NumYears);

//private variables
private:
	double InitInvest;
	double MonthlyAmount;
	int Interest;
	int NumYears;
};


#endif