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

ll findXMAS(vector<string> & wordSearch, int i, int j){
  if(i == 0 || j == 0) return 0;
  if(i == SZ(wordSearch) - 1 || j == SZ(wordSearch[0]) - 1) return 0;

  return wordSearch[i][j] == 'A' && ((wordSearch[i - 1][j - 1] == 'M' && wordSearch[i + 1][j + 1] == 'S') || (wordSearch[i - 1][j - 1] == 'S' && wordSearch[i + 1][j + 1] == 'M')) && ((wordSearch[i + 1][j - 1] == 'M' && wordSearch[i - 1][j + 1] == 'S') || (wordSearch[i + 1][j - 1] == 'S' && wordSearch[i - 1][j + 1] == 'M'));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  vector<string> wordSearch;

  string line;
  while(getline(cin, line))
    wordSearch.pb(line);

  ll ans = 0;

  FOR(i, 0, SZ(wordSearch)){
    FOR(j, 0, SZ(wordSearch[i])){
      if(wordSearch[i][j] == 'A'){
        ans += findXMAS(wordSearch, i, j);
      }
    }
  }

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
