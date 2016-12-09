class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if(E >= C || A >= G || B >= H || F >= D) return sum;
        return sum - (C - A + G - E - (max(C, G) - min(A, E))) * (D - B + H - F - (max(D, H) - min(B, F)));
    }
};
