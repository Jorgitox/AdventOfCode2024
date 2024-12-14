#include <bits/stdc++.h>
#include <regex>
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

ll minTokens(ll x, ll y, ll dxA, ll dyA, ll dxB, ll dyB, ll xG, ll yG, ll A, ll B, map<pair<ll, ll>, ll> & dp){
  if(x == xG && y == yG)
    return 0;

  if(x > xG || y > yG || A > 100 || B > 100)
    return (ll) 1e18;

  if(dp[{x, y}])
    return dp[{x, y}];
  
  return dp[{x, y}] = min(3 + minTokens(x + dxA, y + dyA, dxA, dyA, dxB, dyB, xG, yG, A + 1, B, dp), 1 + minTokens(x + dxB, y + dyB, dxA, dyA, dxB, dyB, xG, yG, A, B + 1, dp));
}

ll parse(string moveA, string moveB, string prize){
  regex xMoveRegex(R"(X\+(\d+))");
  regex yMoveRegex(R"(Y\+(\d+))");

  smatch xSmatchA = *sregex_iterator(ALL(moveA), xMoveRegex);
  smatch ySmatchA = *sregex_iterator(ALL(moveA), yMoveRegex);
  ll dxA = stoll(xSmatchA.str(1)), dyA = stoll(ySmatchA.str(1));

  smatch xSmatchB = *sregex_iterator(ALL(moveB), xMoveRegex);
  smatch ySmatchB = *sregex_iterator(ALL(moveB), yMoveRegex);
  ll dxB = stoll(xSmatchB.str(1)), dyB = stoll(ySmatchB.str(1));

  regex xGoalRegex(R"(X=(\d+))");
  regex yGoalRegex(R"(Y=(\d+))");

  smatch xSmatchG = *sregex_iterator(ALL(prize), xGoalRegex);
  smatch ySmatchG = *sregex_iterator(ALL(prize), yGoalRegex);
  ll xG = stoll(xSmatchG.str(1)), yG = stoll(ySmatchG.str(1));

  map<pair<ll, ll>, ll> dp;

  ll mT =  minTokens(0, 0, dxA, dyA, dxB, dyB, xG, yG, 0, 0, dp);

  if(mT >= (ll) 1e18)
    return 0;
  
  return mT;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  ll ans = 0;
  FOR(i, 0, (SZ(input) + 1) / 4){
    ans += parse(input[i * 4], input[i * 4 + 1], input[i * 4 + 2]);
  }

  cout << ans;

  return 0;
}
