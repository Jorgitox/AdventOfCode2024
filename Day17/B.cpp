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

  queue<pll> q;
  FOR(i, 0, 8){
    q.push({0, i});
  }

  while(!q.empty()){
    auto [i, n] = q.front();
    q.pop();
    
    ll o = ( ( n % 8 ) ^ 5 ^ ( n / ( 1ll << ( ( n % 8 ) ^ 2) ) ) ) % 8;

    cout << "i: " << i << " - n: " << n << " - o: " << o << ENDL;

    if(program[SZ(program) - 1 - i] != o)
      continue;

    if(i == SZ(program) - 1){
      cout << n;
      return;
    }

    FOR(j, 0, 8){
      q.push({i + 1, n * 8 + j});
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