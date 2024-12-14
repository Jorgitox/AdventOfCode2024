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
vector<vector<ll>> mp(w, vector<ll>(h, 0));

struct Robot{
  ll x, y, dx, dy;
};

vector<Robot> work(vector<string> & input){
  vector<Robot> robots;

  regex position(R"(p=(\d+),(\d+))");
  regex velocity(R"(v=(-?\d+),(-?\d+))");
  
  for(auto & robot : input){
    smatch matchPos;
    regex_search(robot, matchPos, position);

    smatch matchVel;
    regex_search(robot, matchVel, velocity);

    ll ix = stoll(matchPos.str(1)), iy = stoll(matchPos.str(2));
    ll dx = stoll(matchVel.str(1)), dy = stoll(matchVel.str(2));

    mp[ix][iy] ++;
    robots.pb({ix, iy, dx, dy});
  }

  return robots;
}

void easterEgg(FILE *fp){
  FOR(i, 0, w){
    FOR(j, 0, h)
      if(mp[i][j])
        fprintf(fp, "█");
      else
        fprintf(fp, " ");

    fprintf(fp, "\n");
  }
}

void move(vector<Robot> & robots){
  for(auto & robot : robots){
    mp[robot.x][robot.y] --;
    robot.x = (robot.x + robot.dx + w) % w;
    robot.y = (robot.y + robot.dy + h) % h;
    mp[robot.x][robot.y] ++;
  }
}

signed main() { 
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  vector<string> input;

  string line;
  while(getline(cin, line))
    input.pb(line);  
  
  vector<Robot> robots = work(input);

  for(ll i = 0; i <= h * w; i++){
    fprintf(fp, "After %lld seconds: \n", i);
    easterEgg(fp);
    
    FOR(i, 0, 50)
      fprintf(fp, "\n");

    move(robots);
  }

  return 0;
}
