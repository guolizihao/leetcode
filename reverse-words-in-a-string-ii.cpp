

public class Solution {
    public void reverseWords(char[] s) {
        if (s.length == 0) return;
        reverse(s, 0, s.length-1);
        int start = 0;
        for (int i=0; i<s.length; i++) {
            if (s[i] == ' ') {
                reverse(s, start, i-1);
                start = i + 1;
            }
        }
    }
    
    public void reverse(char[] s, int l, int r) {
        while (l <= r) {
            int temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
}
/reverse-words-in-a-string
