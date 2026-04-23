class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        vector<int> v;
        int n = arr.size();
        
        int maxi = INT_MIN;
        
        for(int i = 0; i < k; i++){
            maxi = max(maxi, arr[i]);
        }
        v.push_back(maxi);
        for(int i = k; i < n; i++){
            if(arr[i-k] == maxi){
                maxi = INT_MIN;
                for(int j = i-k+1; j <= i; j++){
                    maxi = max(maxi, arr[j]);
                }
            }
            else{
                maxi = max(maxi, arr[i]);
            }

            v.push_back(maxi);
        }
        
        
        return v;
    }
};