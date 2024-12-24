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

void bronKerbosch(set<string>&& R , set<string>&& P, set<string>&& X, map<string, map<string, bool>> & graph, vector<set<string>>& cliques){
  if (P.empty() && X.empty()) {
    cliques.pb(R);
    return;
  }

  while (!P.empty()) {
    string v = *P.begin();
    set<string> newR = R;
    newR.insert(v);
    set<string> newP;
    for (string p : P) {
      if (graph[v][p]) {
        newP.insert(p);
      }
    }
    set<string> newX;
    for (string x : X) {
      if (graph[v][x]) {
        newX.insert(x);
      }
    }
    bronKerbosch(move(newR), move(newP), move(newX), graph, cliques);
    P.erase(v);
    X.insert(v);
  }
}   

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  

  map<string, map<string, bool>> adj;

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
    adj[u][v] = true;
    adj[v][u] = true;
  }

  set<string> vertices;
  for(auto & [computer, connections] : adj){
    vertices.insert(computer);
  }

  vector<set<string>> allCliques;
  bronKerbosch({}, move(vertices), {}, adj, allCliques);

  set<string> maxClique;
  for(auto & clique : allCliques){
    if(SZ(clique) > SZ(maxClique)){
      maxClique = clique;
    }
  }

  for(auto & computer : maxClique){
    cout << computer << ",";
  }
  
  return 0;
}
