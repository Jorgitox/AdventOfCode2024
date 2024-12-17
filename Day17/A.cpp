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

ll combOperand(ll op, ll A, ll B, ll C){
  switch(op){
    case 0:
      return 0;
      break;
    case 1:
      return 1;
      break;
    case 2:
      return 2;
      break;
    case 3:
      return 3;
      break;
    case 4:
      return A;
      break;
    case 5:
      return B;
      break;
    case 6:
      return C;
      break;
    default:
      break;
  }

  return -1;
}

void work(string & a, string & b, string & c, string & p){
  ll A, B, C; 
  regex number (R"((\d+))");

  smatch sa, sb, sc;
  regex_search(a, sa, number);
  regex_search(b, sb, number);
  regex_search(c, sc, number);

  A = stoll(sa.str(1));
  B = stoll(sa.str(1));
  C = stoll(sa.str(1));

  vll program;

  for(sregex_iterator it = sregex_iterator(ALL(p), number); it != sregex_iterator(); it++){
    ll opcode = stoll(it -> str(1));

    it++;
    if(it == sregex_iterator())
      break;
    
    ll operand = stoll(it -> str(1));

    program.pb(opcode);
    program.pb(operand);
  }

  for(int i = 0; i < SZ(program); i += 2){
    switch (program[i]){
    case 0:
      A = A / (1 << combOperand(program[i + 1], A, B, C));
      break;
    case 1:
      B = B ^ program[i + 1];
      break;
    case 2:
      B = combOperand(program[i + 1], A, B, C) % 8;
      break;
    case 3:
      if(A){
        i = program[i + 1] - 2;
      }
      break;
    case 4:
      B = B ^ C;
      break;
    case 5:
      cout << combOperand(program[i + 1], A, B, C) % 8 << ",";
      break;
    case 6:
      B = A / (1 << combOperand(program[i + 1], A, B, C));
      break;
    case 7:
      C = A / (1 << combOperand(program[i + 1], A, B, C));
      break;
    
    default:
      break;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  work(input[0], input[1], input[2], input[4]);

  return 0;
}
