
//
// Copyright (c) Carlos Tojal 2020
// ExemplosGUI
// DisplayImage.java
//

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class DisplayImage {
    static String IMG_PATH = "Imagem.jpg";

    public static void main(String[] args) throws IOException {
        JFrame frame = new JFrame();

        BufferedImage img = ImageIO.read(new File(IMG_PATH));
        ImageIcon icon = new ImageIcon(img);
        JLabel label = new JLabel(icon);

        frame.add(label);
        frame.setExtendedState(frame.getExtendedState() | JFrame.MAXIMIZED_BOTH);
        frame.setVisible(true);
    }
}