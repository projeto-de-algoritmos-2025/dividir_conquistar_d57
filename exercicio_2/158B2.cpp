#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;

struct SparseTable {
  std::vector<std::vector<ll>> st;
  std::vector<int> logs;
  int n;

  SparseTable(const std::vector<ll> &arr) {
    n = arr.size();
    if (n == 0)
      return;

    logs.resize(n + 1);
    logs[1] = 0;
    for (int i = 2; i <= n; i++) {
      logs[i] = logs[i / 2] + 1;
    }

    int k_max = logs[n] + 1;
    st.resize(n, std::vector<ll>(k_max));

    for (int i = 0; i < n; i++) {
      st[i][0] = arr[i];
    }

    for (int k = 1; k < k_max; k++) {
      for (int i = 0; i + (1 << k) <= n; i++) {
        st[i][k] = std::gcd(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
      }
    }
  }

  ll query(int L, int R) {
    if (L > R)
      return 0;
    int k = logs[R - L + 1];
    return std::gcd(st[L][k], st[R - (1 << k) + 1][k]);
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  if (n == 1) {
    std::cout << 1 << "\n";
    return;
  }

  std::vector<ll> b;
  for (int i = 0; i < n - 1; i++) {
    b.push_back(std::abs(a[i + 1] - a[i]));
  }

  SparseTable st(b);
  int n_b = b.size();
  int max_len = 1;

  for (int i = 0; i < n_b; i++) {
    if (b[i] == 1)
      continue;
    int low = i;
    int high = n_b - 1;
    int best_j = i;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (st.query(i, mid) > 1) {
        best_j = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    max_len = std::max(max_len, (best_j - i + 1) + 1);
  }

  std::cout << max_len << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
