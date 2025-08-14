#include <iostream>
#include <iomanip>
#include <vector>
#include "rank_functions.h"

using std::cin, std::cout, std::endl, std::string;

bool onlyAlpha(string str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ' && !isalpha(str.at(i))) {
            return false;
        }
    }
	return true;
}

bool onlyUpper(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ' && isalpha(str.at(i)) && 
		!isupper(str.at(i))) {
            return false;
        }
    }
	return true;
}

bool containsLetter(string str) {
	for (unsigned int i = 0; i < str.length(); i++) {
		if (isalpha(str.at(i))) {
			return true;
		}
	}
	return false;
}


//-------------------------------------------------------
// Name: load_driver_data
// PostCondition: returned vector contains data gotten from standard in and rank initialized to 0
//---------------------------------------------------------
std::vector<driver> load_driver_data() {

	std::vector<driver> drivers;

	for (size_t i = 0; i < SIZE; i++)
	{
		driver d;
		cin >> d.time >> d.country >> d.number;
		getline(cin, d.lastname); // gets the rest of the line while including name space


		d.rank = 0;

		if (d.time <= 0) { // checks valid time
			drivers.clear();
			return drivers;
		}

		if (d.country.length() != 3 || !onlyAlpha(d.country) || !onlyUpper(d.country)) { //checks valid country
			drivers.clear();
			return drivers;
		}

		if (d.number > 99) { //checks valid number
			drivers.clear();
			return drivers;
		}

	d.lastname = trim(d.lastname); //trims lastname
		if (!containsLetter(d.lastname) || !onlyAlpha(d.lastname) || d.lastname.length() <= 1) {
			drivers.clear();
			return drivers;
		}

		drivers.push_back(d); // adds driver to vector
	}

	return drivers;
}

//-------------------------------------------------------
// Name: set_rankings
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places sets the ranks. That updated vector is returned
//---------------------------------------------------------
std::vector<driver> set_rankings(std::vector<driver> v) {



	int rank = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if(v.at(i).time > v.at(j).time) {
				rank++;
			}
		}
		v.at(i).rank = rank+1;
		rank = 0;
	}


	return v;
}

std::string trim(std::string s){

	if(!containsLetter(s) || s == "") {
		return "";
	}
	
	while (isspace(s.at(0))) { // removes from spaces
		s = s.substr(1);
	}

	while (isspace(s.at(s.length()-1))) { // removes end spaces
		s = s.substr(0, s.length()-1);
	}
	
	return s;
}

//-------------------------------------------------------
// Name: print_results
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(std::vector<driver> v)
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= v.size(); j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < v.size(); i++)
		{
			if(v.at(i).rank == 1) // has to be a better way, but need the starting time
			{
				best_time = v.at(i).time;
			}
			
			
			if(v.at(i).rank == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << v.at(i).time << " " << std::setw(15) << std::left << v.at(i).lastname << "\t" << "(" << v.at(i).country << ")  +" << (v.at(i).time - best_time) << std::endl; 
			}
			
		}
	}	
}