# include "linked_list.h"
# include <iostream>
# include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {

    MyNode* node = new MyNode(name, score);

    if(_head == nullptr) {
        _head = node;
        _tail = node;
    } else {

        MyNode* temp = _head;

        while(temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
        _tail = node;

        temp = nullptr;
    }

    node = nullptr;

    _size++;
}

void MyList::clear() {

    MyNode* temp = _tail;
    MyNode* prev = nullptr;

    while(temp != nullptr) {
        prev = temp->prev;
        delete temp;
        temp = prev;
    }

    _size = 0;
    _head = nullptr;
    _tail = nullptr;
    temp = nullptr;
    prev = nullptr;
}

bool MyList::remove(const std::string& name) {
    // if(_size == 0) {
    //    return false; 
    // }

    // MyNode* temp = _head;

    // while(temp->next != nullptr && temp->next->name != name) {
    //     temp = temp->next;
    // }

    // if(temp != nullptr) {
    //     _size--;

    //     if(temp == _head) {
    //         _head = temp->next;
    //         delete temp;
    //         temp = nullptr;
    //         return true;
    //     } else if (temp == _tail) {
    //         _tail = _tail->prev;
    //         delete temp;
    //         temp = nullptr;
    //         return true;
    //     } else {
    //         temp->prev->next = temp->next;
    //         temp->next->prev = temp->prev;

        
    //     delete temp;
    //     temp = nullptr;

    //     return true; // Node foun
    //     }
    // }

    // // temp = nullptr;
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // if(index < 0 || index > _size) {
    //     return false;
    // }

    // _size++;

    // MyNode* node = new MyNode(name, score);

    // if(index == 0) {
    //     node->next = _head;
    //     _head->prev = node;
    //     _head = node;
    //     return true;
    // }

    // if(index == _size) {
    //     _tail->next = node;
    //     node->prev = _tail;
    //     _tail = node;
    //     return true;
    // }

    // MyNode* temp = _head;

    // for(size_t i = 0; i < index-1; i++) {
    //     temp = temp->next;
    // }

    // temp->next->prev = node;
    // node->next = temp->next;
    // temp->next = node;
    // node->prev = temp;
    
    // // node = nullptr;
    // // temp = nullptr;

    return true;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        // _current = nullptr;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    // _current = nullptr;
    return os;
}

MyNode::MyNode(const std::string& name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
