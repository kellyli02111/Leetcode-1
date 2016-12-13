class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> counts(n + 1, 0);
        for(int i = 0; i < n; i++){
            if(citations[i] <= n){
                counts[citations[i]]++;
            }
            else{
                counts[n]++;
            }
        }
        int sum = 0;
        for(int i = n; i >= 1; i--){
            sum = sum + counts[i];
            if(sum >= i) return i;
        }
        return 0;
    }
};
