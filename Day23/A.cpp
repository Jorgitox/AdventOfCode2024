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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  

  map<string, vector<string>> adj;

  FOR(i, 0, SZ(input)){
    string u = "", v = "";
    bool a = 0;
    FOR(j, 0, SZ(input[i])){
      if(input[i][j] >= 'a' && input[i][j] <= 'z'){
        if(a){
          v.pb(input[i][j]);
        } else{
          u.pb(input[i][j]);
        }
      } else{
        a = 1;
      }
    }
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(auto & [computer, connections] : adj){
    sort(ALL(connections));
  }

  set<vector<string>> st;

  for(auto & [computer, connections] : adj){
    FOR(i, 0, SZ(connections)){
      FOR(j, i + 1, SZ(connections)){
        // cout << computer << " - " << connections[i] << " - " << connections[j] << ENDL;
        if(binary_search(ALL(adj[connections[i]]), connections[j])){
          vector<string> trio = {computer, connections[i], connections[j]};
          sort(ALL(trio));
          st.insert(trio);
        } 
      }
    }
  }

  ll ans = 0;

  for(auto & trio : st){
    // cout << trio[0] << " - " << trio[1] << " - " << trio[2] << ENDL;
    if(trio[0][0] == 't' || trio[1][0] == 't' || trio[2][0] == 't')
      ans++;
  }

  cout << SZ(adj) << ENDL;

  cout << ans;
  
  return 0;
}
