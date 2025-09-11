// class SummaryRanges {
// public:
//     set<int> nums;
//     SummaryRanges() {}

//     void addNum(int value) { nums.insert(value); }

//     vector<vector<int>> getIntervals() {
//         vector<vector<int>> ans;
//         if (nums.empty())
//             return ans;
//         int start = -1, end = -1;
//         for (int num : nums) {
//             if (start == -1) {
//                 start = end = num;
//             } else if (num == end + 1) {
//                 end = num;
//             } else {
//                 ans.push_back({start, end});
//                 start = end = num;
//             }
//         }
//         ans.push_back({start, end});
//         return ans;
//     }
// };

class SummaryRanges
{
public:
    map<int, int> intervals; // key = start, value = end

    SummaryRanges() {}

    void addNum(int value)
    {
        if (intervals.empty())
        {
            intervals[value] = value;
            return;
        }

        // find the first interval with start > value
        auto it = intervals.upper_bound(value);
        int start = value, end = value;

        // check if we can merge with previous interval
        if (it != intervals.begin())
        {
            auto prev = it;
            --prev;
            if (prev->second >= value)
                return; // already covered
            if (prev->second + 1 == value)
            {
                start = prev->first;
                end = max(end, prev->second);
                intervals.erase(prev);
            }
        }

        // check if we can merge with next interval
        if (it != intervals.end() && it->first == value + 1)
        {
            end = it->second;
            intervals.erase(it);
        }

        intervals[start] = max(end, value);
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (auto &p : intervals)
        {
            ans.push_back({p.first, p.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */