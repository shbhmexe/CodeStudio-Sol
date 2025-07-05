#include <bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    if (index >= str.length()) {
        if (output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }

    // exclude
    solve(str, output, index + 1, ans);

    // include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main() {
    string str = "abc";
    vector<string> res = subsequences(str);

    cout << "All Subsequences:\n";
    for (string s : res) {
        cout << s << endl;
    }

    return 0;
}
// This code generates all subsequences of a given string using recursion.
// It includes both the empty subsequence and all non-empty subsequences.
// The function `solve` recursively builds subsequences by either including or excluding each character.

// #include <bits/stdc++.h> 

// void solve(string str, string output, int index, vector<string>& ans) {
// 	if (index >= str.length()) {
// 		if (output.length() > 0) {
// 			ans.push_back(output);
// 		}
// 		return;
// 	}

// 	// exclude
// 	solve(str, output, index+1, ans);

// 	// include
// 	output.push_back(str[index]);
// 	solve(str, output, index+1, ans);

// }
// vector<string> subsequences(string str){
// 	// Write your code here
// 	int index = 0;
// 	string output = "";
// 	vector<string> ans;
// 	solve(str, output, index, ans);
// 	return ans;
	
// }