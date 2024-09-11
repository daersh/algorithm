import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p11659 {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuffer sb = new StringBuffer();

    public static void main(String[] args)throws Exception {

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int []list = new int[N+1];
        
        st = new StringTokenizer(br.readLine());
        // 누적합 알고리즘
        // 5 4 3 2 1
        // 5 9 12 14 15
        // 14 = 4 + 3 + 2
        // 2~4 = arr[4] - arr[1] = 14 - 5 = 9
        // 3~4 = 5
        // 14 =  3 + 2
        // 3~4 = arr[4] - arr[2] = 14 - 9 = 5
        // a~b = arr[b] -arr[a-1];
        for(int i = 1; i <= N; i++){
            int x = Integer.parseInt(st.nextToken());
            list[i] = list[i-1] +x;
        }
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int result = list[b]-list[a-1];
            sb.append(result).append("\n");
        }

        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
}

