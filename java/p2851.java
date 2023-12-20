import java.io.*;
import java.util.StringTokenizer;


class p2851{

    static StringBuffer sb;
    static BufferedWriter bw;
    static BufferedReader br;

    public static void main(String[] args)throws Exception {
        sb= new StringBuffer();
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br= new BufferedReader(new InputStreamReader(System.in));
        int x=0;
        int temp;
        boolean next=true;
        for(int i=0; i<10;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            if(next==false) continue;
            temp= x+Integer.parseInt( st.nextToken());

            if(temp>100){
                if(temp-100 <= 100-x){
                    x=temp;
                    next = false;
                    continue;
                }else{
                    next = false;
                    continue;
                }
            }
            x= temp;
        }
        System.out.println(x);
        br.close();
    }

}