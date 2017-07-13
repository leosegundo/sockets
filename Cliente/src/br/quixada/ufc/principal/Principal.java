/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.quixada.ufc.principal;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import javax.swing.JOptionPane;

/**
 *
 * @author segundo
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String endereco;
      endereco =  JOptionPane.showInputDialog("Digite o endereço IP do servidor");
      TelaMain tela = new TelaMain(endereco);
      tela.setVisible(true);
    }
    
}
