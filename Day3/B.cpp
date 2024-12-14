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

  char c;

  string baseMul = "mul(,)";
  int stateMul = 0;
  string baseDo = "do()";
  int stateDo = 0;
  string baseDont = "don't()";
  int stateDont = 0;

  bool enabled = 1;

  ll x = 0, y = 0;
  while(cin >> c){
    if(enabled){
      if(c == baseDont[stateDont]){
        stateDont ++;
        if(stateDont == 7){
          enabled = 0;
          stateDont = 0;
        }
      } else{
        stateDont = c == 'd';
      }
      if(stateMul < 4){
        if(c == baseMul[stateMul]){
          stateMul ++;
          continue;
        } else{
          x = 0, y = 0;
          stateMul = c == 'm';
        }
      } else if(stateMul == 4){
        if(((c < '0' || c > '9') && c != ',') || x >= 1000){
          x = 0, y = 0;
          stateMul = c == 'm';
          continue;
        }

        if(c == ',' ){
          stateMul++;
          continue;
        }

        x = x * 10 + c - '0';
      } else{
        if(((c < '0' || c > '9') && c != ')') || y >= 1000){
          x = 0, y = 0;
          stateMul = c == 'm';
          continue;
        }

        if(c == ')' ){
          stateMul = 0;
          // cout << x << " * " << y << " = " << x * y << ENDL;
          ans += x * y;
          x = 0, y = 0;
          continue;
        }

        y = y * 10 + c - '0';
      }
    } else{
      if(c == baseDo[stateDo]){
        stateDo ++;
        if(stateDo == 4){
          enabled = 1;
          stateDo = 0;
        }
      } else{
        stateDo = c == 'd';
      }
    }
  }

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
