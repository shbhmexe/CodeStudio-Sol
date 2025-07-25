//Question 232
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    unordered_set<int> common(mat[0].begin(), mat[0].end());

    for (int i = 1; i < rows; ++i) {
        unordered_set<int> rowSet(mat[i].begin(), mat[i].end());
        unordered_set<int> temp;

        for (int num : common) {
            if (rowSet.count(num)) {
                temp.insert(num);
            }
        }
        common = std::move(temp);
    }

    // Convert unordered_set to vector
    vector<int> result(common.begin(), common.end());
    return result;
}
