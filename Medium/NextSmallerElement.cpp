#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];

        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    int n = arr.size();

    vector<int> res = nextSmallerElement(arr, n);

    cout << "Next Smaller Elements: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


// #include <stack>
// #include <vector>


// vector<int> nextSmallerElement(vector<int>& arr, int n) {
//     stack<int> s;
//     s.push(-1);

//     vector<int> ans(n);

//     for (int i = n - 1; i >= 0; i--) {
//         int curr = arr[i];

//         while (s.top() >= curr) {
//             s.pop();
//         }

//         ans[i] = s.top();
//         s.push(curr);
//     }

//     return ans;
// }