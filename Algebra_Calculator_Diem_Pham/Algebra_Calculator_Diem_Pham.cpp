//Lab 1 - Algebra calculation program by Diem Pham

#include<iostream>
#include <math.h>
#include<cstdlib>
#include <iomanip>
using namespace std;

void showMenu();
void calsSlope(); //function prototype
void vertexParabola();
void quadraticX();
void hypoCal();
double validInput();
double validInputNot0();
void decPlaces();


int main() {
    char decision = '\0'; //my decision variable
    do {
    //How do I get this to loop until the exit condition of 'e' and 'E' are entered "See DeMorgan's law"
        showMenu();
        cin >> decision; // accept the decision from the user, be sure to look at the ref input validation for chars
        if (decision == 'a' || decision == 'A') {
            cout << "Welcome to the slop calculation program, option A!!!" << endl;
            calsSlope(); //function call
        }
        else if (decision == 'b' || decision == 'B') {
            cout << "Welcome to the vertex of parabola calculation program, option B!!!" << endl;
            cout << "What equation do you want to use?" << endl;
            cout << "Standard form [y = ax^2 + bx + c] or Vertex form [y = a(x - h)^2 + k]" << " [S/V]" << endl;
            vertexParabola();
        }
        else if (decision == 'c' || decision == 'C') {
            cout << "Welcome to the value x of quadratic formula calculation program, option C!!!" << endl;
            cout << " Quadratic function: ax^2 + bx + c = 0" << endl;
            quadraticX();
        }
        else if (decision == 'd' || decision =='D') {
            cout << "Welcome to the hypotenuse calculation program, option D!!!" << endl;
            hypoCal();
        }
        else if (decision == 'e' || decision =='E') {
            cout <<"\n Exit" << endl;
        }
        else if (decision == 'z' || decision =='Z') {
            system("cls");
        }
        else {
            cout << "\nERROR" << endl;
        }
    } while (decision == 'a' || decision == 'A' || decision == 'b' || decision == 'B' || decision == 'c' || decision == 'C' || decision == 'd' || decision =='D' || decision == 'z' || decision =='Z');
    return 0;
}

void showMenu() {
    cout << "Algebra Calculation Program Menu" << endl;
    cout << "A = Slope Calculator" << endl;
    cout << "B = Vertex of a Parabola" << endl;
    cout << "C = Value x of Quadratic Formula" << endl;
    cout << "D = Hypotenuse calculator" << endl;
    cout << "E = Exit Calculation Program" << endl;
    cout << "Z = Clear the screen" << endl;
    cout << "Please enter: (A - E, Z or a - e, z)";
}


double validInput()
{
    double x;
    std::cin >> x;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

double validInputNot0()
{
    double x;
    std::cin >> x;
    while((std::cin.fail()) || (x == 0) )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value which must not equal to 0: ";
        std::cin >> x;
    }
    return x;
}

void decPlaces() {
    cout << noshowpoint << setprecision(4);
}

void calsSlope() //function definition slope formula m = (y2 -y1)/(x2 - x1)
{
    double m = 0.0, y2 = 0.0, y1 = 0.0, x2 = 0.0, x1 = 0.0; //declare an initialize variables
    cout << "Please enter your y2 value: ";
    y2 = validInput(); //using cin >> for now, we wil input validate later
    cout << "Please enter your y1 value: ";
    y1 = validInput();
    cout << "Please enter your x2 value: ";
    x2 = validInput();
    cout << "Please enter your x1 value: ";
    x1 = validInput();
    if ((y2 != y1) && (x1 == x2)) {
        cout << "The slope is infinitive" << endl;
    }
    else if ((y2 == y1) && (x1 == x2)) {
        cout << "Your values are invalid." << endl;
        cout << "y2 must not be equal to y1; and x2 must not be equal to x1" << endl;
        calsSlope();
    }
    else {
        m = ((y2) - (y1))/((x2) - (x1)); //calculate the slope
        //output the results to the user:
        decPlaces();
        cout << "The slope m = [(" << y2 << ") - (" << y1 << ")] / [(" << x2 << ") - (" << x1 << ")] = " << m << endl;
    }
}

void vertexParabola() {
    double a = 0.0, b = 0.0, c = 0.0, h = 0.0, k = 0.0, x = 0.0, y = 0.0;
    char choose = '\0';
    cin >> choose;
    if (choose == 's' || choose == 'S') {
        cout << "Standard form [y = ax^2 + bx + c]" << endl;
        cout << "Please enter your a value, a must not equal to 0: ";
        a = validInputNot0();
        cout << "Please enter your b value: ";
        b = validInput();
        cout << "Please enter your c value: ";
        c = validInput();
        x = (-b)/(2*(a));
        y = ((a)*(x)*(x)) + ((b)*(x)) + (c);
        decPlaces();
        cout << "The vertex of parabola y = " << a << "x^2 + (" << b << ")x + (" << c << ") is [x = -(" << b << ")/(2*(" << a << ")), y = (" << (a)*(x)*(x) << ") + (" << (b)*(x) << ") + " << (c) << "] = (" << x << ", " << y << ")" << endl;
    }
    else if (choose == 'v' || choose == 'V') {
        cout << "Vertex form [y = a(x - h)^2 + k]" << endl;
        cout << "Please enter your a value, a must not equal to 0: ";
        a = validInputNot0();
        cout << "Please enter your h value: ";
        h = validInput();
        cout << "Please enter your k value: ";
        k = validInput();
        decPlaces();
        cout << "The vertex of parabola y = " << a << "(x - (" << h << "))^2 + (" << k << ") is (" << h << ", " << k << ")" << endl;
    }
    else {
        cout << "Your input is invalid" << endl;
        cout << "Please type S for Standard form [y = ax^2 + bx + c] or type V for Vertex form [y = a(x - h)^2 + k]" << endl;
        vertexParabola();
    }
}

void quadraticX() {
    double a = 0.0, b = 0.0, c = 0.0, delta = 0.0, x1 = 0.0, x2 = 0.0, x = 0.0;
    cout << "Please enter your a value, a must not be 0: ";
    a = validInputNot0();
    cout << "Please enter your b value: ";
    b = validInput();
    cout << "Please enter your c value: ";
    c = validInput();
    delta = b*b - 4*a*c;
    if (delta > 0) {
        x1 = (((-1)*b) + sqrt(delta))/(2*a);
        x2 = ((-1)*b - sqrt(delta))/(2*a);
        decPlaces();
        cout << "x1 = ((-" << b << ") + sqrt(" << b << "*" << b << "- 4*" << a << "*" << c << "))/(2*" << a << ") = " << x1 << "; " << endl;
        cout << "x1 = ((-" << b << ") - sqrt(" << b << "*" << b << "- 4*" << a << "*" << c << "))/(2*" << a << ") = " << x2 << "; " << endl;
    }
    else if (delta == 0) {
        x = ((-1)*b)/(2*a);
        cout << "x1 = x2 = (-" << b << ")/(2*" << a << ") = " << x << endl;
    }
    else {
        decPlaces();
        cout << "x1 = ((-" << b << ") + sqrt(" << b << "*" << b << "- 4*" << a << "*" << c << "))/(2*" << a << ") = " << ((-1)*b)/(2*a) << " + "<< (sqrt(- delta))/(2*a) << "i ;" << endl;
        cout << "x1 = ((-" << b << ") - sqrt(" << b << "*" << b << "- 4*" << a << "*" << c << "))/(2*" << a << ") = " << ((-1)*b)/(2*a) << " - "<< (sqrt(- delta))/(2*a) << "i ;" << endl;
    }
}

void hypoCal() {
    double a = 0.0, b = 0.0, c = 0.0;
    cout << "ABC is a right triangle at A, in which c is the length of hypotenuse; a and b are the length of the other 2 sides of the triangle " << endl;
    cout << "Please enter your a value, a must not be equal to 0: ";
    a = validInputNot0();
    cout << "Please enter your b value, b must not be equal to 0: ";
    b = validInputNot0();
    c = sqrt((a)*(a) + (b)*(b));
    decPlaces();
    cout << "The length of the triangle's hypotenuse is c = sqrt((" << a << ")*(" << a << ") + (" << b << ")*(" << b << ")) = " << c << endl;
}
