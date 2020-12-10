/*

if any number is equal then retun false
if its not decreasing but numbers are smaller then decreasing(low) = true
if its decreasing but numbers are incresing then return false
if its never been decreasing then return false
*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int low = false;
        if(arr.size() == 1){
            return false;
        }
        for(int i = 0;i < arr.size()-1;i++){
            if(!low){
                if(arr[i] == arr[i+1]){
                    return false;
                }
                if(arr[i] >= arr[i+1]){
                    if(i == 0){
                        return false;
                    }
                    low = true;
                }
            }
            else{
                if(arr[i] == arr[i+1]){
                    return false;
                }
                if(arr[i] <= arr[i+1]){
                    return false;
                }
            }
        }
        if(!low){
            return false;
        }
        return true;
    }
};