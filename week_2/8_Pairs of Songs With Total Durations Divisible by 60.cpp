
/*
// this solution have a timeout problem
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int  size=time.size();
        int count=0;
        for(int i=0; i<size; i++){
            for (int j=i+1; j<size; j++){
                if((time[i]+time[j] )% 60 == 0){
                    count++;
                }
            }
        }
    return count;
    }
};

*/
// try other solution
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> modulos(60,0);
        int  count = 0;
        for(int i = 0;i < time.size();i++){
            count += modulos[(60  - (time[i]%60)) % 60];
            modulos[time[i]%60]++;
        }
        return count;
    }
};

