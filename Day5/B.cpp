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

void topologicalSortUtil(ll v, vector<vector<ll> >& adj, vector<bool>& visited, stack<ll>& Stack) {
    visited[v] = true;

    for (ll i : adj[v]) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    Stack.push(v);
}

void topologicalSort(vector<vector<ll> >& adj, ll V, vector<ll> & ord) {
    stack<ll> Stack; 
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, Stack);
    }

    while (!Stack.empty()) {
        ord.pb(Stack.top());
        Stack.pop();
    }
}


void order(map<ll, vector<ll>> & ptb, vector<ll> & ordering){
  map<ll, ll> appeared;

  vector<vector<ll>> adjList(SZ(ordering));
  
  for(int i = 0; i < SZ(ordering); i++){
    ll x = ordering[i];
    
    for(int j = 0; j < SZ(ordering); j++){
      ll y = ordering[j];

      if(find(ALL(ptb[x]), y) != ptb[x].end()){
        adjList[i].pb(j);
      }
    }
  }

  vector<ll> ord;
  topologicalSort(adjList, SZ(ordering), ord);

  FOR(i, 0, SZ(ord)){
    ord[i] = ordering[ord[i]];
  }

  FOR(i, 0, SZ(ord)){
    ordering[i] = ord[i];
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
