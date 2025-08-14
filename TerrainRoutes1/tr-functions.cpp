#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <cmath>
#include "tr-functions.h"

using std::vector, std::string, std::endl, std::invalid_argument;
using std::cout, std::cin, std::cerr;
using std::istringstream, std::ifstream, std::ofstream;
using std::max, std::min, std::numeric_limits, std::streamsize, std::abs;



// Part 1 Functions

void getUserInput(std::string& filename, unsigned int& rows, unsigned int& cols) {
    // update to guarantee filename is not an empty string and rows and cols are values from 1 to 4000

    string name = "";
    do {
        cout << "Enter filename: ";
        cin >> name;
    } while(name == "");
    filename = name;


    int r = -1;
    do {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter number of rows (1 - 4000): ";
        cin >> r;
    } while (cin.fail() ||r <= 0 || r > 4000);
    rows = r;


    int c = -1;
    do {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter number of columns (1 - 4000): ";
        cin >> c;
    } while (cin.fail() || c <= 0 || c > 4000);
    cols = c;


    // cout << "filename: " << filename << endl;
    // cout << "rows: " << rows << endl;
    // cout << "cols: " << cols << endl;
}

vector<vector<unsigned int>> loadElevations(string filename, unsigned int rows, unsigned int cols) {
    
    vector<vector<unsigned int>> out(rows,vector<unsigned int>(cols));
    unsigned int val;
    // int r = 0;
    // int c = 0;

	// Declare/Define/Open filestreams
	ifstream in(filename); //reads filename


    // make sure all files were opened and give feedback if not
	if (!in.is_open()) {
		throw invalid_argument("loadElevations: Failed to open " + filename);
	}

    for (unsigned int i = 0; i < rows; i++) {
        vector<unsigned int> v;

        for (unsigned int j = 0; j < cols; j++) {
            if(!(in >> out.at(i).at(j))) {

                if(in.eof()) {
                    throw std::runtime_error("loadElevations: Not enough values");
                }

                throw std::runtime_error("loadElevations: Invalid elevation value");
            }
            // cout << val << endl;
            
        }
    }

    if(in >> val) {
        throw std::runtime_error("loadElevations: Too many values");
    }
    
    in.close(); //closes file reader

    // cout << "act. rows: " << rows << ", r: " 
    // << r << ", r_size: " << out.size() << endl;

    return out;
}

void findMinMax(const vector<vector<unsigned int>>& elevations, unsigned int& min, unsigned int& max) {
    if (elevations.size() == 0 || elevations.at(0).size() == 0) {
        throw std::invalid_argument("findMinMax: Invalid elevations vector");
    }

    max = 0;
    min = 4001;


    for (unsigned int i = 0; i < elevations.size(); i++) {
        if(elevations.at(i).empty()) {
            throw std::invalid_argument("findMinMax: Invalid elevations vector");
        }
        for (unsigned int j = 0; j < elevations.at(i).size(); j++) {

            if(elevations.at(i).at(j) < min) {
                min = elevations.at(i).at(j);
            } 
            if(elevations.at(i).at(j) > max) {
                max = elevations.at(i).at(j);
            }
        }
    }
    cout << "final min: " << min << ", final max" << max << endl;
}

unsigned short scaleValue(unsigned int value, unsigned int min, unsigned int max) {
    // data-87X189.dat
    if(min >= max) {
        // cout << "min: " << min << ", max: " << max << endl;
        throw std::out_of_range("scaleValue: min must be less than max");
    }
    if (value < min || value > max) {
        // cout << "min: " << min << ", max: " << max << endl;
        throw std::out_of_range("scaleValue: value must be in the range min <= value <= max");
    }

    return round((255.0*(value-min))/(max-min)*1.0);
}

vector<vector<Pixel>> createImage(const vector<vector<unsigned int>>& elevations) {

    if(elevations.size() == 0 || elevations.empty() ||
     elevations.at(0).size() == 0 || elevations.at(0).empty()) {
        throw std::invalid_argument("createImage: Invalid elevations vector");
    }

    vector<vector<Pixel>> out(elevations.at(0).size(),vector<Pixel>(elevations.size()));

    unsigned int top = 2;
    unsigned int bottom = 1;

    for(unsigned int i = 0; i < elevations.size(); i++) {

        if(elevations.at(i).empty()) {
            throw std::invalid_argument("createImage: Invalid elevations vector");
        }
        for(unsigned int j = 0; j < elevations.at(i).size(); j++) {
            if(!elevations.at(i).at(j)) {
                throw std::invalid_argument("createImage: Invalid elevations vector");
            }
        }
    }

    //or just try this and catch with exception e& for more efficiency
    findMinMax(elevations, bottom, top);

    for(unsigned int i = 0; i < elevations.size(); i++) {

        if(elevations.at(i).empty()) {
            throw std::invalid_argument("createImage: Invalid elevations vector");
        }

        for(unsigned int j = 0; j < elevations.at(i).size(); j++) {

            if(!elevations.at(i).at(j)) {
                throw std::invalid_argument("createImage: Invalid elevations vector");
            }
            Pixel p;
            // cout << "bottom: " << bottom << ", top: " << top << endl; 
            int gray = scaleValue(elevations.at(i).at(j), bottom, top);
            p.r = gray;
            p.g = gray;
            p.b = gray;
            out.at(j).at(i) = p;
        }
    }

    cout << "rows: " << elevations.at(0).size() << ", cols: "  << elevations.size() << endl;
    return out;
}

void saveImage(string filename, const vector<vector<Pixel>>& image) {

    ofstream out(filename+".ppm");

    if(!out.is_open()) {
        throw std::invalid_argument("saveImage: Failed to open "+filename);
    }

    if(image.empty()) {
        throw std::invalid_argument("saveImage: Invalid image vector");
    }

    out << "P3" << endl << image.size() << ' ' <<
    image.at(0).size() << endl << 255 << endl;

    

    for (unsigned int i = 0; i < image.size(); i++) {
        if(image.at(i).empty()) {
            throw std::invalid_argument("saveImage: Invalid image vector");
        }
    }

    for (unsigned int i = 0; i < image.at(0).size(); i++) {
        for(unsigned int j = 0; j < image.size(); j++) {


            out << image.at(j).at(i).r << " " << image.at(j).at(i).g << " " << image.at(j).at(i).b << " ";
        }
    }
    out.close();


}

// uncomment the following for part 2

void processRoutes(vector<vector<Pixel>>& image, const vector<vector<unsigned int>>& elevations, Pixel colorAll, Pixel colorMin) {
    int shortestRow = 0;

    if(elevations.empty() || elevations.at(0).empty()) {
        throw std::invalid_argument("processRoutes: Invalid elevations vector");
    }

    for(unsigned int i = 0; i < elevations.size(); i++) {
        if(elevations.at(i).empty()) {
            throw std::invalid_argument("processRoutes: Invalid elevations vector");
        }
    }
    
    if(image.empty() || image.at(0).empty()) {
        throw std::invalid_argument("processRoutes: Invalid image vector");
    }

    for(unsigned int i = 0; i < image.size(); i++) {
        if(image.at(i).empty()) {
            throw std::invalid_argument("processRoutes: Invalid image vector");
        }
    }

    if(colorAll.r > 255 ||colorAll.g > 255 || colorAll.b > 255 ||
        colorMin.r > 255 ||colorMin.g > 255 || colorMin.b > 255) {
        throw std::invalid_argument("processRoutes: Invalid Pixel");
    }

    for(unsigned int i = 0; i < elevations.size(); i++) { //goes across cols
        if(colorRoute(image, elevations, colorAll, i) < colorRoute(image, elevations, colorAll, shortestRow)) {
            shortestRow = i;
        }
    }

    colorRoute(image, elevations, colorMin, shortestRow);
}

int colorRoute(vector<vector<Pixel>>& image, const std::vector<std::vector<unsigned int>>& elevations, Pixel color, int startRow) {

    unsigned int totalDist = 0;

    if(elevations.size() <= 0 || elevations.empty() || elevations.at(0).size() <= 0 || elevations.at(0).empty()) {
        throw std::invalid_argument("colorRoute: Invalid elevations vector");
    }
    if(image.size() <= 0 || image.empty() || image.at(0).size() <= 0 || image.at(0).empty()) {
        throw std::invalid_argument("colorRoute: Invalid image vector");
    }

    if(color.r > 255 ||color.g > 255 || color.b > 255) {
            throw std::invalid_argument("colorRoute: Invalid Pixel");
    }

    for(unsigned int i = 0; i < elevations.size(); i++) {
        if(elevations.at(i).empty()) {
            throw std::invalid_argument("colorRoute: Invalid elevations vector");
        }
    }

    for(unsigned int i = 0; i < image.size(); i++) {
        if(image.at(i).empty()) {
            throw std::invalid_argument("colorRoute: Invalid image vector");
        }
    }

    Pixel& p = image.at(0).at(startRow);
            p.r = color.r;
            p.g = color.g;
            p.b = color.b;

    for(unsigned int i = 0; i < elevations.at(0).size()-1; i++) { //num cols
        int left;
        int center;
        int right;

        if(startRow > 0) {
            left = abs((int)(elevations.at(startRow).at(i) - elevations.at(startRow-1).at(i+1)));
            // cout << "left: " << left << endl;
        } else {
            left = -1; //left isn't included if startRow is 0 bc left would be outofbounds
        }

        center = abs((int)(elevations.at(startRow).at(i) - elevations.at(startRow).at(i+1)));
        // cout << "center: " << center << endl;

        if(startRow < (int)elevations.size()-1) {
            right = abs((int)(elevations.at(startRow).at(i) - elevations.at(startRow+1).at(i+1)));
            // cout << "right: " << right << endl;
        } else {
            right = -1; //left isn't included if startRow is 0 bc left would be outofbounds
        }
                // checks if right in bounds, checks if right <= center, checks if right <= left or if left is valid
        if(right != -1 && right <= center && ((right <= left) || left == -1)) {
            totalDist += right;
            startRow += 1;
            Pixel& p = image.at(i+1).at(startRow);
            p.r = color.r;
            p.g = color.g;
            p.b = color.b;

                // checks if left is in bounds, checks if left > center, checks if left > right or right is valid
        }else if(left != -1 && left < center && ((left < right) || right == -1)) {
            totalDist += left;
            startRow -= 1;
            Pixel& p = image.at(i+1).at(startRow);
            p.r = color.r;
            p.g = color.g;
            p.b = color.b;
        }  else if(center < right && center <= left) {
            totalDist += center;
            Pixel& p = image.at(i+1).at(startRow);
            p.r = color.r;
            p.g = color.g;
            p.b = color.b;
        } else {
            totalDist += center;
            Pixel& p = image.at(i+1).at(startRow);
            p.r = color.r;
            p.g = color.g;
            p.b = color.b;
            // cout << "shouldn't get this far, check colorRoute" << endl;
            //if-statement should get this far ( this is a fail-safe (kinda) )
        }
    }

    return totalDist;
}

