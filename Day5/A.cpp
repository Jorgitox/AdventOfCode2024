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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  ll ans = 0;

  map<ll, vector<ll>> pageToBefores;

  string rule;
  while(cin >> rule){
    if(SZ(rule) > 5) break;

    ll x = stoll(rule.substr(0, 2));
    ll y = stoll(rule.substr(3, 5));

    pageToBefores[x].pb(y);
  }

  // firstIteration with rule

  string pageOrdering = rule;
  {
    map<ll, ll> appeared;
    ll n = (SZ(pageOrdering) + 2) / 3;

    ll x = stoll(pageOrdering.substr(0, 2));
    appeared[x] = 1;

    ll a = 1;

    FOR(i, 1, n){
      x = stoll(pageOrdering.substr(i * 3, i * 3 + 2));

      appeared[x] = 1;

      for(ll y : pageToBefores[x]){
        if(appeared[y]){
          a = 0;
          break;
        }
      }
    }

    if(a) ans += stoll(pageOrdering.substr(n / 2 * 3, n / 2 * 3 + 2));
  }

  while(cin >> pageOrdering){
    map<ll, ll> appeared;
    ll n = (SZ(pageOrdering) + 2) / 3;

    ll x = stoll(pageOrdering.substr(0, 2));
    appeared[x] = 1;

    ll a = 1;

    FOR(i, 1, n){
      x = stoll(pageOrdering.substr(i * 3, i * 3 + 2));

      appeared[x] = 1;

      for(ll y : pageToBefores[x]){
        if(appeared[y]){
          a = 0;
          break;
        }
      }
    }

    if(a) ans += stoll(pageOrdering.substr(n / 2 * 3, n / 2 * 3 + 2));
  }
  

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
