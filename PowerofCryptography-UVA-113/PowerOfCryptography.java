import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class PowerOfCryptography {

	/**
	 * @param args
	 */
	private final static BigInteger TWO = new BigInteger("2");
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String n = "";
		String p = "";
		BigInteger pp;
		
		while((n=bf.readLine())!= null && (p=bf.readLine())!=null){
			pp = new BigInteger(p);
			System.out.println(func(Integer.parseInt(n),pp));
			
		}
	}
	private static BigInteger func(int n,BigInteger p){
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger("1000000000");
		int aux;
		if(a.pow(n).equals(p))return a;
		else if(b.pow(n).equals(p))return b;
		BigInteger k = a.add(b).divide(TWO);
		while(true){
			if((aux = k.pow(n).compareTo(p))<0){
				a = k;
			}
			else if(aux > 0){
				b = k;
			}
			else{
				return k;
			}
			k = a.add(b).divide(TWO);
		}
	}
}
