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

  ll cnt = 0;

  ll x = 0, y = 0;
  while(cin >> c){
    // cout << c << " -> " << stateMul << ENDL;
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
        cnt ++;
        continue;
      }

      y = y * 10 + c - '0';

    }
  }

  fprintf(fp, "%lld", ans);
  cout << ans;
  cout << "\n" << cnt;

  return 0;
}
