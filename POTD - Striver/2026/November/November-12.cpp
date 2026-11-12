// Implement a First-In-First-Out (FIFO) queue using an array. The implemented queue should support the following operations: push, peek, pop, and isEmpty Implement the ArrayQueue class:

//     1 - void push(int x): Adds element x to the end of the queue.
//     2 - int pop(): Removes and returns the front element of the queue.
//     3 - int peek(): Returns the front element of the queue without removing it.
//     4 - boolean isEmpty(): Returns true if the queue is empty, false otherwise.







#include <bits/stdc++.h>
using namespace std;

class ArrayQueue {
private:
    vector<int> arr;
    int frontIndex;

public:
    ArrayQueue() {
        frontIndex = 0;
    }

    void push(int x) {
        arr.push_back(x);
    }

    int pop() {
        if (isEmpty()) return -1;
        int frontElement = arr[frontIndex];
        frontIndex++;
        return frontElement;
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[frontIndex];
    }

    bool isEmpty() {
        return frontIndex >= arr.size();
    }
};

int main() {
    ArrayQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Front element: " << queue.peek() << endl;
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    cout << "Front element: " << queue.peek() << endl;
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Popped element: " << queue.pop() << endl;
    cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
}