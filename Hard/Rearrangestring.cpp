//Question 277
#include <bits/stdc++.h>

 

string reArrangeString(string &s) {

    int n = s.size();

    unordered_map<char, int> freq;

    priority_queue<pair<int, char>> pq;

 

    // Count the frequency of each character

    for (char c : s) {

        freq[c]++;

    }

 

    // Push characters with their frequencies into a max-heap

    for (auto &entry : freq) {

        pq.push({entry.second, entry.first});

    }

 

    string result;

    pair<int, char> prev = {0, '#'}; // Initialize previous character with dummy values

 

    // Process the max-heap

    while (!pq.empty()) {

        int count= pq.top().first;

        char char1=pq.top().second;

        pq.pop();

 

        // Append the current character to the result

        result += char1;

 

        // If the previous character still has remaining count, push it back to the heap

        if (prev.first > 0) {

            pq.push(prev);

        }

 

        // Update the previous character with the current one

        prev = {count - 1, char1};

    }

 

    // If the result length is equal to the input string length, return the result

    if (result.size() == n) {

        return result;

    } else {

        return "not possible";

    }

}