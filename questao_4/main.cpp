#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> depth(n, 0);

  function<void(int, int, int)> build = [&](int l, int r, int d) {
    if (l > r)
      return;

    int max_idx = l;
    for (int i = l; i <= r; i++)
      if (a[i] > a[max_idx])
        max_idx = i;

    depth[max_idx] = d;

    build(l, max_idx - 1, d + 1);
    build(max_idx + 1, r, d + 1);
  };

  build(0, n - 1, 0);

  for (int i = 0; i < n; i++)
    cout << depth[i] << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
