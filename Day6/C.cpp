#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int trackGuard(vector<string>& m, vector<vector<ll>>& passed, int i, int j, char dir) {
  if (i < 0 || i >= SZ(m)) return 0;
  if(j < 0 || j >= SZ(m[0])) return 0;

  if (passed[i][j] == dir + 1) {
    return 1;
  }

  if(passed[i][j] == 0){
    passed[i][j] = dir + 1;
  }

  if (dir == '^') {
    for(; i >= -1; i--) {
      if (i > -1)
        if (m[i][j] == '#') {
          i++;
          break;
        }
    }

    return trackGuard(m, passed, i, j, '>');
  }

  if (dir == '>') {
    for(; j <= SZ(m[0]); j++) {
      if (j < SZ(m[i]))
        if (m[i][j] == '#') {
          j--;
          break;
        }
    }

    return trackGuard(m, passed, i, j, 'v');
  }

  if (dir == 'v') {
    for(; i <= SZ(m); i++) {
      if (i < SZ(m[i]))
        if (m[i][j] == '#') {
          i--;
          break;
        }
    }
    return trackGuard(m, passed, i, j, '<');
  }

  if (dir == '<') {
    for(; j >= -1 ; j--) {
      if (j > -1)
        if (m[i][j] == '#') {
          j++;
          break;
        }
    }
    return trackGuard(m, passed, i, j, '^');
  }

  return 0;
}

int loopGuard(vector<string>& m, int x, int y) {
  int ob = 0;
  for(int i = 0; i < SZ(m); i++) {
    for(int j = 0; j < SZ(m[i]); j++) {
      if (m[i][j] == '.') {
        vector<vector<ll>> passed(SZ(m), vector<ll>(SZ(m[0]), 0));
        m[i][j] = '#';
        if (trackGuard(m, passed, x, y, '^')) ob++;
        m[i][j] = '.';
      }
    }
  }
  return ob;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  vector<string> m;
  while (getline(cin, s)) {
    m.pb(s);
  }

  int x, y = 0;
  FOR(i, 0, SZ(m))
    FOR(j, 0, SZ(m[i]))
      if (m[i][j] == '^') {
        x = i;
        y = j;
        break;
      }
  
  cout << loopGuard(m, x, y) << ENDL;

  return 0;
}