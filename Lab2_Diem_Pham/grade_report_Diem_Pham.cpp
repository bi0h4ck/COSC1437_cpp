
//  Lab2_Diem_Pham
//
//  Created by diem pham on 11/1/16.
//  Copyright © 2016 diem pham. All rights reserved.
//

#include <functional>   // std::greater
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

void gradeCal();
int validInt();
double validDouble();
void showMenu();

int main() {
    char decision = '\0';
    do {
        showMenu();
        cin >> decision;
        if (decision == 'y' || decision == 'Y') {
            gradeCal();
        }
        else if (decision == 'n' || decision == 'N' || decision == 'e' || decision == 'E') {
            cout << "\n Exit" << endl;
        }
    } while (decision == 'y' || decision == 'Y');
    
    
    return 0;
}
void showMenu() {
    cout << "Grade Report Program" << endl;
    cout << "Do you want to use the program? Y/N" << endl;
    cout << "E = Exit the program" << endl;
}

int validInt() {
    int x;
    std::cin >> x;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value must be an integer. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

double validDouble() {
    double x;
    std::cin >> x;
    while((std::cin.fail()) || x < 1 || x > 100)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value must be a number that is greater than 1 and smaller than 100. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

void gradeCal() {
    int amount = 0;
    double grades[1];
    string name;
    ofstream outfile;
    ifstream infile;
    
    outfile.open("GradeReport.txt");
    cout << "Writing to the file" << endl;

    cout << "Please enter the amount of your grade: ";
    amount = validInt();
    
    for (int x = 0; x < amount; x++) {
        cout << "Please enter your grade " << x + 1 << ": ";
        grades[x] = validDouble();
    }
    cout << "What is your name?" << endl;
    cin >> name;
    cout << name << endl;
    outfile << name << endl;
    
    sort (grades, grades + amount, greater<int>());
    
    for (int x = 0; x < amount; x++) {
        cout << grades[x] << endl;
        outfile << grades[x] << endl;
    }
    outfile.close();
    
    infile.open("GradeReport.txt");
    
    cout << "Reading from the file" << endl;
    infile >> name;
    cout << name << endl;
    for (int x = 0; x < amount; x++) {
        infile >> grades[x];
        cout << grades[x] << endl;
    }
    infile.close();
}
