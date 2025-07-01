class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        vector<int> result;
        int i = 0, j = 0, k = 0;

        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            // If all three elements are equal
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                // Avoid duplicates
                if (result.empty() || result.back() != arr1[i]) {
                    result.push_back(arr1[i]);
                }
                i++;
                j++;
                k++;
            }
            // Increment the pointer(s) with the smallest value
            else {
                int minVal = min({arr1[i], arr2[j], arr3[k]});
                if (arr1[i] == minVal) i++;
                if (arr2[j] == minVal) j++;
                if (arr3[k] == minVal) k++;
            }
        }

        if (result.empty()) return {-1};
        return result;
    }
};
