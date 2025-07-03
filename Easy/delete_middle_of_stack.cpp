#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {
    // Base Case
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); // Stack is: [5(top), 4, 3, 2, 1]

    cout << "Before Deletion (Top to Bottom): ";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    deleteMiddle(st, st.size());

    cout << "After Deletion (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}


// #include <bits/stdc++.h> 

// void solve(stack<int>& inputStack, int count, int size) {
//     // Base Case
//     if (count == size / 2) {
//         inputStack.pop();
//         return;
//     }

//     int num = inputStack.top();
//     inputStack.pop();

//     // Recursive call
//     solve(inputStack, count + 1, size);

//     inputStack.push(num);
// }

// void deleteMiddle(stack<int>& inputStack, int N) {
//     int count = 0;
//     solve(inputStack, count, N);
// }