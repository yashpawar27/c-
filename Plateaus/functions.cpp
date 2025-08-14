#include <iostream>
#include "functions.h"


using std::cout, std::endl;

// this function checks if the range is valid
bool is_valid_range(long long a, long long b) {
	long long num1 = 1000;
	long long num2 = 1000000000000;

	// TODO complete the code for this function to ensure that a and b are within valid range
	// TODO update the return value accoordingly
	if (a < num1 || b < num1 || b < a || b >= num2 || a >= num2) {
	return false;
	}

	return true;
}

// classify_geo_type operates on a number, slices it and detects if it is plateau, basin or none
// it is called recursively by count_valid_pb_numbers

long long pow10 (int exp) {

	long long out = 1;

	for (int i = 0; i < exp; i++) {
		out *= 10;
	}

	// cout << "pow10: " << out << endl;
	return out;
}

int index_number_getter(int idx, long long num, int digits) {

	// cout << "idx: " << idx << ", number: " << num << ", digits: " << digits << ", out: " << ((long long)(num/pow(10,digits-idx-1)))%10 << endl;
	return ((long long)(num/pow10(digits-idx-1)))%10;
}

char classify_geo_type(long long number) {



	char returnchar = 'n';
	long long workingnumber = number;
	int count = 0;

	while (workingnumber > 0) { //divides number by 10 until it gets to decimals
		workingnumber = (long long)(workingnumber/10);
		// cout << "workingnumber: " << workingnumber << endl;
		count++;
	}

	// phases of the numbers
	bool upslope = true;
	bool steady = false;
	bool downslope = false;
	// comparable digits in the number
	long long n = 0; // first
	long long m = 0; // second

	long long temp = number;

	
	//plateau check
	int pp = 0; // plateau points
	for (int i = 0; i < count-1; i++) {
		
		// n = index_number_getter(i, number, count);
		// m = index_number_getter(i+1, number, count);

		n = temp%10;
		temp = (temp/10);
		m = temp%10;


		// cout << "n: " << n << endl;
		// cout << "m: " << m << endl << endl;

		if(i==0 && n >= m) {
			break;
		}

		if (n==m && upslope) {

			upslope = false;
			steady = true;
		}

		if (n > m && steady) {
			steady = false;
			downslope = true;
		}

		if ((upslope || steady) && i == count-2)
		{
			break;
		}

		if (upslope && n < m) {
			pp++;
		} else if (steady && n == m) {
			pp++;
		} else if (downslope && n > m) {
			pp++;
		}
	}

	if (pp == count - 1) {
		returnchar = 'p';
		return returnchar;
	}

	// resets phases
	upslope = false;
	steady = false;
	downslope = true;

	n = 0;
	m = 0;

	temp = number;

	//basin check
	int bp = 0; // basin points
	for (int i = 0; i < count-1; i++) {

		// n = index_number_getter(i, number, count);
		// m = index_number_getter(i+1, number, count);

		n = temp%10;
		temp = (int)(temp/10);
		m = temp%10;

		// cout << "n: " << n << endl;
		// cout << "m: " << m << endl;

		if(i==0 && n <= m) {
			// cout << "start broken" << endl << endl;
			break;
		}

		if (n==m && downslope) {
			downslope = false;
			steady = true;
		}

		if (m > n && steady) {
			steady = false;
			upslope = true;
		}

		if ((downslope || steady) && i == count-2)
		{
			// cout << "end broken" << endl << endl;
			break;
		}

		if (downslope && n > m) {
			bp++;
		} else if (steady && n==m) {
			bp++;
		} else if (upslope && m > n) {
			bp++;
		}
	}

	// cout << "bp: " << bp << endl << endl;

	if (bp == count - 1) {
		returnchar = 'b';
		return returnchar;
	}

	return returnchar;
}


void count_valid_pb_numbers(long long a, long long b) {

	long long int distance = b-a;
	int plat_count = 0;
	int bas_count = 0;
	char x;


	// TODO for loop to iterate from 0 to distance
	// recursively call classify_geo_type
	// count plateaus and basins based on char returned

	// cout << "Distance: " << distance << endl;
	for (int i = 0; i < distance+1; i++) {
		char type = classify_geo_type(a+i);

		// cout << "type: " << type << endl;

		if (type == 'p') {plat_count ++;}
		if (type == 'b') {bas_count ++;}
		// cout << type << endl;
	}
	// cout << "exits final loop" << endl;

	// cout << "Past for-loop" << endl;

	cout << "There are ";
	cout << plat_count;
	cout << " plateaus and ";
	cout << bas_count;
	cout << " basins between ";
	cout << a;
	cout << " and ";
	cout << b;
	cout <<'.' << endl;


}