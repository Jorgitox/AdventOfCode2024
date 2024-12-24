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
  
  map<string, bool> wires;

  int i = 0;
  for(; i < SZ(input); i++){
    if(SZ(input[i]) < 2){
      break;
    }

    string wire = input[i].substr(0, 3);
    
    bool state = input[i][5] == '1';

    wires[wire] = state;
  }

  i++;

  map<string, pair<string, pair<string, string>>> outputs;

  for(; i < SZ(input); i++){
    string wire1 = "";
    int j = 0;
    for(; j < SZ(input[i]); j++){
      if(!isdigit(input[i][j]) && !isalpha(input[i][j])){
        break;
      }

      wire1.pb(input[i][j]);
    }
    j++;
    string operation = "";
    for(; j < SZ(input[i]); j++){
      if(!isdigit(input[i][j]) && !isalpha(input[i][j])){
        break;
      }

      operation.pb(input[i][j]);
    }
    j++;
    string wire2 = "";
    for(; j < SZ(input[i]); j++){
      if(!isdigit(input[i][j]) && !isalpha(input[i][j])){
        break;
      }

      wire2.pb(input[i][j]);
    }
    j += 4;
    string wire3 = "";
    for(; j < SZ(input[i]); j++){
      if(!isdigit(input[i][j]) && !isalpha(input[i][j])){
        break;
      }

      wire3.pb(input[i][j]);
    }
    
    outputs[wire3] = {operation, {wire1, {wire2}}};
  }

  while(!outputs.empty()){
    for(auto it = outputs.begin(); it != outputs.end(); it++){
      string wire1 = it -> second.second.first;
      string wire2 = it -> second.second.second; 
      if(wires.find(wire1) == wires.end() || wires.find(wire2) == wires.end()){
        continue;
      }

      if(it -> second.first == "AND"){
        wires[it -> first] = wires[wire1] && wires[wire2];
      } else if(it -> second.first == "XOR"){
        wires[it -> first] = wires[wire1] != wires[wire2];
      } else{
        wires[it -> first] = wires[wire1] || wires[wire2];
      }

      outputs.erase(it);
    }
  }

  ll ans = 0;

  for(auto it = wires.find("z00"); it != wires.end(); it++){
    if(it -> second){
      ll id = stoll(it -> first.substr(1, 3));
      ans += (1ll << id);
    }
  }

  cout << ans;
  
  return 0;
}
