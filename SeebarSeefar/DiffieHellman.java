import java.math.*;

class Main {
    static BigInteger modExp(BigInteger b, BigInteger e, BigInteger m) {
        return b.modPow(e, m); // Replace with loop for manual impl
    }

    static BigInteger dh(BigInteger p, BigInteger g, BigInteger a, BigInteger b) {
        BigInteger A = modExp(g, a, p), B = modExp(g, b, p);
        return modExp(B, a, p); // Shared secret (== modExp(A, b, p))
    }

    public static void main(String[] args) {
        System.out.println(dh(
            new BigInteger("23"), // p
            new BigInteger("5"),  // g
            new BigInteger("6"),  // a (private)
            new BigInteger("15")  // b (private)
        )); // Output: 2 (shared secret)
    }
}
