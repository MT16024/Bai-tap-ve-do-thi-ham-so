#include <GL/glut.h>
#include <math.h>

  float a,b,c,d,min,max;
  int round(float x){
  if(x>0) return int (x+0.5);
  else return int (x-0.5);}
  float f (float x){
	return (a*x*x+b*x+c);
  
}

void initGL()
{
	  glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	  glOrtho(-320,320,-240,240,-1,1);	
    
} 

void Vedothi()
{
	    glColor3f(1.0,0.0,0.0);
	    glBegin (GL_LINES);
		  glVertex2i(-320,0);
		  glVertex2i(320,0);
		  glVertex2i(-240,0);
		  glVertex2i(-240,0);
		  glEnd();
      
		  int x1,y1,x2,y2;
		  float x,dx,k;
		  min=-320;max=320;
		  a=1;b=-3,c=2;
		  k=(float)640/15;
		  dx=0.1;
		  glColor3f(0.0,0.0,1.0);
		  x=min;
		  x1=round(x*k);
		  y1=round(f(x)*k);
		  glBegin (GL_LINES);
		  glVertex2i(x1,y1);
		  glVertex2i(x1,y1);
		    while (x<max){
			       x=x+dx;
		         x2=round(x*k);
		         y2=round(f(x)*k);
		         glBegin (GL_LINES);
		         glVertex2i(x1,y1);
		         glVertex2i(x2,y2);x1=x2; y1=y2;
		       } 
       glEnd();
} 

void mydisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
	  Vedothi();
	  glViewport(0,0,640,480);
	  glFlush();
} 

int main(int argc, char** argv){
	int mode=GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("e do thi ham so ");
	
	initGL();
	glutDisplayFunc(mydisplay);    
	glutMainLoop();
}
