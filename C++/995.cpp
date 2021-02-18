class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, n = A.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!q.empty() && i >= (q.front() + K)) q.pop();
            if (q.size() % 2 == A[i]) {
                if (i + K > n) return -1;
                q.push(i);
                res++;
            }
        }
        return res;

        // // 0 0 1 0 0
        // int res = 0, n = A.size();
        // int l = 0, r = 0; // l 指向从左到右第一个0
        // for (int i = 0; i < n; i++) {
        //     if (A[i] == 0) {
        //         if (i + K > n) return -1;
        //         bool isFirst = true;
        //         for (int j = i; j < i + K; j++) {
        //             A[j] = !A[j];
        //             if (A[j] == 0 && isFirst) {
        //                 i = j - 1;
        //                 isFirst = false;
        //             } 
        //         }
        //         res++;
        //     }
        //     // for (int a : A) cout << a << " ";
        //     // cout << endl;
        // }
        // return res;
    }
};