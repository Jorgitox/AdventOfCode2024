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

  string disk;
  getline(cin, disk); 

  vector<ll> fileSystem;
  int isFree = 0;
  ll id = 0;
  FOR(i, 0, SZ(disk)){
    if(isFree)
      FOR(j, 0, disk[i] - '0')
        fileSystem.pb(-1);
    else
      FOR(j, 0, disk[i] - '0')
        fileSystem.pb(id);

    if(isFree)
      id++;
    
    isFree = !isFree;
  }

  for(ll j = SZ(fileSystem) - 1; j >= 0; j--){
    if(fileSystem[j] == -1)
      continue;

    ll dj = j;
    
    while(dj >= 0 && fileSystem[dj] == fileSystem[j])
      dj--;

    ll szj = j - dj;

    for(ll i = 0; i < j; i++){
      if(fileSystem[i] != -1)
        continue;
      
      ll di = i;

      while(di < j && fileSystem[di] == -1)
        di++;
      
      ll szi = di - i;

      if(szi < szj){
        i = di;
        continue;
      }

      for(ll k = 0; k < szj; k++)
        swap(fileSystem[i + k], fileSystem[j - k]);
    }

    j = dj + 1;
  }

  ll ans = 0;

  FOR(i, 0, SZ(fileSystem)){
    if(fileSystem[i] == -1)
      continue;
    
    ans += fileSystem[i] * i;
  }

  cout << ans;

  return 0;
}
