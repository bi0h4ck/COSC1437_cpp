//Triangle calculator by Diem Pham

#include <iostream>

using namespace std;

class Triangle {
	public: 
		double base;
		double height;

		//Member functions declaration
		double getArea(void);
		void setBase(double base);
		void setHeight(double height);
};

//Member functions definitions
double Triangle::getArea(void) {
	return (base*height)/2;
}

void Triangle::setBase(double b) {
	base = b;
}

void Triangle::setHeight(double h) {
	height = h;
}

double validDouble() {
    double x;
    std::cin >> x;
    while((std::cin.fail()) || x == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value must be a number. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

//Main function for the program
int main() {
	Triangle Tri;
	
	double area = 0.0;
	double TotalArea = 0.0;
	double base = 0.0;
	double height = 0.0; 

	for (int x = 0; x < 3; x++) {
		cout << "Triangle " << x + 1 << endl;
		cout << "base " << x + 1 << ": "; 
		base = validDouble();
		Tri.setBase(base);

		cout << "height " << x + 1 << ": ";
		height = validDouble();
		Tri.setHeight(height);

		area = Tri.getArea();
		cout << "Area of triangle " << x + 1 << " is: (" << base << ")*(" << height << ")/2 = " << area << endl;
		TotalArea += area;
	}
	cout << "The total area of 3 triangle is: " << TotalArea << endl;
}