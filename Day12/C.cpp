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

ll di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};

ll dfs(ll i, ll j, ll id, char match, vector<string> & input, vector<vector<ll>> & regions){
  if(i < 0 || i >= SZ(regions) || j < 0 || j >= SZ(regions))
    return 0;

  if(input[i][j] != match || regions[i][j] != -1)
    return 0;

  regions[i][j] = id;

  ll newPlots = 0;

  FOR(k, 0, 4)
    newPlots += dfs(i + di[k], j + dj[k], id, match, input, regions);
  
  return 1 + newPlots;
}

ll countSides(ll id, vector<vector<ll>> & regions){
  vector<vector<ll>> visited(SZ(regions), vector<ll>(SZ(regions)));

  ll sides = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(regions[i][j] == id)
        FOR(k, 0, 4)
          if(i + di[k] < 0 || i + di[k] >= SZ(regions) || j + dj[k] < 0 || j + dj[k] >= SZ(regions) || regions[i + di[k]][j + dj[k]] != id)
            if(!((visited[i][j] >> k) & 1)){
              sides++;

              ll xi = i, xj = j;
              while(xi < SZ(regions) && xj < SZ(regions) && regions[xi][xj] == id && (xi + di[k] < 0 || xi + di[k] >= SZ(regions) || xj + dj[k] < 0 || xj + dj[k] >= SZ(regions) || regions[xi + di[k]][xj + dj[k]] != id)){
                visited[xi][xj] |= (1 << k);
                xi += di[!(k & 1)];
                xj += dj[!(k & 1)];
              }

              xi = i, xj = j;
              while(xi >= 0 && xj >= 0 && regions[xi][xj] == id && (xi + di[k] < 0 || xi + di[k] >= SZ(regions) || xj + dj[k] < 0 || xj + dj[k] >= SZ(regions) || regions[xi + di[k]][xj + dj[k]] != id)){
                visited[xi][xj] |= (1 << k);
                xi -= di[!(k & 1)];
                xj -= dj[!(k & 1)];
              }
            }

  return sides;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  vector<vector<ll>> regions(SZ(input), vector<ll>(SZ(input), -1));
  vector<ll> areas;

  ll id = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(regions[i][j] == -1)
        areas.pb(dfs(i, j, id++, input[i][j], input, regions));

  ll ans = 0;

  FOR(i, 0, id)
    ans += areas[i] * countSides(i, regions);
  
  cout << ans;

  return 0;
}
