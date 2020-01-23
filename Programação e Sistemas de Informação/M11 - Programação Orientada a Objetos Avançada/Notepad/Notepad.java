
//
// Copyright (c) Carlos Tojal 2020
// Notepad
// Notepad.java
//

import javax.swing.*;
import java.awt.Toolkit;
import java.awt.event.*;

public class Notepad implements ActionListener{

    JFrame f;
    JMenuBar mb;
    JMenu file,edit,help;
    JMenuItem newOption, save, open, exit;
    JMenuItem cut,copy,paste,selectAll;
    JFileChooser fc = new JFileChooser();
    JMenuItem about;
    JTextArea ta;

    public Notepad(){
        f=new JFrame();

        newOption = new JMenuItem("New");
        save = new JMenuItem("Save");
        open = new JMenuItem("Open");
        exit = new JMenuItem("Exit");

        newOption.setAccelerator(KeyStroke.getKeyStroke('N', Toolkit.getDefaultToolkit ().getMenuShortcutKeyMask()));

        cut=new JMenuItem("Cut");
        copy=new JMenuItem("Copy");
        paste=new JMenuItem("Paste");
        selectAll=new JMenuItem("Select All");

        about = new JMenuItem("About");

        newOption.addActionListener(this);
        save.addActionListener(this);
        open.addActionListener(this);
        exit.addActionListener(this);

        cut.addActionListener(this);
        copy.addActionListener(this);
        paste.addActionListener(this);
        selectAll.addActionListener(this);

        about.addActionListener(this);

        mb = new JMenuBar();
        mb.setBounds(5,5,400,40);

        file = new JMenu("File");
        edit = new JMenu("Edit");
        help = new JMenu("Help");

        file.add(newOption);
        file.add(save);
        file.add(open);
        file.add(exit);

        edit.add(cut);
        edit.add(copy);
        edit.add(paste);
        edit.add(selectAll);

        help.add(about);

        mb.add(file);
        mb.add(edit);
        mb.add(help);
        
        ta = new JTextArea();
        ta.setBounds(5,30,460,460);

        f.add(mb);f.add(ta);

        f.setLayout(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(500,500);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == save)
            fc.showSaveDialog(null);
        else if(e.getSource() == open)
            fc.showOpenDialog(null);
        else if(e.getSource() == cut)
            ta.cut();
        else if(e.getSource() == paste)
            ta.paste();
        else if(e.getSource() == copy)
            ta.copy();
        else if(e.getSource() == selectAll)
            ta.selectAll();
        else if(e.getSource() == about)
            JOptionPane.showMessageDialog(null, "Developed by Carlos Tojal", "About", JOptionPane.DEFAULT_OPTION);

    }

    public static void main(String[] args) {
        new Notepad();
    }
}