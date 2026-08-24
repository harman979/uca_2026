import java.util.*;

public class PostfixEvaluation {

    public static int evaluate(String expression) {
        Stack<Integer> stack = new Stack<>();

        String[] tokens = expression.split(" ");

        for (String token : tokens) {

            if (Character.isDigit(token.charAt(0))) {
                stack.push(Integer.parseInt(token));
            } 
            else {
                int b = stack.pop();
                int a = stack.pop();

                if (token.equals("+")) {
                    stack.push(a + b);
                } 
                else if (token.equals("-")) {
                    stack.push(a - b);
                } 
                else if (token.equals("*")) {
                    stack.push(a * b);
                } 
                else if (token.equals("/")) {
                    stack.push(a / b);
                }
            }
        }

        return stack.pop();
    }

    public static void main(String[] args) {
        String expression = "2 3 1 * + 9 -";

        System.out.println(evaluate(expression));
    }
}
