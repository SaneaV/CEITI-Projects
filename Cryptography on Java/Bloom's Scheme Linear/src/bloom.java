import java.util.Scanner;

public class bloom {
	public static void main(String args[]) {

		Scanner scanner = new Scanner(System.in);
		int n;
		do {
			System.out.print("Input value n (n>=2)= ");
			n = scanner.nextInt();
		} while (n < 2);

		int p;
		do {
			System.out.print("\nInput value p (p>n) = ");
			p = scanner.nextInt();
		} while (p < n);

		System.out.print("\nInput value a = ");
		int a = scanner.nextInt();
		System.out.print("Input value b = ");
		int b = scanner.nextInt();
		System.out.print("Input value c = ");
		int c = scanner.nextInt();

		System.out.println();
		int[] usersKeys = new int[n];
		for (int i = 0; i < n; i++) {
			System.out.print("User №" + (1 + i) + ", inputs the public key = ");
			usersKeys[i] = scanner.nextInt();
		}
		scanner.close();

		System.out.println("\nSearching of incredible keys");
		int[][] gValues = keysOfIncredebility(a, b, c, usersKeys, n, p);

		System.out.println("\nCalculating of secret keys");
		calculatingOfSecretKeys(usersKeys, n, p, gValues);
	}

	public static int[][] keysOfIncredebility(int a, int b, int c, int[] usersKeys, int n, int p) {
		System.out.println("f(x, y) = (a + b (x + y) + c * x * y) mod p \n");

		int gValues[][] = new int[n][2];

		for (int i = 0; i < n; i++) {
			gValues[i][0] = b + c * usersKeys[i];
			gValues[i][1] = a + b * usersKeys[i];

			System.out.println("G" + (1 + i) + "(x, r" + (1 + i) + ") = " + "( " + a + " + " + b + " ( x + "
					+ usersKeys[i] + " ) " + "+ " + c + " * x *" + usersKeys[i] + " ) (%)mod " + p + " = ( " + a + " + "
					+ b + " * x + " + b * usersKeys[i] + " + " + c * usersKeys[i] + "x ) (%)mod " + p + " = ( "
					+ gValues[i][0] + " * x + " + gValues[i][1] + " ) (%)mod " + p);
		}

		return gValues;
	}

	public static void calculatingOfSecretKeys(int[] usersKeys, int n, int p, int[][] gValues) {
		System.out.println("Gn(x) = f(x, ru) , if u = v, then Ku,v = Ku, v = (ru, rv) \n");

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					int result = (gValues[i][0] * usersKeys[j] + gValues[i][1]) % p;
					System.out.println("K( " + (i + 1) + ", " + (j + 1) + " ) = G( G" + (i + 1) + ", r" + (j + 1)
							+ " ) = ( " + gValues[i][0] + " * x + " + gValues[i][1] + ") (%) mod " + p + " = " + " ( "
							+ gValues[i][0] + " * r" + (j + 1) + " + " + gValues[i][1] + ") (%) mod " + p + " = "
							+ " ( " + gValues[i][0] + " * " + usersKeys[j] + " + " + gValues[i][1] + ") (%) mod " + p
							+ " = " + result);
				}

			}
			System.out.println();
		}
	}
}
