import java.security.*;

class Main {
  static String sha1(String s) throws Exception {
    MessageDigest m = MessageDigest.getInstance("SHA-1");
    m.update(s.getBytes());
    return new BigInteger(1, m.digest()).toString(16);
  }

  public static void main(String[] args) throws Exception {
    System.out.println(
        sha1("hello")); // aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d
  }
}
