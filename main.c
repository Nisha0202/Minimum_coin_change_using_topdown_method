#include <math.h>
#include <stdio.h>
int INT_MAX = 10000;

int minCoins(int num, int size, int coins[], int dp[] ) {

  // base
  if (num == 0)
    return 0;
  dp[0] = 0;
  int ans = INT_MAX;

  // loop
  for (int i = 0; i < size; i++) {
    int subAns;
    if (num- coins[i] >= 0) {
      if( dp[num-coins[i]] != -1){
        subAns = dp[num-coins[i]] ; // using memorixation
      } else{
      subAns = minCoins(num - coins[i], size, coins, dp);} //recurrsion
      if (subAns + 1 < ans) {
        ans = subAns + 1;
      }
    }
  }
  dp[num] = ans;
  return ans;
}

int main() {
  int tn, val;
  scanf("%d %d", &tn, &val); // taking input

  int coins[tn], dp[val];
    for (int i = 0; i < val; i++)
          dp[i] = -1;

  for (int i = 0; i < tn; i++)
    scanf("%d", &coins[i]);

  int ans;

  ans = minCoins(val, tn, coins, dp);

  printf("%d", ans);
}
