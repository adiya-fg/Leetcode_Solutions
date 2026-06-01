class Solution {
public:
    int minimumCost(vector<int>& cost) {
        //less<int>() is the default sorting order, so we can just use greater<int>() to sort in descending order.
        sort(cost.begin(), cost.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2) {
                total += cost[i];
            }
        }
        return total;
    }
};