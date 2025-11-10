#include <bits/stdc++.h>
using namespace std;

int countDiff(const string& s, int l, int r, char target) {
    int count = 0;
    for (int i = l; i < r; i++) {
        if (s[i] != target) count++;
    }
    return count;
}

int solve(const string& s, int l, int r, char c) {
    int len = r - l;

    if (len == 1) {
        return s[l] != c ? 1 : 0;
    }

    int mid = l + len / 2;

    int cost1 = countDiff(s, l, mid, c) + solve(s, mid, r, c + 1);
    int cost2 = countDiff(s, mid, r, c) + solve(s, l, mid, c + 1);

    return min(cost1, cost2);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        cout << solve(s, 0, n, 'a') << endl;
    }

    return 0;
}
