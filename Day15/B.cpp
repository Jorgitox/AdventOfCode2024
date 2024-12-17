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

bool free(ll dir, ll x, ll y, vector<string> & warehouse){
  if(warehouse[x][y] == '#')
    return false;
  if(warehouse[x][y] == '.')
    return true;
  
  if(warehouse[x][y] == '['){
    return free(dir, x + dx[dir], y + dy[dir], warehouse) && free(dir, x + dx[dir], y + dy[dir] + 1, warehouse);
  }
  
  return free(dir, x + dx[dir], y + dy[dir], warehouse) && free(dir, x + dx[dir], y + dy[dir] - 1, warehouse);
}

void move(ll dir, ll x, ll y, vector<string> & warehouse){
  if(warehouse[x][y] == '.'){
    return;
  }

  if(warehouse[x][y] == '['){
    move(dir, x + dx[dir], y + dy[dir], warehouse);
    move(dir, x + dx[dir], y + dy[dir] + 1, warehouse);
    warehouse[x][y] = '.';
    warehouse[x][y + 1] = '.';
    warehouse[x + dx[dir]][y] = '[';
    warehouse[x + dx[dir]][y + 1] = ']';
  } else{
    move(dir, x + dx[dir], y + dy[dir], warehouse);
    move(dir, x + dx[dir], y + dy[dir] - 1, warehouse);
    warehouse[x][y] = '.';
    warehouse[x][y - 1] = '.';
    warehouse[x + dx[dir]][y - 1] = '[';
    warehouse[x + dx[dir]][y] = ']';
  }
}

bool possibleVertical(ll dir, ll x, ll y, vector<string> & warehouse){
  ll idx = x + dx[dir], idy = y + dy[dir];

  if(warehouse[idx][idy] == '.')
    return true;
  
  if(warehouse[idx][idy] == '#')
    return false;

  if(!free(dir, idx, idy, warehouse)){
    return false;
  }

  move(dir, idx, idy, warehouse);

  return true;
}

bool possibleHorizontal(ll dir, ll x, ll y, vector<string> & warehouse){
  ll idx = x + dx[dir], idy = y + dy[dir];
  
  if(warehouse[idx][idy] == '#')
    return false;
    
  if(warehouse[idx][idy] == '.')
    return true;

  char c = warehouse[idx][idy];

  while(warehouse[idx][idy] != '.' && warehouse[idx][idy] != '#'){
    idx += dx[dir];
    idy += dy[dir];
  }

  if(warehouse[idx][idy] == '#')
    return false;

  cout << c << " " << idy << '\n';
  
  ll z = 1;
  for(ll i = idy; i != y; i -= dy[dir]){
    if(z){
      warehouse[x][i] = (c == '[' ? ']' : '[');
    } else{
      warehouse[x][i] = c;
    }

    z = !z;
  }

  return true;
}

void move(ll x, ll y, string & movements, vector<string> & warehouse){
  for(char c : movements){
    switch (c){
    case '^':
      if(possibleVertical(0, x, y, warehouse)){
        warehouse[x][y] = '.';
        x --;
        warehouse[x][y] = '@';
      }
      break;
    case '>':
      if(possibleHorizontal(1, x, y, warehouse)){
        warehouse[x][y] = '.';
        y ++;
        warehouse[x][y] = '@';
      }
      break;
    case 'v':
      if(possibleVertical(2, x, y, warehouse)){
        warehouse[x][y] = '.';
        x ++;
        warehouse[x][y] = '@';
      }
      break;
    case '<':
      if(possibleHorizontal(3, x, y, warehouse)){
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

    string _line = "";
    for(char c : input[z]){
      switch(c){
      case '#':
        _line += "##";
        break;
      case 'O':
        _line += "[]";
        break;
      case '.':
        _line += "..";
        break;
      case '@':
        _line += "@.";
        break;
      }
    }

    warehouse.pb(_line);
  }

  z++;
  string movements = "";
  for(;z < SZ(input); z++)  
    movements += input[z];

  ll x, y;
  
  FOR(i, 0, SZ(warehouse)){
    FOR(j, 0, SZ(warehouse) * 2){
      if(warehouse[i][j] == '@'){
        x = i, y = j;
      }
    }
  }

  move(x, y, movements, warehouse);

  ll ans = 0;

  FOR(i, 0, SZ(warehouse)){
    FOR(j, 0, SZ(warehouse) * 2){
      if(warehouse[i][j] == '['){
        ans += i * 100 + j;
      }
    }
  }

  cout << ans;

  return 0;
}
