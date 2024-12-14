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
  ll cnt = 0;

  if(j < SZ(wordSearch[0]) - 3) 
    cnt += (wordSearch[i][j] == 'X' && wordSearch[i][j + 1] == 'M' && wordSearch[i][j + 2] == 'A' && wordSearch[i][j + 3] == 'S'); // E
  
  if(j > 2) 
    cnt += (wordSearch[i][j] == 'X' && wordSearch[i][j - 1] == 'M' && wordSearch[i][j - 2] == 'A' && wordSearch[i][j - 3] == 'S'); // W
  
  if(i < SZ(wordSearch) - 3) 
    cnt += (wordSearch[i][j] == 'X' && wordSearch[i + 1][j] == 'M' && wordSearch[i + 2][j] == 'A' && wordSearch[i + 3][j] == 'S'); // S
  
  if(i > 2) 
    cnt += (wordSearch[i][j] == 'X' && wordSearch[i - 1][j] == 'M' && wordSearch[i - 2][j] == 'A' && wordSearch[i - 3][j] == 'S'); // N
  
  if(j > 2){ // W
    if(i > 2) // N
      cnt += (wordSearch[i][j] == 'X' && wordSearch[i - 1][j - 1] == 'M' && wordSearch[i - 2][j - 2] == 'A' && wordSearch[i - 3][j - 3] == 'S');

    if(i < SZ(wordSearch) - 3) // S
      cnt += (wordSearch[i][j] == 'X' && wordSearch[i + 1][j - 1] == 'M' && wordSearch[i + 2][j - 2] == 'A' && wordSearch[i + 3][j - 3] == 'S');
  }

  
  if(j < SZ(wordSearch[0]) - 3){ // E
    if(i > 2) // N
      cnt += (wordSearch[i][j] == 'X' && wordSearch[i - 1][j + 1] == 'M' && wordSearch[i - 2][j + 2] == 'A' && wordSearch[i - 3][j + 3] == 'S');

    if(i < SZ(wordSearch) - 3) // S
      cnt += (wordSearch[i][j] == 'X' && wordSearch[i + 1][j + 1] == 'M' && wordSearch[i + 2][j + 2] == 'A' && wordSearch[i + 3][j + 3] == 'S');
  }

  return cnt;
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
      if(wordSearch[i][j] == 'X'){
        ans += findXMAS(wordSearch, i, j);
      }
    }
  }

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
