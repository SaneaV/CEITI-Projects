import java.math.BigInteger;
import java.util.Scanner;

public class TEA {
	
	public static void main(String args[])
	{
		//Input block================================================================
		
		final long DELTA = 2654435769L;
		Scanner s = new Scanner(System.in);
		String mainWord = input("Input the word (max/min length 8 symbols): ", s, 8);
		String key[] = keyInput("Input the key (max/min length 4 symbols): ", s, 4);
		s.close();
		
		//================================================================Input block
		
		System.out.println("\n");
		
		//Binary encrypt block================================================================
		
		System.out.print("Right part: ");
		String rightMainWord = stringToBinarString(mainWord.substring(0, 4));
		System.out.print("Left part: ");
		String leftMainWord = stringToBinarString(mainWord.substring(4, 8));
		System.out.println("\nKeys: ");
		String binaryKey[] = keyBinaryEncrypt(key);
		
		//================================================================Binary encrypt block
		
		System.out.println("\n\nNot paired part ENCRYPT\n\n");
		
		//Not paired part ENCRYPT================================================================
		
		System.out.print("1. ");
		String notPaired1 = leftShift(binarStringToLong(leftMainWord), 0, 4);
		
		System.out.print("2. ");
		String notPaired2 = addition(binarStringToLong(notPaired1), binarStringToLong(binaryKey[0]));
		
		System.out.print("3. ");
		String notPaired3 = addition(binarStringToLong(leftMainWord), DELTA);
		
		System.out.print("4. ");
		String notPaired4 = XOR(binarStringToLong(notPaired2), binarStringToLong(notPaired3));
		
		System.out.print("5. ");
		String notPaired5 = leftShift(binarStringToLong(leftMainWord), 1, 5);
		
		System.out.print("6. ");
		String notPaired6 = addition(binarStringToLong(notPaired5), binarStringToLong(binaryKey[1]));
		
		System.out.print("7. ");
		String notPaired7 = XOR(binarStringToLong(notPaired4), binarStringToLong(notPaired6));
		
		System.out.print("8. ");
		String notPaired8 = addition(binarStringToLong(rightMainWord), binarStringToLong(notPaired7));

		rightMainWord = notPaired8;
		
		//================================================================Not paired part ENCRYPT
		
		System.out.println("\n\nPaired part ENCRYPT\n\n");
		
		//Paired part ENCRYPT================================================================
		
		System.out.print("1. ");
		String Paired1 = leftShift(binarStringToLong(rightMainWord), 0, 4);
		
		System.out.print("2. ");
		String Paired2 = addition(binarStringToLong(Paired1), binarStringToLong(binaryKey[2]));
		
		System.out.print("3. ");
		String Paired3 = addition(binarStringToLong(rightMainWord), DELTA);
		
		System.out.print("4. ");
		String Paired4 = XOR(binarStringToLong(Paired2), binarStringToLong(Paired3));
		
		System.out.print("5. ");
		String Paired5 = leftShift(binarStringToLong(rightMainWord), 1, 5);
		
		System.out.print("6. ");
		String Paired6 = addition(binarStringToLong(Paired5), binarStringToLong(binaryKey[3]));
		
		System.out.print("7. ");
		String Paired7 = XOR(binarStringToLong(Paired4), binarStringToLong(Paired6));
		
		System.out.print("8. ");
		String Paired8 = addition(binarStringToLong(leftMainWord), binarStringToLong(Paired7));
		
		leftMainWord = Paired8;
		
		//================================================================Paired part ENCRYPT
		
		System.out.println("\nLeft part: " + leftMainWord + " => " + binarStringToLong(leftMainWord));
		System.out.println("Right part: " + rightMainWord + " => " + binarStringToLong(rightMainWord) +"\n");
		System.out.println("\n\nPaired part DESCRYPT\n\n");
		
		//Not paired part DECRYPT================================================================
		
		System.out.print("1. ");
		String dPaired1 = leftShift(binarStringToLong(rightMainWord), 0, 4);
		
		System.out.print("2. ");
		String dPaired2 = addition(binarStringToLong(dPaired1), binarStringToLong(binaryKey[2]));
		
		System.out.print("3. ");
		String dPaired3 = addition(binarStringToLong(rightMainWord), DELTA);
		
		System.out.print("4. ");
		String dPaired4 = XOR(binarStringToLong(dPaired2), binarStringToLong(dPaired3));
		
		System.out.print("5. ");
		String dPaired5 = leftShift(binarStringToLong(rightMainWord), 1, 5);
		
		System.out.print("6. ");
		String dPaired6 = addition(binarStringToLong(dPaired5), binarStringToLong(binaryKey[3]));
		
		System.out.print("7. ");
		String dPaired7 = XOR(binarStringToLong(dPaired4), binarStringToLong(dPaired6));
		
		System.out.print("8. ");
		String dPaired8 = minus(binarStringToLong(leftMainWord), binarStringToLong(dPaired7));

		leftMainWord = dPaired8;
		
		//================================================================Not paired part DECRYPT
		
		System.out.println("\n\nNot paired part DECRYPT\n\n");
		
		//Not paired part DECRYPT================================================================
		
		System.out.print("1. ");
		String dNotPaired1 = leftShift(binarStringToLong(leftMainWord), 0, 4);
		
		System.out.print("2. ");
		String dNotPaired2 = addition(binarStringToLong(dNotPaired1), binarStringToLong(binaryKey[0]));
		
		System.out.print("3. ");
		String dNotPaired3 = addition(binarStringToLong(leftMainWord), DELTA);
		
		System.out.print("4. ");
		String dNotPaired4 = XOR(binarStringToLong(dNotPaired2), binarStringToLong(dNotPaired3));
		
		System.out.print("5. ");
		String dNotPaired5 = leftShift(binarStringToLong(leftMainWord), 1, 5);
		
		System.out.print("6. ");
		String dNotPaired6 = addition(binarStringToLong(dNotPaired5), binarStringToLong(binaryKey[1]));
		
		System.out.print("7. ");
		String dNotPaired7 = XOR(binarStringToLong(dNotPaired4), binarStringToLong(dNotPaired6));
		
		System.out.print("8. ");
		String dNotPaired8 = minus(binarStringToLong(rightMainWord), binarStringToLong(dNotPaired7));

		rightMainWord = dNotPaired8;
		
		//================================================================Not paired part DECRYPT
		
		leftMainWord = addZero(leftMainWord);
		rightMainWord = addZero(rightMainWord);
		
		System.out.println("\nLeft part: " + leftMainWord);
		System.out.println("Right part: " + rightMainWord +"\n");		
		
		System.out.println("Your encrypted word: " + BinaryStringToSChar(rightMainWord + leftMainWord));
		
	}
	
	//Input functions block================================================================
	
	public static String input(String message,Scanner scanner, int limit)
	{
		String word;
		do {
			System.out.print(message);
			word = scanner.nextLine();
		}while(word.length()>limit || word.length()<limit);
		
		return word;
	}
	
	public static String[] keyInput(String message,Scanner scanner, int limit)
	{
		String key[] = new String[4];
		for(int i=0;i<4;i++)
		{
			key[i] = input(message, scanner, limit);
		}
		return key;
	}
	
	//================================================================Input functions block
	
	//Binary encrypt functions block================================================================
	
	private static String stringToBinarString(String text) {
		String binarString = new BigInteger(text.getBytes()).toString(2);
		System.out.println(text + " => " + binarString + " => " + binarStringToLong(binarString));
		return binarString;
	}
	
	public static String[] keyBinaryEncrypt(String textKey[])
	{
		String binaryKey[] = new String[4];
		for(int i=0;i<4;i++)
		{
			binaryKey[i] = stringToBinarString(textKey[i]);
		}
		return binaryKey;
	}
	
	private static String longToBinarString(long text) {
		String binarString = Long.toBinaryString(text);
		return binarString;
	}
	
	private static long binarStringToLong(String text) {
		return Long.parseLong(text, 2);
	}
	
	//================================================================Binary encrypt functions block
	
	
	//Encryption================================================================
	
	public static String leftShift(long text, int side, int shift)
	{
		if (side==1)
		{
			System.out.print(text + " >>" + shift + " => " + 
							longToBinarString(text) + " >>" + shift + " = " + 
							longToBinarString((text>>shift)) + " => " +
							(text>>shift) +
							"\n\n");
			
			return longToBinarString(text>>shift);
		}
		else
		{
			System.out.print(text + " <<" + shift + " => " + 
					longToBinarString(text) + " <<" + shift + " = " + 
					longToBinarString((text<<shift)) + " => " +
					(text<<shift) +
					"\n\n");
			
			return longToBinarString(text<<shift);
		}
	}
	
	public static String addition(long text1, long text2)
	{
		long temp = (long) Math.pow(2,  32);
		
		System.out.print("(" + text1 + " + " + text2 +") %(mod)2^32 => (" +
				longToBinarString(text1) + " + " + longToBinarString(text2) + ") %(mod)2^32 = " +
				longToBinarString((text1+text2)%temp) + " => "+ (text1+text2)%temp + "\n\n");
		
		return longToBinarString((text1+text2)%temp);
	}
	
	public static String minus(long text1, long text2)
	{
		long temp = (long) Math.pow(2,  32);
		
		long i = ((((text1-text2)%temp % temp) + temp) % temp);
		
		System.out.print("(" + text1 + " - " + text2 +") %(mod)2^32 => (" +
				longToBinarString(text1) + " - " + longToBinarString(text2) + ") %(mod)2^32 = " +
				longToBinarString(i) + " => "+ i + "\n\n");
		
		return longToBinarString(i);
	}
	
	
	public static String XOR(long text1, long text2)
	{
		System.out.print(text1 + " ^(XOR) " + text2 + " => " +
				longToBinarString(text1) + " ^(XOR) " + longToBinarString(text2) + " = " +
				longToBinarString(text1 ^ text2) + " => "+ (text1 ^ text2) + "\n\n");
		
		return longToBinarString(text1 ^ text2);
	}
	
	//================================================================Encryption
	
	//Decryption================================================================
	
	public static String addZero(String text)
	{
	       while(text.length()<32)
	       {
	    	   text = "0" + text;
	       }
	       
	     return text;
	}
	
	private static String BinaryStringToSChar(String text) {
		String temp = new String(new BigInteger(text, 2).toByteArray());
		return temp;
	}
	
	//================================================================Decryption
}
