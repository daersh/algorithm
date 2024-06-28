import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BufferReader {

    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer sb;
		static StringTokenizer st;


		public static void main(String[] args)throws Exception {
				//init
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        sb = new StringBuffer();

        insert();
        print();
    }

    static void insert() throws Exception{
				//입력받기
        st= new StringTokenizer(br.readLine());
				//입력받은 값을 변수에 넣어주기
        int n=Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
				
				//출력할 내용 저장
        sb.append(n+" ");
        sb.append(m);
    }

	static void print() throws Exception{
		bw.flush();
		bw.write(sb.toString());
    bw.close();
  }  
}