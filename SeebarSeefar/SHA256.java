import java.security.*;

class Main {
  static String sha256(String s) throws Exception {
    MessageDigest m = MessageDigest.getInstance("SHA-256");
    m.update(s.getBytes());
    return new BigInteger(1, m.digest()).toString(16);
  }

  public static void main(String[] args) throws Exception {
    System.out.println(sha256(
        "hello")); // 2cf24dba5fb0a30e26e83b2ac5b9e29e1b161e5c1fa7425e73043362938b9824
  }
}
