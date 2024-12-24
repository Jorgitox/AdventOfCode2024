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

struct Gate{
  string a, op, b;
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  regex wire_regex(R"((.{3}): (\d))");
  regex gate_regex(R"((.{3}) ([^\s]+) (.{3}) -> (.{3}))");
  
  map<string, bool> wires;
  map<string, Gate> outputs;

  int i = 0;
  for(; SZ(input[i]) != 1; i++){
    smatch wire_smatch;
    regex_search(input[i], wire_smatch, wire_regex);

    wires[wire_smatch.str(1)] = (wire_smatch[2] == "1");
  }
  i++;
  for(; i < SZ(input); i++){
    smatch gate_smatch;
    regex_search(input[i], gate_smatch, gate_regex);

    string fill_color = "aqua";

    if(gate_smatch.str(2) == "AND"){
      fill_color = "fuchsia";
    } else if (gate_smatch.str(2) == "XOR"){
      fill_color = "crimson";
    }

    cout << "  " << i << " [label=\"" << gate_smatch.str(2) << "\"][style=filled][fillcolor=" << fill_color << "]\n";

    cout << "  {" << gate_smatch.str(1) << ", " << gate_smatch.str(3) << "} -> " << i << " -> " << gate_smatch.str(4) << ENDL;

    outputs[gate_smatch.str(4)] = {gate_smatch.str(1), gate_smatch.str(2), gate_smatch.str(3)};
  }

  while(!outputs.empty()){
    for(auto it = outputs.begin(); it != outputs.end(); it++){
      string wire1 = it -> second.a;
      string wire2 = it -> second.b; 
      if(wires.find(wire1) == wires.end() || wires.find(wire2) == wires.end()){
        continue;
      }

      if(it -> second.op == "AND"){
        wires[it -> first] = wires[wire1] && wires[wire2];
      } else if(it -> second.op == "XOR"){
        wires[it -> first] = wires[wire1] != wires[wire2];
      } else{
        wires[it -> first] = wires[wire1] || wires[wire2];
      }

      outputs.erase(it);
    }
  }

  ll x = 0, y = 0, z = 0;

  for(auto & [id, state] : wires){
    if(!state)
      continue;
    if(id[0] == 'x')
      x += (1ll << stoll(id.substr(1, 3)));
    else if(id[0] == 'y')
      y += (1ll << stoll(id.substr(1, 3)));
    else if(id[0] == 'z')
      z += (1ll << stoll(id.substr(1, 3)));
  }

  ll expected_z = x + y;

  FOR(i, 0, 48){
    if(((expected_z >> i) & 1) != ((z >> i) & 1)){
      cout << "Wrong at z: " << i << ENDL;
    }
  }

  
  return 0;
}
