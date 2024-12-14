#include <bits/stdc++.h>
#include <regex>
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

  regex mulRegex(R"(mul\((\d{1,3}),(\d{1,3})\))");
  regex doRegex(R"(do\(\))");
  regex dontRegex(R"(don't\(\))");

  ll ans = 0;

  string memory;

  bool isEnabled = 1;

  while(cin >> memory){
    queue<smatch> mulPositions;
    queue<smatch> doPositions;
    queue<smatch> dontPositions;
    
    for(sregex_iterator it = sregex_iterator(ALL(memory), mulRegex); it != sregex_iterator(); it++)
      mulPositions.push(*it);

    for(sregex_iterator it = sregex_iterator(ALL(memory), doRegex); it != sregex_iterator(); it++)
      doPositions.push(*it);

    for(sregex_iterator it = sregex_iterator(ALL(memory), dontRegex); it != sregex_iterator(); it++)
      dontPositions.push(*it);
    
    ll lastDo = -1, lastDont = -1;
    while(!mulPositions.empty()){
      smatch match = mulPositions.front();
      mulPositions.pop();

      while(!doPositions.empty() && doPositions.front().position(0) < match.position(0)){
        lastDo = doPositions.front().position(0);
        doPositions.pop();
      }
      
      while(!dontPositions.empty() && dontPositions.front().position(0) < match.position(0)){
        lastDont = dontPositions.front().position(0);
        dontPositions.pop();
      }

      if(lastDo < lastDont) isEnabled = 0;
      if(lastDo > lastDont) isEnabled = 1;

      if(isEnabled){
        ans += stoll(match.str(1)) * stoll(match.str(2));
      }
    }

    while(!doPositions.empty()){
      lastDo = doPositions.front().position(0);
      doPositions.pop();
    }
      
    while(!dontPositions.empty()){
      lastDont = dontPositions.front().position(0);
      dontPositions.pop();
    }

    if(lastDo < lastDont) isEnabled = 0;
    if(lastDo > lastDont) isEnabled = 1;
  }

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
