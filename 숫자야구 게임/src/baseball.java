import java.util.Random;
import java.util.Scanner;
public class baseball {
public static void main(String args[]) {
	int com[]= new int[3];
	int man[]=new int [3];
	Random R=new Random();
	Scanner s=new Scanner(System.in);
	
	for(int i=0;i<com.length;i++) {
		com[i]=1+R.nextInt(9);
		for(int a = 0;a<i;a++) {
			if(com[i]==com[a])
				i--;
		}
	}
		System.out.println("���� �߱��� �����մϴ�.");
		
		int stack=0;
		while(true) {
			System.out.println("���� 3���� �Է��ϼ���");
			int total=s.nextInt();
			int num1=total/100;
			int num2=(total/10)%10;
			int num3=total%10;
			int user[]= {num1,num2,num3};
			for(int c=0;c<man.length;c++) {
				man[c]=user[c];
			}
			int str = 0;
			int ball=0;
			
			for(int p=0;p<com.length;p++) {
				for(int k=0;k<man.length;k++) {
					if(com[p]==man[k])
					{
						if(p==k) {
							str++;
							
						}
						else {
							ball++;
						}
						
						}
					}
				}
			stack++;
			System.out.println(str + "��Ʈ����ũ" + ball+ "��");
			if(str==3) {
				System.out.println("you win");
				System.out.println(stack+"�� �õ��ϼ̽��ϴ�");
				break;
			}
		}
		
		s.close();
	}
}

