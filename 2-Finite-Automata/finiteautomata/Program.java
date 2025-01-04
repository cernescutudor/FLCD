package finiteautomata;
public class Program {

    public static void main(String[] args) {
        FiniteAutomat DFA = new FiniteAutomat("2-Finite-Automata/finiteautomata/FA.in");
        String testString1 = "_abc"; // should be accepted
        String testString2 = "abc"; // shouldn't be accepted
        if(DFA.isAcceptedDFA(testString1)!=0){
            System.out.println("The string " + testString1 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testString1 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testString2)!=0){
            System.out.println("The string " + testString2 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testString2 + " is not accepted by the DFA");
        }

        String testInt = "123"; // should be accepted
        String testInt2 = "123a"; // shouldn't be accepted
        String testInt3 = "0123"; // shouldn't be accepted
        String testInt4 = "0"; // should be accepted
        String testInt5 = "00"; // shouldn't be accepted
        String testInt6 = "-0"; // shouldn't be accepted
        String testInt7 = "-223"; // should be accepted
        if(DFA.isAcceptedDFA(testInt)!=0){
            System.out.println("The string " + testInt + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt2)!=0){
            System.out.println("The string " + testInt2 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt2 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt3)!=0){
            System.out.println("The string " + testInt3 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt3 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt4)!=0){
            System.out.println("The string " + testInt4 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt4 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt5)!=0){
            System.out.println("The string " + testInt5 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt5 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt6)!=0){
            System.out.println("The string " + testInt6 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt6 + " is not accepted by the DFA");
        }
        if(DFA.isAcceptedDFA(testInt7)!=0){
            System.out.println("The string " + testInt7 + " is accepted by the DFA");
        } else {
            System.out.println("The string " + testInt7 + " is not accepted by the DFA");
        }

        
    }
    
}
