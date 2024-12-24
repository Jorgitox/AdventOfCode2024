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
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};

int numerical_ID(char c){
  if(c == 'A')
    return 10;

  return c - '0';
}

int directional_ID(char c){
  switch (c){
  case '^':
    return 0;
  case 'A':
    return 1;
  case '<':
    return 2;
  case 'v':
    return 3;
  case '>':
    return 4;
  default:
    return -1;
  }
}

string numerical_moveset[11][11] = {
  {"A","^<A","^A",">^A","^^<A","^^A",">^^A","^^^<A","^^^A",">^^^A",">A"}, // from 0
  {">v","A",">A",">>A","^A",">^A",">>^A","^^A",">^^A",">>^^A",">>vA"}, // from 1
  {"vA","<A","A",">A","<^A","^A",">^A","<^^A","^^A",">^^A","v>A"}, // from 2
  {"<vA","<<A","<A","A","<<^A","<^A","^A","<<^^A","<^^A","^^A","vA"}, // from 3
  {">vvA","vA","v>A","v>A","A",">A",">>A","^A",">^A",">>^A",">>vvA"}, // from 4
  {"vvA","<vA","vA","v>A","<A","A",">A","<^A","^A",">^A","vv>A"}, // from 5
  {"<vvA","<<vA","<vA","vA","<<A","<A","A","<<^A","<^A","^A","vvA"}, // from 6
  {">vvvA","vvA","vv>A","vv>>A","vA","v>A","v>>A","A",">A",">>A",">>vvvA"}, // from 7
  {"vvvA","<vvA","vvA","vv>A","<vA","vA","v>A","<A","A",">A","vvv>A"}, // from 8
  {"<vvvA","<<vvA","<vvA","vvA","<<vA","<vA","vA","<<A","<A","A","vvvA"}, // from 9
  {"<A","^<<A","<^A","^A","^^<<A","<^^A","^^A","^^^<<A","<^^^A","^^^A","A"}  // from A
};

string directional_moveset[5][5] = {
  {"A", ">A", "v<A", "vA", "v>A"}, // from ^  
  {"<A", "A", "v<<A", "<vA", "vA"}, // from A
  {">^A", ">>^A", "A", ">A", ">>A"}, // from <
  {"^A", ">^A", "<A", "A", ">A"}, // from v
  {"<^A", "^A", "<<A", "<A", "A"}, // from >
};

auto get_length_recursive(string str, int depth, vector<map<string, ll>> & dp){
  if(depth == 0)
    return SZ(str);
  
  auto it = dp[depth].find(str);
  if(it != dp[depth].end()){
    return (it -> second);
  }

  string new_code = "";
  char last_char = 'A';

  for(auto & c : str){
    new_code += directional_moveset[directional_ID(last_char)][directional_ID(c)];
    last_char = c;
  }

  ll len = get_length_recursive(new_code, depth - 1, dp);

  return dp[depth][str] = len;
}

auto complexity(string & code, int depth){
  vector<map<string, ll>> dp(depth + 1);

  string new_code = "";
  char last_char = 'A';

  for(auto & c : code){
    new_code += numerical_moveset[numerical_ID(last_char)][numerical_ID(c)];
    last_char = c;
  }

  auto len = get_length_recursive(new_code, depth, dp);

  cout << code << ": " << len << ENDL;

  return len * stoll(code.substr(0, 3));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line.substr(0, 4));

  auto ans = 0;

  for(auto & code : input){
    ans += complexity(code, 2);
  }

  cout << ans;
  
  return 0;
}
