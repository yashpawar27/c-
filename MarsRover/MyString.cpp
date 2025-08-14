// TODO: Implement this source file
# include "MyString.h"

using std::cout, std::endl;

    MyString::MyString() : letters(nullptr), size_(0), capacity_(0) {
        resize(1);
        letters[0] = '\0';
    }

    MyString::MyString(const MyString& str) : letters(nullptr), size_(0), capacity_(0) {

        resize(str.size_+1);

        size_ = str.size_;

        for(unsigned int i = 0; i < str.size_; i++) {
            letters[i] = str.letters[i];
        }


        letters[size_] = char('\0');
    }

    MyString::MyString(const char *s) : letters(nullptr), size_(0), capacity_(0) {
        unsigned int s_size = 0;

        while(s[s_size] != '\0') { // end of the c-string
            s_size++;
        }

        resize(s_size+1);

        for(unsigned int i = 0; i < s_size; i++) {
            letters[i] = s[i];
        }

        size_ = s_size;

        letters[size_] = '\0';

    }

    void MyString::resize(unsigned int cap) {
        
        if(cap < capacity_) {
            cap = capacity_;
        }

        char* temp = new char[cap];

        for(unsigned int i = 0; i < size_; i++) {
            temp[i] = letters[i];
        }

        delete [] letters;

        
        letters = temp;
        letters[size_] = '\0';
        capacity_ = cap;
        temp = nullptr;
    }

    int MyString::capacity() const { // amount of space allocated to storage
        return capacity_;
    }

    unsigned int MyString::size() const { // number of chars in a string
        return size_;
    }

    int MyString::length() const { // same thing as size
        return size_;
    }

    char* MyString::data() const { // the c-string
        return letters;
    }

    bool MyString::empty() const { // if the c-string is empty
        return size_==0;
    }

    const char& MyString::front() const { // first char is c-string
        return letters[0];
    }

    MyString::~MyString() { // destructor 💀
        clear();
        capacity_ = 0;
        delete [] letters;
        letters = nullptr;
    }

    char MyString::at(unsigned int npos) const { // char in position npos of the c-string

        if(npos >= size_) {
            throw std::out_of_range("at(): Invalid npos");
        }

        return letters[npos];
    }

    void MyString::clear() { // clears everything
        for(unsigned int i = 0; i < size_; i++) {
            letters[i] = '\0';
        }
        size_ = 0;
    }

    int MyString::find(const MyString& str, unsigned int npos) const { // finds the index of a str value

            
        if(size_ < str.size_ || npos > size_ || str.size_ <= 0) {
            return -1;
        }

        for(unsigned int i = npos; i < size_-str.size_+1; i++) {
            if(letters[i] == str.letters[0]) {
                unsigned int count = 0;
                for(unsigned int j = 0; j < str.size_; j++) {
                    if(str.letters[j] != letters[i+j]) {
                        break;
                    }
                    count++;
                }
                if(count == str.size_) {
                    return i;
                }
            }
        }


        return -1;
    }

    MyString& MyString::operator=(const MyString& str){

        if(this == &str) {
            return *this;
        }

        if(capacity_ < str.capacity_) {
            resize(str.capacity_+1);
        }

        if(size_ != str.size_) {
            size_ = str.size_;
        }

        for(unsigned int i = 0; i < str.size_; i++) {
            letters[i] = str.letters[i];
        }

        letters[size_] = '\0';
        return *this;
    }

    MyString& MyString::operator+=(const MyString& str) {

        if(str.letters[0] == '\0' || str.empty()) {
            return *this;
        }

        if(capacity_ <= size_ + str.size_) {
            resize((size_ + str.size_)*2);
        }

        for(unsigned int i = 0; i < str.size_; i++) {
            letters[size_+i] = str.letters[i];
        }

        size_ += str.size_;
        letters[size_] = '\0';


        return *this;
    }

    ostream& operator<<(std::ostream& os, const MyString& str) {
        for(unsigned int i = 0; i < str.size_; i++) {
            os << str.letters[i];
        }

        return os;
    }
