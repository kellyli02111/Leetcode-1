class Solution {
public:
    bool isNumber(string s) {
        if(s.empty()) return false;
        int i = 0;
        while(isspace(s[i])){
            i++;
        }
        if((s[i] == '+') || (s[i] == '-')){
            i++;
        }
        bool dotAppear = false;
        bool eAppear = false;
        bool spaceAppear = false;
        bool firstPart = false;
        bool secondPart = false;
        while(i < s.size()){
            if(s[i] == '.'){
                if(dotAppear || spaceAppear || eAppear){
                    return false;
                }
                dotAppear = true;
            }
            else if((s[i] == 'e') || (s[i] == 'E')){
                if(!firstPart || spaceAppear || eAppear){
                    return false;
                }
                eAppear = true;
            }
            else if(isdigit(s[i])){
                if(spaceAppear){
                    return false;
                }
                if(!eAppear){
                    firstPart = true;
                }
                else{
                    secondPart = true;
                }
            }
            else if((s[i] == '+') || (s[i] == '-')){
                if(spaceAppear || !eAppear || !((s[i - 1] == 'e') || (s[i - 1] == 'E'))){
                    return false;
                }
            }
            else if(isspace(s[i])){
                spaceAppear = true;
            }
            else{
                return false;
            }
            i++;
        }
        if(!firstPart){
            return false;
        }
        if(eAppear && (!secondPart)){
            return false;
        }
        return true;
    }
};
