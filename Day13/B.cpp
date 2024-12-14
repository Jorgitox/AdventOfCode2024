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

ll minTokens(ll dxA, ll dyA, ll dxB, ll dyB, ll xG, ll yG){
  ll A = 0, B = 0;
  // eq1: a * A + b * B = c
  // eq2: d * A + e * B = f
  ll a, b, c;
  ll d, e, f;
  // eq1: dxA * A + dxB * B = xG
  // eq2: dyA * A + dyB * B = yG
  a = dxA, b = dxB, c = xG;
  d = dyA, e = dyB, f = yG;

  // eq1: dyA * dxA * A + dyA * dxB * B = dyA * xG
  // eq2: dxA * dyA * A + dxA * dyB * B = dxA * yG
  a *= dyA, b *= dyA, c *= dyA;
  d *= dxA, e *= dxA, f *= dxA;

  // eq: (dyA * dxB - dxA * dyB) * B = (dyA * xG - dxA * yG)
  // eq: (b - e) * B = (c - f)
  // eq: g * B = h;
  ll g = b - e, h = c - f;

  // B = h / g
  if(g == 0)
    return 0;
  if(h % g)
    return 0;

  B = h / g;

  if(B < 0)
    return 0;

  // A = (xG dxB * B) / dxA
  if((xG - dxB * B) % dxA)
    return 0;

  A = (xG - dxB * B) / dxA;

  if(A < 0)
    return 0;

  return A * 3 + B;
}

ll parse(string moveA, string moveB, string prize){
  regex xMoveRegex(R"(X\+(\d+))");
  regex yMoveRegex(R"(Y\+(\d+))");

  smatch xSmatchA, ySmatchA;
  regex_search(moveA, xSmatchA, xMoveRegex);
  regex_search(moveA, ySmatchA, yMoveRegex);
  ll dxA = stoll(xSmatchA.str(1)), dyA = stoll(ySmatchA.str(1));

  smatch xSmatchB, ySmatchB;
  regex_search(moveB, xSmatchB, xMoveRegex);
  regex_search(moveB, ySmatchB, yMoveRegex);
  ll dxB = stoll(xSmatchB.str(1)), dyB = stoll(ySmatchB.str(1));

  regex xGoalRegex(R"(X=(\d+))");
  regex yGoalRegex(R"(Y=(\d+))");

  smatch xSmatchG, ySmatchG;
  regex_search(prize, xSmatchG, xGoalRegex);
  regex_search(prize, ySmatchG, yGoalRegex);
  ll xG = stoll(xSmatchG.str(1)), yG = stoll(ySmatchG.str(1));
  
  return minTokens(dxA, dyA, dxB, dyB, xG + 10000000000000, yG + 10000000000000);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  ll ans = 0;
  FOR(i, 0, (SZ(input) + 1) / 4)
    ans += parse(input[i * 4], input[i * 4 + 1], input[i * 4 + 2]);

  cout << ans;

  return 0;
}
