#include <iostream>
using namespace std;

class student {
public:
    string name;
    int age;

    student(string name, int age) {
        this->name = name;
        this->age = age;
    }
    void print() { cout << name << " " << age << endl; }
};

template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node(T *value) {
        this->value = value;
        this->next = NULL;
    }
    void print() { value->print(); }
};

template <typename T> class LinkedList {
private:
    int length;
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList(T *value) {
        Node<T> *newNode = new Node<T>(value);
        length = 1;
        head = newNode;
        tail = newNode;
    }
    ~LinkedList() {
        Node<T> *current = this->head;
        while (head) {
            head = head->next;
            delete current;
            current = head;
        }
    }
    void add(T *value) {
        Node<T> *newNode = new Node<T>(value);
        tail->next = newNode;
        tail = newNode;
        length++;
    }

    void addhead(T *value) {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void delfirst() {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void dellast() {
        Node<T> *temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T> *pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    Node<T>* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node<T>* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    void deleteNode(int index) {
       //TODO:Write the function to delete at the given index. Reuse the pre-written functions for edge cases. Account for missing index.
        if (index < 0 || index >= length) {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 0) {
            delfirst();
            return;
        }

        if (index == length - 1) {
            dellast();
            return;
        }

        else {
            Node<T>* temp = get(index);
            Node<T>* tempPrev = get(index - 1);
            tempPrev->next = temp->next;
            delete temp;
            length--;
        }


    }

   void insert(int index, T *value) {
        //TODO:Write a function to insert a new node at a give index. Reuse the pre-written functions for edge cases. Account for missing index
        if (index < 0 || index > length) {
            cout << "Index is invalid." << endl;
            return;
        }

        if (index == 0) {
            addhead(value);
            return;
        }

        if (index == length) {
            add(value);
            return;
        }

        else {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

   void reverselist(){
        //TODO:Write a function to reverse the list using the logic from the slide.
        Node<T>* previous = NULL;
        Node<T>* current = head;
        Node<T>* next;

        while (current != NULL) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    void print() {
        cout << "Printing List.." << endl;
        Node<T> *temp = head;
        while (temp != NULL) {
            temp->print();
            temp = temp->next;
        }
    }
};

int main() {
    student *s1 = new student("A", 20);
    student *s2 = new student("B", 21);
    student *s3 = new student("C", 22);
    LinkedList<student> *ll = new LinkedList<student>(s1);
    ll->add(s2);
    ll->addhead(s3);
    ll->print();
    ll->reverselist();
    ll->print();
    ll->deleteNode(1);
    ll->print();
    ll->insert(1, s1);
    ll->print();
    ll->delfirst();
    ll->print();
    ll->dellast();
    ll->print();
    ll->~LinkedList();
    ll->print();
}