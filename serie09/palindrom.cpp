#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string str;
	string::iterator it;
	string::iterator rit;

	cout << "Enter the string: ";
	getline(cin, str);
	
	for (it=str.begin(), rit=str.end()-1; it < rit; it++, rit--) {
		if(tolower(*it) != tolower(*rit)) {
			cout << "String is not a palindrom" << endl;
			return EXIT_FAILURE;
		}
	}
	cout << "String is a palindrom" << endl;

	return EXIT_SUCCESS;
}
