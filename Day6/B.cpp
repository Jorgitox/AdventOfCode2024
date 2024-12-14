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

ll dx [] = {-1, 0, 1, 0};
ll dy [] = {0, 1, 0, -1};

ll findLoop(vector<string> & lab, vector<vector<ll>> & visited, ll x, ll y, ll dir){
  if(x < 0 || y < 0) return 0;
  if(x >= SZ(lab) || y >= SZ(lab[0])) return 0;
  if(lab[x][y] == '#'){
    ll newX = x - dx[dir];
    ll newY = y - dy[dir];
    dir = (dir + 1) % 4;
    return findLoop(lab, visited, newX + dx[dir], newY + dy[dir], dir);
  }

  if(visited[x][y] == dir + 1) return 1;

  // cout << x << " " << y << endl;

  visited[x][y] = dir + 1;

  return findLoop(lab, visited, x + dx[dir], y + dy[dir], dir);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  vector<string> lab;

  ll x, y;

  ll x2 = 0;
  string line;
  while(getline(cin, line)){
    ll y2 = 0;
    for(char c : line){
      if(c == '^'){
        x = x2;
        y = y2;
      }
      y2++;
    }

    lab.pb(line);

    x2++;
  }

  ll ans = 0;

  vector<vector<ll>> visited(SZ(lab), vector<ll>(SZ(lab[0])));
  for(int i = 0; i < SZ(lab); i ++){
    for(int j = 0; j < SZ(lab[0]); j++){
      if(lab[i][j] == '.'){
        FOR(k, 0, SZ(visited)) FOR(l, 0, SZ(visited[0])) visited[k][l] = 0;
        lab[i][j] = '#';
        ans += findLoop(lab, visited, x, y, 0);
        lab[i][j] = '.'; 
      }
    }
  }

  cout << ans; 
  fprintf(fp, "%lld", ans);

  return 0;
}
