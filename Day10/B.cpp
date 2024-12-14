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

vi di = {1, -1, 0 , 0}, dj = {0, 0, 1, -1};

ll trail(int i, int j, int cur, vector<string> & input, vector<vi> & visited){
  if(i < 0 || i >= SZ(input)) return 0;
  if(j < 0 || j >= SZ(input)) return 0;
  if(input[i][j] - '0' != cur) return 0;
  
  if(visited[i][j])
    return visited[i][j];

  if(cur == 9)
    return visited[i][j] = 1;  

  ll ans = 0;
  FOR(k, 0, 4){
    ans += trail(i + di[k], j + dj[k], cur + 1, input, visited);
  }

  return visited[i][j] = ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  ll ans = 0;

  vector<vi> visited(SZ(input), vi(SZ(input)));
  
  FOR(i, 0, SZ(input))
    FOR(j, 0, SZ(input))
      if(input[i][j] == '0'){
        ans += trail(i, j, 0, input, visited);
      }

  cout << ans;

  return 0;
}
