#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(const string& s) {
    if (s.empty()) {
        return "";
    }

    int start = 0;
    int maxLength = 1;

    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right]) {
            int currentLength = right - left + 1;
            if (currentLength > maxLength) {
                start = left;
                maxLength = currentLength;
            }
            --left;
            ++right;
        }
    };

    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        expandAroundCenter(i, i);
        expandAroundCenter(i, i + 1);
    }

    return s.substr(start, maxLength);
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    string answer = longestPalindrome(input);

    cout << "Longest palindromic substring: " << answer << '\n';

    return 0;
}
