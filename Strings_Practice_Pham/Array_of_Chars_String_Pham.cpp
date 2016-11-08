//lab4 by Diem Pham

#include <iostream>

using namespace std;

int main(){
	char input[1000];
	cout << "Your input: ";
	cin.getline(input, 1000);
	cout << input << endl;
	
	for (int x = 0; input[x] != '\0'; x++) {
		if (input[x-1] == ' ' && input [x+1] == ' ' && input[x] == 'i') {
			input[x] = 'I';
			cout << input[x];
		} else cout << input[x];

	}
	return 0;
}
