#include <iostream>
#include <string>
using namespace std;

int minOperationsToGoodString(string s) {
    int n = s.length();
    int count = 0;
    for (int i = 0; i <= n - 3; ) {
        if ((s[i] == '0' && s[i+1] == '1' && s[i+2] == '0') ||
            (s[i] == '1' && s[i+1] == '0' && s[i+2] == '1')) {
            count++;
            // Flip middle character to break pattern (optional string update):
            // s[i+1] = s[i+1] == '0' ? '1' : '0';
            i += 3; // Skip ahead to avoid overlap
        } else {
            i++;
        }
    }
    return count;
}

int main() {
    string s = "111101110100";
    cout << minOperationsToGoodString(s) << endl; // Output: 2
    return 0;
}
