#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int solve(vector<long long>& a) {
    int n = a.size();
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<long long> diff(n - 1);
    for (int i = 0; i < n - 1; i++) {
        diff[i] = abs(a[i + 1] - a[i]);
    }

    int maxLen = 1;
    map<long long, int> gcd_to_start;

    for (int i = 0; i < n - 1; i++) {
        map<long long, int> new_gcd_to_start;
        new_gcd_to_start[diff[i]] = i;

        for (auto& p : gcd_to_start) {
            long long g = gcd(p.first, diff[i]);
            if (g > 1) {
                if (new_gcd_to_start.find(g) == new_gcd_to_start.end()) {
                    new_gcd_to_start[g] = p.second;
                } else {
                    new_gcd_to_start[g] = min(new_gcd_to_start[g], p.second);
                }
            }
        }

        gcd_to_start = new_gcd_to_start;

        for (auto& p : gcd_to_start) {
            if (p.first > 1) {
                maxLen = max(maxLen, i - p.second + 2);
            }
        }
    }

    return maxLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve(a) << "\n";
    }

    return 0;
}
