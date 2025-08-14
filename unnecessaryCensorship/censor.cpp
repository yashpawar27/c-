#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::cin, std::cout, std::cerr, std::endl, std::string, std::vector;
using std::istringstream, std::ifstream, std::ofstream;

int main(int argc, char *argv[]) {
	// use hard coded if files are not provided
	string censorWordsFilename = "censorwords.txt";
	string originalTextFilename = "frozen.txt";

	// Get filenames if provided in command line arguments
	string censoredTextFilename = "censored-" + originalTextFilename;

	// Declare/Define/Open filestreams
	ifstream ifs_cwds(censoredTextFilename);
	ifstream ifs_txt(censoredTextFilename);
	ofstream ofs(censoredTextFilename);

	// make sure all files were opened and give feedback if not
	if(!ifs_cwds.is_open()) {
		cerr << "Unable to open: " << censoredTextFilename << endl;
		return 1; //means exiting with an error
	}

	if(!ifs_txt.is_open()) {
		cerr << "Unable to open: " << originalTextFilename << endl;
		return 1;
	}

	if(!ofs.is_open()) {
		cerr << "Unable to open: " << censoredTextFilename << endl;
		return 1;
	}

	// get list of words to censor from file
	vector<string> censorWds;
	string censorWd;
	while (ifs_cwds >> censorWds) {
		censorWd.pushback(censorWd);
	}


	// print out list of censored words (for debugging) remove later from final program

	// read original, process and send to output
	// process line by line
		// get next line
		// see if each censor word is in line
		// if it is there, replace with symbols
		// output modified line
}