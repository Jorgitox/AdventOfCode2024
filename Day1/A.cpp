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

  vector<ll> leftList, rightList;

  string leftID, rightID;
  while(1){
    if(!(cin >> leftID)){
      break;
    }
    
    if(!(cin >> rightID)){
      break;
    }

    leftList.pb(stoll(leftID));
    rightList.pb(stoll(rightID));
  }

  sort(ALL(leftList));
  sort(ALL(rightList));

  ll totalDistance = 0;

  ll n = SZ(leftList);
  FOR(i, 0, n){
    // cout << leftList[i] << " " << rightList[i] << ENDL;
    totalDistance += abs(leftList[i] - rightList[i]);
  }
  
  fprintf(fp, "%lld", totalDistance);
  cout << totalDistance;

  return 0;
}
