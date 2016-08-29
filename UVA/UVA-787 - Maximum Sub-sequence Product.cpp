import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	
	
	public static void main(String[] args) throws Exception {
	
		Scanner scan = new Scanner(System.in);
//		Scanner scan = new Scanner(new FileReader(new File("input.txt")));
		
		BigInteger a[] = new BigInteger[200];
		a[0] = BigInteger.ONE;
		
		
		while(scan.hasNext()) {
			int t;
			int n = 1;
			while(scan.hasNext()) {
				t = scan.nextInt();
				if(t == -999999) {
					break;
				}
				a[n++] = new BigInteger("" + t);
			}
			
			BigInteger ans = a[1];
			for(int i = 1; i < n; i++) {
				ans = ans.max(a[i]);
				if(a[i].compareTo(BigInteger.ZERO) == 0) {
					a[i] = BigInteger.ONE;
				}
				else {
					a[i] = a[i].multiply(a[i - 1]);
				}
				
			}
			
			
			
			for(int i = 1; i < n; i++) {
				if(a[i].compareTo(BigInteger.ONE) == 0)
					continue;
				for(int j = i; j < n; j++) {
					if(a[j].compareTo(BigInteger.ONE) == 0)
						break;
					ans = ans.max(a[j].divide(a[i - 1]));
				}
			}
			
			System.out.println(ans);
			
		}
		
		
		scan.close();
	}

}











