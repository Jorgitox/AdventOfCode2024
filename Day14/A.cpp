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

ll w = 101, h = 103;

ll work(string & robot){
  regex position(R"(p=(\d+),(\d+))");
  regex velocity(R"(v=(-?\d+),(-?\d+))");
  
  smatch matchPos;
  regex_search(robot, matchPos, position);

  smatch matchVel;
  regex_search(robot, matchVel, velocity);

  ll ix = stoll(matchPos.str(1)), iy = stoll(matchPos.str(2));
  ll dx = stoll(matchVel.str(1)), dy = stoll(matchVel.str(2));
  ll fx = ix + dx * 100, fy = iy + dy * 100;
  
  while(fx < 0)
    fx += w;
  fx %= w;
  while(fy < 0)
    fy += h;
  fy %= h;

  if(fx < w / 2){
    if(fy < h / 2)
      return 0;
    
    if(fy > h / 2)
      return 1;
    
    return 4;
  }
  
  if(fx > w / 2){
    if(fy < h / 2)
      return 2;

    if(fy > h / 2)
      return 3;
    
    return 4;
  }
  
  return 4;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  ll quadrants[5] = {0, 0, 0, 0, 0};

  for(auto & robot : input){
    quadrants[work(robot)] ++;
  }

  ll ans = 1;
  FOR(i, 0, 4)
    ans *= quadrants[i];

  cout << ans;

  return 0;
}
