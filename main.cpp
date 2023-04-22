#include "airgeadbanking.h"
#include <iostream>
#include <iomanip>

using namespace std;
//main
int main() {
	BankingProjections menu; //user menu 
	menu.userMenu();       
	menu.finalCalculationScreen();//final calculation screen
}