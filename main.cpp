#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node * next;
};

class Stack {
    public:
    Stack(); //constructor
    ~Stack(); //destructor
    void push(string data); //push new node on top of stack
    void pop(); //remove node from top of stack
    void output_stack(); //output top data
    bool isEmpty();
    
    private:
    Node * top;
    
};

Stack::Stack() { //constructor
    //initialize top node to point to NULL
    top = NULL;
}
Stack::~Stack() { //destructor
    if (isEmpty())
        pop();
    else {
        while(!isEmpty()) {
            pop();
        }
    }
    
}
void Stack::push(string data) {
    //initialize dynamically a new node called temp, store the old top in temp's next, make temp the new top, store passed data in temp's data
    Node * temp = new Node();
    temp->next = top;
    top = temp;
    top->data = data;
}

void Stack::pop() {
    if (!isEmpty()) {
        Node * temp = top;
        top = top->next;
        cout << temp->data << " popped!" << endl;
        delete temp;
    }
    else {
        cout << "Nothing to pop!" << endl;
    }
}

void Stack::output_stack() {
    if (!isEmpty()) {
        Node * temp = top->next;
        cout << endl << "Stack's content: " << endl << endl;
        cout << "(top)-> " << top->data;
        while (temp != NULL) {
            cout << " -> " << temp->data;
            temp = temp->next;
        }
        cout << " ->(end)" << endl << endl;
    }
    else {
        cout << "Stack empty, nothing to display..." << endl;
    }
    
    
}

bool Stack::isEmpty() {
    return (top == NULL);
}


int main() {
    Stack * s1 = new Stack();
    string data;
    while(true) {
        cout << "Enter data to add to Stack ('p' to pop top | 'd' to display entire stack | 'x' to pop entire stack & exit): " << flush;
        cin >> data;
        if (data == "p")
            s1->pop();
        else if (data == "d")
            s1->output_stack();
        else if (data == "x")
            break;
        else
            s1->push(data);
    }
    
    delete s1;
}