// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        vector<int> temp(arr.size());
        for(int i=0;i<arr.size();i++){
            temp[(i+1)%arr.size()]=arr[i];         
        }
        arr=temp;
    }
};