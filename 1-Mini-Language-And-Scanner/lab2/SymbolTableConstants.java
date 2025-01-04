package lab2;


public class SymbolTableConstants {

    private HashTable<String, String[]> symbolTable = new HashTable<>();

    public SymbolTableConstants() {
      
    }


    public void addConstant(String name, String type, String value) {
        symbolTable.put(name, new String[]{type, value});
    }

    public String[] getConstant(String name) {
        return symbolTable.get(name);
    }

    public int[] getPosition(String name) {
        return symbolTable.getPosition(name);
    }
    

    public void removeConstant(String name) {
        symbolTable.remove(name);
    }

}