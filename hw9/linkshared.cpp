//Tavishka ta24435 tavishka
#include <iostream>
#include <memory>
using std::cin, std::cout, std::make_shared, std::shared_ptr;

class Node; //forward declaration

class List {
private:
    shared_ptr<Node> head{nullptr};

public:
    List() {};
    auto headnode() { return head; };
    void insert(int value);
    int length();
    bool contains_value(int v);
    void print();
};

class Node {
private:
    int datavalue{0}, datacount{0};
    shared_ptr<Node> next{nullptr};

public:
    Node() {};
    Node(int value, shared_ptr<Node> next = nullptr)
        : datavalue(value), datacount(1), next(next) {};

    int value() { return datavalue; };
    int count() { return datacount; };
    shared_ptr<Node> nextnode() { return next; };
    bool has_next() { return next != nullptr; };

    //method to increment datacount
    void increment_count() { datacount++; }

    //method to update the next node
    void set_next(shared_ptr<Node> new_next) { next = new_next; }

    int length();
    bool contains_value(int v);
    void insert(int value);
};

//insert a value into the list while maintaining sorted order
void List::insert(int value) {
    //if the list is empty or the new value is less than the head value, insert at head
    if (head == nullptr || value < head->value()) {
        head = make_shared<Node>(value, head);
    } else {
        auto current = head;

        //traverse the list to find the correct position
        while (current->has_next() && current->nextnode()->value() <= value) {
            current = current->nextnode();
        }

        //if the current node's value matches, increment the count
        if (current->value() == value) {
            current->increment_count();
        } else {
            //insert the new node in the correct position
            auto newNode = make_shared<Node>(value, current->nextnode());
            current->set_next(newNode);
        }
    }
}



//recursively calculate the length of the list
int List::length() {
    if (head == nullptr)
        return 0;
    else
        return head->length();
}

int Node::length() {
    if (!has_next())
        return 1;
    else
        return 1 + next->length();
}

//check if the list contains a specific value
bool List::contains_value(int v) {
    auto current = head;  //declare and initialize current
    while (current != nullptr) {
        if (current->value() == v)
            return true;
        current = current->nextnode();
    }
    return false;
}


//print the list with values separated by commas
void List::print() {
    auto current = head;
    bool first = true;
    while (current != nullptr) {
        if (!first) cout << ", ";
        cout << current->value() << ":" << current->count();
        current = current->nextnode();
        first = false;
    }
    cout << '\n';
}

//main interactive input 
int main() {
    List mylist;
    int input;
    cout << "Enter numbers (0 to end):\n";
    while (true) {
        cin >> input;
        if (input == 0) break;
        mylist.insert(input);
        // Print the list after each insertion
        mylist.print();
    }
    return 0;
}
