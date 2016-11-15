
#include <GL/glut.h >
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
using namespace std;

double angle;
void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 210.0, 0.0, 200.0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'g') {
        cin >> angle;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    while (angle <90) {
    int flag = 0; //IF Ball hits the ceiling
    int flag1 = 0; //IF Ball hits the Rim and Falls on the ground
    int flag2 = 0; //IF Ball hits The Pole
    int flag3 = 0; //IF Ball goes into the Basket

    /*------Different co-ordinates for Ball*/

    int Y_BallHitsCeiling = 0, RelativeX_BallHitsPole = 1,RelativeX_BallHitsRim = 1;
    double X_BallHitsCeiling, X_BallHitsRim, Y_BallHitsRim, X_BallInBasket, Y_BallInBasket, X_BallHitsPole, Y_BallHitsPole;

    float theta = ((3.1415926f)/180)*(angle);
    double cx = 100, cy = 100, r = 5;       // Center Coordinates and Radius Of the BasketBall

    for (double time = 0; time < 600; time++) {     // Number of Iterations For Trajectory OF the Ball
        glClear(GL_COLOR_BUFFER_BIT);


        /*--------Basketball Court---------*/

        glBegin(GL_LINES);
        glVertex2f(20.0, 25.0);
        glVertex2f(210.0, 25.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(210.0, 25.0);
        glVertex2f(200.0, 80.0);

        glEnd();
        glBegin(GL_LINES);
        glVertex2f(200.0, 80.0);
        glVertex2f(30.0, 80.0);

        glEnd();
        glBegin(GL_LINES);
        glVertex2f(20.0, 25.0);
        glVertex2f(30.0, 80.0);
        glEnd();


        /*--------Basketball Ring---------*/

        // The Circumference of Ring

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        float cx1 = 175.0, cy1 = 165.0, r1 = 7.5, num_segments = 1000;
        float alpha = 2 * 3.1415926 / float(num_segments);
        float c = cosf(alpha); //pre calculate the sine and cosine
        float s = sinf(alpha);
        float t;

        float x = r1; //we start at angle = 0
        float y = 0;

        glBegin(GL_POLYGON);
        for (int ii = 0; ii < num_segments; ii++) {
            glVertex2f(2 * x + cx1, (0.5) * y + cy1); //output vertex

            //apply the rotation matrix
            t = x;
            x = c * x - s * y;
            y = s * t + c * y;
        }
        glEnd();

        // The Pole

        glBegin(GL_LINES);
        glVertex2f(190.0, 185.0);
        glVertex2f(190.0, 150.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(190.0, 165.0);
        glVertex2f(200.0, 150.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(200.0, 165.0);
        glVertex2f(200.0, 45.0);
        glEnd();
        //glBegin(GL_POLYGON);

        /*glBegin(GL_LINES);
        glVertex2f(186.0,145.0);
        glVertex2f(190.0,165.0);
        //glVertex2f(24.0,50.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(164.0,145.0);
        glVertex2f(160.0,165.0);
        //glVertex2f(24.0,50.0);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(164.0,145.0);
        glVertex2f(186.0,145.0);
        //glVertex2f(24.0,50.0);
        glEnd();*/

        /*-------The Player-------*/

        // Player's Face

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_POLYGON);
        cx1 = 30.0, cy1 = 92.5, r1 = 10, num_segments=1000;
        for (int ii = 0; ii < num_segments; ii++)
        {
            float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
            float x = r1 * cosf(alpha); //calculate the x component
            float y = r1 * sinf(alpha); //calculate the y component
            glVertex2f(x + cx1, y + cy1); //output vertex
        }
        glEnd();

        // Player's Hand

        glBegin(GL_LINES);
        glVertex2f(30.0, 57.5);
        glVertex2f(41.0, 40.0);
        glEnd();

        // Player's Body

        glBegin(GL_LINES);
        glVertex2f(30.0, 57.5);
        glVertex2f(19.0, 40.5);
        glEnd();

        // Player's Legs

        glBegin(GL_LINES);
        glVertex2f(50.0, 105.0);
        glVertex2f(30.0, 70.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(30.0, 82.5);
        glVertex2f(30.0, 57.5);
        glEnd();

        /*---------The BasketBall-------*/


        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_POLYGON);

        for (int ii = 0; ii < num_segments; ii++)
        {
            float alpha = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
            float x = r * cosf(alpha); //calculate the x component
            float y = r * sinf(alpha); //calculate the y component
            glVertex2f(x + 50 + cx, y + 200 + cy); //output vertex
        }
        glEnd();

        /*---------Defining Trajectory Of The Ball--------*/


        cx = time;
        cout << angle << " ";
        if (angle == 90)
            cy = (cx / 0.0001) - ((9.81 * cx * cx) / (2 * 2800 * 0.0001 * 0.0001));
        else
            cy = cx * tan(theta) - ((9.81 * cx * cx) / (2 * 3500 * cos(theta) * cos(theta)));
        // equation of trajectory for projectile (x*tan(theta)-(g*x*x)/(2*velocity*velocity*cos(theta)*cos(theta)

        cx = (0.5) * cx;
        cy = cy - 90;

        if (flag1 != 1 && flag2 != 1)
            cout << cx << "  " << cy << "   ";


        // IF Ball hits the Rim and Falls on the ground #NO SCORE
        if (((cy < -35.5 && cy > -40.5 && cx < 110 && cx > 109) || flag1 == 1) && flag != 1 && flag2 != 1 && flag3 != 1) {

            /*if (flag1 == 0)
                X_BallHitsRim = cx;

            cx = cx - 0.25;
            cy = cx * tan(theta) - ((9.81 * cx * cx) / (2 * 3500 * cos(theta) * cos(theta)));

            cy = cy - 90;
            flag1 = 1;
            usleep(2000);
            if (cx == 0) {
                cout << "cx = 0\n";
                break;
            }*/

            if (flag1 == 0) {
                X_BallHitsRim = cx;
                Y_BallHitsRim = cy;
            }
            flag1 = 1;
            cx = RelativeX_BallHitsRim;
            RelativeX_BallHitsRim++;
            cy = -((9.81 * cx * cx) / (2 * 2800));
            //   cy = (2800 * k2) - (0.5 * 9.81 * k2 * k2);
            cx = X_BallHitsRim - (RelativeX_BallHitsRim * 0.5);
            cy = Y_BallHitsRim + cy;
            cout << cx << "  " << cy << "   ";
            usleep(4000);
            // IF Ball hits Ground after it hits the pole
            if (cy < -151) {
                cout << "cy < -151 -- 2\n";
                break;
            }
        }

        // IF Ball hits the ceiling #NO SCORE
        else if ((cy > -5 || flag == 1) && (flag2 != 1)) {
            if (flag == 0)
                X_BallHitsCeiling = cx;
            flag = 1;
            cx = X_BallHitsCeiling;
            cy = Y_BallHitsCeiling--;
            usleep(3000);
        }

        // IF Ball goes into the Basket #SCORE
        else if ((cx > 110 && cx < 140 && cy < -35.5 && cy > -40.5 && flag2 != 1 && flag != 1 && flag1 != 1) || flag3 == 1) {
            if (flag3 == 0) {
                X_BallInBasket = cx;
                Y_BallInBasket = cy;
            }
            flag3 = 1;
            cx = X_BallInBasket;
            cy = Y_BallInBasket--;
            usleep(2000);
        }

        else
            usleep(2000);

        // IF Ball hits the Ground
        if (cy < -151 && flag2 != 1)
            break;


        // IF Ball hits The Pole #NO SCORE
        if (cx > 145 || flag2 == 1) {
            if (flag2 == 0) {
                X_BallHitsPole = cx;
                Y_BallHitsPole = cy;
            }
            flag2 = 1;
            cx = RelativeX_BallHitsPole;
            RelativeX_BallHitsPole++;
            cy = -((9.81 * cx * cx) / (2 * 2800));
            //   cy = (2800 * k2) - (0.5 * 9.81 * k2 * k2);
            cx = X_BallHitsPole - (RelativeX_BallHitsPole * 0.5);
            cy = Y_BallHitsPole + cy;
            cout << cx << "  " << cy << "   ";

            // IF Ball hits Ground after it hits the pole
            if (cy < -151) {
                cout << "cy < -151 -- 2\n";
                break;
            }
        }
        glEnd();
        glFlush();

    }
    //glutKeyboardFunc( keyboard );
    //cin >> th;
    angle++;
    }
}
//glFlush();

int main(int argc, char * argv[])

{
    for (int i = 0; i < 10; i++)
    {
        cin >> angle;
        glutInit( & argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(700, 0);
        glutCreateWindow("Lab-1(b)_1");
        init2D(0.0, 0.0, 0.0);
        glutDisplayFunc(display);
        glutMainLoop();
    }
}
