package finiteautomata;


import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;

public class FiniteAutomat {


    private final ArrayList<String> states;
    private final ArrayList<String> alphabet;
    private String initialState;
    private final ArrayList<String> finalStates;
    private final HashMap<String, HashMap<String, String>> transitions;

    public FiniteAutomat(String fileName) {
        this.states = new ArrayList<>();
        this.alphabet = new ArrayList<>();
        this.finalStates = new ArrayList<>();
        this.transitions = new HashMap<>();
        readFromFile(fileName);

        System.out.println("States: " + this.states);
        System.out.println("Alphabet: " + this.alphabet);
        System.out.println("Initial state: " + this.initialState);
        System.out.println("Final states: " + this.finalStates);
        System.out.println("Transitions: " + this.transitions);
        

    }

    public void readFromFile(String fileName) {

        try {
            BufferedReader reader = new BufferedReader(new FileReader(fileName));
            String line = reader.readLine();
            String[] alphabet = line.split(" ");
            for (String letter : alphabet) {
                this.alphabet.add(letter);
            }
            line = reader.readLine();
            String[] states = line.split(" ");
            for (String state : states) {
                this.states.add(state);
            }
            line = reader.readLine();
            this.initialState = line;
            line = reader.readLine();
            String[] finalStates = line.split(" ");
            for (String state : finalStates) {
                this.finalStates.add(state);
            }
            // Read the transitions
            line = reader.readLine();
            System.out.println(line);

            line = reader.readLine();
            while (line != null) {
                String[] elements = line.split(" ");
                String from = elements[0];
                String to = elements[1];
                String[] transitionsFile = elements[2].split(",");
                this.transitions.putIfAbsent(from, new HashMap<>());
                HashMap<String, String> stateTransitions = this.transitions.get(from);
                for( String symbol : transitionsFile) {
                    stateTransitions.put(symbol, to);
                }
                
                line = reader.readLine();
            }
            reader.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    Integer isAcceptedDFA(String sequence) {
        for (int i = 0; i < sequence.length(); i++) {
            String symbol = sequence.substring(i, i + 1);
            if (!this.alphabet.contains(symbol)) {
                return 0;
            }
        }
        
        return traversalDFA(this.initialState, sequence );
        

    }

    Integer traversalDFA(String state, String sequence) {
        if (sequence.isEmpty()) {

            switch (state) {
                case "q2":
                    return 1;
                case "q3":
                    return 2;
                case "q5":
                    return 2;
                case "q6":
                    return 2;

                default:
                    return 0;
            }
            
        }
        String symbol = sequence.substring(0, 1);
        if (!this.transitions.containsKey(state) || !this.transitions.get(state).containsKey(symbol)) {
            return 0;
        }
        String nextState = this.transitions.get(state).get(symbol);
        return traversalDFA(nextState, sequence.substring(1));
    }

    public Boolean isIdentifier(String token) {
        return isAcceptedDFA(token) == 1;
    }

    public Boolean isIntConstant(String token) {
        return isAcceptedDFA(token) == 2;
    }



     







    

}
