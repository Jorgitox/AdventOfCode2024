#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

int main() {
  cin.tie(0)->sync_with_stdio(0);
  // std::ifstream myfile("C:/Users/USUARIO/OneDrive/c++programs/advent-of-code-2024/day9Base.txt");

  string r; getline(cin, r);

  // myfile.close();

  vector<ll> diskmap;
  map<ll, pair<ll, ll>> files;
  ll  id = 0;

  FOR(i, 0, SZ(r)) {
    ll size = r[i] - '0';
    if (i % 2 != 0) {
      FOR(j, 0, size) diskmap.pb(-1);
    } else {
      files[id] = {SZ(diskmap), size}; 
      cout << "id position: " << SZ(diskmap) << " size: " << size << ENDL;
      FOR(j, 0, size) diskmap.pb(id);
      id++;
    }
  }

  id -= 1;
  FOR(i, 0, SZ(diskmap)) {
    if (diskmap[i] == -1) {
      ll freeSpace = 0;
      FOR(j, i, SZ(diskmap)) {
        if (diskmap[j] == -1) freeSpace++;
        else break;
      }

      cout << "FREESPACE: " << freeSpace << " id: " << id << ENDL;
      //cout << (files[id].second < freeSpace ? "true" : "false") << ENDL;
      //cout << "files: " << files[id].second << ENDL;

      while (files[id].second > freeSpace && files[id].second != 0) {
        std::cout << "files: " << files[id].second << std::endl;
        if (id >= 0) id--;
        else break;
      }

      if (id == -1 || files[id].first < i) break;

      for(int j = 0, k = files[id].first; j < files[id].second; i++, j++, k++) {
        swap(diskmap[i], diskmap[k]);
        if (j == 0) files[id].first = i;
        
              FOR(k, 0, SZ(diskmap)) {
        cout << diskmap[k];
      } 
      }

      FOR(k, 0, SZ(diskmap)) {
        cout << diskmap[k] << " ";
      }
      cout << ENDL;
    }
  }


  ll checksum = 0;
  FOR(i, 0, SZ(diskmap)) {
    cout << diskmap[i] << " ";
    if (diskmap[i] == -1) 
      continue;
    
    checksum += (diskmap[i] * i);
  }

  cout << ENDL << checksum;
  return 0;
}