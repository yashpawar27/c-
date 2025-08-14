// TODO: Implement this header file
# ifndef MYSTRING_H
# define MYSTRING_H

# include <iostream>
# include <fstream>
# include <tuple>
# include <limits>
# include <stdexcept>

using std::ostream;


class MyString{
    private:
        char *letters;
        unsigned int size_;
        // int length_;
        unsigned int capacity_;

    public:
        //constructors
        MyString();
        MyString(const MyString& str);
        MyString(const char *s);

        //destructor
        ~MyString(); 

        void resize(unsigned int cap = 0); //default to zero // adds additional spaces by size_t
        int capacity() const; //returns current capacity
        unsigned int size() const; //returns size of dynamic array
        int length() const; //returns length
        char* data() const; // returns the pointer to the address(reference) to letters
        bool empty() const; // returns if dynarray is empty
        const char& front() const;// returns the first letter
        char at(unsigned int idx) const; // returns a character at a position at idx in the dynarray
        void clear(); // clears dynarray;
        MyString& operator=(const MyString& str);
        MyString& operator+=(const MyString& str);
        int find(const MyString& str, unsigned int npos = 0) const;
        friend ostream& operator<<(std::ostream& os, const MyString& str);

};


# endif