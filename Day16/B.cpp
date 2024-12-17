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

ll dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

void backtrack(ll ans, ll x, ll y, vector<vector<vector<ll>>> & dp, vector<vector<bool>> & seats){
  FOR(i, 0, 4){
    if(dp[x][y][i] == ans){
      seats[x][y] = 1;
      backtrack(ans - 1, x - dx[i], y - dy[i], dp, seats);
      backtrack(ans - 1001, x - dx[i], y - dy[i], dp, seats);
      backtrack(ans - 2001, x - dx[i], y - dy[i], dp, seats);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  ll x1, y1, x2, y2;
  FOR(i, 0, SZ(input))
    FOR(j, 0, SZ(input))
      if(input[i][j] == 'E'){
        x1 = i; 
        y1 = j;
      } else if(input[i][j] == 'S'){
        x2 = i;
        y2 = j;
      }

  vector<vector<vector<ll>>> dp(SZ(input), vector<vector<ll>>(SZ(input), vector<ll>(4, 1000000000000)));
  
  priority_queue<pair<pi, pi>> pq;
  pq.push({{0, 1}, {x2, y2}});
  dp[x2][y2][1] = 0;

  while(!pq.empty()){
    auto [a, b] = pq.top();
    pq.pop();
    auto [dist, dir] = a;
    auto [x, y] = b;

    dist *= -1;

    if(input[x][y] == '#')
      continue;

    // cout << "dist: " << dist << " - dir: " << dir << " - x: " << x << "s - y: " << y << ENDL;
    
    if(dp[x + dx[dir]][y + dy[dir]][dir] > (dist + 1)){
      dp[x + dx[dir]][y + dy[dir]][dir] = (dist + 1);
      pq.push({{-(dist + 1), dir}, {x + dx[dir], y + dy[dir]}});
    }

    if(dp[x + dx[(dir + 1) % 4]][y + dy[(dir + 1) % 4]][(dir + 1) % 4] > (dist + 1001)){
      dp[x + dx[(dir + 1) % 4]][y + dy[(dir + 1) % 4]][(dir + 1) % 4] = (dist + 1001);
      pq.push({{-(dist + 1001), (dir + 1) % 4}, {x + dx[(dir + 1) % 4], y + dy[(dir + 1) % 4]}});
    }

    if(dp[x + dx[(dir + 3) % 4]][y + dy[(dir + 3) % 4]][(dir + 3) % 4] > (dist + 1001)){
      dp[x + dx[(dir + 3) % 4]][y + dy[(dir + 3) % 4]][(dir + 3) % 4] = (dist + 1001);
      pq.push({{-(dist + 1001), (dir + 3) % 4}, {x + dx[(dir + 3) % 4], y + dy[(dir + 3) % 4]}});
    }

    if(dp[x + dx[(dir + 2) % 4]][y + dy[(dir + 2) % 4]][(dir + 2) % 4] > (dist + 2001)){
      dp[x + dx[(dir + 2) % 4]][y + dy[(dir + 2) % 4]][(dir + 2) % 4] = (dist + 2001);
      pq.push({{-(dist + 2001), (dir + 2) % 4}, {x + dx[(dir + 2) % 4], y + dy[(dir + 2) % 4]}});
    }
  }

  vector<vector<bool>> usedSeats(SZ(dp), vector<bool>(SZ(dp), false));

  backtrack(min(min(dp[x1][y1][0], dp[x1][y1][1]), min(dp[x1][y1][2], dp[x1][y1][3])), x1, y1, dp, usedSeats);

  ll ans = 0;
  FOR(i, 0, SZ(dp))
    FOR(j, 0, SZ(dp)) 
      ans += usedSeats[i][j];

  cout << ans;


  return 0;
}
