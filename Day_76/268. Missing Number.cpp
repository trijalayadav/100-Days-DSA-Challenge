// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> present(n + 1, false);
//         for (int num : nums)
//             present[num] = true;
//         for (int i = 0; i <= n; i++) {
//             if (!present[i])
//                 return i;
//         }
//         return -1;
//     }
// };

// optimal -- sum formula
//  class Solution {
//  public:
//      int missingNumber(vector<int>& nums) {
//          int n = nums.size();
//          int expected = n * (n + 1) / 2;
//          int actual = 0;
//          for (int num : nums) actual += num;
//          return expected - actual;
//      }
//  };

// optimal--xor
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int xorAll = 0, xorNums = 0;
        for (int i = 0; i <= n; i++)
            xorAll ^= i;
        for (int num : nums)
            xorNums ^= num;
        return xorAll ^ xorNums;
    }
};
