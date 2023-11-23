import java.io.*;
import java.util.HashMap;
import java.util.Scanner;


public class dsfafas {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuffer menuList;

	public static void main(String[] args) throws Exception{

        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        menuList = new StringBuffer();
		Scanner sc = new Scanner(System.in);

		boolean run =true;
		int select = 0; 
		int select_val=0;
        int[] num = {0,2000,2500,1500,3000,2500};
        HashMap<Integer,String> hm = new HashMap<Integer,String>();
        hm.put(1,"아메리카노");
        hm.put(2,"카페라떼");
        hm.put(3,"에스프레소");
        hm.put(4,"초코라떼");
        hm.put(5,"유자차");

		int[] num_sum = {0,0,0,0,0,0};
        int[] num_cnt= {0,0,0,0,0,0};
        int total=0;

		while(run) {
			select = menu();
            System.out.println(hm.get(select)+"를 선택하셨습니다.");
            System.out.printf("수량>");
            select_val = Integer.parseInt(br.readLine());
            num_sum[select] += num[select]*select_val;
            num_cnt[select]+=select_val;

			System.out.println("--------------------------");
			System.out.println("1.추가주문하기 || 2.계산하기");
			System.out.println("--------------------------");
			select = Integer.parseInt(br.readLine());

            switch(select) {
                case 1:
                    continue;     
                case 2:
                    System.out.println("계산하겠습니다.");
                    System.out.println("--------------------------");
                    System.out.println("          영수증          ");
                    System.out.println("--------------------------");
                    for(int i=0; i<num.length; i++) {
                        if(num_sum[i] != 0) {
                            System.out.println(hm.get(i)+" "+ num_cnt[i] +"개      "+ num_sum[i]);
                            total +=num_sum[i];
                        }
                    }
                    System.out.println("--------------------------");
                    System.out.println("총 금액: "+total);
                    System.out.println("--------------------------");
                    break;
                default:
                    System.out.println("잘못된 입력값 입니다.");
                    break;
            }
            run = false;
		}

	}
    
    
    static int menu() throws Exception{
        System.out.println("--------------------------");
		System.out.println("         메뉴판       ");
		System.out.println("--------------------------");
		System.out.println("1.아메리카노          2000");
		System.out.println("2.카페라떼            2500");
		System.out.println("3.에스프레소          1500");
		System.out.println("4.초코라떼            3000");
		System.out.println("5.유자차              2500");
        System.out.println("--------------------------");
		System.out.printf("메뉴선택 >");
        
        int n = Integer.parseInt(br.readLine());
        return n;
   }
   
}