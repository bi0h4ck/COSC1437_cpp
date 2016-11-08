//Assignment 4 by Diem Pham

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
// #include <windows.h>



using namespace std;
double validDouble();
void showMenu();
void aveCal();
// void changeColor(int);

int main() {
	char decision = '\0';
	do { 
		aveCal();
		showMenu();	
		cin >> decision;
		system("CLEAR");	//This clear sreen command works on my mac
		//system("cls");	//uncomment this if the above doesn't work on your machine.
	}	
	while (decision == 'n'|| decision == 'N');
	
	return 0;	
}

void showMenu(){	
	cout << "Do you want to exit the program? Y/N ";	
	
}

void aveCal() {
	vector<double> gradesVector;
	double totalGrade = 0.0;
	double averageGrade = 0.0;
	double input = 0.0;

	cout <<"Welcome to grade average calculation. Please give 15 grades." << endl;
	for (int x = 0; x < 15; x++) {
		cout <<"Grade " << x + 1 << ": ";
		input = validDouble();
		gradesVector.push_back(input);
		totalGrade += gradesVector[x];
	}
	
	sort(gradesVector.begin(), gradesVector.end(), greater<double>());
	averageGrade = totalGrade/15;
	
	//changeColor(10);
	cout << "\033[1;34mHere is your grades in descending order: " << endl;

	for (int x = 0; x < 15; x++) {
		cout << noshowpoint << setprecision(4) << gradesVector[x] <<  endl;
	}
	cout << "\033[1;31mYour average grade is: " << fixed << setprecision(4) << averageGrade << "\033[0m\n";
}

double validDouble() {
    double x;
    std::cin >> x;
    while((std::cin.fail()) || x < 0 || x > 100)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value must be a number that is greater than or equal 0 and smaller than 100. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

// void changeColor(int colorValue) //function with no return type, 1 paramter to change colors
// {
//     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //use of SetConsoleTextAttribute()
//     SetConsoleTextAttribute(console,colorValue); //set the color of text to the user-value 1-255 
// }
