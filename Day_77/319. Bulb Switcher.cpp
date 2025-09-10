//  brute
//  class Solution {
//  public:
//      int bulbSwitch(int n) {
//          vector<bool> bulbs(n + 1, false);
//          for (int i = 1; i <= n; i++) {
//              for (int j = i; j <= n; j += i) {
//                  bulbs[j] = !bulbs[j];
//              }
//          }
//          int count = 0;
//          for (int i = 1; i <= n; i++) {
//              if (bulbs[i]) {
//                  count++;
//              }
//          }
//          return count;
//      }
//  };

// better
// only numbers with odd numbers divisor will end up ON
// number that are perfect squares have odd number of factorials
// class Solution {
// public:
//     int bulbSwitch(int n) {
//         int count = 0;
//         for (long long i = 1; i * i <= n; i++) { // check all perfect squares
//             count++;
//         }
//         return count;
//     }
// };

// optimal - count the number of perfect squares before n
class Solution
{
public:
    int bulbSwitch(int n) { return (int)sqrt(n); }
};