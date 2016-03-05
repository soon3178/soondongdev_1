#include "glut.h"
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


float x0 = 8., y0 = -50., z0 = 75.;
float xref = -8., yref = 50., zref = -75.;
float Vx = 0., Vy = 1., Vz = 3.;
float incrementX=0.5;
float incrementY=0.5;
float tt=0;
int i=0;
int score=0;
float pp=0.3;
int move=2;
int direction =1;//공의 초기방향
//////////////////////아이템
float dd = 0;
int itemgo = 0;
float ii =0 ;
/////////////////////////////



//////////////움직이는 공
struct ball
{
	float x,y;
};
ball playball;
GLuint regHex1;
///////////////////////////////////////////////////////////움직이는 바
struct bar
{
	float x,y;
};
bar bar1;
GLuint regHex2;
GLuint regHex20;
//////////////////////////////////////////////////////////움직이는 블럭
float bart=0;
int r=0;
struct Block
{
	float x;
	float y;
};
Block BB[3];
Block *BP=BB;
/////////////블록에 필요한 변수 및 초기값.
int direction1=direction2=direction3=1;//벽돌의 초기방향
float incrementX1=incrementX3=0.3;//벽돌의 x축으로의 증가량
float incrementX2=-0,3; //벽돌의 x축으로의 증가량
GLuint regHex3;//1번벽돌이 저장될 변수이름
GLuint regHex4;//2번벽돌이 저장될 변수이름
GLuint regHex5;//31번벽돌이 저장될 변수이름
//////////////////


float incrementX2=-0.3;

//////////////////////////////세번 째 꺼
float incrementX3=0.3;

/////////////////////////////아이템
int num1=0;
int num2=0;
int num3=0;
int num4=0;

int item1 =0;
int item2 =0;
int item3 =0;
int item4 =0;

struct itemball
{
	float x;
	float y;
};
itemball itm1;
itemball itm2;
itemball itm3;
itemball itm4;

GLuint regHex6;
GLuint regHex7;
GLuint regHex8;
GLuint regHex9;

void init_re()
{
	incrementX=0.5;
	incrementY=0.5;
	tt=0;
	///////////////////공 좌표 초기화
	playball.x =25;
	playball.y =11;
	///////////////////바 좌표 초기화 
	bar1.x =25;
	bar1.y =9;
	/////////////////첫번째 블록 초기화
	BP[0].x  =4;
	BP[0].y =57;
	/////////////////두번째 블록 초기화
	BP[1].x =40; 
	BP[1].y =53;
	/////////////////세번째 블록 초기화
	BP[2].x =24; 
	BP[2].y =49;

	pp=0.3;
	dd = 0;
	itemgo = 0;
	ii =0 ;

	direction =1;
	score=0;//스코어계산을 위한.
	item1=item2=item3=item4=0;
	itm1.y = itm2.y =itm3.y =itm4.y =-100;

} 



////////////////////////////////////////////
void init (void)
{
	glClearColor( 1.0, 1.0, 1.0, 0.0 );
 
 //////////////////////////////////////////////움직이는 공
	regHex1 = glGenLists (1);
	glNewList( regHex1, GL_COMPILE_AND_EXECUTE );
	glColor3f(0.3, 0.5, 0.3);
	glutWireCube(1);
	glFlush();
//	glutSolidCube(1);
	glEndList();
 //////////////////////////////////////////////
 
 //////////////////////////////////////////////움직이는 바
	regHex2 = glGenLists (1);
	glNewList( regHex2, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.0, 0.0);  
	glScalef(6, 2, 2);   
    glLineWidth(2);
	glutWireCube(1);
	glColor3f(1.0, 0.0, 0.0);
//	glutSolidCube(1);
	glEndList();
	//////////////////////////////////////////////

	/////////////////////////////////////////아이템 적용시 움직이는 바
	regHex20 = glGenLists (1);
	glNewList( regHex20, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.0, 0.0);  
	glScalef(10, 2, 2);   
	glLineWidth(2);
	glutWireCube(1);
	//glutSolidCube(1);
	glEndList();
	//////////////////////////////////////////////

	//////////////////////////////////////////////움직이는 블록1
	regHex3 = glGenLists (1);
	glNewList( regHex3, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 1.0, 0.0);  
	glScalef(6, 2, 2);
	glLineWidth(2);
	glutWireCube(1);
	glColor3f(0.0, 0.0, 1.0);
//	glutSolidCube(1);
	glEndList();
	//////////////////////////////////////////////

	//////////////////////////////////////////////움직이는 블록2
	regHex4 = glGenLists (1);
	glNewList( regHex4, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.0, 1.0);  
	glScalef(6, 2, 2);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////

	//////////////////////////////////////////////움직이는 블록3
	regHex5 = glGenLists (1);
	glNewList( regHex5, GL_COMPILE_AND_EXECUTE );
	glColor3f(0.0, 1.0, 1.0);  
	glScalef(6, 2, 2);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////

	//////////////////////////////////////////////움직이는 아이템1
	regHex6 = glGenLists (1);
	glNewList( regHex6, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.5, 0.5);  
	glScalef(0, 0, 0);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////


	//////////////////////////////////////////////움직이는 아이템2
	regHex7 = glGenLists (1);
	glNewList( regHex7, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.5, 0.5);  
	glScalef(1, 1, 0);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////
	
	//////////////////////////////////////////////움직이는 아이템3
	regHex8 = glGenLists (1);
	glNewList( regHex8, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.5, 0.5);  
	glScalef(1, 1, 0);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////

	//////////////////////////////////////////////움직이는 아이템3
	regHex9 = glGenLists (1);
	glNewList( regHex9, GL_COMPILE_AND_EXECUTE );
	glColor3f(1.0, 0.5, 0.5);  
	glScalef(1, 1, 0);   
	glLineWidth(2);
	glutWireCube(1);
//	glutSolidCube(1);
	glEndList();
	///////////////////////////////////////////////
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
	glMatrixMode( GL_PROJECTION );
	glOrtho( 0, 50, 0, 60, -10, 300);
	//////////////////////////////////////////////////////
	
	///////////////////공 좌표 초기화
	playball.x =25;
	playball.y =11;
	///////////////////바 좌표 초기화 
	bar1.x =25;
	bar1.y =9;
	/////////////////첫번째 블록 초기화
	BP[0].x  =4;
	BP[0].y =57;
	/////////////////두번째 블록 초기화
	BP[1].x =40; 
	BP[1].y =53;
	/////////////////세번째 블록 초기화
	BP[2].x =24; 
	BP[2].y =49;


	//////////////////////////////////////아이템 좌표 초기화
	itm1.x =-100;
	itm1.y =-100;
	itm2.x =-100;
	itm2.y =-100;
	itm3.x =-100;
	itm3.y =-100;
	itm4.x =-100;
	itm4.y =-100;

}

void show_game_over()
{
	//1. 게임오버 텍스트 출력

	glColor3f(0.2 , 0.7, 0.5);
	GLubyte label[9] = {'G', 'A', 'M', 'E', ' ', 'O', 'V', 'E', 'R'};	
	int k=0;	//좌표점증변화를 위한 임시변수	

	for(int i=0; i<9; i++)
	{
		glRasterPos2i( 10+k, 40 );		
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, label[i]);
		k+=3;
	}

	//2. 스코어 텍스트 출력
	glColor3f(0.2 , 0.5, 0.2);
	GLubyte label2[6] = {'S', 'C', 'O', 'R', 'E', ':'};
	k=0;	
	for(i=0; i<6; i++)
	{
		glRasterPos2i( 10+k, 35);
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, label2[i]);
		k+=3;
	}

	//3. 스코어를 연산한후 itoa(정수형->문자형)를 이용하여 점수를 출력
	
	int string_size =1;
	if(score >= 0 && score < 10)
	{
		string_size=1;
	}
	else if(score >= 10 && score < 100)
	{
		string_size=2;
	}
	else if(score >= 100 && score < 1000)
	{
		string_size=3;
	}
	else 
	{
		string_size=3;
		score=999;
	}
	char *score_ch= new char [string_size];

	itoa(score, score_ch, 10);	
	GLubyte label3[100];
	for(int z=0; z<string_size; z++)
	{
		label3[z] = *(score_ch+z);
		glRasterPos2i( 10+k, 35);
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, label3[z]);
		k+=3;
	}

}

void displayHex( void )
{
	srand((unsigned int)time(NULL));
	glClear( GL_COLOR_BUFFER_BIT );
	if(playball.y<bar1.y)
	{
	glutIdleFunc( NULL );
	show_game_over(); }

	//////////////////////////////////////움직이는 공
	glPushMatrix();
	glTranslatef( playball.x, playball.y, 0.0 );
	glCallList( regHex1 );
	glPopMatrix();
	//////////////////////////////////////
	if( ii == 0)
	{
		//////////////////////////////////////움직이는 바
		glPushMatrix();
		glTranslatef( bar1.x  ,bar1.y, 0.0 );
		glCallList( regHex2 );
		glPopMatrix();
		//////////////////////////////////////
	}
	else if (ii ==4)
	{
		//////////////////////////////////////움직이는 긴 바
		glPushMatrix();
		glTranslatef( bar1.x  ,bar1.y, 0.0 );
		glCallList( regHex20 );
		glPopMatrix();
		/////////////////////////////////////
	}
	//////////////////////////////////////움직이는 블록1
	glPushMatrix();
	glTranslatef( BP[0].x  ,BP[0].y, 0.0 );
	glCallList( regHex3 );
	glPopMatrix();
	//////////////////////////////////////

	//////////////////////////////////////움직이는 블록2
	glPushMatrix();
	glTranslatef( BP[1].x   , BP[1].y, 0.0 );
	glCallList( regHex4 );
	glPopMatrix();
	//////////////////////////////////////

	//////////////////////////////////////움직이는 블록3
	glPushMatrix();
	glTranslatef( BP[2].x  ,BP[2].y, 0.0 );
	glCallList( regHex5 );
	glPopMatrix();
	//////////////////////////////////////
	
	///////////////////////////////////아이템
	glPushMatrix();
	glTranslatef( itm1.x   , itm1.y , 0.0 );
	glCallList( regHex6 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( itm2.x   , itm2.y , 0.0 );
	glCallList( regHex7 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( itm3.x   , itm3.y , 0.0 );
	glCallList( regHex8 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( itm4.x   , itm4.y , 0.0 );
	glCallList( regHex9 );
	glPopMatrix();
	////////////////////////////////////
	
	glutSwapBuffers();
	glFlush();
}

 

void moveHex( void ) 
{
	////////////////////////////움직이는 공
	playball.x = playball.x+incrementX;
	playball.y = playball.y+incrementY;
	////////////////////////////

	//////////////////////////// 움직이는 바 첫번째 꺼
	BP[0].x = BP[0].x + incrementX1;
	switch(direction1)
	{
	case 1:
		if (BP[0].x >= 47 )
		{
			incrementX1 = -0.3 - bart;
			direction1 =2;
		}
		break;
	case 2:
		if (BP[0].x <= 4 )
		{
			incrementX1 = 0.3 + bart;
			direction1 =1;
		}
		break;
	}
	//////////////////////////////////////


	//////////////////////////////////////움직이는 바 두번째 꺼
	BP[1].x =BP[1].x + incrementX2;

	switch(direction2)
	{
	case 2:
		if (BP[1].x >= 47 )
		{
			incrementX2 = -0.3 - bart;
			direction2 = 1;
		}
		break;
	case 1:
		if (BP[1].x <= 4 )
		{
			incrementX2 = 0.3 + bart;
			direction2 = 2;
		}
		break;
	}
	//////////////////////////////////////

	//////////////////////////////////////움직이는 바 세번째 꺼
	BP[2].x = BP[2].x + incrementX3;

	switch(direction3)
	{
	case 1:
		if (BP[2].x >= 47 )
		{
			incrementX3 = -0.3 - bart;
			direction3 =2;
		}
		 break;
	case 2:
		if (BP[2].x <= 4 )
		{
			incrementX3 = 0.3 + bart;
			direction3 =1;
		}
		break;
	}
	//////////////////////////////////////

	/////////////////////////////////////////////////아이템 떨어지기
	if(item1==1)
	{
		if(num1 >=1 && num1 <=3)
		{
			tt = 0.25;
		}
		else if (num1==4)
		{
			num1=4;
			tt = 0;
			item1=0;
		}

	}
	if(item2==2)
	{
		if(num2 >=1 && num2 <=3)
		{
			tt = -0.25;
		}
		else if (num2==4)
		{
			num2=4;
			tt = 0;
			item2=0;
		}
	}
	if(item3==3)
	{
		if(num3 >=1 && num3 <=3)
		{
			dd = 3;
		}
		else if (num3==4)
		{
			num3=4;
			dd = 0;
			item3=0;
		}
	}
	if(item4==4)
	{
		if(num4 >=1 && num4 <=3)
		{
			ii = 4;
		}
		else if (num4==4)
		{
			num4=4;
			ii = 0;
			item4=0;
		}
	}



	if(itm1.y <= bar1.y+1 && itm1.y >= bar1.y-1 && itm1.x <= bar1.x +3+(ii/2) && itm1.x >= bar1.x -3-(ii/2))
	{
		if(item2 == 2)
		{
			itm1.x = -100;
			itm1.y = -100;
			item1=0;
		}
		else
		{
			itm1.x = -100;
			itm1.y = -100;
			item1=1;
			itemgo=0;
			num1=1;
			tt = 0.4;
		}
	}
	else if(itm2.y <= bar1.y+1 && itm2.y >= bar1.y-1 &&itm2.x <= bar1.x +3+(ii/2) && itm2.x >= bar1.x -3-(ii/2))
	{
		if(item1 ==1 )
		{
			itm2.x = -100;
			itm2.y = -100;
			item2=0;
		}
		else
		{
			itm2.x = -100;
			itm2.y = -100;
			item2=2;
			itemgo=0;
			num2=1;
			tt = -0.25;
		}


	}
	else if(itm3.y <= bar1.y+1 && itm3.y <= bar1.y-1&&itm3.x <= bar1.x +3+(ii/2) && itm3.x >= bar1.x -3-(ii/2))
	{
		itm3.x = -100;
		itm3.y = -100;
		item3=3;
		num3=1;
		itemgo=0;
		dd = 3;
	}
	else if(itm4.y <= bar1.y+1 && itm4.y >= bar1.y-1&& itm4.x <= bar1.x +3+(ii/2) && itm4.x >= bar1.x -3-(ii/2))
	{
		itm4.x = -100;
		itm4.y = -100;
		item4=4;
		num4=1;
		itemgo=0;
		ii = 4;
	}
	else if(itm1.y <=0 || itm2.y <=0 || itm3.y <=0 || itm4.y <=0 ) 
	{
		itemgo=0;
	}


	
	itm1.y = itm1.y - pp;
	
	itm2.y = itm2.y - pp;

	itm3.y = itm3.y - pp;
	
	itm4.y = itm4.y - pp;


	/////////////////////////////움직이는 공
	switch(direction)
	{
		
	case 1:
		if (playball.x >=49 )
		{
			incrementX = -0.5-tt;
			incrementY = 0.5+tt;
			direction = 4;
		}
		else if (playball.y >=59 )
  {
   direction = 2;
   incrementX = 0.5+tt;
   incrementY = -0.5-tt;
  }
  else if (playball.x >= 49 && playball.y >= 59)
  {
   direction = 3;
   incrementX = -0.5-tt;
   incrementY = -0.5-tt;
  }
  ////////////////////////////////////튕기기1
 
  for(i=0;i<3;i++)
    {
  	  if(playball.x >= BP[i].x-3.5 && playball.x <= BP[i].x-2.5 && playball.y >= BP[i].y-1 && playball.y <= BP[i].y+1)
  	  {
		  score = score+5;
		  incrementX = -0.5-tt;
		  incrementY = 0.5+tt;
		  direction=4;
	  	  if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4  )
	  {
		  break;
	  }
	  itemgo = rand()%12;
	  if(itemgo==1) 
	  {
		  itm1.x = BP[i].x ;
		  itm1.y = BP[i].y ;
	  }
	  else if(itemgo==2)
	  {
		  itm2.x = BP[i].x ;
		  itm2.y = BP[i].y ;
	  }
	  else if(itemgo==3)
	  {
		  itm3.x = BP[i].x ;
		  itm3.y = BP[i].y ;
	  }
	  else if(itemgo==4)
	  {
		  itm4.x = BP[i].x ;
		  itm4.y = BP[i].y ;
	  }
  	  break;
	  } 
	  
	  else if(playball.y >= BP[i].y-1.5 && playball.y <= BP[i].y-0.5 && playball.x >= BP[i].x-3 && playball.x <= BP[i].x+3)
	  {
		  score = score+3;
		  direction=2;
		  incrementX = 0.5+tt;
		  incrementY = -0.5-tt;
		  if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4  )
		  {
			  break;
		  }
		  itemgo = rand()%12;
		  if(itemgo==1) 
		  {
			  itm1.x = BP[i].x ;
			  itm1.y = BP[i].y ;
		  }
		  else if(itemgo==2)
		  {
			  itm2.x = BP[i].x ;
			  itm2.y = BP[i].y ;
		  }
		  else if(itemgo==3)
		  {
			  itm3.x = BP[i].x ;
			  itm3.y = BP[i].y ;
		  }
		  else if(itemgo==4)
		  {
			  itm4.x = BP[i].x ;
			  itm4.y = BP[i].y ;
		  }
		  break;
	  }
  }

  ////////////////////////////////////////////////
  break;

  
  
  
	case 2:
		if (playball.x >=49 )
		{
			direction = 3;
			incrementX = -0.5-tt;
			incrementY = -0.5-tt;
		}
		else if (playball.y <=1 )
		{
			direction = 1;
			incrementX = 0.5+tt;
			incrementY = 0.5+tt;
		}
		else if (playball.x >=49 && playball.y <= 1)
		{
			direction = 4;
			incrementX = -0.5-tt;
			incrementY = 0.5+tt;
		}
		else if(playball.y <= bar1.y && playball.x <= bar1.x +3+(ii/2) &&playball.x >= bar1.x -3-(ii/2))
		{
			direction = 1;
			incrementX = 0.5+tt;
			incrementY = 0.5+tt;
			if (item1==1)
			{
				num1++;
			}
			if (item2==2)
			{
				num2++;
			}
			if (item3==3)
			{
				num3++;
			}
			if (item4==4)
			{
				num4++;
			}
		}
		//////////////////////////튕기기 2
		for(i=0;i<3;i++)
		{
			if(playball.x >= BP[i].x-3.5 && playball.x <= BP[i].x-2.5 && playball.y <= BP[i].y+1 && playball.y >= BP[i].y-1)
			{
				score = score+5;
				direction=3;
				incrementX = -0.5-tt;
				incrementY = -0.5-tt;
				if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4 )
				{
					break;
				}
				itemgo = rand()%12;
				if(itemgo==1) 
				{
					itm1.x = BP[i].x ;
					itm1.y = BP[i].y ;
				}
				else if(itemgo==2)
				{
					itm2.x = BP[i].x ;
					itm2.y = BP[i].y ;
				}
				else if(itemgo==3)
				{
					itm3.x = BP[i].x ;
					itm3.y = BP[i].y ;
				}
				else if(itemgo==4)
				{
					itm4.x = BP[i].x ;
					itm4.y = BP[i].y ;
				}
				break;
			}
			else if(playball.y <= BP[i].y+1.5 && playball.y >= BP[i].y+0.5 && playball.x >= BP[i].x-3 && playball.x <= BP[i].x+3)
			{
				score = score+3;
				direction=1;
				incrementX = 0.5+tt;
				incrementY = 0.5+tt;
				if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4)
				{
					break;
				}
				itemgo = rand()%12;
				if(itemgo==1) 
				{
					itm1.x = BP[i].x ;
					itm1.y = BP[i].y ;
				}
				else if(itemgo==2)
				{
					itm2.x = BP[i].x ;
					itm2.y = BP[i].y ;
				}
				else if(itemgo==3)
				{
					itm3.x = BP[i].x ;
					itm3.y = BP[i].y ;
				}
				else if(itemgo==4)
				{
					itm4.x = BP[i].x ;
					itm4.y = BP[i].y ;
				}
				break;
			}
		}
		
		////////////////////////////////////////////////
		break;
		
 case 3:
	 if (playball.x <=1 )
	 {
		 direction = 2;
		 incrementX = 0.5+tt;
		 incrementY = -0.5-tt;
	 }
	 else if (playball.y <=1 )
	 {
		 direction = 4;
		 incrementX = -0.5-tt;
		 incrementY = 0.5+tt;
	 }
	 else if (playball.x <=1 && playball.y <= 1)
	 {
		 direction = 1;
		 incrementX = 0.5+tt;
		 incrementY = 0.5+tt;
	 }
	 else if(playball.y <= bar1.y && playball.x <= bar1.x +3+(ii/2) &&playball.x >= bar1.x -3-(ii/2))
	 {
		 direction = 4;
		 incrementX = -0.5-tt;
		 incrementY = 0.5+tt;
		 if (item1==1)
		 {
			 num1++;

         }
         if (item2==2)
         {
			 num2++;
         }
         if (item3==3)
         {
			 num3++;
         }
         if (item4==4)
         {
			 num4++;
         }
	 }
	 
	 ///////////////튕기기 3
	 for(i=0;i<3;i++)
	 {
		 if(playball.y <= BP[i].y+1.5 && playball.y >= BP[i].y+0.5 && playball.x >= BP[i].x-3 && playball.x <= BP[i].x+3)
		 {
			 score = score+3;
			 direction=4;
			 incrementX = -0.5-tt;
			 incrementY = 0.5+tt;
			 if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4 )
			 {
				 break;
			 }
			 itemgo = rand()%12;
			 if(itemgo==1) 
			 {
				 itm1.x = BP[i].x ;
				 itm1.y = BP[i].y ;
			 }
			 else if(itemgo==2)
			 {
				 itm2.x = BP[i].x ;
				 itm2.y = BP[i].y ;
			 }
			 else if(itemgo==3)
			 {
				 itm3.x = BP[i].x ;
				 itm3.y = BP[i].y ;
			 }
			 else if(itemgo==4)
			 {
				 itm4.x = BP[i].x ;
				 itm4.y = BP[i].y ;
			 }
			 break;
		 }
		 else if(playball.x <= BP[i].x+3.5 && playball.x >= BP[i].x+2.5 && playball.y >= BP[i].y-1 && playball.y <= BP[i].y+1)
		 {
			 score = score+5;
			 direction=2;
			 incrementX = 0.5+tt;
			 incrementY = -0.5-tt;
			 if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4 )
			 {
				 break;
			 }
			 itemgo = rand()%12;
			 if(itemgo==1) 
			 {
				 itm1.x = BP[i].x ;
				 itm1.y = BP[i].y ;
			 }
			 else if(itemgo==2)
			 {
				 itm2.x = BP[i].x ;
				 itm2.y = BP[i].y ;
			 }
			 else if(itemgo==3)
			 {
				 itm3.x = BP[i].x ;
				 itm3.y = BP[i].y ;
			 }
			 else if(itemgo==4)
			 {
				 itm4.x = BP[i].x ;
				 itm4.y = BP[i].y ;
			 }
			 break;

		 }
	 }
	 
	 ////////////////////////////////////////////////
	 break;

 case 4:
	 if (playball.x <=1 )

	 {
		 direction =1;
		 incrementX = 0.5+tt;
		 incrementY = 0.5+tt;
	 }
	 else if(playball.y >=59 )
	 {
		 direction = 3;
		 incrementX = -0.5-tt;
		 incrementY = -0.5-tt;
	 }
	 else if(playball.x == 1 && playball.y ==59)
	 {
		 direction = 2;
		 incrementX = 0.5+tt;
		 incrementY = -0.5-tt;
	 }

	 /////////////////튕기기 4
	 for(i=0;i<3;i++)
	 {
		 if(playball.y >= BP[i].y-1.5 && playball.y <= BP[i].y-0.5 && playball.x >= BP[i].x-3 && playball.x <= BP[i].x+3)
		 {
			 score = score+3;
			 direction=3;
			 incrementX = -0.5-tt;
			 incrementY = -0.5-tt;
			 if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4)
			 {
				 break;
			 }
			 itemgo = rand()%12;
			 if(itemgo==1) 
			 {
				 itm1.x = BP[i].x ;
				 itm1.y = BP[i].y ;
			 }
			 else if(itemgo==2)
			 {
				 itm2.x = BP[i].x ;
				 itm2.y = BP[i].y ;
			 }

			 else if(itemgo==3)
			 {
				 itm3.x = BP[i].x ;
				 itm3.y = BP[i].y ;
			 }
			 else if(itemgo==4)
			 {
				 itm4.x = BP[i].x ;
				 itm4.y = BP[i].y ;
			 }
			 break;
		 }
		 else if(playball.x <= BP[i].x+3.5 && playball.x >= BP[i].x+2.5&& playball.y >= BP[i].y-1 && playball.y <= BP[i].y+1)
		 {
			 score = score+5;
			 direction=1;
			 incrementX = 0.5+tt;
			 incrementY = 0.5+tt;
			 if(itemgo==1 || itemgo==2 ||itemgo==3 ||itemgo==4)
			 {
				 break;
			 }
			 itemgo = rand()%12;
			 if(itemgo==1) 
			 {
				 itm1.x = BP[i].x ;
				 itm1.y = BP[i].y ;
			 }
			 else if(itemgo==2)
			 {
				 itm2.x = BP[i].x ;
				 itm2.y = BP[i].y ;
			 }
			 else if(itemgo==3)
			 {
				 itm3.x = BP[i].x ;
				 itm3.y = BP[i].y ;
			 }
			 else if(itemgo==4)
			 {
				 itm4.x = BP[i].x ;
				 itm4.y = BP[i].y ;
			 }
			 break;
		 }
	 }
	 
	 ////////////////////////////////////////////////
	 break;
  }
  glutPostRedisplay();
  
}

void input(GLubyte key, GLint xMouse, GLint yMouse)
{
	switch(key)
	{
	case 'a':
		move=2;
		if (bar1.x <= 1)
		{
			move=0;
		}
		else
		{
			bar1.x -=move;
		}
		glutPostRedisplay();
		break;
	case 'd':
		move=2;
		if (bar1.x <= 48)
		{
			move=0;
		}
		else
		{
			bar1.x -=move;
		}
		bar1.x +=2+dd;
		glutPostRedisplay();
		break;
	case 'r': 
		glClear( GL_COLOR_BUFFER_BIT );	
		init_re();
		glutIdleFunc( moveHex );
		break;
		/////////////////////////////

	default : break;
	} 
}

void main( int argc, char** argv)
{
	glutInit( &argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowPosition(150, 100);
	glutInitWindowSize(400,500);
	glutCreateWindow("S.D.H");
	init();

	glutIdleFunc( displayHex );
	glutDisplayFunc(displayHex);
	glutKeyboardFunc(input);
	glutMainLoop();
}


