#include <bits/stdc++.h>

using namespace std;

string normalize(const string &s) {
  int n = s.size();
  if (n % 2 == 1)
    return s;
  string a = normalize(s.substr(0, n / 2));
  string b = normalize(s.substr(n / 2));
  if (a < b)
    return a + b;
  else
    return b + a;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string As, Bs;
  cin >> As >> Bs;

  if (normalize(As) == normalize(Bs))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
