#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    string s, t;
    int n, m;
    vector<vector<vector<int>>> memo;

    int powerOf2(int exp) {
        ll res = 1;
        ll base = 2;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    int dp(int i, int j, int tight) {
        if (j == m) {
            // t is prefix of current subsequence, so rest of s gives valid subsequences
            return powerOf2(n - i);
        }
        if (i == n) return 0;

        if (memo[i][j][tight] != -1)
            return memo[i][j][tight];

        ll res = 0;

        // Option 1: skip s[i]
        res += dp(i + 1, j, tight);
        res %= MOD;

        // Option 2: take s[i]
        if (tight) {
            if (s[i] > t[j]) {
                res += powerOf2(n - i - 1);
            } else if (s[i] == t[j]) {
                res += dp(i + 1, j + 1, 1);
            }
        } else {
            res += dp(i + 1, j, 0);
        }

        return memo[i][j][tight] = res % MOD;
    }

    int countSecuredStrings(string s_input, string t_input) {
        s = s_input;
        t = t_input;
        n = s.length();
        m = t.length();
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));
        return dp(0, 0, 1);
    }
};

// Driver code for testing
int main() {
    Solution sol;
    cout << sol.countSecuredStrings("aba", "ab") << endl; // Output: 3
    cout << sol.countSecuredStrings("bab", "ab") << endl; // Output: 5
    return 0;
}
