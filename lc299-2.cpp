class Solution {
public:
    string getHint(string secret, string guess) {
        int b = 0;
        int c = 0;
        vector<int> v(10, 0);
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                b++;
            }
            else{
                if(v[secret[i] - '0'] < 0){
                    c++;
                }
                v[secret[i] - '0']++;
                if(v[guess[i] - '0'] > 0){
                    c++;
                }
                v[guess[i] - '0']--;
            }
        }
        string res = to_string(b) + "A" + to_string(c) + "B";
        return res;
    }
};
