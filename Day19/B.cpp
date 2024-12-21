#include <bits/stdc++.h>
#include <regex>
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

ll isPossible(string pattern, map<string, bool> & available, map<string, ll> & dp){
  if(SZ(pattern) == 0)
    return 1;

  if(dp[pattern])
    return dp[pattern];

  ll ans = 0;
  ROF(i, SZ(pattern), 0){
    if(available[pattern.substr(i, SZ(pattern))])
      ans += isPossible(pattern.substr(0, i), available, dp);
  }

  return dp[pattern] = ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line)){
    string addedLine = "";

    FOR(i, 0, SZ(line)){
      if(line[i] == ',' || (line[i] >= 'a' && line[i] <= 'z')){
        addedLine += line[i];
      }
    }

    input.pb(addedLine);
  }
  
  map<string, bool> available;
  string aux = "";
  FOR(i, 0, SZ(input[0])){
    if(input[0][i] == ','){
      available[aux] = true;
      aux = "";
      continue;
    }

    if(input[0][i] >= 'a' && input[0][i] <= 'z'){
      aux.pb(input[0][i]);
    }
  }
  available[aux] = true;

  ll ans = 0;

  map<string, ll> dp;

  FOR(i, 2, SZ(input)){
    ans += isPossible(input[i], available, dp);
  }

  cout << ans;
  
  return 0;
}
