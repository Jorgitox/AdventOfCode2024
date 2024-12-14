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

  // 2333133121414131402
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
  
  ll ans = 0;

  int j = SZ(fileSystem) - 1;

  for(int i = 0; i < SZ(fileSystem) && i <= j; i++){
    if(fileSystem[i] != -1){
      // cout << fileSystem[i] << " * " << i << ENDL;
      ans += fileSystem[i] * i;
      continue;
    }

    while(fileSystem[j] == -1)
      j--;

    if(j < i)
      break;
      
    // cout << fileSystem[j] << " * " << i << ENDL;
    ans += fileSystem[j] * i;
    j--;
  }

  cout << ans;

  return 0;
}
