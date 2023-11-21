import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class p11022 {

    static BufferedWriter bw;
    static BufferedReader br;
    static StringBuilder sb;
    
    public static void main(String[] args) throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        for(int i=1;i<=n;i++){
            
            sb.append("Case #"+ i +": ");
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y= Integer.parseInt(st.nextToken());
            int sum = x+y;
            sb.append(x+" + "+y+ " = "+ sum + "\n");
        
        }

        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}
