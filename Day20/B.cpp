#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};

ll path(ll xS, ll yS, ll xE, ll yE, vvll & dp, vvll & visited, vector<string> & map){
  if(xS < 0 || xS >= SZ(dp))
    return 999999;

  if(yS < 0 || yS >= SZ(dp))
    return 999999;

  if(map[xS][yS] == '#')
    return 999999;
  
  if(xS == xE && yS == yE)
    return dp[xS][yS] = 0;
  
  if(visited[xS][yS])
    return 9999;

  visited[xS][yS] = 1;

  ll ans = 99999;
  FOR(i, 0, 4){
    ans = min(ans, path(xS + dx[i], yS + dy[i], xE, yE, dp, visited, map));
  }

  return dp[xS][yS] = 1 + ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  ll xS = 0, yS = 0, xE = 0, yE = 0;
  FOR(i, 0, SZ(input))
    FOR(j, 0, SZ(input))
      if(input[i][j] == 'S'){
        xS = i;
        yS = j;
      } else if(input[i][j] == 'E'){
        xE = i;
        yE = j;
      }

  vvll dp(SZ(input), vll(SZ(input), -1));
  vvll visited(SZ(input), vll(SZ(input), 0));

  path(xS, yS, xE, yE, dp, visited, input);

  map<ll, ll> savedTimes;

  FOR(i, 0, SZ(input) )
    FOR(j, 0, SZ(input)){
      if(dp[i][j] != -1){
        FOR(k, -21, 22){
          FOR(l, -21, 22){
            if(abs(k) + abs(l) <= 20){
              ll newX = i + k;
              ll newY = j + l;
              if(0 <= newX && newX < SZ(dp) && 0 <= newY && newY < SZ(dp)){
                if(dp[newX][newY] != -1){
                  ll savedTime = dp[newX][newY] - dp[i][j] - abs(k) - abs(l);

                  if(savedTime > 0){
                    savedTimes[savedTime] ++;
                  }
                }
              }
            }
          }
        }
      }
    }
  
  ll ans = 0;

  for(auto & p : savedTimes)  {
    if(p.first >= 100){
      // cout << "There are " << p.second << " cheats that save " << p.first << " picoseconds.\n";
      ans += p.second;
    }
  }

  cout << ans;
  
  return 0;
}
