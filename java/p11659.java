import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p11659 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuffer sb = new StringBuffer();
    

    public static void main(String[] args)throws Exception {

        // cin n, m
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int []list = new int[N+1];

        st = new StringTokenizer(br.readLine());

        for(int i = 1; i <= N; i++) {
            int x = Integer.parseInt(st.nextToken());
            list[i] = list[i - 1] + x;
        }
        
        for(int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int sum = list[b] - list[a - 1];
            sb.append(sum+"\n");
            
        }
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}
