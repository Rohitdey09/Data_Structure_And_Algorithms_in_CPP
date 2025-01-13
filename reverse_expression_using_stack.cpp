#include <iostream>
using namespace std;

// Stack class definition
class Stack {
    int capacity;
    char* arr;
    int top;

public:
    Stack(int size) {
        this->capacity = size;
        this->top = -1;
        this->arr = new char[capacity];
    }

    ~Stack() { // Destructor to clean up memory
        delete[] arr;
    }

    bool isfull() {
        return top == capacity - 1;
    }

    bool isempty() {
        return top == -1;
    }

    void push(char ch) {
        if (!isfull())
            arr[++top] = ch;
    }

    void pop() {
        if (!isempty())
            top--;
    }

    char peek() {
        if (!isempty())
            return arr[top];
        return '\0'; // Return null character if stack is empty
    }

    int getCapacity() const {
        return capacity;
    }

    int getSize() const {
        return top + 1;
    }
};

// Function to reverse a stack using an auxiliary stack
void reverseStack(Stack& st) {
    Stack aux(st.getCapacity()); // Auxiliary stack to help reverse

    // Transfer all elements from st to aux
    while (!st.isempty()) {
        aux.push(st.peek());
        st.pop();
    }

    // Transfer all elements from aux back to st (reversing them)
    while (!aux.isempty()) {
        st.push(aux.peek());
        aux.pop();
    }
}

// Function to print the stack
void printStack(Stack& st) {
    Stack temp(st.getCapacity());
    while (!st.isempty()) {
        cout << st.peek() << " ";
        temp.push(st.peek());
        st.pop();
    }
    cout << endl;

    // Restore the original stack
    while (!temp.isempty()) {
        st.push(temp.peek());
        temp.pop();
    }
}

int main() {
    Stack st(5); // Example stack with capacity 5
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');

    cout << "Original Stack: ";
    printStack(st);

    // Reverse the stack
    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
