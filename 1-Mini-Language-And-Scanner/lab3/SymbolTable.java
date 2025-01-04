package lab3;
import java.util.AbstractMap.SimpleEntry;


public class SymbolTable {

    private HashTable<String,String> symbolTable = new HashTable<>();

    public SymbolTable() {
    }

    public void addSymbol(String name) {
        symbolTable.put(name, "");
    }

    public SimpleEntry<String, String> getSymbol(String name) {
        return symbolTable.get(name);
    }

    public void removeIdentifier(String name) {
        symbolTable.remove(name);
    }

    public int[] getPosition(String name) {
        return symbolTable.getPosition(name);
    }

    public HashTable<String, String> getSymbolTable() {
        return symbolTable;
    }

}


