import java.io.*;
import java.util.StringTokenizer;

public class p25304 {

    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;
    public static void main(String[] args) throws Exception{

        br =  new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb=new StringBuilder();
        long x = Integer.parseInt(br.readLine());
        long n = Integer.parseInt(br.readLine());
        long sum = 0;
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long val = Integer.parseInt(st.nextToken());
            val *= Integer.parseInt(st.nextToken());
            sum+=val;
        }
        if(x ==sum){
            System.out.println("Yes");
        }else{
            System.out.println("No");
        }
    }
}
