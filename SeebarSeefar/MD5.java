import java.security.*;
import java.math.*;

class Main {
    static String md5(String s) throws Exception {
        MessageDigest m = MessageDigest.getInstance("MD5");
        m.update(s.getBytes());
        
        return new BigInteger(1, m.digest()).toString(16);
    }

    public static void main(String[] args) throws Exception {
        System.out.println(md5("hello")); // 5d41402abc4b2a76b9719d911017c592
    }
}
