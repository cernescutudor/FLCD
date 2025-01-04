package lab3;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.ArrayList;
import java.util.AbstractMap.SimpleEntry;
import java.util.regex.Pattern;
import java.util.LinkedList;
import finiteautomata.FiniteAutomat;


public class Scanner {

    private FiniteAutomat DFA;
    private SymbolTable identifierTable = new SymbolTable();
    private SymbolTable constantTable = new SymbolTable();

    public ArrayList<String> separators = new ArrayList<>();
    public ArrayList<String> operators = new ArrayList<>();
    public ArrayList<String> reservedWords = new ArrayList<>();

    private ArrayList<SimpleEntry<String, int[]>> PIF = new ArrayList<>();

    private BufferedReader sourceReader;
    private BufferedReader tokenReader;

    private int identifiersID;
    private int constantsID;

    private int currentLine = 0;
    private Boolean lexicalCorrect = true;

    public Scanner(String tokenFile, String sourceFile) {

        DFA = new FiniteAutomat("2-Finite-Automata/finiteautomata/FA.in");
        try { 
            this.tokenReader = new BufferedReader(new FileReader(tokenFile));
            this.sourceReader = new BufferedReader(new FileReader(sourceFile));
            this.ReadTokens();
            this.identifiersID = this.separators.size() + this.operators.size() + this.reservedWords.size() + 3;
            this.constantsID = this.identifiersID + 1;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addIdentifierPIF(String token) {
        int[] position = identifierTable.getPosition(token);
        PIF.add(new SimpleEntry<>(token, new int[] { identifiersID, position[0], position[1] }));
    }

    public void addConstantPIF(String token) {
        int[] position = constantTable.getPosition(token);
        PIF.add(new SimpleEntry<>(token, new int[] { identifiersID, position[0], position[1] }));
    }

    public void addPIF(String token) {
        if (this.separators.contains(token)) {

            int position = this.separators.indexOf(token) + 1;
            PIF.add(new SimpleEntry<>(token, new int[] { position, -1 }));

        } else if (this.operators.contains(token)) {

            int position = this.operators.indexOf(token);
            position += this.separators.size() + 2;

            PIF.add(new SimpleEntry<>(token, new int[] { position, -1 }));
        } else if (this.reservedWords.contains(token)) {

            int position = this.reservedWords.indexOf(token);
            position += this.separators.size() + this.operators.size() + 3;
            PIF.add(new SimpleEntry<>(token, new int[] { position, -1 }));

        }

    }

    public void ReadTokens() {
        // For this to work, the token file must have the following structure:
        // 1. Separators
        // 2. Operators
        // 3. Reserved words
        // Each section must be separated by an empty line
        try {
            String line;
            int section = 0; // 0: separators, 1: operators, 2: reserved words

            while ((line = tokenReader.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) {
                    section++;
                    continue;
                }

                switch (section) {
                    case 0:
                        separators.add(line);
                        break;
                    case 1:
                        operators.add(line);
                        break;
                    case 2:
                        reservedWords.add(line);
                        break;
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public void writePIF() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("1-Mini-Language-And-Scanner/lab3/PIF.out"))) {
            for (SimpleEntry<String, int[]> entry : PIF) {
                if(entry.getValue().length == 3) {
                    writer.write(entry.getKey() + " -> " + entry.getValue()[0] + " -> (" + entry.getValue()[1] + ", " + entry.getValue()[2] + ")");
                    writer.newLine();
                } else {
                    writer.write(entry.getKey() + " -> " + entry.getValue()[0] + " -> " + entry.getValue()[1]);
                    writer.newLine();
                }

            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void writeTables() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("1-Mini-Language-And-Scanner/lab3/ST.out"))) {

            LinkedList<Node<String, String>>[] symbolTable1 = identifierTable.getSymbolTable().getTable();
            LinkedList<Node<String, String>>[] symbolTable2 = constantTable.getSymbolTable().getTable();

            writer.write("Identifiers");
            writer.newLine();

            for (int i = 0; i < 10; i++) {
                if (symbolTable1[i] != null) {
                    for (Node<String, String> node : symbolTable1[i]) {
                        int[] position = identifierTable.getPosition(node.key);
                        writer.write(node.key + " -> " + identifiersID + " -> (" + position[0] + ", " + position[1] + ")");
                        writer.newLine();
                    }
                }
            }

            writer.write("Constants");
            writer.newLine();

            for (int i = 0; i < 10; i++) {
                if (symbolTable2[i] != null) {
                    for (Node<String, String> node : symbolTable2[i]) {

                        int[] position = constantTable.getPosition(node.key);
                        writer.write(node.key + " -> " + constantsID + " -> (" + position[0] + ", " + position[1] + ")");
                        writer.newLine();

                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String addSpaces(String line) {
        for (String separator : separators) {
            line = line.replace(separator, " " + separator + " ");
        }

        for (String operator : operators) {
            line = line.replace(operator, " " + operator + " ");
        }

        // for (String reservedWord : reservedWords) {
        // line = line.replace(reservedWord, " " + reservedWord + " ");
        // }

        return line;
    }

    public Boolean isIdentifier(String token) {
        // return Pattern.matches("^_[a-zA-Z][a-zA-Z0-9]*", token);
        return DFA.isIdentifier(token);
    }

    public Boolean isIntConstant(String token) {
        // return Pattern.matches("^0|[+-]?[1-9][0-9]*$", token);
        return DFA.isIntConstant(token);
    }

    public Boolean isBoolConstant(String token) {
        return Pattern.matches("^(true|false)$", token);
    }

    public Boolean isCharConstant(String token) {
        return Pattern.matches("^'.'$", token);
    }

    public void Scan() {
        try {
            String line;
            while ((line = sourceReader.readLine()) != null) {
                currentLine++;
                if (!line.isEmpty()) {

                    line = addSpaces(line);
                    // Split the line into tokens
                    String[] tokens = line.trim().split("\\s+");

                    // Parse the tokens
                    for (String token : tokens) {
                        if (token.isEmpty()) {
                            continue;
                        }
                        if (separators.contains(token)) {
                            this.addPIF(token);

                        } else if (operators.contains(token)) {
                            this.addPIF(token);

                        } else if (reservedWords.contains(token)) {
                            this.addPIF(token);

                        } else {
                            if (isIdentifier(token)) {
                                identifierTable.addSymbol(token);
                                this.addIdentifierPIF(token);

                            } else if (isIntConstant(token)) {
                                constantTable.addSymbol(token);
                                this.addConstantPIF(token);

                            } else if (isBoolConstant(token)) {
                                constantTable.addSymbol(token);
                                this.addConstantPIF(token);

                            } else if (isCharConstant(token)) {
                                constantTable.addSymbol(token);
                                this.addConstantPIF(token);

                            } else {
                                System.out.println("Unknown token " + token + " found on line " + currentLine);
                                lexicalCorrect = false;
                            }
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (lexicalCorrect) {
                System.out.println("Lexically correct");
            } else {
                System.out.println("Lexically incorrect");
            }
        }
    }

}
