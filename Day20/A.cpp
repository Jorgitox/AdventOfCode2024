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

ll distance(ll xS, ll yS, ll xE, ll yE, vector<string> &  map){
  vector<vector<bool>> visited(SZ(map), vector<bool>(SZ(map)));
  queue<pair<ll, pll>> q;
  q.push({0, {xS, yS}});
  visited[xS][yS] = 1;
  
  while(!q.empty()){
    auto [dist, coords] = q.front();
    auto [x, y] = coords;
    q.pop();

    if(x == xE && y == yE){
      return dist;
    }

    FOR(i, 0, 4){
      ll newX = x + dx[i];
      ll newY = y + dy[i];  
      if(0 <= newX && newX < SZ(map) && 0 <= newY && newY <= SZ(map)){
        if(!visited[newX][newY] && map[newX][newY] != '#'){
          visited[newX][newY] = 1;
          q.push({dist + 1, {newX, newY}});
        }
      }
    }
  }

  return 999999;
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

  ll originalDistance = distance(xS, yS, xE, yE, input);

  vector<string> cheatedInput(SZ(input));
  FOR(i, 0, SZ(input))
    FOR(j, 0, SZ(input))
      cheatedInput[i].pb(input[i][j]);

  map<ll, ll> savedTimes;

  FOR(i, 0, SZ(input))
    FOR(j, 0, SZ(input)){
      if(input[i][j] == '#'){
        cheatedInput[i][j] = '.';
        ll dist = distance(xS, yS, xE, yE, cheatedInput);
        cheatedInput[i][j] = input[i][j];

        if(originalDistance - dist > 0){
          // cout << "Saved at: {" << i << ", " << j << "} and {"  << i << ", "<< j + 1 << "}\n";
          savedTimes[originalDistance - dist] ++;
        }
      }
    }
  
  ll ans = 0;

  for(auto & p : savedTimes)  {
    // cout << "There are " << p.second << " cheats that save " << p.first << " picoseconds.\n";
    if(p.first >= 100)
      ans += p.second;
  }

  cout << ans;
  
  return 0;
}
