#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;


int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }

  string str;

  int maxUIN = 0;
  double maxDonations = 0;
  
  while(getline(ifs, str)) {
    int UIN = 0;
    double donation = 0;
    double t = 0;
    int i = 0;
    istringstream iss(str);

    iss >> UIN;
    while(iss.good()) {
      i++;
      iss >> t;
      // cout << "t: " << t << endl;
      donation += t;
      // cout << "donation: " << donation << endl;
    }

    if(i > 1 && donation > maxDonations) {
      maxDonations = donation;
      maxUIN = UIN;
    }
  }
  // cout << "maxDonations: " << maxDonations << endl;

  if(maxDonations > 0) {
    cout << "Highest donation total: " << maxDonations << endl;
    cout << "-- collected by id: " << maxUIN << endl;
  } else {
    cout << "Highest donation total: No donations";
  }


  
}
