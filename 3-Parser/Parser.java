import java.util.*;

public class Parser {
    private Grammar G;
    private String input;
    private Stack<String> stack;
    private HashMap<String, List<List<String>>> P;
    private HashMap<String, List<String>> first;
    private HashMap<String, List<String>> follow;
    private HashMap<AbstractMap.SimpleEntry<String, String>, List<String>> parsingTable;
    public Parser(){
        this.G = new Grammar("3-Parser/gtest2.txt");
        G.processGrammar();
        this.P = G.getProductions();
        System.out.println(this.P);
        computeFirst();
        computeFollow();
        computeTable();
    }
    public void computeTable() {
        this.parsingTable = new HashMap<>();

        for (String nonterminal : G.getNonterminals()) {
            for (String terminal : G.getTerminals()) {
                parsingTable.put(new AbstractMap.SimpleEntry<>(nonterminal, terminal), new ArrayList<>());
            }
            parsingTable.put(new AbstractMap.SimpleEntry<>(nonterminal, "$"), new ArrayList<>());
        }

        for (String nonterminal : G.getNonterminals()) {
            List<List<String>> productions = G.getNonterminalProductions(nonterminal);

            for (List<String> production : productions) {
                Set<String> firstSet = new HashSet<>();
                boolean containsEpsilon = true;
                for (String symbol : production) {
                    if (G.getTerminals().contains(symbol)) {
                        firstSet.add(symbol);
                        containsEpsilon = false;
                        break;
                    } else {
                        firstSet.addAll(first.get(symbol));
                        if (!first.get(symbol).contains("epsilon")) {
                            containsEpsilon = false;
                            break;
                        }
                    }
                }

                for (String terminal : firstSet) {
                    if (!terminal.equals("epsilon")) {
                        AbstractMap.SimpleEntry<String, String> key = new AbstractMap.SimpleEntry<>(nonterminal, terminal);
                        parsingTable.put(key, production);
                    }
                }

                if (containsEpsilon || firstSet.contains("epsilon")) {
                    for (String terminal : follow.get(nonterminal)) {
                        AbstractMap.SimpleEntry<String, String> key = new AbstractMap.SimpleEntry<>(nonterminal, terminal);
                        parsingTable.put(key, production);
                    }
                }
            }
        }
    }

    public void computeFirst(){
        this.first = new HashMap<>();
        for (String nonterminal : G.getNonterminals()) {
            first.put(nonterminal, new ArrayList<String>());
        }
        List<String> reversedNT = new ArrayList<>(G.getProductions().keySet().stream().toList());
        Collections.reverse(reversedNT);
        for(String nonterminal : reversedNT){
            List<List<String>> productions = G.getNonterminalProductions(nonterminal);
            for(List<String> production : productions){
                String firstSymbol = production.get(0);
                if(G.getTerminals().contains(firstSymbol)){
                    first.get(nonterminal).add(firstSymbol);
                } else {
                    first.get(nonterminal).addAll(first.get(firstSymbol));
                }
            }

        }
    }
    public void computeFollow() {
        this.follow = new HashMap<>();

        for (String nonterminal : G.getNonterminals()) {
            follow.put(nonterminal, new ArrayList<>());
        }

        follow.get(G.getStartSymbol()).add("$");

        boolean updated;
        do {
            updated = false;

            for (String nonterminal : G.getNonterminals()) {
                List<List<String>> productions = G.getNonterminalProductions(nonterminal);

                for (List<String> production : productions) {
                    for (int i = 0; i < production.size(); i++) {
                        String symbol = production.get(i);

                        if (G.getNonterminals().contains(symbol)) {
                            List<String> followOfSymbol = follow.get(symbol);

                            boolean allNullable = true;
                            for (int j = i + 1; j < production.size(); j++) {
                                String nextSymbol = production.get(j);

                                if (G.getTerminals().contains(nextSymbol)) {
                                    if (!followOfSymbol.contains(nextSymbol)) {
                                        followOfSymbol.add(nextSymbol);
                                        updated = true;
                                    }
                                    allNullable = false;
                                    break;
                                } else {
                                    List<String> firstOfNext = first.get(nextSymbol);
                                    if (firstOfNext != null) {
                                        for (String terminal : firstOfNext) {
                                            if (!terminal.equals("epsilon") && !followOfSymbol.contains(terminal)) {
                                                followOfSymbol.add(terminal);
                                                updated = true;
                                            }
                                        }

                                        if (!firstOfNext.contains("epsilon")) {
                                            allNullable = false;
                                            break;
                                        }
                                    }
                                }
                            }

                            if (allNullable) {
                                List<String> followOfNonterminal = follow.get(nonterminal);
                                for (String terminal : followOfNonterminal) {
                                    if (!followOfSymbol.contains(terminal)) {
                                        followOfSymbol.add(terminal);
                                        updated = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } while (updated);
    }
    public void printParsingTable(){
        for (String nonterminal : G.getNonterminals()) {
            for (String terminal : G.getTerminals()) {
                List<String> production = parsingTable.get(new AbstractMap.SimpleEntry<>(nonterminal, terminal));
                System.out.println(nonterminal + " and " + terminal + " with production  " + production);
            }
            List<String> production = parsingTable.get(new AbstractMap.SimpleEntry<>(nonterminal, "$"));
            System.out.println(nonterminal + " and " + "$" + " with production  " + production);
        }

    }
    public TreeNode parseInput(String Input) {
        this.input = Input + "$";
        this.stack = new Stack<>();
        this.stack.push("$");
        this.stack.push(G.getStartSymbol());

        Stack<TreeNode> treeStack = new Stack<>();
        TreeNode root = new TreeNode(G.getStartSymbol());
        treeStack.push(root);

        int i = 0;

        while (i != input.length() - 1 && stack.peek() != "$") {
            System.out.println("Stack: " + stack);
            String top = stack.pop();
            TreeNode currentNode = treeStack.pop();

            System.out.println("TreeStack: " + treeStack);
            System.out.println("Current Input: " + input.substring(i));

            if (G.getTerminals().contains(top) || top.equals("$")) {
                if (top.equals(input.substring(i, i + 1))) {
                    i++;
                } else {
                    System.out.println("Mismatch at terminal: " + top);
                    return null;
                }
            } else if (G.getNonterminals().contains(top)) {
                String currentInput = input.substring(i, i + 1);
                List<String> production = parsingTable.get(new AbstractMap.SimpleEntry<>(top, currentInput));

                if (production == null || production.isEmpty()) {
                    System.out.println("No production found for: " + top + " with input: " + currentInput);
                    return null;
                }

                System.out.println("Applying production: " + top + " -> " + production);

                if (production.size() == 1 && production.get(0).equals("epsilon")) {
                    currentNode.addChild(new TreeNode("epsilon"));
                } else {
                    List<TreeNode> children = new ArrayList<>();
                    List<String> reversedProduction = new ArrayList<>(production);
                    Collections.reverse(reversedProduction);

                    for (String symbol : reversedProduction) {
                        TreeNode childNode = new TreeNode(symbol);
                        stack.push(symbol);
                        treeStack.push(childNode);
                        children.add(childNode);
                    }

                    Collections.reverse(children);
                    for (TreeNode child : children) {
                        currentNode.addChild(child);
                    }
                }
            } else {
                System.out.println("Unexpected symbol: " + top);
                return null;
            }
        }

        if (i != input.length() - 1) {
            System.out.println("Input not fully consumed. Remaining: " + input.substring(i));
            return null;
        }

        return root;
    }

    public static void main(String[] args) {
        Parser p = new Parser();
        System.out.println("FIRST: " + p.first);
        System.out.println("FOLLOW: " + p.follow);
        p.printParsingTable();

        TreeNode parseTree = p.parseInput("adb");
        if (parseTree != null) {
            System.out.println("Parsing succeeded. Parsing tree:");
            parseTree.printTree("");
        } else {
            System.out.println("Parsing failed.");
        }
    }

}
class TreeNode {
    String value;
    List<TreeNode> children;

    public TreeNode(String value) {
        this.value = value;
        this.children = new ArrayList<>();
    }

    public void addChild(TreeNode child) {
        children.add(child);
    }

    public void printTree(String indent) {
        System.out.println(indent + value);
        for (TreeNode child : children) {
            child.printTree(indent + "  ");
        }
    }
}

