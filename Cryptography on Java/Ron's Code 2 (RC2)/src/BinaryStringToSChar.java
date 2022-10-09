import java.math.BigInteger;

public class BinaryStringToSChar {

    public static String binaryStringToSChar(String string) {
        return new String(new BigInteger(string, 2).toByteArray());
    }
}
