// KMP Algorithm for Pattern Searching

class Solution {
public:  
    int strStr(string haystack, string needle) {
        int n_size = needle.size();
        int h_size = haystack.size();
        
        if (n_size == 0 || (n_size == 0 && h_size == 0))
            return 0;
        if (n_size > h_size)
            return -1;

        // Preprocess the pattern (calculate lps[] array)
        int lps[n_size];
        computeLPSArray(needle, n_size, lps);

        int i = 0; // index for haystack[]
        int j = 0; // index for needle[]
        while (i < h_size) {
            if (needle[j] == haystack[i]) {
                j++;
                i++;
            }

            if (j == n_size)
                return (i - j);
                //printf("Found pattern at index %d ", i - j);
                //j = lps[j - 1]; // For next pattern(needle) matching.

            // mismatch after j matches
            else if (i < h_size && needle[j] != haystack[i])
                // Do not match lps[0..lps[j-1]] characters, they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
        }
        return -1;
    }

    // Fills lps[] for given patttern pat[0..M-1]
    void computeLPSArray(string needle, int n_size, int* lps)
    {
        // length of the previous longest prefix suffix
        int len = 0;

        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < n_size)
            if (needle[i] == needle[len])
                lps[i++] = ++len;
            else
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
    }
};
