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

vector<vector<ll>> visited;

void move(vector<string> & lab, ll x, ll y, ll dir){
  if(x < 0 || y < 0) return;
  if(x >= SZ(lab) || y >= SZ(lab[0])) return;
  if(lab[x][y] == '#'){
    ll newX = x - dx[dir];
    ll newY = y - dy[dir];
    dir = (dir + 1) % 4;
    move(lab, newX + dx[dir], newY + dy[dir], dir);
    return;
  }

  // cout << x << " " << y << endl;

  visited[x][y] = 1;

  move(lab, x + dx[dir], y + dy[dir], dir);
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

    vector<ll> l (SZ(line));

    visited.pb(l);

    x2++;
  }

  move(lab, x, y, 0);

  ll ans = 0;

  for(auto v : visited)
    for(auto i : v)
      ans += i;
    

  cout << ans;
  fprintf(fp, "%lld", ans);

  return 0;
}
