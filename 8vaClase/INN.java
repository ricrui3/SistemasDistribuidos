public class INN {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String megaCadena="";
        String miniCadena="IPN";
        int i = 0, j = 0;

        for (i = 0; i <17576 ; i++) {
            for(j = 0; j < 3; j++){
                char aux=(char)((Math.random()*25)+65);
                megaCadena+=aux;
            }
            megaCadena+=" ";
        }
        System.out.println(megaCadena.contains(miniCadena));
    }    
}


