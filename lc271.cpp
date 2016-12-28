class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs.size(); i++){
            res = res + to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.size();
        vector<string> res;
        int ptr = 0;
        while(ptr < n){
            int len = 0;
            while(s[ptr] != '#'){
                len = len * 10 + (s[ptr] - '0');
                ptr++;
            }
            ptr++;
            res.push_back(s.substr(ptr, len));
            ptr = ptr + len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
