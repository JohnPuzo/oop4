#include <string>

class Set {
private:
    struct Node {
        std::string value;
        Node* next;

        Node(const std::string& val, Node* nxt = nullptr)  : value(val), next(nxt) {}
    };

    Node* head;
    int count;

public:
    Set();
    Set(const Set& other);
    ~Set();

    Node* findNode(const std::string& value) const;
    void add(const std::string& value);
    void remove(const std::string& value);
    int size() const;

    void clear();

    Set operator&&(const Set& other) const;
    bool operator==(const Set& other) const;
    Set& operator<<(const std::string& value);

    void print() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
