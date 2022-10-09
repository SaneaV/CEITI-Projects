import java.util.Scanner;

public class RonsCode2 {

    private static String[] encrypt(String sWord, String sKey) {
        System.out.println("Encoding: ");
        char[] cWord = sWord.toCharArray();
        char[] cKey = sKey.toCharArray();

        String a = CharToBinaryString.charToBinaryString(cWord[0], cWord[1]);
        System.out.println(cWord[0] + " " + cWord[1] + " = " + a);
        String b = CharToBinaryString.charToBinaryString(cWord[2], cWord[3]);
        System.out.println(cWord[2] + " " + cWord[3] + " = " + b);
        String c = CharToBinaryString.charToBinaryString(cWord[4], cWord[5]);
        System.out.println(cWord[4] + " " + cWord[5] + " = " + c);
        String d = CharToBinaryString.charToBinaryString(cWord[6], cWord[7]);
        System.out.println(cWord[6] + " " + cWord[7] + " = " + d);
        String key = CharToBinaryString.charToBinaryString(cKey[0], cKey[1]);
        System.out.println(cKey[0] + " " + cKey[1] + " = " + key + "\n");

        String part1 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(a) + BinaryStringToInteger.binaryStringToInt(key));
        System.out.println("1. " + cWord[0] + " " + cWord[1] +
                " + " + cKey[0] + " " + cKey[1] + " => " +
                CharToBinaryString.charToBinaryString(cWord[0], cWord[1]) + " + " +
                CharToBinaryString.charToBinaryString(cKey[0], cKey[1]) + " => " +
                BinaryStringToInteger.binaryStringToInt(a) + " + " + BinaryStringToInteger.binaryStringToInt(key) +
                " = " + (BinaryStringToInteger.binaryStringToInt(a) + BinaryStringToInteger.binaryStringToInt(key)) +
                " => " + part1 + "\n");

        String part2 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(c) & BinaryStringToInteger.binaryStringToInt(d));
        System.out.println("2. " + cWord[4] + " " + cWord[5] +
                " & " + cWord[6] + " " + cWord[7] + " => " +
                CharToBinaryString.charToBinaryString(cWord[4], cWord[5]) + " & " +
                CharToBinaryString.charToBinaryString(cWord[6], cWord[7]) + " => " +
                BinaryStringToInteger.binaryStringToInt(c) + " & " + BinaryStringToInteger.binaryStringToInt(d) +
                " = " + (BinaryStringToInteger.binaryStringToInt(c) & BinaryStringToInteger.binaryStringToInt(d)) +
                " => " + part2 + "\n");

        String part3 = IntegerToBinaryString.integerToBinaryString(~BinaryStringToInteger.binaryStringToInt(d) & BinaryStringToInteger.binaryStringToInt(b));
        System.out.println("3. " + "(~ " + cWord[6] + " " + cWord[7] +
                ") & " + cWord[2] + " " + cWord[3] + " => ~ (" +
                CharToBinaryString.charToBinaryString(cWord[6], cWord[7]) + ") & " +
                CharToBinaryString.charToBinaryString(cWord[2], cWord[3]) + " => ~ (" +
                BinaryStringToInteger.binaryStringToInt(d) + ") & " + BinaryStringToInteger.binaryStringToInt(b) +
                " = " + ((~BinaryStringToInteger.binaryStringToInt(d)) & BinaryStringToInteger.binaryStringToInt(b)) +
                " => " + part3 + "\n");

        String part4 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part2) + BinaryStringToInteger.binaryStringToInt(part3));
        System.out.println("4. " + "( " + cWord[4] + " " + cWord[5] +
                " & " + cWord[6] + " " + cWord[7] + " ) + " +
                "((~ " + cWord[6] + " " + cWord[7] +
                ") & " + cWord[2] + " " + cWord[3] + " ) => " +
                part2 + " + " + part3 + " => " +
                BinaryStringToInteger.binaryStringToInt(part2) + " + " +
                BinaryStringToInteger.binaryStringToInt(part3) + " = " +
                (BinaryStringToInteger.binaryStringToInt(part2) + BinaryStringToInteger.binaryStringToInt(part3)) +
                " => " + part4 + "\n");

        String part5 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part4) + BinaryStringToInteger.binaryStringToInt(part1));
        System.out.println("5. " + "( " + cWord[0] + " " + cWord[1] +
                " + " + cKey[0] + " " + cKey[1] + " ) + " +
                "(( " + cWord[4] + " " + cWord[5] +
                " & " + cWord[6] + " " + cWord[7] + " ) + " +
                "((~ " + cWord[6] + " " + cWord[7] +
                ") & " + cWord[2] + " " + cWord[3] + " )) => " +
                part1 + " + " + part4 + " => " +
                BinaryStringToInteger.binaryStringToInt(part1) + " + " +
                BinaryStringToInteger.binaryStringToInt(part4) + " = " +
                (BinaryStringToInteger.binaryStringToInt(part1) + BinaryStringToInteger.binaryStringToInt(part4)) +
                " => " + part5 + "\n");

        String part6 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part5) << 4);
        System.out.println("6. (" + "( " + cWord[0] + " " + cWord[1] +
                " + " + cKey[0] + " " + cKey[1] + " ) + " +
                "(( " + cWord[4] + " " + cWord[5] +
                " & " + cWord[6] + " " + cWord[7] + " ) + " +
                "((~ " + cWord[6] + " " + cWord[7] +
                ") & " + cWord[2] + " " + cWord[3] + " ))) << 4 => (" +
                part1 + " + " + part4 + ") << 4 => (" +
                BinaryStringToInteger.binaryStringToInt(part1) + " + " +
                BinaryStringToInteger.binaryStringToInt(part4) + ") <<4 = " +
                (BinaryStringToInteger.binaryStringToInt(part1) + BinaryStringToInteger.binaryStringToInt(part4)) +
                " => " + part6 + "\n");

        a = part6;

        System.out.println("b = " + b);
        System.out.println("c = " + c);
        System.out.println("d = " + d);
        System.out.println("a = " + a);
        System.out.println("key = " + key + "\n");

        System.out.println("Combine: " + b + c + d + a);

        String[] values = new String[5];
        values[0] = b;
        values[1] = c;
        values[2] = d;
        values[3] = a;
        values[4] = key;

        return values;
    }

    private static String[] decrypt(String[] encrypted) {
        System.out.println("\nDecrypting: ");
        String a, b, c, d, key;

        b = encrypted[0];
        c = encrypted[1];
        d = encrypted[2];
        a = encrypted[3];
        key = encrypted[4];

        String part1 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(a) >> 4);
        System.out.println("1. a >> 4 = " + a + " >> 4 = " +
                (BinaryStringToInteger.binaryStringToInt(part1) >> 4) + " = " +
                part1 + "\n");

        String part2 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(c) & BinaryStringToInteger.binaryStringToInt(d));
        System.out.println("2. c & d = " +
                c + " & " +
                d + " => " +
                BinaryStringToInteger.binaryStringToInt(c) + " & " + BinaryStringToInteger.binaryStringToInt(d) +
                " = " + (BinaryStringToInteger.binaryStringToInt(c) & BinaryStringToInteger.binaryStringToInt(d)) +
                " => " + part2 + "\n");

        String part3 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(d) & BinaryStringToInteger.binaryStringToInt(b));
        System.out.println("3. (~ d) & b  => ~ (" +
                d + ") & " +
                b + " => ~ (" +
                BinaryStringToInteger.binaryStringToInt(d) + ") & " + BinaryStringToInteger.binaryStringToInt(b) +
                " = " + ((~BinaryStringToInteger.binaryStringToInt(d)) & BinaryStringToInteger.binaryStringToInt(b)) +
                " => " + part3 + "\n");

        String part4 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part2) + BinaryStringToInteger.binaryStringToInt(part3));
        System.out.println("4. (c & d) + (not d ^b) => " +
                part2 + " + " + part3 + " => " +
                BinaryStringToInteger.binaryStringToInt(part2) + " + " +
                BinaryStringToInteger.binaryStringToInt(part3) + " = " +
                (BinaryStringToInteger.binaryStringToInt(part2) + BinaryStringToInteger.binaryStringToInt(part3)) +
                " => " + part4 + "\n");

        String part5 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part1) - BinaryStringToInteger.binaryStringToInt(part4));
        System.out.println("5. ( PUNCT_1 - (b ^ (not d) + (c ^ d) )) => " +
                part1 + " - " + part4 + " => " +
                BinaryStringToInteger.binaryStringToInt(part1) + " - " +
                BinaryStringToInteger.binaryStringToInt(part4) + " = " +
                (BinaryStringToInteger.binaryStringToInt(part1) - BinaryStringToInteger.binaryStringToInt(part4)) +
                " => " + part5 + "\n");

        String part6 = IntegerToBinaryString.integerToBinaryString(BinaryStringToInteger.binaryStringToInt(part5) - BinaryStringToInteger.binaryStringToInt(key));
        System.out.println("6. PUNCT_5 - key => " +
                part5 + " - " + key + " => " +
                BinaryStringToInteger.binaryStringToInt(part5) + " - " +
                BinaryStringToInteger.binaryStringToInt(key) + " = " +
                (BinaryStringToInteger.binaryStringToInt(part5) - BinaryStringToInteger.binaryStringToInt(key)) +
                " => " + part6 + "\n");

        String[] values = new String[5];
        values[0] = part6;
        values[1] = b;
        values[2] = c;
        values[3] = d;
        values[4] = key;
        System.out.println("Combine: " + part6 + b + c + d + "\n");

        return values;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String word, key;
        do {
            System.out.print("Enter an 8 letter word: ");
            word = sc.nextLine();

        } while (word.length() != 8);

        do {
            System.out.print("Enter a 2 letter codeword: ");
            key = sc.nextLine();
        } while (key.length() != 2);

        System.out.println();
        sc.close();

        String[] encryptedWord = encrypt(word, key);
        String[] decryptedWord = decrypt(encryptedWord);

        for (int i = 0; i < 4; i++) {
            do {
                decryptedWord[i] = "0" + decryptedWord[i];
            } while (decryptedWord[i].length() < 16);
        }

        String binaryWord = decryptedWord[0] + decryptedWord[1] +
                decryptedWord[2] + decryptedWord[3];
        String binaryKey = decryptedWord[4];

        System.out.println("Your encrypted word: " + BinaryStringToSChar.binaryStringToSChar(binaryWord));
        System.out.println("Your encrypted key: " + BinaryStringToSChar.binaryStringToSChar(binaryKey));
    }
}
