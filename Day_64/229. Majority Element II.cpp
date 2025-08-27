// hashmap
//  class Solution {
//  public:
//      vector<int> majorityElement(vector<int>& nums) {
//          int n = nums.size();
//          unordered_map<int, int> count;
//          for (int num : nums) {
//              count[num]++;
//          }
//          vector<int> ans;
//          for (auto i : count) {
//              if (i.second > n / 3) {
//                  ans.push_back(i.first);
//              }
//          }
//          return ans;
//      }
// };


//Boyer-Moore optimal solution
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand1 = 0, cand2 = 1; // initialize to different values
        int cnt1 = 0, cnt2 = 0;

        // Phase 1: Find possible candidates
        for (int num : nums) {
            if (num == cand1) {
                cnt1++;
            } else if (num == cand2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cand1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                cand2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Phase 2: Verify candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1)
                cnt1++;
            else if (num == cand2)
                cnt2++;
        }

        vector<int> ans;
        if (cnt1 > n / 3)
            ans.push_back(cand1);
        if (cnt2 > n / 3)
            ans.push_back(cand2);

        return ans;
    }
};
