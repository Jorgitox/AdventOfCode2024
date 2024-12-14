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

void convert(string & report, vector<ll> & levels){
  ll aux = 0;
  for(char & c : report){
    if('0' <= c && c <= '9'){
      aux = (aux * 10) + (c - '0');
    } else{
      levels.pb(aux);
      aux = 0;
    }
  }

  if(aux) levels.pb(aux);
}

int increasing(vector<ll> levels){
  FOR(i, 1, SZ(levels))
    if(levels[i - 1] >= levels[i])
      return 0;

  return 1;
}

int decreasing(vector<ll> levels){
  FOR(i, 0, SZ(levels) - 1)
    if(levels[i + 1] >= levels[i])
      return 0;

  return 1;
}

int safe(vector<ll> & levels){
  FOR(i, 1, SZ(levels))
    if(abs(levels[i - 1] - levels[i]) < 1 || 3 < abs(levels[i - 1] - levels[i]))
      return 0;

  return increasing(levels) || decreasing(levels);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  string report;
  ll safeReports = 0;
  while(getline(cin, report)){
    vector<ll> levels;
    convert(report, levels);

    safeReports += safe(levels);
  }
  
  fprintf(fp, "%lld", safeReports);
  cout << safeReports;

  return 0;
}
