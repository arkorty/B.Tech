class Solution:
    def strStr(self, haystack: str, needle: str):
        if needle == "":
            return 0
        lps = [0] * len(needle)

        i, j = 1, 0
        while i < len(needle):
            if needle[i] == needle[j]:
                lps[i] = j + 1
                i += 1
                j += 1

            elif j == 0:
                lps[i] = 0
                i += 1

            else:
                j = lps[j - 1]

        i, j = 0, 0
        while i < len(haystack):
            if haystack[i] == needle[j]:
                i += 1
                j += 1

            elif j == 0:
                i += 1

            else:
                j = lps[j - 1]

            if j == len(needle):
                return i - len(needle)

        return -1
