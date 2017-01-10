import java.util.*;
import java.io.*;
import java.math.*;
import java.math.BigInteger;
import java.lang.*;
import java.io.File;
class Main{
	//public static final BigInteger ZERO;
	public static int n,target;
	/**
	 *dp[y][x][s] = number of ways to make sum s with y sided dice and rolling x times
	 */
	static BigInteger dp[][][] = new BigInteger[21][25][445];
	
	static void calc(int dice)
	{		
		int i,j;
		for(j=0;j<=20;j++){
			for(i=0;i<=400;i++){
				dp[dice][j][i] = BigInteger.valueOf(0);
			}
		}
		dp[dice][0][0] = BigInteger.valueOf(1);			
		int d,s;
		for(d = 1; d <= 20; d++){
			for(s = 1; s <= 400; s++){
				BigInteger bc = BigInteger.valueOf(0);
				for(i=1;i<=dice;i++){
					if(s-i >=0)
						bc = bc.add(dp[dice][d-1][s-i]);
				}
				dp[dice][d][s] = bc;
			}
		}
	}	
    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger two,res,gcd;	
        File file = new File("fighting_the_zombie.txt");
        //System.out.println(file.getAbsolutePath());
        PrintWriter outputfile = null;
        Scanner myScanner = new Scanner(System.in);
        try
	    {
	       myScanner = new Scanner(file);
	       outputfile = new PrintWriter("2.txt");       
	    }
	    catch (FileNotFoundException ex)  
	    {
	        // insert code to run when exception occurs
	    }		
		int ca=1;
	   	int i,j,k;
	   	int h,s;
	       
		calc(4);
		calc(6);
		calc(8);
		calc(10);
		calc(12);
		calc(20);
		int t = myScanner.nextInt();	
		while(t-- > 0)
		{
			h = myScanner.nextInt();
			s = myScanner.nextInt();
			String str = myScanner.nextLine();
		    str = myScanner.nextLine();
		    BigDecimal ans = new BigDecimal(0.0);
		    int len = str.length();		 
		    for(i=0;i<len;i++){
		    	int x = 0;
			    int y = 0;
			    int z = 0;
		    	for(j=i;j<len;j++){
		    		if(str.charAt(j) == 'd'){
		    			break;
		    		}
		    		x = x*10 + (str.charAt(j) - '0');
		    	}
		    	j++;
		    	for(;j<len;j++){
		    		if(str.charAt(j) == '+' || str.charAt(j) == '-' || str.charAt(j) == ' '){
		    			break;
		    		}
		    		y = y*10 + (str.charAt(j) - '0');
		    	}
		    	int index=-1;
		    	if(j<len && (str.charAt(j) == '+' || str.charAt(j) == '-')){
		    		index = j;
		    		j++;
		    		for(;j<len;j++){
			    		if(str.charAt(j) == ' '){
			    			break;
			    		}
			    		z = z*10 + (str.charAt(j) - '0');
			    	}
		    	}
		    	i = j;
		    	int mult = 1;
		    	if(index > -1 && str.charAt(index) == '-'){
		    		mult = -1; 
		    	}
		    	int m = Math.max(x,h);
		    	if(mult == 1){
		    		m -= z;
		    	}else{
		    		m += z;
		    	}
		    	if(m > 400)
		    	m = Math.min(m, 400);
		    	//if(m < 1)
		    	//m = Math.max(m, 1);
		    	BigInteger a = BigInteger.valueOf(0);
				for(k=1;k<m;k++){
					a = a.add(dp[y][x][k]);
				}
				BigDecimal bigDecX = new BigDecimal(a);
				BigDecimal bigDecY = new BigDecimal(BigInteger.valueOf(y).pow(x));
				bigDecX = bigDecX.divide(bigDecY, 6, BigDecimal.ROUND_HALF_UP);
				BigDecimal one = new BigDecimal(1.0);
				bigDecX = one.subtract(bigDecX);
				if(bigDecX.compareTo(ans) == 1){ //update max probability
					ans = bigDecX;
				}
		    }
			//ans = ans.setScale(6,BigDecimal.ROUND_HALF_UP);
			System.out.print("Case #"+ca+": ");
			outputfile.print("Case #"+ca+": ");
			outputfile.print(ans);
			outputfile.println();
			
			System.out.println(ans);
			ca++;
        }
        outputfile.close();
    }
}
