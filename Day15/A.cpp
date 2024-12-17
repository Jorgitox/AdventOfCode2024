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

bool possible(ll dir, ll x, ll y, vector<string> & warehouse){
  ll idx = x + dx[dir], idy = y + dy[dir];

  if(warehouse[idx][idy] == '.')
    return true;

  while(warehouse[idx][idy] != '.' && warehouse[idx][idy] != '#'){
    idx += dx[dir];
    idy += dy[dir];
  }

  if(warehouse[idx][idy] == '#')
    return false;

  warehouse[idx][idy] = 'O';
  return true;
}

void move(ll x, ll y, string & movements, vector<string> & warehouse){
  for(char c : movements){
    switch (c){
    case '^':
      if(possible(0, x, y, warehouse)){
        warehouse[x][y] = '.';
        x --;
        warehouse[x][y] = '@';
      }
      break;
    case '>':
      if(possible(1, x, y, warehouse)){
        warehouse[x][y] = '.';
        y ++;
        warehouse[x][y] = '@';
      }
      break;
    case 'v':
      if(possible(2, x, y, warehouse)){
        warehouse[x][y] = '.';
        x ++;
        warehouse[x][y] = '@';
      }
      break;
    case '<':
      if(possible(3, x, y, warehouse)){
        warehouse[x][y] = '.';
        y --;
        warehouse[x][y] = '@';
      }
      break;
    default:
      break;
    }
  }

}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  vector<string> warehouse;

  ll z = 0;
  for(; z < SZ(input); z++){
    if(SZ(input[z]) < 3)
      break;

    warehouse.pb(input[z]);
  }

  z++;
  string movements = "";
  for(;z < SZ(input); z++)  
    movements += input[z];

  ll x, y;
  
  FOR(i, 0, SZ(warehouse)){
    FOR(j, 0, SZ(warehouse)){
      if(warehouse[i][j] == '@'){
        x = i, y = j;
      }
    }
  }

  move(x, y, movements, warehouse);

  ll ans = 0;

  FOR(i, 0, SZ(warehouse)){
    FOR(j, 0, SZ(warehouse)){
      // cout << warehouse[i][j];
      if(warehouse[i][j] == 'O'){
        ans += i * 100 + j;
      }
    }
    // cout << ENDL;
  }

  cout << ans;

  return 0;
}
