public class Bissexto {
    public boolean verificarBissexto(int ano) {
        if(ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))
            return true;
        else
            return false;
    }
}