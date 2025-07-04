#include <iostream>
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> ans;

    for (int cols = 0; cols < mCols; cols++) {
        if (cols & 1) {
            // Odd index --> bottom to top
            for (int rows = nRows - 1; rows >= 0; rows--) {
                ans.push_back(arr[rows][cols]);
            }
        } else {
            // Even index --> top to bottom
            for (int rows = 0; rows < nRows; rows++) {
                ans.push_back(arr[rows][cols]);
            }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = wavePrint(arr, 3, 3);

    cout << "Wave Print: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


// #include <bits/stdc++.h> 
// vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
//     vector<int> ans;

//     for (int cols = 0; cols < mCols; cols++) {
//         if (cols & 1) {
//             // Odd index --> bottom to top
//             for (int rows = nRows - 1; rows >= 0; rows--) {
//                 ans.push_back(arr[rows][cols]);
//             }
//         } else {
//             // Even index --> top to bottom
//             for (int rows = 0; rows < nRows; rows++) {
//                 ans.push_back(arr[rows][cols]);
//             }
//         }
//     }

//     return ans;
// }