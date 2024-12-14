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

ll di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void dfs(ll i, ll j, ll id, char match, vector<string> & input, vector<vector<ll>> & regions){
  if(i < 0 || i >= SZ(regions))
    return;
  if(j < 0 || j >= SZ(regions))
    return;
  if(input[i][j] != match)
    return;
  if(regions[i][j] != -1)
    return;

  regions[i][j] = id;

  FOR(k, 0, 4)
    dfs(i + di[k], j + dj[k], id, match, input, regions);
}

ll area(vector<vector<ll>> & regions, ll id){
  ll a = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      a += regions[i][j] == id;

  return a;
}

ll perimeter(vector<vector<ll>> & regions, ll id){
  ll a = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(regions[i][j] == id){
        if(i > 0){
          a += (regions[i - 1][j] != id);
        } else{
          a++;
        }

        if(j > 0){
          a += (regions[i][j - 1] != id);
        } else{
          a++;
        }

        if(i < SZ(regions) - 1){
          a += (regions[i + 1][j] != id);
        } else{
          a++;
        }

        if(j < SZ(regions) - 1){
          a += (regions[i][j + 1] != id);
        } else{
          a++;
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

  ll id = 0;
  FOR(i, 0, SZ(regions))
    FOR(j, 0, SZ(regions))
      if(regions[i][j] == -1)
        dfs(i, j, id++, input[i][j], input, regions);

  ll ans = 0;
  FOR(i, 0, id){
    ans += area(regions, i) * perimeter(regions, i);
  }

  cout << ans;

  return 0;
}
