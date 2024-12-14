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

vector<ll> blink(vector<ll> & stones){
  vector<ll> newStones;
  
  for(auto & stone : stones){
    string _stone = to_string(stone);
    ll sz = SZ(_stone);
    
    if(stone == 0){
      newStones.pb(1);
    } else if(sz & 1){
      newStones.pb((stone) * 2024);
    } else{
      string firstHalf = _stone.substr(0, sz / 2);
      string secondHalf = _stone.substr(sz / 2, sz);

      newStones.pb(stoll(firstHalf));
      newStones.pb(stoll(secondHalf));
    }
  }

  return newStones;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  vector<ll> stones;
  ll currentStone = 0;

  for(char & c : line){
    if(c >= '0' && c <= '9')
      currentStone = currentStone * 10 + c - '0';
    else{
      stones.pb(currentStone);
      currentStone = 0;
    }
  }
  stones.pb(currentStone);

  FOR(i, 0, 25){
    stones = blink(stones);
  }

  cout << SZ(stones);

  return 0;
}
