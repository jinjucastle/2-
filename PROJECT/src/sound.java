
import javax.sound.sampled.*;
	import java.awt.event.*;

	import java.io.*;

	public class sound implements ActionListener{


	@SuppressWarnings("deprecation")
	
	Clip clip;

		
	public void actionPerformed(String std,boolean loop) {
		// TODO Auto-generated method stub
		
			try {
			AudioInputStream audioInputStream=AudioSystem.getAudioInputStream(new File(std));
			 clip = AudioSystem.getClip();	
			clip.open(audioInputStream);
			clip.start();
			if(loop)clip.loop(-1);
			
				
			
		}
			catch(Exception ex) {
			System.out.println("Error with playing sound.");
			ex.printStackTrace();
			}
	}

	
	public void stop() {
		clip.stop();
		clip.close();
	}
	

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
	}
	
	}