class Solution {
public:
    int helpFunction(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int ans = INT_MAX;

        int minVal = INT_MAX;
        int n = landStartTime.size();
        for(int i=0; i<n; i++) {
            minVal = min(minVal,landStartTime[i]+landDuration[i]);
        }

        int m = waterStartTime.size();
        for(int i=0; i<m; i++) {
            ans = min(ans,((minVal>=waterStartTime[i]) ? minVal : waterStartTime[i])+waterDuration[i]);
        }
        return ans;        
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(helpFunction(landStartTime,landDuration,waterStartTime,waterDuration),helpFunction(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};