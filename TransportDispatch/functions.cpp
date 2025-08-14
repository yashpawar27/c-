#include <iostream>
#include <sstream>
#include <limits>
#include "functions.h"

using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

int mapping (string loc) {
            int num = 0;
            if (loc == "Boston") num = 1;
            else if (loc == "Hartford") num = 2;
            else if (loc == "NewYork") num = 3;
            else if (loc == "Philadelphia") num = 4;
            else if (loc == "Baltimore") num = 5;
            else if (loc == "WashingtonDC") num = 6;
            else if (loc == "Pittsburgh") num = 7;
            else if (loc == "Cleveland") num = 8;
            else if (loc == "Detroit") num = 9;
            else if (loc == "Chicago") num = 10;
            else if (loc == "Indianapolis") num = 11;
            else if (loc == "Nashville") num = 12;
            else if (loc == "Atlanta") num = 13;
            else if (loc == "Houston") num = 14;
            else if (loc == "Austin") num = 15;
            else if (loc == "Dallas") num = 16;
            else if (loc == "Denver") num = 17;
            else if (loc == "Albuquerque") num = 18;
            else if (loc == "Phoenix") num = 19;
            else if (loc == "Sacramento") num = 20;
            else {
                try { throw invalid_argument("Undefined location"); } 
                catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
            }
            return num;
}

string rev_mapping (int num) {
            string loc;
            switch (num)
            {
            case 1: { loc = "Boston"; break; }
            case 2: { loc = "Hartford"; break; }
            case 3: { loc = "NewYork"; break; }
            case 4: { loc = "Philadelphia"; break; } 
            case 5: { loc = "Baltimore"; break; }
            case 6: { loc = "WashingtonDC"; break; }
            case 7: { loc = "Pittsburgh"; break; }
            case 8: { loc = "Cleveland"; break ; }
            case 9: { loc = "Detroit"; break; }
            case 10: { loc = "Chicago"; break; }
            case 11: { loc = "Indianapolis"; break; }
            case 12: { loc = "Nashville"; break; }
            case 13: { loc = "Atlanta"; break; }
            case 14: { loc = "Houston"; break; }
            case 15: { loc = "Austin"; break; }
            case 16: { loc = "Dallas"; break; }
            case 17: { loc = "Denver"; break; }
            case 18: { loc = "Albuquerque"; break; }
            case 19: { loc = "Phoenix"; break; }
            case 20: { loc = "Sacramento"; break; }
            default: { loc = "undefined"; break;}
            }            
            if (loc == "undefined") {
                try { throw invalid_argument("Undefined location"); } 
                catch (std::invalid_argument const& e) { cout << e.what() << endl; } 
            }
            return loc;
}

void get_op(const string& line, string* operation) {
    std::istringstream sin(line);
    sin >> *operation;
    if (sin.fail()) {
        sin.clear();
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        *operation = "ignore";
    }
}

void get_loc(const string& line, string* location) {
    std::istringstream sin(line);
    sin >> *location;
    if (sin.fail()) {
        sin.clear();
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void print_inst_1() {
    cout << "*** enter operation: push <location> | insert <location> | delete <location> | pop | clear | print | locations | quit" << endl;
    cout << "*** enter location from above list on next line" << endl;
    cout << "*** enter an empty line to end input" << endl;
    cout << "***" << endl;
    cout << "*** WARNING: push operation pushes location in push order without any location ordering" << endl;
    cout << "***" << endl;
}

void print_inst_2() {
    cout << "*** Locations: Boston | Hartford | NewYork | Philadelphia | Baltimore | WashingtonDC | Pittsburgh | Cleveland | Detroit | Chicago | " << endl;
    cout << "*** Indianapolis | Nashville | Atlanta | Houston | Dallas | Austin | Denver | Albuquerque | Phoenix | Sacramento" << endl;
    cout << "*** .... you can repeat this list anytime at prompt by typing locations ...." << endl;
    cout << "***" << endl;   
}

void print_inst_3() {
    cout << endl;
    cout << "next" << endl;
}

node::node (int arg_val, node *ptr = nullptr) {
            this->value = arg_val;
            this->ptr = ptr;    
}

// getters, gets value, gets ptr
// HOMEWORK
int node::getvalue () { return value;} // done
node *node::getptr () { return ptr;} // done

// setter
// HOMEWORK
void node::setptr (node *ptr) { // done
    this->ptr = ptr;
}
void node::setvalue (int value) { //done
    this->value = value;
}

//LinkedList constructor
LinkedList::LinkedList () : headptr(nullptr) {
            this->headptr = nullptr;
}

//LinkedList destructor
// HOMEWORK
LinkedList::~LinkedList () {
    node* n = headptr;
    node* p = nullptr;
    while(n != nullptr) {
        p = n;
        n = n->getptr();
        p->setvalue(0);
        p->setptr(nullptr);
        delete p;
    }
    headptr = nullptr;
    n = nullptr;
    p = nullptr;
}

//LinkedList copy constructor
// HOMEWORK
LinkedList::LinkedList (const LinkedList& object) : headptr(nullptr){
    this->headptr = object.headptr;
}

// Copy assignment constructor
// HOMEWORK
LinkedList& LinkedList::operator=(const LinkedList &object) {

    if(object.headptr == this->headptr) {
        return *this;
    }

    while(headptr != nullptr) { // deletes all nodes
        pop();
    }
    
    node* copy = new node(object.headptr->getvalue());

    node* temp = copy;
    node* itr = object.headptr->getptr();
    node* t2;
    
    while(itr != nullptr) {
        t2 = new node(itr->getvalue());

        temp->setptr(t2);
        itr = itr->getptr();
        temp = temp->getptr();
    }

    headptr = copy;

    copy = nullptr;
    itr = nullptr;
    temp = nullptr;
    t2 = nullptr;

    return *this;
}

// push a node
// HOMEWORK
void LinkedList::push (int value) { // should work

    node* n = new node(value, headptr);
    headptr = n;
    n = nullptr;
}

// pop a node
// HOMEWORK
int LinkedList::pop () { // should work
    int value_to_remove;

    if(headptr == nullptr) {
        cout << "Cannot remove elements from empty link list" << endl;
        return -1;
    }

    value_to_remove = headptr->getvalue();
    headptr->setvalue(0);

    node* temp = headptr->getptr();

    headptr->setptr(nullptr);
    delete headptr;

    headptr = temp;
    temp = nullptr;

    return value_to_remove;
}

// helper function: print linked list
void LinkedList::printLinkedList () {
    node *curNode = headptr;
    int i=0;
    int reference;
        while (curNode != nullptr) {
            reference = curNode->getvalue();
            cout << rev_mapping(reference) << " -> ";
            curNode = curNode->getptr();
            // this piece of code prevents printing of endless nodes if you have an infinite loop
            // you can delete this if so desired, it doesn't affect functionality
            i++;
            if (i>20) {
                    cout << "Warning: broken linked list possible." << endl;    
                    break;
            }
        }
    cout << endl;
}

// Find the node closest to and less than value, i.e. where in the linked list
// should you insert. It approximates the correct driving order for the driver.
// HOMEWORK
int LinkedList::find_closest_less_than(int value) {

    if(headptr == nullptr) {
        return 0;
    }

    node* itr = headptr;
    int idx = 0;
    int dif = 2147483647; // max int
    // node* closest = itr; //currently set to head

    if(itr == nullptr) {
        return 0;
    }else {
        while(itr != nullptr) {
            if(value-itr->getvalue() > 0 && dif > value-itr->getvalue()) {
                dif = value-itr->getvalue();
                idx = itr->getvalue();
            }
            itr = itr->getptr();
        }
    }

    
    itr = nullptr;
    // closest = nullptr;
    return idx;

}

// inserts a node in a sepcific
// HOMEWORK
void LinkedList::insertNode(int value, int reference_value) { // should work

    node* itr = headptr;
    node* n = new node(value);

    // int idx = find_closest_less_than(0);

    while (itr != nullptr) {
        if(itr->getvalue() == reference_value) {
            n->setptr(itr->getptr());
            itr->setptr(n);
            return;
        }
        itr = itr->getptr();
    }

    cout << "Trying to add a node at a location that does not exist" << endl;
    
    n = nullptr;
    itr = nullptr;
} // end insertNode


void LinkedList::add(node& n) {
    int idx = find_closest_less_than(n.getvalue());
    insertNode(n.getvalue(), idx);
}

// deletes a node in a specific location
// HOMEWORK
void LinkedList::deleteNode(int reference_value) {
    node* itr = headptr;

    if(headptr == nullptr) {
        cout << "Cannot remove elements from empty link list" << endl;
        return;
    }

    if(headptr->getvalue() == reference_value) {
        pop();
        return;
    }

    while(itr->getptr() != nullptr && itr->getptr()->getvalue() != reference_value) {
        itr = itr->getptr();
    }

    if(itr != nullptr && itr->getptr() != nullptr && itr->getptr()->getvalue() == reference_value) {
        node* t = itr->getptr()->getptr();
        delete itr->getptr();
        itr->setptr(t);
        t = nullptr;
        return;
    }


    cout << "Trying to delete a node that does not exist" << endl;
    itr = nullptr;
} // end deleteNode

// helper function: Is the link list empty?
bool LinkedList::link_list_empty() {
    if (this->headptr == nullptr) {return true;}
        else {return false;}
}

// function for unit test, do not change
int LinkedList::obtain_value_head () {
    node *curNode = headptr;
    return curNode->getvalue();
}

// function for unit test, do not change
int LinkedList::obtain_value_node (int steps) {
    node *curNode = headptr;
    for (int i = 0; i < steps; i++) {
        curNode = curNode->getptr();
    }
    return curNode->getvalue();
}
// end of public methods for LinkedList
