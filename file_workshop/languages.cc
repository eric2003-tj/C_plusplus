#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct language {
	string lang;
	string designer;
	int date;
};

int main() {
	// Vector to store the language details
	vector<language> languages;

	// Open the file with the language data
	ifstream ifile{"languages.txt"};

	if (ifile) {
		// Read in each line of data from the file
		string line;

		while (getline(ifile, line)) {
			string lang;
			string designer;
			int year;

			// Use an istringstream to process the line of input, one word at a time
			istringstream istring{line};
			istring >> lang;
			istring >> designer;
			istring >> year;

			// Add this line of data to the vector
			languages.push_back({lang, designer, year});
		}

		// Print out all the languages in the vector
		for (auto language: languages)
			cout << language.lang << ", " << language.designer << ", " << language.date << endl;
	}
}
