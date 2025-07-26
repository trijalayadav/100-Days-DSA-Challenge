class Solution
{
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> maxHeap;
    //     for (int x : nums) {
    //         maxHeap.push(x);
    //     }
    //     int i = k;
    //     while (--k) {
    //         maxHeap.pop();
    //     }
    //     return maxHeap.top();
    // }
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int x : nums)
        {
            minHeap.push(x);
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
