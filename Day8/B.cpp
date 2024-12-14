#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  // FILE *fp = fopen("output.txt", "a");

  ll ans = 0;

  vector<string> mp;
  string line;
  while(getline(cin, line)){
    mp.pb(line);
  } 

  map<char, vector<pi>> nodes;

  FOR(i, 0, SZ(mp))
    FOR(j, 0, SZ(mp[0]) - 1)
      if(mp[i][j] != '.')
        nodes[mp[i][j]].pb({i, j});

  vector<vi> antinodes(SZ(mp), vi(SZ(mp[0]) - 1));

  for(auto aux : nodes){
    vector<pi> n = aux.second;

    FOR(i, 0, SZ(n))
      FOR(j, i + 1, SZ(n)){
        int xDiff = (n[j].first - n[i].first);
        int yDiff = (n[j].second - n[i].second);

        FOR(k, -100, 100){
          int xi = n[i].first + k * xDiff;
          int yi = n[i].second + k * yDiff;
          if(0 <= xi && xi < SZ(mp) && 0 <= yi && yi < SZ(mp[0]) - 1)
            antinodes[xi][yi] = 1;
        }
      }
  }

  FOR(i, 0, SZ(mp))
    FOR(j, 0, SZ(mp[0]) - 1)
      ans += antinodes[i][j];

  cout << ans;

  return 0;
}