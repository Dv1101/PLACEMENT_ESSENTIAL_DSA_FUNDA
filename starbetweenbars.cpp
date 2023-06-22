#include <iostream>
#include <vector>
using namespace std;

vector<int> countStarsBetweenBars(string s, vector<int>& startIndex, vector<int>& endIndex) {
    vector<int> result;
    for (int i = 0; i < startIndex.size(); i++) {
        int start = startIndex[i] - 1;
        int end = endIndex[i] - 1;
        string substring = s.substr(start, end - start);
        int count = 0;
        for (char c : substring) {
            if (c == '*') {
                count++;
            }
        }
        result.push_back(count);
    }
    return result;
}

int main() {
    string s = "*|*|";
    vector<int> startIndex = {1};
    vector<int> endIndex = {3};

    vector<int> result = countStarsBetweenBars(s, startIndex, endIndex);

    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}