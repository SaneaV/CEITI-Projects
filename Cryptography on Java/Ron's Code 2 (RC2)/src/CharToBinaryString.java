import java.math.BigInteger;

public class CharToBinaryString {

    public static String charToBinaryString(char charOne, char charTwo) {
        String charToString = Character.toString(charOne + charTwo);
        return new BigInteger(charToString.getBytes()).toString(2);
    }
}
