class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int start = 0;
        int end = -1;
        int totLen = 0;
        vector<string> res;
        int i = 0;
        while(i < words.size()){
            int newLen = totLen + (end - start + 1) + words[i].size();
            if(newLen <= maxWidth){
                totLen = totLen + words[i].size();
                end = i;
                i++;
            }
            else{
                string line = createLine(words, maxWidth, start, end, totLen, false);
                res.push_back(line);
                start = i;
                end = i - 1;
                totLen = 0;
            }
        }
        string lastLine = createLine(words, maxWidth, start, end, totLen, true);
        res.push_back(lastLine);
        return res;
    }
    
    
    string createLine(vector<string>& words, int maxWidth, int start, int end, int totLen, bool isLast){
        string res;
        int n = end - start + 1;
        res.append(words[start]);
        if((n == 1) || isLast){
            for(int i = start + 1; i <= end; i++){
                res.append(" " + words[i]);
            }
            int j = maxWidth - totLen - (n - 1);
            res.append(j, ' ');
            return res;
        }
        int k = (maxWidth - totLen) / (n - 1);
        int m = (maxWidth - totLen) % (n - 1);
        for(int i = start + 1; i <= end; i++){
            int nSpace;
            if(i - start <= m){
                nSpace = k + 1;
            }
            else{
                nSpace = k;
            }
            res.append(nSpace, ' ');
            res.append(words[i]);
        }
        return res;
    }
};
