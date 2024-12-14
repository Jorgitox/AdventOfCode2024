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

map<pair<ll, ll>, ll> dp;

ll blink(ll valor, ll blinks){
  if(!blinks) 
    return 1;

  if(dp[{valor, blinks}])
    return dp[{valor, blinks}];

  if(!valor)
    return dp[{valor, blinks}] = blink(1, blinks - 1);
  
  string _valor = to_string(valor);
  if(SZ(_valor) & 1)
    return dp[{valor, blinks}] = blink(valor * 2024, blinks - 1);
  
  return dp[{valor, blinks}] = blink(stoll(_valor.substr(0, SZ(_valor) / 2)), blinks - 1) + blink(stoll(_valor.substr(SZ(_valor) / 2, SZ(_valor))), blinks - 1);
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

  ll ans = 0;

  FOR(i, 0, SZ(stones)){
    ans += blink(stones[i], 75);
  }

  cout << ans;

  return 0;
}
