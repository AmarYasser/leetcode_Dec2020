class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i =1; i<=n ; i++){
            if(n%i == 0){
                factors.push_back(i);
            }
        }
        sort(factors.begin(), factors.end());
        
        if (factors.size() < k){
            return -1;
        }
        else{
            return factors[k-1];
        }
        
    }
};