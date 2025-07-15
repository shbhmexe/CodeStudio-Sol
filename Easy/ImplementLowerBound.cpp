int lowerBound(vector<int> arr, int n, int x) {
    int low = 0;
    int high = n - 1;
    int ans = n;  // Default answer if no element >= x is found

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= x) {
            ans = mid;        // Potential answer found
            high = mid - 1;   // Try to find an even lower index
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
