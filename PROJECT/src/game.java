

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class game {
public static void main(String[] ar){
game_Frame fms = new game_Frame();
}
}

class game_Frame extends JFrame {
	private static int x=500;
	private static int y=800;
	private Image img;
	private Graphics buffg;
	int mousx,mousy;
	Image img2;
		Toolkit tool=Toolkit.getDefaultToolkit();
	JLabel startbutton,endbutton; 
	public game_Frame() {
		setUndecorated(true);
		img=tool.getImage("첫화면1.png");
		
		startbutton=new JLabel("start");
		endbutton=new JLabel("종료");
		setTitle("테스트용");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		startbutton.setFont(new Font("Defualt",Font.BOLD,20));
		startbutton.setForeground(new Color(0x00688a));
		startbutton.setBounds(225, 500, 200, 100);
		startbutton.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				second s=new second();
			}
		
		});
		add(startbutton);
		endbutton.setFont(new Font("Defualt",Font.BOLD,20));
		endbutton.setForeground(new Color(0x00688a));
		endbutton.setBounds(225, 600, 200, 100);
		endbutton.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				System.exit(0);
			}
		
		});
		add(endbutton);
		
		setBackground(new Color(0,0,0,0));
		setSize(x,y);
		setLocationRelativeTo(null);
		setResizable(false);
		setVisible(true);
	
	}
	public void paint(Graphics g) {
		img2=createImage(x,y);
		buffg=img2.getGraphics();
		
		updata(buffg);
		g.drawImage(img2,0,0,null);
	}
	public void updata(Graphics g) {
		g.drawImage(img,0,0,null);
		paintComponents(g);
		this.repaint();
		
		
	}
	
		
		
	
}
	
	
	


	
