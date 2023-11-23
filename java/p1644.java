import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class p1644 {
    static BufferedWriter bw;
    static BufferedReader br;
    static StringBuffer   sb;

    public static void main(String[] args)throws Exception {
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuffer();

        int N = Integer.parseInt(br.readLine());
        if(N==1){
            System.out.println(0);
        }else if(N==2){
            System.out.println(1);
        }
        else{
        //제곱근
        int Nsqrt = (int)Math.sqrt((double)N)+1;
        int[] arr = new int[N+1];
        for(int i=0;i<=N;i++){
            arr[i]=i;
        }
        ArrayList<Integer> arr2  = new ArrayList<>();
        
        for(int i=2; i<=N;i++){
            if(arr[i]!=0){
                arr2.add(i);
                for(int j=i;j<=N;j+=i){
                    arr[j]=0;
                }
            }
        }
        // System.out.println("정렬 완료 ");
        // System.out.println("arr1");
        // for(int i=0;i<=N;i++){
        //     System.out.printf("%d ",arr[i]);
        // }
        // System.out.println("\narr2");
        // System.out.println("arr2.size: "+ arr2.size());
        // for(int i=0;i<arr2.size();i++){
        //     System.out.printf("%d ",arr2.get(i));
        // }

        int start=0;
        int end=1;
        int temp = arr2.get(start)+arr2.get(end);
        int cnt = 0;
        while(start<arr2.size())
        {
            if(temp<N){
                end++;
                if(end==arr2.size()){
                    break;
                }
                temp+=arr2.get(end);
            }else if(temp>N){
                temp-=arr2.get(start);
                start++;
            }else{
                cnt++;
                temp-=arr2.get(start);
                start++;
            }
        }
        System.out.println(cnt);
    }
    }
}
