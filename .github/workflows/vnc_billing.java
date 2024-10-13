package com.vnc_billing;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class VNC_Users extends JFrame implements ActionListener {
    
    public String yk_un = "vnc001";
    public String ram_un = "vnc002";
    public String sun_un = "vnc003";
    public String prm_un = "vnc004";
    private JLabel jl11;
    private JButton jb1, jb2, jb3, jb4;
    private ImageIcon i1;
    private Font f1, f2;

    public VNC_Users() {
        i1 = new ImageIcon("C:\\Users\\vinee\\OneDrive\\Pictures\\Saved Pictures\\Register.jpg");
        f1 = new Font("Bookman Old Style", Font.PLAIN, 18);
        f2 = new Font("Calibri (Body)", Font.PLAIN, 16);
        
        jb1 = createButton("YKS");
        jb2 = createButton("RAMESH");
        jb3 = createButton("SUNITHA");
        jb4 = createButton("PRANITHA");

        jl11 = new JLabel(i1);
        
        setLayout(null);
        
        setButtonBounds();
        jl11.setBounds(0, 0, 1366, 786);
        
        addButtons();
    }

    private JButton createButton(String text) {
        JButton button = new JButton(text);
        button.setFont(f2);
        button.setBackground(Color.blue);
        button.setForeground(Color.white);
        button.addActionListener(this);
        return button;
    }

    private void setButtonBounds() {
        jb1.setBounds(600, 200, 120, 30);
        jb2.setBounds(600, 300, 120, 30);
        jb3.setBounds(600, 400, 120, 30);
        jb4.setBounds(600, 500, 120, 30);
    }

    private void addButtons() {
        add(jb1);
        add(jb2);
        add(jb3);
        add(jb4);
        add(jl11);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals(jb1)) {
            openLoginPage();
        } else {
            // Display a consistent error message for unimplemented buttons
            showMessage("Action not implemented for this button.");
        }
    }

    private void openLoginPage() {
        VNC_Users_Loginpage loginPage = new VNC_Users_Loginpage();
        loginPage.setTitle("VNC_Users_Loginpage");
        loginPage.setFont(new Font("TimesRoman", Font.ITALIC, 20));
        loginPage.setSize(1366, 786);
        loginPage.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        loginPage.setVisible(true);
    }

    /**
     * Displays a message dialog with the given message.
     * This method is used to provide feedback to the user.
     */
    private void showMessage(String message) {
        JOptionPane.showMessageDialog(this, message);
    }
}
