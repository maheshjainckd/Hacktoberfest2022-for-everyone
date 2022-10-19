import java.util.*;
import java.util.Stack;

import javax.swing.plaf.nimbus.State;
public class StackinArrayList {
//      static class Stack{
//         ArrayList<integer> list = new ArrayList<>();
//          public static boolean isEmpty(){
//              return list.size() == 0;
//          }
//          // push
//          public static void push(int data){
//              list.add(data);
//          }
//          // pop
//          public static int pop(){
//               if(isEmpty()){
//                   return -1;
//               }
//              int top = list.get(list.size()-1);
//              list.remove = (list.size()-1);
//              return top;
//          }
//          // peek 
//          public static int peek(){
//             if(isEmpty()){
//                 return -1;
//             }
//             return list.get(list.size()-1);
//          }
//      }
//     public static void main(String[] args) {
//         Stack s = new Stack();
//         s.push(1);
//         s.push(2);
//         s.push(3);
//         s.push(4);
//         while (!s.isEmpty()) {
//             System.out.println(s.peek());
//             s.pop();
//         }
//     }
// }
// short
public static void main(String[] args) {
   Stack<integer> s = new Stack();
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    while (!s.isEmpty()) {
        System.out.println(s.peek());
        s.pop();
    }
}
}

