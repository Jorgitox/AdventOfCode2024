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

void order(map<ll, vector<ll>> & ptb, vector<ll> & ordering){
  map<ll, ll> appeared;
  
  for(int i = 0; i < SZ(ordering); i++){
    ll x = ordering[i];
    appeared[x] = i + 1;

    bool a = 0;
    for(ll y : ptb[x])
      if(appeared[y]){
        ll aux = x;
        ordering[i] = y;
        ordering[appeared[y] - 1] = aux;
        order(ptb, ordering);
        a = 1;
        break;
      }

    if(a) break;
  }
}

int correct(map<ll, vector<ll>> & ptb, vector<ll> & ordering){
  map<ll, ll> appeared;
  
  for(int i = 0; i < SZ(ordering); i++){
    ll x = ordering[i];
    appeared[x] = i + 1;

    for(ll y : ptb[x])
      if(appeared[y])
        return false;
  }

  return true;
}

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
    ll n = (SZ(pageOrdering) + 2) / 3;

    vector<ll> ordering;

    FOR(i, 0, n){
      ordering.pb(stoll(pageOrdering.substr(i * 3, i * 3 + 2)));
    }

    if(!correct(pageToBefores, ordering)){
      order(pageToBefores, ordering);

      ans += ordering[n / 2];
    }
  }

  while(cin >> pageOrdering){
    ll n = (SZ(pageOrdering) + 2) / 3;

    vector<ll> ordering;

    FOR(i, 0, n){
      ordering.pb(stoll(pageOrdering.substr(i * 3, i * 3 + 2)));
    }

    if(!correct(pageToBefores, ordering)){
      order(pageToBefores, ordering);

      ans += ordering[n / 2];
    }
  }
  

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
