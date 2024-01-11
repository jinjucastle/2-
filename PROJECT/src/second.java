                               
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.util.*;
import java.io.*;
import javax.imageio.*;


	

public  class second extends JFrame  implements KeyListener, Runnable{
	int speed;
	int bullet_Speed=5;
	int f_x=500; 
	static int f_y=800;
	int img_x=250;
	int img_y=700 ;
	int bx=1;
	int enemycnt=0;
	int skill=2;
	int skillcnt=0;
	int backGround2;
	boolean k_up=false;
	boolean k_down=false;
	boolean k_lift=false;
	boolean k_right=false;
	boolean k_ctrl=false;
	boolean k_t=false;
	boolean k_q=false;
	
	boolean player_status=true;
	int enemytime=0;
	//boolean cnt=true;
	int bgspeed=5;
	int game_score=0;
	int enemys;
	int player_h;
	int cntit=0;
	Thread th;
	Toolkit tool=Toolkit.getDefaultToolkit();
	Image img,firstImage;
	Image bullet_img;
	Image[] Enemy_img;
	Image BoseEnemy_img;
	Image Enemybullet_img;
	Image Background_img;
	Image Background_img2;
	Image item_img;
	Image lastImage;
	Image result_Img;
	Graphics buffg;
	Vector bullet=new Vector();
	Vector Enemy1=new Vector();
	Vector effect=new Vector();
	Vector enemy2=new Vector();
	Vector enemy3=new Vector();
	Vector Item1=new Vector();
	Bullet oper;
	Enemy power,tower,star;
	Effect ef;
	Item it;
	Random r=new Random();
	int backGround1;
	private int fps= 16;
	Image[] effect_img;
	sound s =new sound();
	public second () {
		init();

		//setUndecorated(true);
		
		setSize(f_x,f_y);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		addKeyListener(this);
		//setBackground(new Color(0,0,0,0));
		th=new Thread(this);
		th.start();
		Dimension screen = tool.getScreenSize();
		
		setLayout(null);
		setResizable(false);
		setLocationRelativeTo(null);
		
		setVisible(true);
		s.actionPerformed("지구방위본부.wav",player_status);
	}
	public void init() {
		enemys=2;
		
		player_h=3;
		speed=0;
		backGround1=0;
		backGround2=-800;
		effect_img=new Image[2];
		for( int i=0;i<effect_img.length;i++) {
			effect_img[i]=tool.getImage("effect"+i+".png");
		}
		img=tool.getImage("10.png");
		 bullet_img=tool.getImage("12-1.png");
		 //BoseEnemy_img=tool.getImage("enemy1.jpg");
		 Enemybullet_img=tool.getImage("12.png");
		 Background_img=tool.getImage("15.jpg");
		 Background_img2=tool.getImage("15.jpg");
		item_img=tool.getImage("50.png");
		Enemy_img=new Image[3];
		for (int i=0;i<Enemy_img.length;i++) {
				Enemy_img[i]=tool.getImage("enemy"+i+".png");
				
		}
		lastImage=tool.getImage("첫화면.jpg");
		result_Img=tool.getImage("결과창.png");
		
	}
	
	
	
	public void paint(Graphics g) {
		//super.paint(g);
		//g.clearRect(0, 0,f_x , f_y);
		//g.drawImage(img,img_x,img_y,100,100,null);
		
		firstImage=createImage(f_x,f_y);//이미지 객체 생성
		buffg=firstImage.getGraphics();//이미지객체의 그래픽스를 얻는다
		
		
				no_Buff(g);//ㅇ미시로 그림을 그린다
	}
	
	public void no_Buff(Graphics g) {//그림을 그리는 부분
		
		//paintComponents(g);
		Draw_Background();
		double_buff();
		
		paint_bullet();
		Enemy_paint();
		Draw_Effect();
		Draw_score();
		Draw_Item();
		if(player_status==false)
			finalscense();
			//이미지 객체를 출력한
		g.drawImage(firstImage,0,0,null);
	}
	public void double_buff() {//비행기? 의 이미지를 출력한다
		
		if(player_status)
		buffg.drawImage(img,img_x,img_y,null);
		
		for(int i=0;i<player_h;i++) {
			buffg.drawImage(img,400+20*i,700,null);
		}
		
	}
	public void paint_bullet() {//총알을 출력한다
		for(int i=0;i< bullet.size();i++) {
			oper=  (Bullet)bullet.elementAt(i);
			if(oper.bs==0)
			buffg.drawImage(bullet_img, oper.x, oper.y,this);
			if(oper.bs==1)
				buffg.drawImage(Enemybullet_img,oper.x,oper.y,this);
			//oper.move();
			}
		}
	
	public void Enemy_paint() {//적을 출력한다//특정적이 나타나면 아이템을 떨굼 그걸 먹으면  아이템 하낙 ㅏ증가하는 형식 으로 짜야 할듯
		
			
				for(int i=0;i<enemy2.size();i++) {//보스는 다른 어레이를 만들어서 enemy와 다르게 독자적으로 한다
					tower=(Enemy)enemy2.elementAt(i);
					 buffg.drawImage(Enemy_img[1],tower.x,tower.y,null);
					}
			
			
			for(int i=0;i<Enemy1.size();i++) {
			power=(Enemy)Enemy1.elementAt(i);
			
			 buffg.drawImage(Enemy_img[2],power.x,power.y,null);
				
			}
			for(int i=0;i<enemy3.size();i++) {
				star=(Enemy)enemy3.elementAt(i);
				
				 buffg.drawImage(Enemy_img[0],star.x,star.y,null);
					
				}
			
				
		
	}
	public void Draw_Background() {
		buffg.clearRect(0, 0, f_x, f_y);
		
		buffg.drawImage(Background_img,0,backGround1,f_x,f_y,this);
			buffg.drawImage(Background_img2,0,backGround2,f_x,f_y,this);
			
			
	}
	public void Draw_Effect() {
		for(int i=0;i<effect.size();i++) {
			ef=(Effect)effect.elementAt(i);
		if(ef.damage==0) {
			if ( ef.ex_cut < 5  ) {
				buffg.drawImage( effect_img[0], ef.x - 
				effect_img[0].getWidth(null) / 2, ef.y - 
				effect_img[0].getHeight(null) / 2, this);
				}else if ( ef.ex_cut < 10 ) {
				buffg.drawImage(effect_img[1], ef.x - 
				effect_img[1].getWidth(null) / 2, ef.y - 
				effect_img[1].getHeight(null) / 2, this);
				
				}
				else if( ef.ex_cut >10 ) {
				effect.remove(i);
				
				ef.ex_cut = 0;
		}
	}
		
	}
	}
	public void Draw_score() {
		buffg.setColor(Color.WHITE);
		buffg.setFont(new Font("Defualt",Font.BOLD,20));
	
		buffg.drawString("SCore: "+game_score,100,50);
		buffg.drawString("SKill: "+skill,10,780);
		
	}
	public void Draw_Item() {
		for(int i=0;i<Item1.size();i++) {
			it=(Item)Item1.elementAt(i);
			buffg.drawImage(item_img,it.x,it.y,null);
		}
	}
	
	public boolean clash(int x,int y,int x2,int y2,Image img1,Image img2) {
		boolean op=false;
		
		
		if(Math.abs((x+img1.getWidth(null)/2)-(x2+img2.getWidth(null)/2))
				<(img2.getWidth(null)/2+img1.getWidth(null)/2)
				&&Math.abs((y+img1.getHeight(null)/2)-(y2+img2.getHeight(null)/2))
			<(img2.getHeight(null)+img1.getHeight(null))) {
			
		
		
		op=true;
		}
		
		else
			op=false;
		return op;
	}
	
	
	
	
	public static void main(String[] args ) {
		new second();
	}
			

	@Override
	public void run() {
		// TODO Auto-generated method stub
		long sTime;
		long gapTime;
			while(true) {
		sTime=System.currentTimeMillis();
		
		try{
			
			if(player_status) {
				
				keymove();
				bulletmove();
				
			backgroundProcess();
			Enemymove();
			enemymove2();
			enemymove3();
			Effectmove();
			Itemmove();
			}
			
			
			repaint();
			gapTime=System.currentTimeMillis()-sTime;
			long newfps=(fps-gapTime<0?0:fps-gapTime);
			speed++;
			
			enemytime++;
			
				Thread.sleep(newfps);
					
			
	}catch(InterruptedException e) {
		return;
	}
			
			}
	}
		

	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		
		int KeyCode=e.getKeyCode();
		
		switch(KeyCode) {
		case KeyEvent.VK_UP:
			k_up=true;break;
			
		case KeyEvent.VK_DOWN:
			 k_down=true;break;
		case KeyEvent.VK_LEFT:
			 k_lift=true; break;
		case KeyEvent.VK_RIGHT:
			 k_right=true; break;
		case KeyEvent.VK_CONTROL:
			 k_ctrl=true; break;
		case KeyEvent.VK_T:
			k_t=true; break;
		case KeyEvent.VK_Q:
			k_q=true; break;
		}
	
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
int KeyCode=e.getKeyCode();
		
		switch(KeyCode) {
		case KeyEvent.VK_UP:
			k_up=false; break;
		case KeyEvent.VK_DOWN:
			 k_down=false;break;
		case KeyEvent.VK_LEFT:
			 k_lift=false; break;
		case KeyEvent.VK_RIGHT:
			 k_right=false; break;
		case KeyEvent.VK_CONTROL:
			k_ctrl=false; break;
		case KeyEvent.VK_T:
			k_t=false; 
			if(skill!=0) {
			skill-=1; skillcnt++;
			}
			break;
		case KeyEvent.VK_Q: 
			k_q=false; break;
		}
	}
public void keymove() {
	if(k_up==true&&img_y-20>0) img_y-=5;
	else if(k_down==true) {
		if(img_y+img.getHeight(null)<f_y)
			img_y+=5;
	}
	else if (k_lift==true&&img_x>0) 
		img_x-=5;
	else if (k_right==true) {
		if(img_x+img.getWidth(null)<f_x)
		img_x+=5;
	}
	if(skill!=0) {
	if(k_t==true) {
		
		for(int i=0;i<Enemy1.size();i++)
			enemycnt++;
			game_score+=10;
			
		
	
		for (int j=0;j<Enemy1.size();j++)
		{
			power=(Enemy)(Enemy1.get(j));
		ef=new Effect(power.x+Enemy_img[2].getWidth(null)/2,
				power.y+Enemy_img[2].getHeight(null)/2,0);
		effect.add(ef);
		}
		s.actionPerformed("폭발1.wav", false);
		Enemy1.clear();
		
	}
	
	}
	
	if(k_q==true) {
		
	
			player_status=false;
		}
	if(player_h==0)
		
		player_status=false;
}
	
public void bulletmove() {
	sound s =new sound();
	if(k_ctrl==true) {
		if(speed%bullet_Speed==0) {//조절해야됨
		oper=new Bullet(img_x+14,img_y,0,bx);
		bullet.add(oper);
		s.actionPerformed("레이저.wav",false);
		}
	}
	
		for(int i=0;i< bullet.size();i++) {
			oper=  (Bullet)bullet.elementAt(i);
			oper.move();
			if(oper.y>f_y) {
				bullet.remove(i);
			}
		
		
			/*if(clash(img_x,img_y,oper.x,oper.y,img,bullet_img)&&oper.bs==1){
				ef=new Effect(img_x,img_y,0);
				effect.add(ef);
				
				bullet.remove(i);
				
			}*/
			//s.actionPerformed("Gun.wav");
	
		for (int j=0;j<Enemy1.size();j++)
		{
			power=(Enemy)(Enemy1.get(j));
			
			if(clash(oper.x,oper.y,power.x,power.y,bullet_img,Enemy_img[2])&&oper.bs==0&&power.h!=0) {
				power.h-=bx;
				bullet.remove(i);
				if(power.h<=0) {
					s.actionPerformed("폭발1.wav", false);
				Enemy1.remove(j);
				enemycnt++;
				game_score+=10;
				ef=new Effect(power.x+Enemy_img[2].getWidth(null)/2,
						power.y+Enemy_img[2].getHeight(null)/2,0);
				effect.add(ef);
				
			
				}
			}
		
}		
		
		}
		for(int i=0;i< bullet.size();i++) {
			oper=  (Bullet)bullet.elementAt(i);
		for (int j=0;j<enemy2.size();j++)
		{
			tower=(Enemy)(enemy2.get(j));
			
			if(clash(oper.x,oper.y,tower.x,tower.y,bullet_img,Enemy_img[1])&&oper.bs==0&&tower.h!=0) {
				
					tower.h-=bx;
					bullet.remove(i);
					if(tower.h<=0) {
				enemy2.remove(j);
				enemycnt++;
				
				game_score+=2000;
				ef=new Effect(tower.x+Enemy_img[2].getWidth(null)/2,
						tower.y+Enemy_img[2].getHeight(null)/2,0);
				effect.add(ef);
				
				
				
					}
			}
		}
		}
		
		
		
}
public void Enemymove() {
	int a=2;
	for(int i=0; i<Enemy1.size();i++) {
		power=(Enemy)(Enemy1.elementAt(i));
		power.move();
		
		if(clash(img_x,img_y,power.x,power.y,img,Enemy_img[enemys])) {
			Enemy1.remove(i);
			ef=new Effect(power.x+Enemy_img[2].getWidth(null)/2,
					power.y+Enemy_img[2].getHeight(null)/2,0);
			effect.add(ef);
			player_h--;
			 
			
		}
		
	
		if(power.y>f_y) {
			Enemy1.remove(i);
		}
	}
	if(player_h==0) {
		
		player_status=false;
	}
	
	
	if(enemytime>100&&(enemytime%90==0||r.nextInt(10)==5&&enemytime%45==0)) {
	
		for(int i=1;i<=5;i++) {
		power=new Enemy(i*76,-20*r.nextInt(5),a);
		Enemy1.add(power);
		
		}
	}
	if(enemytime>100&&enemytime%1300==0)
		a+=2;
		
}
public void enemymove2() { //느린적
	for(int i=0; i<enemy2.size();i++) {
		tower=(Enemy)(enemy2.elementAt(i));
		tower.move2();
		
		if(clash(img_x,img_y,tower.x,tower.y,img,Enemy_img[1])) {
			enemy2.remove(i);
			ef=new Effect(tower.x+Enemy_img[1].getWidth(null)/2,
					tower.y+Enemy_img[1].getHeight(null)/2,0);
			effect.add(ef);
			
			player_h--;
			
		}
				
				
		
		if(tower.y>f_y) {
			player_h--;
			enemy2.remove(i);
			
		}
			
	
	
	}
	if(player_h==0) {
		
		player_status=false;
	}
	
	 if(enemytime>0&&enemytime%600==0) {
		
			tower=new Enemy(30+r.nextInt(f_x-80),0,100);
			enemy2.add(tower);
			
		}
	
	
}
public void enemymove3() {//별똥별
	for(int i=0; i<enemy3.size();i++) {
		star=(Enemy)(enemy3.elementAt(i));
		star.move3();
		
		
				
		if(star.y>f_y) {
			enemy3.remove(i);
		}
			
	if(clash(img_x,img_y,star.x,star.y,img,Enemy_img[0])) {
		player_h--;
	}
	
	}
	
	
	 if(enemytime>100&&enemytime%700==0) {
		 
			star=new Enemy(30+r.nextInt(f_x-80),0,0);
			enemy3.add(star);
			
		}
	
}
public void Itemmove() {
	
	for (int i=0;i< Item1.size();i++) {
		it=(Item)Item1.elementAt(i);
		it.move();
	
	if(clash(img_x,img_y,it.x,it.y,img,item_img)) {
		
		if(cntit==1) {
		s.actionPerformed("해비머신건.wav", false);
		bullet_img=tool.getImage("14-1.png");
		}
		else if(cntit>=2) {
			s.actionPerformed("오케이.wav", false);
			skill++;
		}
			bx++;
			Item1.remove(i);
			game_score+=20;
	}
	}
	if(enemytime>100&&enemytime%500==0) {
		it= new Item(30+r.nextInt(f_x-80),0);
		cntit++;
		Item1.add(it);
		
		
	}
	
}
public void Effectmove() {
	for(int i=0;i<effect.size();i++) {
		ef=(Effect)effect.elementAt(i);
		ef.count();
				
	
	
	}
}

public void backgroundProcess(){

	
	backGround1+=bgspeed;
	backGround2+=bgspeed;
	if(backGround1>=f_y)
		backGround1=-f_y+backGround1%f_y;
	if(backGround2>=f_y)
		backGround2=-f_y+backGround2%f_y;

}



public void gameover() {
	
		s.stop();
		
		
	}
	
public void finalscense() {
	
	
	buffg.clearRect(0, 0, f_x, f_y);
	
	buffg.drawImage(result_Img,0,0,null);
	buffg.setColor(Color.WHITE);
	buffg.setFont(new Font("Defualt",Font.BOLD,20));
	buffg.drawString("점수:   "+game_score,150,350);
	buffg.drawString("폭탄사용횟수:   "+skillcnt,150,400);
	buffg.drawString("적처치 횟수:   "+enemycnt,150,450);
	buffg.drawString("제작자: 이주현",200,600);
	buffg.setFont(new Font("Defualt",Font.BOLD,15));
	buffg.drawString("제작자 메일 :guswlwl22@naver.com",130 ,650);
	buffg.drawString("버그있으면 메일 보내주세요",170,690);
	
	
}

class Bullet{
	int x;
	int y;
	int bs;
	int type;
	public Bullet(int x,int y,int bs,int type) {
		this.x=x;
		this.y=y;
		this.bs=bs;
	}
	public void move() { 
		if(bs==0)
		y-=10;
	
	}
	
}
class Enemy{
	int x;
	int y;
	int h;
	
	public Enemy(int x,int y,int h){
		this.x=x;
		this.y=y;
		this.h=h;
	}
	public void move() {
		y+=3;
	}
	public void move2() {
		y+=1;
	}
	public void move3() {
		y+=10;
	}
}
class Effect {
	public int ex_cnt;
	int x;
	int y;
	int ex_cut;
	int damage;
	Effect(int x,int y,int damage){
		this.x=x;
		this.y=y;
		this.damage=damage;
		ex_cut=0;
	}
	
public void count() {
	ex_cut++;
}
}
class Item{
	int x,y;
	int vx,vy;
	int cnt=0;
	public Item(int x,int y) {
		this.x=x;
		this.y=y;
		
		}
	public void move() {
		if(cnt==0) {
		x+=2;
		y+=3;
				
				
		
		}
		
		
		else if (cnt==1) {
			x-=2;
			y+=3;
			
		}
		else if (cnt==2) {
			x-=2;
			y-=3;
		}
		else if (cnt==3) {
			x+=2;
			y-=3;
		}
		if(x+item_img.getWidth(null)+50>=f_x)
			cnt=1;
		else if(y+item_img.getHeight(null)+50>=f_y)
			cnt=2;
		else if(x<=0)
			cnt=3;
		else if (y-20<=0)
			cnt=0;
		
		
	}
}
}
