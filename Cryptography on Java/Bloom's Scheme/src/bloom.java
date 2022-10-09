import java.util.Scanner;

public class bloom {
	public static void main(String args[])
	{
		//------------------------------------------���� ������
		
		Scanner s = new Scanner(System.in);
		System.out.print("������� �������� p: ");
		int pMod = s.nextInt();
		System.out.println();
		System.out.println("���������� ������� D: ");
		int[][] D = inputArray(3, 3, s);
		System.out.println();
		System.out.println("���������� ������� I1: ");
		int[][] I1 = inputArray(3, 1, s);
		System.out.println();
		System.out.println("���������� ������� I2: ");
		int[][] I2 = inputArray(3, 1, s);
		s.close();
		System.out.println();
		
		//------------------------------------------����� ������ � �������
		
		System.out.println("p = " + pMod);
		System.out.println("\n������� D: ");
		showArray(D, 3, 3);
		System.out.println("\n������� I1: ");
		showArray(I1, 3, 1);
		System.out.println("\n������� I2: ");
		showArray(I2, 3, 1);
		System.out.println();
		
		//------------------------------------------��������� ������
		
		int[][] G1 = multipleArray(D, I1, 3, 3, 1);
		System.out.println();
		int[][] G2 = multipleArray(D, I2, 3, 3, 1);
		
		
		//------------------------------------------����� ������ � �������
		
		System.out.println("\n������� G1: ");
		showArray(G1, 3, 1);
		System.out.println("\n������� G2: ");
		showArray(G2, 3, 1);
		System.out.println();
		
		
		//------------------------------------------����� ������
		System.out.println("\n����� ������� G1 � I2: ");
		int K1 = sumArray(G1, I2, 3, 1) % pMod;
		System.out.println();
		System.out.println("\n����� ������� G2 � I1: ");
		int K2 = sumArray(G2, I1, 3, 1) % pMod;
		System.out.println();
		
		//------------------------------------------�����
		
		System.out.println("\nK1 mod " + pMod + " = : " + K1);
		System.out.println("\nK1 mod " + pMod + " = : " + K2);
		System.out.println();
	}
	
	public static int[][] inputArray(int n, int m, Scanner s)
	{
		int[][] temp = new int[n][m];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				System.out.print("������� �����: ");
				temp[i][j] = s.nextInt(); 
				//(int) (10 + Math.random() * 10); 
			}
		return temp;
	}
	
	public static void showArray(int[][] Array, int n, int m)
	{	
		for(int i=0;i<n;i++)
			{
			for(int j=0;j<m;j++)
				System.out.print(Array[i][j] + " ");
			System.out.println();
			}
	}
	
	public static int[][] multipleArray(int[][] Array, int[][] Array2, int n, int m, int m2)
	{
		int[][] temp = new int[n][m2];
		
		for(int i=0;i<n;i++)
		{
			System.out.print(i+1 + ") ");
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<m2;k++)
				{
					temp[i][k] += Array[i][j]*Array2[j][k];
					
					if(j!=2)
						System.out.print(Array[i][j] + " * " +Array2[j][k] + " + ");
					else
						System.out.print(Array[i][j] + " * " +Array2[j][k] + " = " + temp[i][k]);
					
					
				}
			}
			
			System.out.println();
		}
			
		return temp;
	}
	
	public static int sumArray(int[][] Array, int[][] Array2, int n, int m)
	{
		int sum = 0;
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				sum += Array[i][j] * Array2[i][j];
				if(i!=2)
				System.out.print(Array[i][j] + " * " +Array2[i][j] + " + ");
				else
				System.out.print(Array[i][j] + " * " +Array2[i][j] + " = " + sum);
			}
		}	
		
		return sum;
	}
	
}
