// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    
    double exam = 0, fnal = 0, hw = 0, lw = 0, read = 0, engage = 0; //sum score
    int Ne = 0, Nhw = 0, Nlw = 0, Nread = 0, Nengage = 0; //amount of material


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            exam += score;
            Ne+=100;
        } else if (category == "final-exam") {
            fnal = score;
            Ne+=100;
        } else if (category == "hw") {
           hw += score;
           Nhw+=100;
        } else if (category == "lw") {
            if (score >= 50) {
                lw += 100;
            }
            Nlw+=100;
        } else if (category == "reading") {
            read += score;
            Nread += 1;
        } else if (category == "engagement") {
            if (score > 0) {
                engage += 100;
            }
            Nengage+=100;
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    double exam_average = 0;
    double hw_average = 0;
    double lw_average = 0;
    double reading = 15;
    double engagement = 15;
    // TODO(student): compute component averages and assign to the above variables
    // exam_average = ???; // etc.

    if (Ne < 300) { //ensures 3 tests minimum
        Ne = 300;
    }

    if (fnal > ((fnal + exam)/Ne)*100) {
        exam_average = fnal;
    } else {
        exam_average = ((fnal + exam)/Ne)*100;
    }

    if (Nhw != 0) {
        hw_average = (hw/Nhw)*100;
        if (hw_average > 100) {
            hw_average = 100;
        }
    }

    if (Nlw != 0) {
        lw_average = (lw/Nlw)*100;
        // cout << "lw_average: " << lw_average << endl;
        if (lw_average > 100) {
            lw_average = 100;
        }

    }

    if (Nread != 0) {
        reading += (read/Nread)*100;
        if (reading > 100) {
            reading = 100;
        }
    }

    if (Nengage != 0) {
        engagement += (engage/Nengage)*100;
        if (engagement > 100) {
            engagement = 100;
        }
    }

    // TODO(student): compute weighted total of components
    double weighted_total = 0;
    weighted_total = (exam_average*.40) + (hw_average*.40) + (lw_average*.10) + 
    (reading*.05) + (engagement*.05);


    // cout << "exam avg: " << (exam_average*.40) << endl;
    // cout << "hw avg: " << (hw_average*.40) << endl;
    // cout << "lw avg: " << (lw_average * .10) << endl;
    // cout << "reading avg: " << (reading*.05) << endl;
    // cout << "engage avg: " << (engagement*.05) << endl;

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if (weighted_total >= 90) {
        final_letter_grade = 'A';
    } else if (weighted_total >= 80) {
        final_letter_grade = 'B';
    } else if (weighted_total >= 70) {
        final_letter_grade = 'C';
    } else if (weighted_total >= 60) {
        final_letter_grade = 'D';
    } else {
        final_letter_grade = 'F';
    }

    // Do not modify print_results since this will not help
    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them
// Even minor changes might cause you to fail test cases for the wrong reasons

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "        exam average: " << exam_average << endl;
    cout << "          hw average: " << hw_average << endl;
    cout << "          lw average: " << lw_average << endl;
    cout << "     reading average: " << reading << endl;
    cout << "  engagement average: " << engagement << endl;
    cout << "  -------------------" << endl;

    cout << "      weighted total: " << weighted_total << endl;

    cout << "  final letter grade: " << final_letter_grade << endl;
}
