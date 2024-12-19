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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  vvll memorySpace(71, vll(71, 0));

  FOR(i, 0, 1024){
    ll x = 0, y = 0;
    ll j = 0;
    while(input[i][j] >= '0' && input[i][j] <= '9' && j < SZ(input[i])){
      x = x * 10 + input[i][j] - '0';
      j++;
    }
    j++;
    while(input[i][j] >= '0' && input[i][j] <= '9' && j < SZ(input[i])){
      y = y * 10 + input[i][j] - '0';
      j++;
    }
    
    memorySpace[y][x] = 1;
  }
  
  queue<pair<ll, pll>> q;
  q.push({0, {0, 0}});
  memorySpace[0][0] = 1;

  while(!q.empty()){
    auto [dist, coords] = q.front();
    auto [x, y] = coords;
    q.pop();

    if(x == 70 && y == 70){
      cout << dist;
      return 0;
    }

    FOR(i, 0, 4){
      ll newX = x + dx[i], newY = y + dy[i];
      if(0 <= newX && newX <= 70 && 0 <= newY && newY <= 70 && !memorySpace[x + dx[i]][y + dy[i]]){
        memorySpace[x + dx[i]][y + dy[i]] = 1;
        q.push({dist + 1, {x + dx[i], y + dy[i]}});
      }
    }
  }
  
  return 0;
}
