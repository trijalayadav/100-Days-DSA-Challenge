class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // brute force approach
        int m = nums1.size(), n = nums2.size();
        vector<int> ans(m, -1);
        // for (int i = 0; i < m; i++) {
        //     int j = 0;
        //     while (j < n && nums1[i] != nums2[j]) {
        //         j++;
        //     }
        //     for(int k=j+1;k<n;k++){
        //         if(nums2[k]>nums1[i]){
        //             ans[i]=nums2[k];
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // better approach
        //  unordered_map<int,int> indices;
        //  for(int j=0;j<n;j++){
        //      indices[nums2[j]]=j;
        //  }
        //  for (int i = 0; i < m; i++) {
        //      int j = 0;
        //      for(int k=indices[nums1[i]];k<n;k++){
        //          if(nums2[k]>nums1[i]){
        //              ans[i]=nums2[k];
        //              break;
        //          }
        //      }
        //  }
        //  return ans;

        // optimal approach
        unordered_map<int, int> nextGreater;
        stack<int> st;
        for (int num : nums2)
        {
            while (!st.empty() && st.top() < num)
            {
                // this loop will fill the map nextGreater of a number if exists
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
            for (int i = 0; i < m; i++)
            {
                if (nextGreater.count(nums1[i]))
                {
                    ans[i] = nextGreater[nums1[i]];
                }
            }
        }
        return ans;
    }
};