import java.io.*;
import java.util.*;

import javax.print.DocFlavor.STRING;

public class p13229{
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;

    public static void solve() throws Exception{
        int n = Integer.parseInt(br.readLine());
        int []arr = new int[n+1];
        arr[0]=0;
        int i = 1;
        StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                arr[i] = Integer.parseInt(st.nextToken()) +arr[i-1];
                i++;
            }
        n= Integer.parseInt(br.readLine());
        for(int j=0;j<n;j++){
            StringTokenizer insert2 = new StringTokenizer(br.readLine());
            int x =Integer.parseInt( insert2.nextToken());
            int y =Integer.parseInt( insert2.nextToken())+1;
            sb.append(arr[y]-arr[x]);
            sb.append('\n');
        }
    }
    public static void print()throws Exception{
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }
    public static void main(String[] args) throws Exception{
        //입력
        br = new BufferedReader(new InputStreamReader(System.in)); // input c++ cin
        bw = new BufferedWriter(new OutputStreamWriter(System.out)); // ouput c++ cout
        sb = new StringBuilder();
        solve();        
        print();
    }
}