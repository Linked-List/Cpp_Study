import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger b = new BigInteger(sc.nextLine());
		System.out.println(LinearFib(b));

	}
	public static BigInteger LinearFib(BigInteger n) {
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("1");
        BigInteger res = new BigInteger("0");


        if(n.equals(BigInteger.ZERO))
            return a;
        else if(n.equals(BigInteger.ONE))
            return b;
        
        while(n.compareTo(BigInteger.ONE)==1){
            res = a.add(b);
            a = b;
            b = res;
            n= n.subtract(BigInteger.ONE);
        }
        return res;
	}
}
