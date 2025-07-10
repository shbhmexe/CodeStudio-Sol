#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    bool isFirstRowZero = false;
    bool isFirstColZero = false;

    // Check if first row contains zero
    for (int j = 0; j < m; j++) {
        if (matrix[0][j] == 0) {
            isFirstRowZero = true;
            break;
        }
    }

    // Check if first column contains zero
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }

    // Mark zeros on first row and column for other zeros
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set matrix cells to 0 based on marks in first row and column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Finally, update first row and first column if needed
    if (isFirstRowZero) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }

    if (isFirstColZero) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}
