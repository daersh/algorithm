import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Math;

public class eboon
 {
    public static void main(String[] args)throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        double n = Integer.parseInt(br.readLine());
        double m = Integer.parseInt(br.readLine());
        //problem3(n, m);
        problem5(n, m);
    }   
    static void problem3(double n, double m){
        double result=1;
        for(int i=0;i<20;i++){
            double mid = (n+m)/2;
            result= Math.cos(mid)+mid -3;
            
            System.out.printf("%.4f\n",result);
            if(result<0){
                n=mid;
            }else if(result>0){
                m = mid;
            }
        }
        System.out.println("n: "+n +" m: "+m);

    }
    
    static void problem5(double n, double m){
        double result=1;
        for(int i=0;i<20;i++){
            
            double mid = (m*problem5_mid(m)-n*problem5_mid(n))/( problem5_mid(m) - problem5_mid(n));

            result= problem5_mid(mid);
            
            System.out.printf("%.4f\n",result);
            if(result<0){
                n=mid;
            }else if(result>0){
                m = mid;
            }
        }
        System.out.println("n: "+n +" m: "+m);

    }
    static double problem5_mid(double mid){

        return  mid*mid+Math.sin(mid) -0.1;
    }
}
