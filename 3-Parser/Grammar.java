import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class Grammar {
    private Set<String> N;
    private Set<String> E;
    private String S;
    private LinkedHashMap<String, List<List<String>>> P;
    private String filename;

    public Grammar( String filename) {
        this.filename = filename;
        try {
            readFromFile(filename);
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
        
    }

    public void readFromFile(String filename) throws IOException {
        List<String> lines = Files.readAllLines(Paths.get(filename), StandardCharsets.UTF_8);
        Iterator<String> iterator = lines.iterator();

        this.N = new HashSet<>(parseLine(iterator.next()));
        this.E = new HashSet<>(parseLine(iterator.next()));
        this.S = iterator.next().split("=")[1].replace(" ", "").trim();
        iterator.next(); 

        this.P = parseProductions(iterator);

        if (!isValid()) {
            throw new IllegalArgumentException("Grammar in " + filename + " is not valid");
        }
    }

    private static List<String> parseLine(String line) {
        return Arrays.asList(line.split("=", 2)[1].trim().split("\\s+"));
    }

    private static LinkedHashMap<String, List<List<String>>> parseProductions(Iterator<String> iterator) {
        LinkedHashMap<String, List<List<String>>> P = new LinkedHashMap<>();
        while (iterator.hasNext()) {
            String line = iterator.next().trim();
            if (line.isEmpty()) continue;

            String[] parts = line.split("->");
            String lhs = parts[0].trim();
            String[] rhsList = parts[1].trim().split("\\|");

            for (String alternative : rhsList) {
                List<String> symbols = Arrays.asList(alternative.trim().split("\\s+"));
                P.computeIfAbsent(lhs, k -> new ArrayList<>()).add(symbols);
            }
        }
        return P;
    }

    private boolean isValid() {
        if (!N.contains(S)) {
            System.out.println("Error: Start symbol '" + S + "' is not in the set of nonterminals N.");
            return false;
        }

        for (String lhs : P.keySet()) {
            if (!N.contains(lhs)) {
                System.out.println("Error: Production LHS '" + lhs + "' is not a nonterminal.");
                return false;
            }

            for (List<String> rhs : P.get(lhs)) {
                for (String symbol : rhs) {
                    if (!N.contains(symbol) && !E.contains(symbol) && !"epsilon".equals(symbol)) {
                        System.out.println("Error: Symbol '" + symbol + "' in production '" + lhs + " -> " + String.join(" ", rhs) + "' is neither a terminal nor a nonterminal.");
                        return false;
                    }
                }
            }
        }
        return true;
    }

    public boolean isCFG() {
        if (!N.contains(S)) {
            return false;
        }
    
        for (String lhs : P.keySet()) {
           
            if (!N.contains(lhs) || lhs.split("\\s+").length > 1) {
                return false;
            }
    
            for (List<String> rhs : P.get(lhs)) {
                for (String symbol : rhs) {
                    if (!N.contains(symbol) && !E.contains(symbol) && !"epsilon".equals(symbol)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    public HashMap<String, List<List<String>>> getProductions(){
        return P;
    }
    public List<List<String>> getNonterminalProductions(String nonterminal) {
        if (!N.contains(nonterminal)) {
            throw new IllegalArgumentException("Can only show productions for non-terminals");
        }
        return P.get(nonterminal);
    }

    public Set<String> getNonterminals() {
        return N;
    }

    public Set<String> getTerminals() {
        return E;
    }
    public String getStartSymbol() {
        return S;
    }

    @Override
    public String toString() {
        return "N = " + getNonterminals() + "\nE = " + getTerminals() + "\nS = " + S + "\nP = " + P;
    }

    public void processGrammar() {
        try {
            System.out.println("Checking " + filename + ":");


            System.out.println("Nonterminals (N): " + getNonterminals());
            System.out.println("Terminals (E): " + getTerminals());
            System.out.println("Start Symbol (S): " + S);
            System.out.println("Productions (P):");
            for (String lhs : P.keySet()) {
                String formattedRhs = P.get(lhs).stream()
                        .map(prod -> String.join(" ", prod))
                        .reduce((a, b) -> a + " | " + b).orElse("");
                System.out.println("  " + lhs + " -> " + formattedRhs);
            }

            System.out.println("Is CFG: " + isCFG());

            System.out.println("Productions for Start Symbol (" + S + "): " + getNonterminalProductions(S));

        } catch (IllegalArgumentException  e) {
            System.out.println("Error in " + filename + ": " + e.getMessage());
        } catch (Exception ex) {
            System.out.println("An unexpected error occurred while processing " + filename + ": " + ex.getMessage());
        }

        System.out.println("\n" + "-".repeat(30) + "\n");
    }


    public static void main(String[] args) {
        
        Grammar g = new Grammar("3-Parser/g1.txt");
        g.processGrammar();
    }
}
