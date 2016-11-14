
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include<math.h>
using namespace std;
double th;
void init2D(float r, float g, float b)

{



// glClearColor sets the colour to clear the buffer

//to.

glClearColor(r, g, b, 0.0);

// used to set up the view volume,

//GL_MODELVIEW can be used to set up viewing

//transformation

glMatrixMode(GL_PROJECTION);

// gluOrtho2D specifies the coordinates to be used

//with the viewport which defaults to the window size.

gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void translate(double x, double y, double x1,double y1,double vec[][3]) {
    vec[0][0] = x-x1;
    vec[0][1] = y-y1;

}
void keyboard( unsigned char key, int x, int y )
{
    if( key == 'g' )
    {
        cin >> th;
    }
}

void display(void)

{
while (th < 90) {
double cx = 100, cy = 100, r = 5;

int num_segments = 100;
double z[3][3];

// clear the buffers currently enabled for color

//writing.

glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 0.0, 0.0);

int f=0,k=0,fx,kk=1,f1=0,f2=0,jx1,k2=1,jy;
double jx;

float y1=0, theta1 = ((3.1415926f)/180)*(th),x1=0;
//cin >> th;

for (double jj =0; jj< 600;jj = jj + 1) {
//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glClear(GL_COLOR_BUFFER_BIT);
//glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_LINES);
glVertex2f(20.0,25.0);
glVertex2f(180.0,25.0);
glEnd();
glBegin(GL_LINES);
glVertex2f(180.0,25.0);
glVertex2f(170.0,60.0);
//glVertex2f(24.0,50.0);
glEnd();
glBegin(GL_LINES);
glVertex2f(170.0,60.0);
glVertex2f(30.0,60.0);
//glVertex2f(24.0,50.0);
glEnd();
glBegin(GL_LINES);
glVertex2f(20.0,25.0);
glVertex2f(30.0,60.0);
//glVertex2f(24.0,50.0);
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_POINT);
int cx1 = 25.0,cy1 = 42.5,r1 = 18;
for(int ii = 0; ii < num_segments; ii++)

{


float theta = 2.0f * 3.1415926f * float(ii) /

float(num_segments);//get the current angle

float x = r1 * cosf(theta);//calculate the x

//component

float y = r1 * sinf(theta);//calculate the y

//component

glVertex2f(x + cx1, y + cy1);//output vertex

}
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_LINES);
glVertex2f(160.0,165.0);
glVertex2f(190.0,165.0);
//glVertex2f(24.0,50.0);
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_LINES);
glVertex2f(40.0,105.0);
glVertex2f(60.0,105.0);
//glVertex2f(24.0,50.0);
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_LINES);
glVertex2f(190.0,200.0);
glVertex2f(190.0,45.0);
//glVertex2f(24.0,50.0);
glEnd();
glPolygonMode(GL_FRONT_AND_BACK,GL_LINES);
glBegin(GL_POLYGON);

for(int ii = 0; ii < num_segments; ii++)

{


float theta = 2.0f * 3.1415926f * float(ii) /

float(num_segments);//get the current angle

float x = r * cosf(theta);//calculate the x

//component

float y = r * sinf(theta);//calculate the y

//component

glVertex2f(x + 50 + cx, y + 200 + cy);//output vertex

}
//x1 = 50;
/*int y11;
if (jj >= 5 && jj <=8)
    y11 = -10;
else if (jj>=9 && jj <=12)
    y11 = 10;
else if (jj>=13 && jj <=15)
    y11 = -10;
else if (jj>=16 && jj<=18)
    y11 = 10;
else if (jj>=19 && jj<=20)
    y11 = -10;
else if (jj>=21 && jj<=22)
    y11 = 10;
else if (jj==23)
    y11 = -10;
else if (jj<5)
    y11 = 10;
else
    y11 = 10;
if (jj <= 12)
    usleep(105000);
else if (jj >=12 && jj<=18)
    usleep(150000);
else
    usleep(200000);*/
double var = -1;

cx = jj;
cout << th << " ";
if (th == 90) {
    cy = (cx/0.0001) - ((9.81*cx*cx)/(2*2800*0.0001*0.0001));
    cout  << cy << "   ";
}
else
    cy = cx*tan(theta1) - ((9.81 * cx * cx)/(2*3500*cos(theta1)*cos(theta1)));

//cy = (-9.81 * jj * jj)/2 + 100*(1/sqrt(2))*jj + 40;
cx = (0.5)*cx;

cy = cy - 90;
if(f1 != 1 && f2!=1)
//    cout << cx << " ";
cout << cx << "  " << cy << "   ";
//cout << cos(theta1) << "     ";
if (((cy < -35.5 && cy > -40.5 && cx < 110 && cx> 109) || f1 == 1) && f != 1 && f2 != 1) {
//    if ((cx < 110 && cx> 109) || (cx > 140))
//        cout << "\n";
        if (f1 == 0)
            jx = cx;
        cx = cx - 0.25;
        cy = cx*tan(theta1) - ((9.81 * cx * cx)/(2*2800*cos(theta1)*cos(theta1)));

        cy = cy-90;
        kk+=2;
        f1 = 1;
        usleep(4000);
//        cout << cx << "  " << cy << "\n";
        cout << cx << "-";
        if (cx == 0) {
            cout << "cx = 0\n";
            break;
        }
       // break;
}
else if ((cy > -5 || f==1) && (f2 != 1)) {
    if (f == 0)
        fx = cx;
    f=1;
    cx = fx;
    cy = k--;
    usleep(3000);
}
else
    usleep(2000);
if (cy < -151 && f2 != 1) {
         cout << "cy < -151 -- 1\n";
        break;
    }
if (cx > 135 || f2 == 1) {
    if (f2 == 0){
        jx1 = cx;
        jy = cy;
    }
    f2 = 1;
    cx= k2;
    k2++;
    cy = -((9.81 * cx * cx)/(2*2800));
 //   cy = (2800 * k2) - (0.5 * 9.81 * k2 * k2);
    cx = jx1-(k2*0.5);
    cy = jy + cy ;
    cout << cx << "  " << cy << "   ";
    if (cy < -151) {
         cout << "cy < -151 -- 2\n";
        break;
    }
}
cout << jj << "  ";
  //  break;
  glEnd();


glFlush();

}
//glutKeyboardFunc( keyboard );
//cin >> th;
th++;
}
//glFlush();

}
int main(int argc, char *argv[])

{

// glutInit will initialize the GLUT library and

//negotiate a session with the window system.
for (int i=0;i<10;i++) {

cin >> th;
    cout << "hello\n";
glutInit(&argc,argv);

// Select a display mode with single buffer because

//its a simple application and Red, green, blue

//framebuffer

glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

glutInitWindowSize(500, 500);

glutInitWindowPosition(700, 0);

glutCreateWindow("Lab-1(b)_1");

init2D(0.0, 0.0, 0.0);

// calls the function display everytime the display

//needs to be updated
//glutKeyboardFunc( keyboard );
glutDisplayFunc(display);
glutMainLoop();
cout << "end\n";
}



}
