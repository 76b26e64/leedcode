/*
28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence
of needle in haystack, or -1 if needle is not part of haystack.

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters.
*/

class Solution {
private:
    vector<int> buildLPS(const string& pattern) {
        vector<int> lps(pattern.size(), 0);
        int len = 0;
        for (size_t i = 1; i < pattern.size(); ) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        const auto lps = buildLPS(needle);
        size_t i = 0; // index for haystack
        size_t j = 0; // index for needle

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                if (j == needle.size()) {
                    return static_cast<int>(i - j);
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return -1;
    }
};
