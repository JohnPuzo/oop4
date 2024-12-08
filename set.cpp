#include "set.h"
#include <iostream>
#include <stdexcept>
#include <fstream>


Set::Set() : head(nullptr), count(0) {}
Set::Set(const Set& other) {
    Node* current = other.head;
    while (current) {
        add(current->value);
        current = current->next;
    }
    head = other.head;
    count = other.count;
}
Set::~Set() {
    clear();
}


Set::Node* Set::findNode(const std::string& value) const {
    Node* current = head;
    while (current) {
        if (current->value == value) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void Set::add(const std::string& value) {
    if (findNode(value) != nullptr) {
        return;
    }
    head = new Node(value, head);
    ++count;
}

void Set::remove(const std::string& value) {
    Node* current = head;
    Node* previous = nullptr;

    while (current) {
        if (current->value == value) {
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            --count;
            return;
        }
        previous = current;
        current = current->next;
    }
}

int Set::size() const {
    return count;
}

void Set::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    count = 0;
}

Set Set::operator && (const Set& other) const {
    Set result;
    Node* current = head;
    while (current != nullptr) {
        if (other.findNode(current->value) != nullptr) {
            result.add(current->value);
        }
        current = current->next;
    }
    return result;
}

bool Set::operator == (const Set& other) const {
    if (count != other.count) {
        return false;
    }

    Node* current = head;
    while (current != nullptr) {
        if (other.findNode(current->value) == nullptr) {
            return false;
        }
        current = current->next;
    }
    return true;
}

Set& Set::operator << (const std::string& value) {
    add(value);
    return *this;
}

void Set::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << "\n";
}

void Set::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    Node* current = head;
    if (!file.is_open()) {
        std::cout << "wrong filename";
        return;
    }
    while (current != nullptr) {
        file << current->value << "\n";
        current = current->next;
    }
    file.close();
}


void Set::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "wrong filename";
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        add(line);
    }
}
