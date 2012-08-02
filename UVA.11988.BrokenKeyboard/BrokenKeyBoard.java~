import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.GregorianCalendar;
import java.util.Locale;


public class BrokenKeyBoard {
	public static void main(String[] args) throws Exception {
		BufferedReader bf = initBF(args);

		String line = "";
		while((line = bf.readLine())!=null)	{
			System.out.println(line);
		}
	}
	private static BufferedReader	initBF(String[] args) throws Exception {
		if(args.length > 0){
			return new BufferedReader(new FileReader(new File(args[0])));
		}
		else{
			return new BufferedReader(new InputStreamReader(System.in));
		}
	}
}










