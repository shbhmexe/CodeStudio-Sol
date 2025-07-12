#include <bits/stdc++.h>
using namespace std;

// Helper function to insert element in sorted (ascending) order
void sortedInsert(stack<int>& s, int x) {
    if (s.empty() || x < s.top()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

// Main function to sort stack using recursion (ascending order)
void sortStack(stack<int>& s) {
    if (s.empty()) return;

    int num = s.top();
    s.pop();

    sortStack(s);
    sortedInsert(s, num);
}
