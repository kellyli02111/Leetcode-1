class Solution {
public:
    void heapify(vector<pair<int, int>> &A) {
        // write your code here
        int n = A.size();
        if(n < 2) return;
        int begin = (n - 2) / 2;
        for(int i = begin; i >= 0; i--){
            int cur = i;
            while((cur * 2 + 1 <= n - 1) && A[cur * 2 + 1].first > A[cur].first || (cur * 2 + 2 <= n - 1) && A[cur * 2 + 2].first > A[cur].first){
                if(cur * 2 + 2 > n - 1){//only left exists
                    swap(A[cur], A[cur * 2 + 1]);
                    cur = cur * 2 + 1;
                }
                else{//both left and right exist
                    if(A[cur * 2 + 1].first > A[cur * 2 + 2].first){
                        swap(A[cur], A[cur * 2 + 1]);
                        cur = cur * 2 + 1;
                    }
                    else{
                        swap(A[cur], A[cur * 2 + 2]);
                        cur = cur * 2 + 2;
                    }
                }
            }
        }
    }

    void popFromHeap(vector<pair<int, int>> &A){
        int n = A.size();
        swap(A[0], A[n - 1]);
        A.pop_back();
        n--;
        int cur = 0;
        while((cur * 2 + 1 <= n - 1) && A[cur * 2 + 1].first > A[cur].first || (cur * 2 + 2 <= n - 1) && A[cur * 2 + 2].first > A[cur].first){
            if(cur * 2 + 2 > n - 1){//only left exists
                swap(A[cur], A[cur * 2 + 1]);
                cur = cur * 2 + 1;
            }
            else{//both left and right exist
                if(A[cur * 2 + 1].first > A[cur * 2 + 2].first){
                    swap(A[cur], A[cur * 2 + 1]);
                    cur = cur * 2 + 1;
                }
                else{
                    swap(A[cur], A[cur * 2 + 2]);
                    cur = cur * 2 + 2;
                }
            }
        }
        return;
    }

    int jump(vector<int>& nums) {
        vector<pair<int, int>> pq;
        int n = nums.size();
        if(n < 2) return 0;
        for(int i = 0; i < n; i++){
            pq.push_back(make_pair(i + nums[i], i));
        }
        heapify(pq);
        int target = n - 1;
        int start = target;
        int step = 0;
        while(target > 0){
            while(!pq.empty() && pq[0].first >= target){
                if(pq[0].second < start){
                    start = pq[0].second;
                }
                popFromHeap(pq);
            }
            target = start;
            step++;
        }
        return step;
    }
};
