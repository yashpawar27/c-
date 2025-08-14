# include "functions.h"
// add any includes


using std::cout, std::cin, std::endl, std::string, std::getline;

int pow10(int idx) {
    int out = 1;
    for (int i = 0; i < idx; i++) {
        out *= 10;
    }
    return out;
}

void deobfuscate() {

    string sentence = "";
    cout << "Please enter obfuscated sentence: ";
    getline(cin, sentence);

    int idxs = 0;
    cout << "Please enter deobfuscation details: ";
    cin >> idxs;

    int temp = idxs;
    int count = 0;
    while (temp != 0) {
        temp/=10;
        count++;
    }

    string out = "";

    int prev = 0;
    int ind = 0;

    for (unsigned int i = 0; i < count; i++) {
        // cout << count-i-1 << endl;
        // cout << nums.at(count-i-1) << endl;
        temp = idxs;

        // cout << (temp/pow10(count-i-1))%10 << endl;
        
        sentence.insert((temp/pow10(count-i-1))%10 + prev, " ");
        // cout << sentence << endl;

        prev += (temp/pow10(count-i-1))%10+1;
    }
    
    cout << "Deobfuscated sentence: " << sentence << endl;
}

void wordFilter() {
    string sentence = "";
    cout << "Please enter the sentence: ";
    getline(cin, sentence);

    string filter = "";
    cout << "Please enter the filter word: ";
    getline(cin, filter);

    string censor = "";

    for (unsigned int i = 0; i < filter.length(); i++) {
        censor += "#";
    }

    // cout << sentence << endl;
    // cout << filter << endl;
    // cout << censor << endl;

    for (unsigned int i = 0; i < sentence.length()-filter.length(); i++) {

        // cout << "Detection: " << sentence.substr(i, filter.length()) << endl;
        // cout << "Det. Length: " << sentence.substr(i, filter.length()).length() << endl << endl;
        if (sentence.substr(i, filter.length()) == filter)
        {
            sentence.replace(i, filter.length(), censor);
        }
    }

    cout << "Filtered sentence: " << sentence << endl;
    
}

void passwordConverter() {
    cout << "Please enter your text input: input: ";
    string password = ""; 
    getline(cin, password);
    cout << password << endl;

    string out1 = "";
    string out2 = "";

    for (unsigned int i = 0; i < password.length(); i++) {
        if (password.at(i) == 'a') {
            out1 += "@";
            out2 = "@" + out2;
        } else if (password.at(i) == 'e') {
            out1 += "3";
            out2 = "3" + out2;
        } else if (password.at(i) == 'i') {
            out1 += "!";
            out2 = "!" + out2;
        } else if (password.at(i) == 'o') {
            out1 += "0";
            out2 = "0" + out2;
        } else if (password.at(i) == 'u') {
            out1 += "^";
            out2 = "^" + out2;
        } else {
            out1 += password.at(i);
            out2 = password.at(i) + out2;
        }
    }
    cout << "output: " << out1 << out2 << endl;
}

void wordCalculator() {
    cout << "Please enter word equation (type 'equals' at the end):";
    string eq = "";
    getline(cin, eq);
    eq += " ";
    
    string outEQ = "";
    int total = 0;
    int a = -1;
    int b = -1;
    char sign = 'n';
    int min = 0;
    int blank = 1;
    string word = "";

    while (blank > 0) {

        blank = eq.find(" ");
        word = eq.substr(0, blank+1);
        eq = eq.substr(blank);

        cout << word << endl;
        
    }


    
    cout << outEQ << total << endl;


    // cout << "a: " << a << endl;
    // cout << "sign: " << sign << endl;
    // cout << "b: " << b << endl;
}

void palindromeCounter() { //madam, eve saw bob race a car at noon.
    cout << "Please enter a sentence (end with 'quit'): ";
    string sentence = "";
    getline(cin, sentence);
    sentence += " ";

    // for (int i = 0; i < )

    int dromes = 0;
    int prevSpace = 0;
    for (unsigned int i = 0; i < sentence.length(); i++) { // goes through sentence
        if (i == sentence.length()-1 || sentence.at(i) == ' ') { // check for a space
            // cout << "found space/end" << endl;
            int max = i-1;

            if (i < sentence.length()-1 && sentence.at(i) != ' ' &&
             sentence.at(i+1) == ' ') {
                dromes++;
            }

            if(i == sentence.length()-1) {
                max = i;
                cout << "changes max value at end" << endl;
            }
            cout << "min: " << prevSpace << ", " << sentence.at(prevSpace) << endl;
            cout << "max: " << max  << ", " << sentence.at(max) << endl;

            for (unsigned int j = 0; j < max-prevSpace; j++) {
                cout << '(' << prevSpace+j << ", " << max-j << ")" << endl;
                cout << "(" << sentence.at(prevSpace+j) << ", " << sentence.at(max-j) << ")" << endl << endl;
                if (sentence.at(prevSpace+j) != sentence.at(max-j)) {
                    cout << 'Breaks Here : (' << prevSpace+j << ", " << max-j << ")" << endl;
                    break;
                }
                if (j==max-prevSpace-1){
                    dromes++;
                    cout << "plaindrome has been found!" << endl;
                }
            }

            prevSpace = i+1;
            // cout << "prevSpace: " <<prevSpace << endl;
        }
    }
    
    cout << "You have typed " << dromes << " palindromes." << endl;
    // for (int i = 0; i < sentence.length()/2; i++) {
    //     if (sentence.at(i) == sentence.at(sentence.length()-1)) {
    //         dromes++;
    //     }
    // }
}