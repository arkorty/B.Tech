class Main {
    static String f(String s, int k, boolean e) { 
        try {
            if (k == 1) return s;
            StringBuilder[] r = new StringBuilder[k];
            for (int i = 0; i < k; i++) r[i] = new StringBuilder();
            int d = 1, row = 0;
            for (char c : s.toCharArray()) {
                r[row].append(c);
                row += d;
                if (row == 0 || row == k - 1) d *= -1;
            }
            return e ? String.join("", r) : d(s, k); 
        } catch (Exception ex) { return "Error"; }
    }

    static String d(String s, int k) { 
        int[][] x = new int[k][s.length()];
        int d = 1, row = 0;
        for (int i = 0; i < s.length(); i++) {
            x[row][i] = 1;
            row += d;
            if (row == 0 || row == k - 1) d *= -1;
        }
        int idx = 0;
        char[] r = new char[s.length()];
        for (int i = 0; i < k; i++)
            for (int j = 0; j < s.length(); j++)
                if (x[i][j] == 1) r[j] = s.charAt(idx++);
        return new String(r);
    }

    public static void main(String[] args) {
        String s = "HELLOWORLD";
        int k = 3;
        String enc = f(s, k, true), dec = f(enc, k, false);
        System.out.println("Encrypted: " + enc + "\nDecrypted: " + dec);
    }
}
