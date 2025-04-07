import java.math.*;

class Main {
    static BigInteger modExp(BigInteger b, BigInteger e, BigInteger m) {
        return b.modPow(e, m); // Manual impl would loop bits
    }

    static BigInteger[] rsa(BigInteger p, BigInteger q, BigInteger e, BigInteger m) {
        BigInteger n = p.multiply(q);
        BigInteger phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        BigInteger d = e.modInverse(phi);
        return new BigInteger[]{
            modExp(m, e, n),  // Encrypt
            modExp(modExp(m, e, n), d, n)  // Decrypt
        };
    }

    public static void main(String[] args) {
        var res = rsa(
            new BigInteger("61"), // p
            new BigInteger("53"), // q
            new BigInteger("17"), // e
            new BigInteger("123") // m
        );
        System.out.println("Enc: " + res[0] + "\nDec: " + res[1]);
    }
}
