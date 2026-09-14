/**
 * @author Professor da disciplina (exemplo de aula)
 */
public class TryCatch {

    public static void main(String[] args) {
        excecao();
        System.out.println("main");
    }
    
    public static int excecao(){
        try{
            int n = 7/0;
            System.out.println("try");
        }
        catch(Exception e){
            System.out.println("catch");
            return 0;
        }
        finally{
            System.out.println("finally");
        }
        System.out.println("fora try");
        return 0;
    }
    
}