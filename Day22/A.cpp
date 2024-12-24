#include <bits/stdc++.h>
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

ll final_magic_number(ll n){
  FOR(i, 0, 2000){
    n ^= n * 64;
    n %= 16777216;
    n ^= n / 32;
    n %= 16777216;
    n ^= n * 2048;
    n %= 16777216;
  }

  return n;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  ll ans = 0;

  FOR(i, 0, SZ(input)){
    string fixed_input = input[i];
    if(i != SZ(input) - 1)
      fixed_input = input[i].substr(0, SZ(input[i]) - 1);

    ll result = final_magic_number(stoll(fixed_input));

    cout << result << ENDL;

    ans += result;
  }

  cout << ans;
  
  return 0;
}
