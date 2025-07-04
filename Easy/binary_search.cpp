#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int s, int e, int key) {
    if (s > e) {
        return -1;
    }

    int mid = s + (e - s) / 2;

    if (nums[mid] == key) {
        return mid;
    }

    if (nums[mid] < key) {
        return binarySearch(nums, mid + 1, e, key);
    } else {
        return binarySearch(nums, s, mid - 1, key);
    }
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    return binarySearch(nums, 0, n - 1, target);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    int target = 7;
    cout << "Index of " << target << ": " << search(nums, target) << endl;
    return 0;
}


// int binarySearch(vector<int>& nums , int s, int e , int key){
//     if( s > e) {
//         return -1;
//     }

//     int mid = s + (e - s) / 2;

//     if(nums[mid] == key){
//         return mid;
//     }

//     if(nums[mid] < key){
//         return binarySearch(nums , mid + 1 , e , key);
//     }
//     else {
//         return binarySearch(nums , s , mid - 1 , key);
//     }
// }

// int search(vector<int> &nums, int target) {
//     int n = nums.size();
//     int ans = binarySearch(nums , 0 , n , target);
//     return ans;
// }