class Main {
    static String v(String s, String k, boolean e) { 
        try {
            StringBuilder r = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i), kc = k.charAt(i % k.length());
                int x = e ? c + kc : c - kc;
                r.append((char) (x % 256)); 
            }
            return r.toString();
        } catch (Exception ex) { return "Error"; }
    }

    public static void main(String[] args) {
        String s = "HELLOWORLD", k = "KEY";
        String enc = v(s, k, true), dec = v(enc, k, false);
        System.out.println("Encrypted: " + enc + "\nDecrypted: " + dec);
    }
}
