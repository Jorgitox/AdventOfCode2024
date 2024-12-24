#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const ll dx[] = {-1, 0, 1, 0};
const ll dy[] = {0, 1, 0, -1};

map<queue<ll>, ll> mpAns;

void print_queue(queue<ll> q){
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
}

void final_magic_number(ll n, map<queue<ll>, ll> & mp){
  queue<ll> last_changes;

  FOR(i, 0, 2000){
    ll aux = n;
    n ^= n * 64;
    n %= 16777216;
    n ^= n / 32;
    n %= 16777216;
    n ^= n * 2048;
    n %= 16777216;
    
    last_changes.push(n % 10 - aux % 10);

    if(SZ(last_changes) == 4){
      if(mp.find(last_changes) == mp.end()){
        mp[last_changes] = (n % 10);
      }
      // print_queue(last_changes);
      // cout << (n % 10) << ENDL;
      last_changes.pop();
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  

  FOR(i, 0, SZ(input)){
    string fixed_input = input[i];
    if(i != SZ(input) - 1)
      fixed_input = input[i].substr(0, SZ(input[i]) - 1);

    map<queue<ll>, ll> mp;

    final_magic_number(stoll(fixed_input), mp);
    for(auto [sequence, bananas] : mp){
      mpAns[sequence] += bananas;
    }
  }

  ll max_bananas = 0;

  for(auto & [sequence, bananas] : mpAns){
    if(bananas < max_bananas)
      continue;
    cout << "Sequence: ";
    queue<ll> q = sequence;
    while(!q.empty()){
      cout << q.front() << " ";
      q.pop();
    }
    cout << "- " << bananas << ENDL;

    max_bananas = max(max_bananas, bananas);
  }

  queue<ll> q;
  q.push(-2); q.push(1); q.push(-1); q.push(3);

  cout << max_bananas;
  
  return 0;
}
