class ZigzagIterator {
private:
    vector<int>::iterator it1, it1End;
    vector<int>::iterator it2, it2End;
    
    int turn;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = v1.begin();
        it2 = v2.begin();
        it1End = v1.end();
        it2End = v2.end();
        turn = 0;
    }

    int next() {
        int res;
        if(it1 == it1End){
            res = *it2++;
        }
        else if(it2 == it2End){
            res = *it1++;
        }
        else{
            if(turn % 2 == 0){
                res = *it1++;
            }
            else{
                res = *it2++;
            }
            turn = turn + 1;
        }
        return res;
    }

    bool hasNext() {
        return (it1 != it1End || it2 != it2End);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
