#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> result;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicate elements for the first element of triplet
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int target = K - arr[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == target) {
                result.push_back({arr[i], arr[left], arr[right]});

                // Skip duplicates for second element
                while (left < right && arr[left] == arr[left + 1]) left++;
                // Skip duplicates for third element
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}
