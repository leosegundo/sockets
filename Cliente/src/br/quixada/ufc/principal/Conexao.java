package br.quixada.ufc.principal;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import javax.swing.JOptionPane;

public class Conexao {
    
    public void conecta(String serverAdress, String valor){
         try{
            //JOptionPane.showMessageDialog(null, serverAdress);
            Socket s = new Socket(serverAdress,33333);
            InputStream i = s.getInputStream();
            OutputStream o = s.getOutputStream();
            
            byte[] line =  new byte[100];
            char[] array;
            array = valor.toCharArray();		
            
            o.write(array[0]);
            
            i.read(line);
            String str = new String(line);
            JOptionPane.showMessageDialog(null, str.trim());
            
            s.close();
		
        }catch (Exception e) {
            JOptionPane.showMessageDialog(null, "Server não encontrado");
        }
        
    }
  
    
}
    
