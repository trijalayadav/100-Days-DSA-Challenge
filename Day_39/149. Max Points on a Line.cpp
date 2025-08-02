class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        if (points.size() <= 2)
            return points.size();
        int maxCount = 0;

        for (int i = 0; i < points.size(); ++i)
        {
            unordered_map<string, int> slopeMap;
            int overlap = 0, curMax = 0;

            for (int j = i + 1; j < points.size(); ++j)
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0)
                {
                    overlap++;
                    continue;
                }

                int gcd = __gcd(dx, dy);
                dx /= gcd;
                dy /= gcd;

                if (dx < 0)
                {
                    dx = -dx;
                    dy = -dy;
                }

                string slope = to_string(dy) + "/" + to_string(dx);
                slopeMap[slope]++;
                curMax = max(curMax, slopeMap[slope]);
            }

            maxCount = max(maxCount, curMax + overlap + 1);
        }

        return maxCount;
    }
};
