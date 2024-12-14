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

ll calculate(ll value, ll currentValue, vector<ll> & numbers, ll pos){
  // cout << "Pos: " << pos << " - CurrentValue: " << currentValue << endl;
  if(pos == SZ(numbers)) 
    return value == currentValue;

  if(calculate(value, currentValue + numbers[pos], numbers, pos + 1))
    return 1;
  
  if(calculate(value, currentValue * numbers[pos], numbers, pos + 1))
    return 1;
  
  return calculate(value, stoll(to_string(currentValue) + to_string(numbers[pos])), numbers, pos + 1);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FILE *fp = fopen("output.txt", "a");

  ll ans = 0;

  string equation;
  while(getline(cin, equation)){
    // cout << equation << endl;
    ll testValue = 0;

    int i = 0;
    for(; i < SZ(equation); i++){
      if(equation[i] == ':') 
        break;
      testValue = testValue * 10 + equation[i] - '0';
    }

    // cout << testValue << ": ";

    i += 2;

    vector<ll> numbers;

    ll currentNumber = 0;
    for(; i < SZ(equation); i++){
      if(equation[i] < '0' || equation[i] > '9') {
        numbers.pb(currentNumber);
        // cout << currentNumber << " ";
        currentNumber = 0;
        continue;
      }

      currentNumber = currentNumber * 10 + equation[i] - '0';
    }

    if(currentNumber)
      numbers.pb(currentNumber);
    
    // cout << endl;

    if(calculate(testValue, numbers[0], numbers, 1)){
      // cout << testValue << endl;
      ans += testValue;
    }
  }

  fprintf(fp, "%lld", ans);
  cout << ans;

  return 0;
}
