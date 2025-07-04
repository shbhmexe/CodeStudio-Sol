#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int start, int end) {

    int pivot = arr[start];
    int count = 0;

    // Count elements <= pivot
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    // Rearranging left and right of pivot
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void solve(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int p = partition(arr, start, end);

    solve(arr, start, p - 1);
    solve(arr, p + 1, end);
}

vector<int> quickSort(vector<int> arr) {
    solve(arr, 0, arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};

    cout << "Before Sorting: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    arr = quickSort(arr);

    cout << "After Sorting: ";
    for (int i : arr) cout << i << " ";
    cout << endl;

    return 0;
}



// #include <bits/stdc++.h> 

// int partition(vector<int>& arr, int start, int end) {

//     int pivot = arr[start];

//     int count = 0;

//     // calculating the mnumber of value which are less then pivot
//     for (int i=start+1; i<=end; i++) {
//         if (arr[i]<=pivot) {
//             count++;
//         }
//     }

//     // plcing pivot at right position
//     int pivotIndex = start + count;
//     swap(arr[pivotIndex], arr[start]);

//     int i=start, j = end;

//     while (i < pivotIndex && j > pivotIndex) {
//         while (arr[i] <= pivot) {
//             i++;
//         }

//         while (arr[j] > pivot) {
//             j--;
//         }

//         if (i < pivotIndex && j > pivotIndex) {
//             swap(arr[i++], arr[j--]);
//         } 
//     }

//     return pivotIndex;

// }

// void solve(vector<int>& arr, int start, int end) {

//     if (start  >= end) {
//         return ;
//     }

//     int p = partition(arr, start, end);

//     // sorting the left part of the array
//     solve(arr, start, p-1);

//     // sorting the right part of the array
//     solve(arr, p+1, end);
// }


// vector<int> quickSort(vector<int> arr)
// {
//     // Write your code here.
//     solve(arr, 0, arr.size()-1);
//     return arr;
// }