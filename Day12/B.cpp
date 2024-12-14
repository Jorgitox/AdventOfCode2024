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

ll di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

ll dfs(ll i, ll j, ll id, char match, vector<string> & input, vector<vector<ll>> & regions){
  if(i < 0 || i >= SZ(regions))
    return 0;
  if(j < 0 || j >= SZ(regions))
    return 0;
  if(input[i][j] != match)
    return 0;
  if(regions[i][j] != -1)
    return 0;

  regions[i][j] = id;

  ll newPlots = 0;

  FOR(k, 0, 4)
    newPlots += dfs(i + di[k], j + dj[k], id, match, input, regions);
  
  return 1 + newPlots;
}

ll sides(vector<vector<ll>> & regions, ll id){
  vector<vector<ll>> visited(SZ(regions), vector<ll>(SZ(regions)));

  ll a = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(regions[i][j] == id){
        if(i == 0 || regions[i - 1][j] != id)
          if(!((visited[i][j] >> 0) & 1)){
            // cout << "SIDE UP AT {" << i << ", " << j << "}\n";
            a++;
            ll xj = j;
            while(xj < SZ(regions) && regions[i][xj] == id && (i == 0 || regions[i - 1][xj] != id)){
              // cout << xj << " ";
              visited[i][xj] |= (1 << 0);
              xj++;
            }
            xj = j;
            while(xj >= 0 && regions[i][xj] == id && (i == 0 || regions[i - 1][xj] != id)){
              // cout << xj << " ";
              visited[i][xj] |= (1 << 0);
              xj--;
            }

            // cout << endl;
          }

        if(j == 0 || regions[i][j - 1] != id)
          if(!((visited[i][j] >> 1) & 1)){
            // cout << "SIDE LEFT AT {" << i << ", " << j << "}\n";
            a++;
            ll xi = i;
            while(xi < SZ(regions) && regions[xi][j] == id && (j == 0 || regions[xi][j - 1] != id)){
              visited[xi][j] |= (1 << 1);
              xi++;
            }
            xi = i;
            while(xi >= 0 && regions[xi][j] == id && (j == 0 || regions[xi][j - 1] != id)){
              visited[xi][j] |= (1 << 1);
              xi--;
            }
          }

        if(i == SZ(regions) - 1 || regions[i + 1][j] != id)
          if(!((visited[i][j] >> 2) & 1)){
            // cout << "SIDE DOWN AT {" << i << ", " << j << "}\n";
            a++;
            ll xj = j;
            while(xj < SZ(regions) && regions[i][xj] == id && (i == SZ(regions) - 1 || regions[i + 1][xj] != id)){
              visited[i][xj] |= (1 << 2);
              xj++;
            }
            xj = j;
            while(xj >= 0 && regions[i][xj] == id && (i == SZ(regions) - 1 || regions[i + 1][xj] != id)){
              visited[i][xj] |= (1 << 2);
              xj--;
            }
          }

        if(j == SZ(regions) - 1 || regions[i][j + 1] != id)
          if(!((visited[i][j] >> 3) & 1)){
            // cout << "SIDE RIGHT AT {" << i << ", " << j << "}\n";
            a++;
            ll xi = i;
            while(xi < SZ(regions) && regions[xi][j] == id && (j == SZ(regions) - 1 || regions[xi][j + 1] != id)){
              visited[xi][j] |= (1 << 3);
              xi++;
            }
            xi = i;
            while(xi >= 0 && regions[xi][j] == id && (j == SZ(regions) - 1 || regions[xi][j + 1] != id)){
              visited[xi][j] |= (1 << 3);
              xi--;
            }
          }
      }

  return a;
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

  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(areas[regions[i][j]]){
        ll sidesID = sides(regions, regions[i][j]);
        // cout << "ID: " << regions[i][j] << " - Area: " << areas[regions[i][j]] << " - Sides: " << sidesID << ENDL;
        ans += areas[regions[i][j]] * sidesID;

        areas[regions[i][j]] = 0;
      }
  

  cout << ans;

  return 0;
}
