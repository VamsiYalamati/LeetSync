class Solution {
public:
    int kthGrammar(int n, int k) {

        // Base case
        if (n == 1)
            return 0;

        if (k % 2 == 1) {
            // Left child
            return kthGrammar(n - 1, (k + 1) / 2);
        } else {
            // Right child
            return 1 - kthGrammar(n - 1, k / 2);
        }
    }
};