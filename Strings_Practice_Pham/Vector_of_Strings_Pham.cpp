// lab4 by Diem Pham

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main() {
	string s;
	string sl;
	std::locale loc;
	vector<string> v;

	cout << "List of animal names, type End to end: ";
	while(cin >> s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);	
		if (s == "end") {
			break;		
		} else {
			v.push_back(s);
		}		
	}
	sort (v.begin(), v.end());
	cout << "List of animal names in decending order: " << endl;
	for (int x = 0; x < v.size(); x++) {	
		cout << v[x] << endl;
	}
	return 0;
}
