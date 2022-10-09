import java.util.HashSet;
import java.util.Scanner;

public class diffieHellman {

	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);

		System.out.println("We have two users Alice and Bob:\n");

		System.out.print("User Alice generates value p = ");
		int p = scanner.nextInt();

		long g = findPrimitive(p);
		if (g != -1) {
			System.out.println("The smallest primitive root modulo for " + p + " is g = " + g);

			System.out.print("Alice's secret key is a = ");
			long a = scanner.nextInt();

			System.out.print("Bob's secret key is b = ");
			long b = scanner.nextInt();

			long A = (long) Math.pow(g, a) % p;
			System.out.println(
					"Alice's public key is A = pow(g,a) (%)mod p => pow(" + g + "," + a + ") (%)mod " + p + " = " + A);

			long B = (long) Math.pow(g, b) % p;
			System.out.println(
					"Alice's public key is B = pow(g,b) (%)mod p => pow(" + g + "," + b + ") (%)mod " + p + " = " + B);

			System.out.println("Alice and Bob exchanged with keys");

			long kA = (int) Math.pow(B, a) % p;
			System.out.println("Alice are trying to calculate K(A) = pow(B,a) (%)mod p => pow(" + B + "," + a
					+ ") (%)mod " + p + " = " + kA);

			long kB = (int) Math.pow(B, a) % p;
			System.out.println("Bob are trying to calculate K(B) = pow(A,b) (%)mod p => pow(" + A + "," + b
					+ ") (%)mod " + p + " = " + kB);

			System.out.println("The result is K(A) = K(B) => " + kA + " = " + kB);

			scanner.close();
		} else {
			System.out.println("Alice made a mistake, she needs to try another number!");
		}

	}

	static boolean isPrime(int n) {
		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
		if (n % 2 == 0 || n % 3 == 0)
			return false;

		for (int i = 5; i * i <= n; i = i + 6) {
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		}

		return true;
	}

	static int power(int x, int y, int p) {
		int res = 1;
		x = x % p;

		while (y > 0) {
			if (y % 2 == 1)
				res = (res * x) % p;
			y = y >> 1;
			x = (x * x) % p;
		}
		return res;
	}

	static void findPrimefactors(HashSet<Integer> s, int n) {
		while (n % 2 == 0) {
			s.add(2);
			n = n / 2;
		}

		for (int i = 3; i <= Math.sqrt(n); i = i + 2) {
			while (n % i == 0) {
				s.add(i);
				n = n / i;
			}
		}

		if (n > 2) {
			s.add(n);
		}
	}

	static int findPrimitive(int n) {
		HashSet<Integer> s = new HashSet<Integer>();

		if (isPrime(n) == false) {
			return -1;
		}

		int phi = n - 1;

		findPrimefactors(s, phi);

		for (int r = 2; r <= phi; r++) {
			boolean flag = false;
			for (Integer a : s) {
				if (power(r, phi / (a), n) == 1) {
					flag = true;
					break;
				}
			}

			if (flag == false) {
				return r;
			}
		}

		return -1;
	}
}
