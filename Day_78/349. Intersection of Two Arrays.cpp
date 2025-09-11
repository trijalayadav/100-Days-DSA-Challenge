class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // int i = 0, j = 0;
        // int n = nums1.size(), m = nums2.size();
        // set<int> ans;
        // while (i < n && j < m) {
        //     if (nums1[i] == nums2[j]) {
        //         ans.insert(nums1[i]);
        //         i++;
        //         j++;
        //     } else if (nums1[i] < nums2[j]) {
        //         i++;
        //     } else {
        //         j++;
        //     }
        // }
        // return vector<int>(ans.begin(), ans.end());

        // hash table
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> ans;
        for (int num : nums2)
        {
            if (set1.find(num) != set1.end())
            {
                ans.insert(num);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};