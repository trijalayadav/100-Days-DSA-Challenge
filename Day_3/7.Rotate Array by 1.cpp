// // User function Template for C++

// class Solution {
//   public:
//     void rotate(vector<int> &arr) {
//         // code here
//         vector<int> temp(arr.size());
//         for(int i=0;i<arr.size();i++){
//             temp[(i+1)%arr.size()]=arr[i];         
//         }
//         arr=temp;
//     }
// };

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return;

        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
};
