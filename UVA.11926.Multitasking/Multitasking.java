import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.BitSet;


public class Multitasking {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String line;
		BitSet bs = new BitSet(1000010);
		while( (line = bf.readLine())!=null && !line.equals("0 0") ){
			bs.clear();
			String[] ts = line.split(" +");
			int n = Integer.parseInt(ts[0]);
			int m = Integer.parseInt(ts[1]);
			boolean noConflict = true;
			for(int i = 0;i<n;++i){
				line = bf.readLine();
				ts = line.split(" +");
				int a = Integer.parseInt(ts[0]);
				int b = Integer.parseInt(ts[1]);
				if(bs.get(a, b).cardinality()>0){
					noConflict = false;
				}
				else{
					bs.set(a, b);
				}
			}
			for(int i = 0;i<m;++i){
				line = bf.readLine();
				ts = line.split(" +");
				int a = Integer.parseInt(ts[0]);
				int b = Integer.parseInt(ts[1]);
				int rep = Integer.parseInt(ts[2]);
				int dif = b-a;
				for(int j = a;j<=1000000 && noConflict;j+=rep){
					if(bs.get(j, j+dif).cardinality()>0){
						noConflict = false;
					}
					else{
						bs.set(j, j+dif);
					}
				}
			}
			if(noConflict){
				System.out.println("NO CONFLICT");
			}
			else{
				System.out.println("CONFLICT");
			}
		}
	}

}
