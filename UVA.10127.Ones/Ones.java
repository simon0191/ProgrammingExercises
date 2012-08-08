import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;


public class Ones {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String line = "";
		int[] arr = new int[10000];
		M m1 = new M(0,2500,arr);
		M m2 = new M(2501,5000,arr);
		M m3 = new M(5001,7500,arr);
		M m4 = new M(7501,10000,arr);
		m1.start();
		m2.start();
		m3.start();
		m4.start();
		while( (m1.isAlive() || m2.isAlive() || m3.isAlive() || m4.isAlive())  ){}
		for(int i = 0;i<arr.length;++i){
			System.out.print("arr["+i+"] = "+arr[i]+";");
		}
		
	}

}

class M extends Thread{
	int ini,fin;
	int[] arr;
	public M(int ini,int fin,int[] arr){
		this.ini = ini;
		this.fin = fin;
		this.arr = arr;
	}
	@Override
	public void run(){
		for(int j = ini;j<=fin;++j){
			if( (j%2 == 0) || (j%5 == 0))continue;
			StringBuilder sb = new StringBuilder();
			String line = ""+j;
			for(int i = 0;i<line.length();++i){
				sb.append('1');
			}
			BigInteger bi = new BigInteger(line);
			BigInteger ones = new BigInteger(sb.toString());
			while( !ones.mod(bi).equals(BigInteger.ZERO) ){
				sb.append('1');
				ones = new BigInteger(sb.toString());
			}
			arr[j] = ones.toString().length();
			//System.out.print("arr["+j+"] = "+ones.toString().length()+";");
		}
	}
}
