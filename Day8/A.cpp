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
        // first antinode
        int x1 = (n[i].first) - (n[j].first - n[i].first);
        int y1 = (n[i].second) - (n[j].second - n[i].second);

        if(x1 >= 0 && y1 >= 0 && x1 < SZ(mp) && y1 < SZ(mp[0]) - 1){
          // cout << "Antinode at {" << x1 << ", " << y1 << "}\n";
          antinodes[x1][y1] = 1;
        }
        // second antinode
        int x2 = (n[j].first) - (n[i].first - n[j].first);
        int y2 = (n[j].second) - (n[i].second - n[j].second);

        if(x2 >= 0 && y2 >= 0 && x2 < SZ(mp) && y2 < SZ(mp[0]) - 1){
          // cout << "Antinode at {" << x2 << ", " << y2 << "}\n";
          antinodes[x2][y2] = 1;
        }
      }
    
  }

  FOR(i, 0, SZ(mp))
    FOR(j, 0, SZ(mp[0]) - 1)
      ans += antinodes[i][j];

  cout << ans;

  return 0;
}