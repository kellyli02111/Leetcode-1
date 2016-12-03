class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        int leadSpace = 0;
        int n = s.size();
        int trailSpace = n - 1;
        while(leadSpace < n && s[leadSpace] == ' '){
            leadSpace++;
        }
        while(trailSpace >= 0 && s[trailSpace] == ' '){
            trailSpace--;
        }
        if(leadSpace > trailSpace){
            s = "";
            return;
        }
        
        s = s.substr(leadSpace, trailSpace - leadSpace + 1);
        n = s.size();
        int start = 0; 
        int end = n - 1;
        while(start < end){
            int piece = 1;
            int pieceSpace = 1;
            while(end > 1 && s[end - 1] != ' '){
                end--;
                piece++;
            }
           // cout<<piece<<endl;
            end--;
            while(end > 1 && s[end - 1] == ' '){
                end--;
                pieceSpace++;
            }
            end--;
            if(start > end) return;
            s = s.substr(0, start) + s.substr(s.size() - piece, piece) + " " + s.substr(start, end - start + 1);
            start = start + piece + 1;
            end = s.size() - 1;
        }
    }
};
