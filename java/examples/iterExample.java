package examples;
import java.util.*;


public class iterExample{
    
    public static void main(String[] args) {
        LinkedList<Integer> Llist = new LinkedList<Integer>();

        Llist.add(4);
        Llist.add(5);
        Llist.add(3);
        Llist.add(10);
        iter(Llist);
        iterlist(Llist);
    }
    
    //Listiterator은 역방향으로도 움ㅣㄱ일 수  있ㅡㅁ

    public static void iter(LinkedList<Integer> Llist){
         Iterator<Integer> iter = Llist.iterator();
        while(iter.hasNext()){
            System.out.println(iter.next()+" ");
        }
    }

    public static void iterlist(LinkedList<Integer> Llist){
        ListIterator<Integer> iter = Llist.listIterator();
        while (iter.hasNext()) {
            System.out.println(iter.next() + " ");
        }
        while (iter.hasPrevious()) {
            System.out.println(iter.previous() + " ");
        }

    }
}