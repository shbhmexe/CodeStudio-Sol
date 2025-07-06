// #include <bits/stdc++.h> 
// class TwoStack {
//     int *arr;
//     int top1;
//     int top2;
//     int size;

// public:

//     // Initialize TwoStack.
//     TwoStack(int s) {
//         // Write your code here.
//         this->size = s;
//         top1 = -1;
//         top2 = s;
//         arr = new int[s];
        
//     }
    
//     // Push in stack 1.
//     void push1(int num) {
//         // Write your code here.
//         if (top2-top1 > 1) {
//             top1++;
//             arr[top1] = num;
//         }
//     }

//     // Push in stack 2.
//     void push2(int num) {
//         // Write your code here.
//         if (top2-top1 > 1) {
//             top2--;
//             arr[top2] = num;
//         }
//     }

//     // Pop from stack 1 and return popped element.
//     int pop1() {
//         // Write your code here.
//         if (top1 >= 0) {
//             int ans = arr[top1];
//             top1--;
//             return ans;
//         }
//         else {
//             return -1;
//         }
//     }

//     // Pop from stack 2 and return popped element.
//     int pop2() {
//         // Write your code here.
//         if (top2 < size) {
//             int ans = arr[top2];
//             top2++;
//             return ans;
//         }
//         else {
//             return -1;
//         }
//     }
// };


#include <iostream>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            return -1;
        }
    }

    // Destructor to free memory
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(5);

    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    cout << "Pop from stack 1: " << ts.pop1() << endl; // Should print 20
    cout << "Pop from stack 2: " << ts.pop2() << endl; // Should print 40
    cout << "Pop from stack 1: " << ts.pop1() << endl; // Should print 10
    cout << "Pop from stack 2: " << ts.pop2() << endl; // Should print 30

    cout << "Pop from stack 1: " << ts.pop1() << endl; // Should print -1

    return 0;
}
