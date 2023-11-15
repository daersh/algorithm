
import java.util.*;

// 빠른 입출력 용 
import java.io.*;
import javax.print.DocFlavor.STRING;

public class TRIE {
    static BufferedReader br;
    static BufferedWriter bw;
    static StringBuilder sb;


    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in)); // input c++ cin
        bw = new BufferedWriter(new OutputStreamWriter(System.out)); // ouput c++ cout
        sb = new StringBuilder();
        solve();        
        print();
    }

    public static void solve() throws Exception{
        int Q = Integer.parseInt(br.readLine());
        Trie trie= new Trie();
        for(int i=0;i<Q;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<String> str = new ArrayList<String>();
            
            while (st.hasMoreTokens()) {
                str.add(st.nextToken());
            }

            if(str.get(0).equals("add")){
                trie.insert(str);
            }else if(str.get(0).equals("delete")){
                //trie.delete(str);
            }else {
                trie.print();
            }

        }
    }

    public static void print() throws Exception{
        bw.flush();
        bw.write(sb.toString());
        bw.close();
    }


    public static class Node {
        HashMap<String, Node> childHashMap;
        int isEnd;
        Node(){
            childHashMap = new HashMap<String, Node>();
        };
    }

    //내부 클래스
    public static class Trie{
        Node root;
        Trie(){root = new Node();}
        //삽입
        void insert(List<String> str){
            //0번째는 add이므로 제외
            Node loc = this.root;
            
            for(int i=1; i < str.size();i++){
                if(loc.childHashMap.size()==0){
                    loc.childHashMap.put(str.get(i),new Node());
                    loc = loc.childHashMap.get(str.get(i));
                }else{
                    if(loc.childHashMap.containsKey(str.get(i))){
                        loc = loc.childHashMap.get(str.get(i));
                    }else {
                        loc.childHashMap.put(str.get(i),new Node());
                        loc = loc.childHashMap.get(str.get(i));
                    }
                }
            }
        }

        //루트 출력
        void print(){
            Node loc = this.root;
            for(String i: loc.childHashMap.keySet()){
                sb.append(i);
                sb.append("\n");
                print(loc.childHashMap.get(i), 1);
            }
        }
        //자식 노드 출력
        void print(Node loc, int cnt){
            for(String i: loc.childHashMap.keySet()){
                for(int j=0;j<cnt;j++){
                    sb.append("-");
                }
                sb.append(i);
                sb.append("\n");
                print(loc.childHashMap.get(i), cnt+1);
            }
        }

       void delete(){

       }
    }

    
}
