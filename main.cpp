#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <GL/glut.h>
#define PI 3.14159265
#define CTRL_COUNT 100

using namespace std;





// Colors in RGB Scheme
double sky[3] = {19,190,242};
double cloud[3] = {255,255,255};
double smoke[3] = {58,51,39};
double sun[3] = {219,230,21};
double road[3]={0,0,0};
double soil[3] = {199,192,141};
double water[3] = {152,222,245};
double building3[3] = {220,101,150};
double building2[3] = {100,0,70};
double building1Box2[3] = {110,67,187};
double building1Box3[3] = {250,105,179};

//Variable Declarations
double train = 0;
double car1 = 0;
double car2 = 0;
double fly = 0;
float ship = 1.3f;
float ship2 = 0.0f;
double rain = 0;
int revf = 0;
double var = -6;
double rainX = -6;
double rainY;
bool Rain = false;


// Functions to draw a 2D object

void drawCloud()
{
    glutSolidSphere(0.4,40,40);
    glScalef(1,0.4,1);
    glTranslatef(-0.1,0,0);glBegin(GL_POLYGON);
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glutSolidSphere(0.7,40,40);
}

void drawSmoke()
{
    glutSolidSphere(0.4,40,40);
    glScalef(1,0.4,1);
    glTranslatef(-0.1,0,0);glBegin(GL_POLYGON);
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glutSolidSphere(0.7,40,40);
}



 void drawRoad()
 {
     //draw road
    glPushMatrix();
    glTranslatef(0,-0.15,-0.25);
    glScalef(25,1.0,1);
    glColor3ub(road[0],road[1],road[2]);
    glutSolidCube(0.5);
    glPopMatrix();

    //white 1
    glPushMatrix();
    glTranslatef(-5,-0.15,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

     //white 2
    glPushMatrix();
    glTranslatef(-4,-0.15,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

     //white 3
    glPushMatrix();
    glTranslatef(-3,-0.15,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

     //white 4
    glPushMatrix();
    glTranslatef(-2,-0.15,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

      //white 5
    glPushMatrix();
    glTranslatef(0,-0.06,0);
    glPushMatrix();
    glTranslatef(-1,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();


   //white 6
    glPushMatrix();
    glTranslatef(0,-0.1,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();
     //white 7
    glPushMatrix();
    glTranslatef(1,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();
     //white 8
    glPushMatrix();
    glTranslatef(2,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();
     //white 9
    glPushMatrix();
    glTranslatef(3,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

         //white 10
    glPushMatrix();
    glTranslatef(4,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();

          //white 11
    glPushMatrix();
    glTranslatef(5,-0.11,0);
    glScalef(5,0.8,0.1);
    glColor3f(1,1,1);
    glutSolidCube(0.1);
    glPopMatrix();


    glPopMatrix();
}

void drawRailTrack(){

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glTranslatef(0,0,1);
    glVertex3f(-6,0.2,0);
    glVertex3f(5,0.2,0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glTranslatef(0,0,1);
    glVertex3f(-6,0.1,0);
    glVertex3f(5,0.1,0);
    glEnd();


    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
        glColor3f(0,0,0);
        glTranslatef(0,0,1);
        glVertex3f(var,0.1,0);
        glVertex3f(var,0.2,0);
        glEnd();
        var += 0.1;
    }

    var = -6;

}

void drawTrain(){

    //body
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glColor3f(0.4, 0, 0);
    glScalef(1.5, 0.8, 0.1);
    glutSolidCube(1.3);
    glPopMatrix();

     //top body
    glPushMatrix();
    glTranslatef(0.28, -0.2, 0);
    glScalef(1.6, 0.5, 0.1);
    glColor3f(0.5, 0.5, 0.5);
    glutSolidCube(0.8);
    glPopMatrix();

    //smoke place
    glPushMatrix();
    glColor3f(0, 0, 0.2);
    glTranslatef(-0.8, -0.28, 1);
    glScalef(0.9, 1.3, 0.01);
    glutSolidCube(0.35);
    glPopMatrix();

    //top of smoke place
    glPushMatrix();
    glTranslatef(-0.81, 0.06, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0, 0.3, 0.4);
    glRotatef(90, 1, 0, 0);
    glutSolidCone(0.26, 0.3, 20, 20);
    glPopMatrix();

    //smoke
    glPushMatrix();
    glTranslatef(-0.65, 0.2, 1);
    glScalef(1, 1, 0.01);
    glColor3f(50, 38, 25);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    //smoke
    glPushMatrix();
    glTranslatef(-0.4, 0.5, 1);
    glScalef(1.4, 1.4, 0.01);
    glColor3f(50, 38, 25);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    //smoke
    glPushMatrix();
    glTranslatef(-0.1, 0.8, 1);
    glScalef(2, 2, 0.01);
    glColor3f(50, 38, 25);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    //wheel 1
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0.5, -1.4, 1);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    //wheel 2
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(-0.5, -1.4, 1);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    //body to body connector
    glPushMatrix();
    glTranslatef(1.1, -1.1, 0);
    glScalef(1, 3, 0.01);
    glutSolidCube(0.20);
    glPopMatrix();

    //bogy
    glPushMatrix();
    glColor3f(0.4, 0.4,0);
    glScalef(1.3, 0.75, 0.01);
    glTranslatef(1.65, -1.25, 0);
    glutSolidCube(1.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.05, 0, 0);

    //bogy window 1
    glPushMatrix();
    glTranslatef(1.5, -0.9, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.2,0.1,0);
    glutSolidCube(0.4);
    glPopMatrix();


    //bogy window 2
    glPushMatrix();
    glTranslatef(2.0, -0.9, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.2, 0.1, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    //bogy window 2
    glPushMatrix();
    glTranslatef(2.5, -0.9, 1);
    glScalef(1, 1, 0.01);
    glColor3f(0.2, 0.1, 0);
    glutSolidCube(0.4);
    glPopMatrix();

    glPopMatrix();


    //bogy wheel
    glPushMatrix();
    glTranslatef(1.5, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    glColor3f(0, 0, 0);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();

    //bogy wheel
     glPushMatrix();
     glTranslatef(2.05, -1.55, 1);
     glScalef(0.7, 0.7, 0.01);
     glColor3f(0, 0, 0);
     glutSolidTorus(0.1, 0.2, 20, 20);
     glPopMatrix();

    //bogy wheel
    glPushMatrix();
    glTranslatef(2.6, -1.55, 1);
    glScalef(0.7, 0.7, 0.01);
    glColor3f(0, 0, 0);
    glutSolidTorus(0.1, 0.2, 20, 20);
    glPopMatrix();




}

void wheel(float k,float m,float rad){
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3f(0.6,0.1,0.2);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=rad-0.15;
        float x =k+r * cos(A);
        float y =m+r * sin(A);
        glVertex3f(x,y ,0);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        glColor3f(0.0,0.0,0.0);
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=rad;
        float x =k+r * cos(A);
        float y =m+r * sin(A);
        glVertex3f(x,y ,0);
    }
    glEnd();
}

void drawCar(){

    wheel(-5.1,-1.5,0.3);
    wheel(-3.8,-1.5,0.3);

    //body
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.3,0.5);
    glVertex3f(-5.5, -1.45, 0.0);
    glVertex3f(-3.4, -1.45, 0.0);
    glVertex3f(-3.4,-1.05, 0.0);
    glVertex3f(-5.5, -1.05, 0.0);
    glEnd();


    //window 1
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.1,1.0);
    glVertex3f(-4.90,-1.0,0.0);
    glVertex3f(-4.55,-1.0,0.0);
    glVertex3f(-4.55,-0.75,0.0);
    glVertex3f(-4.90,-0.75,0.0);
    glEnd();
    //window 2
    glBegin(GL_POLYGON);
    glColor3f(0.2,0.1,1.0);
    glVertex3f(-4.45,-1.0,0.0);
    glVertex3f(-4.1,-1.0,0.0);
    glVertex3f(-4.1,-0.75,0.0);
    glVertex3f(-4.45,-0.75,0.0);
    glEnd();
    //hood
    glBegin(GL_POLYGON);
    glColor3f(0.3,0.4,0.0);
    glVertex3f(-4.98,-1.05,0.0);
    glVertex3f(-4.0,-1.05,0.0);
    glVertex3f(-4.0,-0.69,0.0);
    glVertex3f(-4.98,-0.69,0.0);
    glEnd();
    //first triangle
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.2);
    glVertex3f(-4.0,-1.05,0.0);
    glVertex3f(-4.0,-0.69,0.0);
    glVertex3f(-3.6,-1.05,0.0);
    glEnd();
    //last triangle
    glBegin(GL_POLYGON);
    glColor3f(1.2,0.0,0.2);
    glVertex3f(-4.98,-1.05,0.0);
    glVertex3f(-4.98,-0.69,0.0);
    glVertex3f(-5.4,-1.05,0.0);
    glEnd();
}

void building(){

    //Bottom box 1
    glColor3ub(building3[0],building3[1],building3[2]);
    glBegin(GL_POLYGON);
    glVertex2i(100,50);
    glVertex2i(100,250);
    glVertex2i(250,250);
    glVertex2i(250, 50);
    glEnd();

    //Box padding -
    glColor3f(0.6, 0.3, 0.6);
    glBegin(GL_POLYGON);
    glVertex2i(100,250);
    glVertex2i(100,260);
    glVertex2i(250,260);
    glVertex2i(250,250);
    glEnd();


    //Bottom box 2
    glColor3ub(building1Box2[0],building1Box2[1],building1Box2[2]);
    glBegin(GL_POLYGON);
    glVertex2i(100,260);
    glVertex2i(100,370);
    glVertex2i(250,370);
    glVertex2i(250,260);
    glEnd();


    //Box padding -
    glColor3f(0.6, 0.3, 0.6);
    glBegin(GL_POLYGON);
    glVertex2i(100,370);
    glVertex2i(100,380);
    glVertex2i(250,380);
    glVertex2i(250,370);
    glEnd();


    //Bottom box 3
    //Top
    glColor3ub(building1Box3[0],building1Box3[1],building1Box3[2]);
    glBegin(GL_POLYGON);
    glVertex2i(100,380);
    glVertex2i(100,500);
    glVertex2i(250,500);
    glVertex2i(250,380);
    glEnd();

    //Coloumn 2
    //Bottom box 1 from bottom
    //Top
    glColor3ub(building2[0], building2[1], building2[2]);
    glBegin(GL_POLYGON);
    glVertex2i(250,50);
    glVertex2i(250,525);
    glVertex2i(425,525);
    glVertex2i(425,50);
    glEnd();

    //Coloumn 3
    //Bottom box 1 from bottom
    //Top
    glColor3ub(building3[0], building3[1], building3[2]);
    glBegin(GL_POLYGON);
    glVertex2i(425,50);
    glVertex2i(425,550);
    glVertex2i(525,550);
    glVertex2i(525,50);
    glEnd();

    //Shadow

    glColor3f(0.4, 0.4, 0.6);
    glBegin(GL_POLYGON);
    glVertex2i(100,50);
    glVertex2i(100,500);
    glVertex2i(50,400);
    glVertex2i(50,75);
    glEnd();


    //shadow lines
    //Box padding -
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(100,370);
    glVertex2i(100,380);
    glVertex2i(50,300);
    glVertex2i(50,290);
    glEnd();

    //shadow lines
    //Box padding -
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
    glVertex2i(100,250);
    glVertex2i(100,260);
    glVertex2i(50,190);
    glVertex2i(50,180);
    glEnd();

    //Shadow triangle
    glColor3f(0.517647, 0.517647, 0.517647);
    glBegin(GL_TRIANGLES);
    glVertex2i(250, 525);
    glVertex2i(250, 500);
    glVertex2i(240, 500);
    glEnd();

    //Shadow triangle
    glColor3f(0.517647, 0.517647, 0.517647);
    glBegin(GL_TRIANGLES);
    glVertex2i(425, 525);
    glVertex2i(425, 550);
    glVertex2i(415, 525);
    glEnd();
    glFlush();

}

void drawPlane(){

    //body
    glPushMatrix();
    glTranslatef(0,-1,0);
    glScalef(5,0.8,0.1);
    glColor3f(0.1,0.1,0.4);
    glutSolidCube(0.2);
    glPopMatrix();

    //head
    glPushMatrix();
    glTranslatef(0.5,-0.92,0);
    glScalef(0.15,0.16,1);
    glRotatef(90,0,0,-1);
    glColor3f(0.6,0.0,0.3);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0.5,1,0);
    glEnd();
    glPopMatrix();

    //tail
    glPushMatrix();
    glTranslatef(-0.5,-0.92,0);
    glScalef(0.2,0.2,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0,1,0);
    glVertex3f(0.3,1,0);
    glVertex3f(1,0,0);
    glEnd();
    glPopMatrix();

    //up left wing
    glPushMatrix();
    glTranslatef(0,-0.92,0);
    glScalef(0.2,0.3,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(0.2,1,0);
    glVertex3f(-0.5,1,0);
    glEnd();
    glPopMatrix();

    // down left wing
    glPushMatrix();
    glTranslatef(-0.1,-1.38,0);

    glScalef(0.2,0.33,1);
    glBegin(GL_QUADS);
    glVertex3f(0,0,0);
    glVertex3f(0.7,0,0);
    glVertex3f(1.5,1,0);
    glVertex3f(0.5,1,0);
    glEnd();
    glPopMatrix();


}


void DrawHouse()
{


    //--------------Upper Triangle-----------------
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    glColor3f(0.392, 0.694, 1);
    glVertex3f(0, 0.5,1);
    glVertex3f(-0.5, 0,1);
    glVertex3f(0.5, 0,1);
    glEnd();
    glFlush();
    glPopMatrix();

    //--------------Main Rectangle-----------------
    glPushMatrix();
    glTranslatef(0,-1,0);
   // glColor3f(0.502, 0.502, 0.502);
	glColor3ub(building3[0],building3[1],building3[2]);
    glBegin(GL_QUADS);
    glVertex3f(-0.5,0,1);
    glVertex3f(0.5,0,1);
    glVertex3f(0.5,1,1);
    glVertex3f(-0.5,1,1);
    glEnd();
    glFlush();
    glPopMatrix();

    //--------------Door-----------------
    glPushMatrix();
    glTranslatef(0.7,-0.75,0);
    glColor3f(0.863, 0.863, 0.863);
    glBegin(GL_QUADS);
    glVertex3f(-0.5,0,1.5);
    glVertex3f(-0.3,0,1.5);
    glVertex3f(-0.3,0.4,1.5);
    glVertex3f(-0.5,0.4,1.5);
    glEnd();
    glFlush();
    glPopMatrix();


    //window
    glPushMatrix();
    glTranslatef(0.75,-0.25,0);
    glScalef(0.37,0.37,1);
    glColor3f(0.863, 0.863, 0.863);
    glBegin(GL_QUADS);
    glVertex3f(-0.5,0,1.5);
    glVertex3f(0,0,1.5);
    glVertex3f(0,0.5,1.5);
    glVertex3f(-0.5,0.5,1.5);
    glEnd();
    glFlush();
    glPopMatrix();


    //window
    glPushMatrix();
    glTranslatef(0.03,-0.25,0);
    glScalef(0.37,0.37,1);
    glColor3f(0.863, 0.863, 0.863);
    glBegin(GL_QUADS);
    glVertex3f(-0.5,0,1.5);
    glVertex3f(0,0,1.5);
    glVertex3f(0,0.5,1.5);
    glVertex3f(-0.5,0.5,1.5);
    glEnd();
    glPopMatrix();


    //--------------Chimney-----------------
    glPushMatrix();
    //glTranslatef(0.4,-0.9,0);
    glColor3f(0.502, 0.000, 0.000);
    glBegin(GL_QUADS);
    glVertex3f(-0.5,0,1);
    glVertex3f(-0.35,0,1);
    glVertex3f(-0.35,0.3,1);
    glVertex3f(-0.5,0.3,1);
    glEnd();
    glPopMatrix();

    //smoke{58,51,39};
    glPushMatrix();
    glTranslatef(-0.4, 0.5, 1);
    glScalef(1.4, 1.4, 0.01);
	glColor3ub(58,51,39);
    //glColor3f(50, 38, 25);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();

    //smoke
    glPushMatrix();
    glTranslatef(-0.1, 0.8, 1);
    glScalef(2, 2, 0.01);
   glColor3ub(58,51,39);
    glutSolidSphere(0.1, 20, 20);
    glPopMatrix();
    //---------------------------------------------

}

int  d, x, y;
float cpsx = 100, cpsy = 0;
int run2 = 0;

void draw_circle(int xC, int yC, int Radius)
{
    d = 1 - Radius;
    x = 0;
    y = Radius;

    while (y > x)
    {
        if (d < 0)
        {
            d = d + 2 * x + 3;
            x++;
        }
        else
        {
            d = d + 2 * (x - y) + 5;
            x++;
            y--;
        }
        glVertex2i(xC + x, yC + y);
        glVertex2i(xC + x, yC - y);
        glVertex2i(xC - x, yC + y);
        glVertex2i(xC - x, yC - y);
        glVertex2i(xC + y, yC + x);
        glVertex2i(xC - y, yC + x);
        glVertex2i(xC + y, yC - x);
        glVertex2i(xC - y, yC - x);
    }
}

void drawBoat(){





     //2nd box
    glColor3f(0.0,0.0,0.387);
    glBegin(GL_POLYGON);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,8.5);
    glVertex2f(19.5,8.5);
    glVertex2f(19.5,5.5);
    glEnd();





   //3rd box
    glColor3f(0.1,0.1,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(1,5.5);
    glVertex2f(4,1);
    glVertex2f(19,1);
    glVertex2f(21.5,5.5);
    glEnd();
    glColor3f(0.1,0.0,0.6);
    glBegin(GL_POLYGON);
    glVertex2f(4,5.5);
    glVertex2f(4,8);
    glVertex2f(5,8);
    glVertex2f(5,5.5);
    glEnd();


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(7,7.5);
    glVertex2f(7,8);
    glVertex2f(10,8);
    glVertex2f(10,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11.5,7.5);
    glVertex2f(11.5,8);
    glVertex2f(15,8);
    glVertex2f(15,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(16,7.5);
    glVertex2f(16,8);
    glVertex2f(19,8);
    glVertex2f(19,7.5);
    glEnd();
    //1st box
    glColor3f(0.1,0.0,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(4.5,8.5);
    glVertex2f(4.5,10);
    glVertex2f(18.5,10);
    glVertex2f(18.5,8.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,10);
    glVertex2f(5.5,12.9);
    glVertex2f(7,12.9);
    glVertex2f(7,10);
    glEnd();
    //1st
    glColor3f(0.7,0.0,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,12.9);
    glVertex2f(5.5,13.5);
    glVertex2f(7,13.5);
    glVertex2f(7,12.9);
    glEnd();
     //2nd
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,10);
    glVertex2f(8.5,12.9);
    glVertex2f(10,12.9);
    glVertex2f(10,10);
    glEnd();
    glColor3f(0.7,0.0,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,12.9);
    glVertex2f(8.5,13.5);
    glVertex2f(10,13.5);
    glVertex2f(10,12.9);
    glEnd();
    //3rd
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,10);
    glVertex2f(11.5,12.9);
    glVertex2f(13,12.9);
    glVertex2f(13,10);
    glEnd();
    glColor3f(0.7,0.0,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,12.9);
    glVertex2f(11.5,13.5);
    glVertex2f(13,13.5);
    glVertex2f(13,12.9);
    glEnd();

    //4th
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,10);
    glVertex2f(14.5,12.9);
    glVertex2f(16,12.9);
    glVertex2f(16,10);
    glEnd();
    glColor3f(0.7,0.0,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,12.9);
    glVertex2f(14.5,13.5);
    glVertex2f(16,13.5);
    glVertex2f(16,12.9);
    glEnd();





    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.5,5.5);
    glVertex2f(1.5,6.5);
    glVertex2f(2,6.2);
    glVertex2f(3,6.2);
    glVertex2f(3.5,6.5);
    glVertex2f(3.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,6.5);
    glVertex2f(4,6.2);
    glVertex2f(5,6.2);
    glVertex2f(5.5,6.5);
    glVertex2f(5.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.5,5.5);
    glVertex2f(5.5,6.5);
    glVertex2f(6,6.2);
    glVertex2f(7,6.2);
    glVertex2f(7.5,6.5);
    glVertex2f(7.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7.5,5.5);
    glVertex2f(7.5,6.5);
    glVertex2f(8,6.2);
    glVertex2f(9,6.2);
    glVertex2f(9.5,6.5);
    glVertex2f(9.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,5.5);
    glVertex2f(9.5,6.5);
    glVertex2f(10,6.2);
    glVertex2f(11,6.2);
    glVertex2f(11.5,6.5);
    glVertex2f(11.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11.5,5.5);
    glVertex2f(11.5,6.5);
    glVertex2f(12,6.2);
    glVertex2f(13,6.2);
    glVertex2f(13.5,6.5);
    glVertex2f(13.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13.5,5.5);
    glVertex2f(13.5,6.5);
    glVertex2f(14,6.2);
    glVertex2f(15,6.2);
    glVertex2f(15.5,6.5);
    glVertex2f(15.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15.5,5.5);
    glVertex2f(15.5,6.5);
    glVertex2f(16,6.2);
    glVertex2f(17,6.2);
    glVertex2f(17.5,6.5);
    glVertex2f(17.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17.5,5.5);
    glVertex2f(17.5,6.5);
    glVertex2f(18,6.2);
    glVertex2f(19,6.2);
    glVertex2f(19.5,6.5);
    glVertex2f(19.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(19.5,5.5);
    glVertex2f(19.5,6.5);
    glVertex2f(20,6.2);
    glVertex2f(20.5,6.2);
    glVertex2f(21,6.5);
    glVertex2f(21,5.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.5,3.5);
    glVertex2f(4.5,4.5);
    glVertex2f(5.5,4.5);
    glVertex2f(5.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,3.5);
    glVertex2f(7,4.5);
    glVertex2f(8,4.5);
    glVertex2f(8,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,3.5);
    glVertex2f(9.5,4.5);
    glVertex2f(10.5,4.5);
    glVertex2f(10.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(12,3.5);
    glVertex2f(12,4.5);
    glVertex2f(13,4.5);
    glVertex2f(13,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(14.5,3.5);
    glVertex2f(14.5,4.5);
    glVertex2f(15.5,4.5);
    glVertex2f(15.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17,3.5);
    glVertex2f(17,4.5);
    glVertex2f(18,4.5);
    glVertex2f(18,3.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5,10);
    glVertex2f(5,11);
    glVertex2f(5.5,10.8);
    glVertex2f(6.5,10.8);
    glVertex2f(7,11);
    glVertex2f(7,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,10);
    glVertex2f(7,11);
    glVertex2f(7.5,10.8);
    glVertex2f(8.5,10.8);
    glVertex2f(9,11);
    glVertex2f(9,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9,10);
    glVertex2f(9,11);
    glVertex2f(9.5,10.8);
    glVertex2f(10.5,10.8);
    glVertex2f(11,11);
    glVertex2f(11,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11,10);
    glVertex2f(11,11);
    glVertex2f(11.5,10.8);
    glVertex2f(12.5,10.8);
    glVertex2f(13,11);
    glVertex2f(13,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13,10);
    glVertex2f(13,11);
    glVertex2f(13.5,10.8);
    glVertex2f(14.5,10.8);
    glVertex2f(15,11);
    glVertex2f(15,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15,10);
    glVertex2f(15,11);
    glVertex2f(15.5,10.8);
    glVertex2f(16.5,10.8);
    glVertex2f(17,11);
    glVertex2f(17,10);
    glEnd();


}



void drawRain(){

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,-0.1,0);
        glVertex3f(rainX,-0.2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
          glColor3f(50, 38, 25);

        glVertex3f(rainX,-0.4,0);
        glVertex3f(rainX,-0.5,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,-0.7,0);
        glVertex3f(rainX,-0.8,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);
;
        glVertex3f(rainX,-1,0);
        glVertex3f(rainX,-1.1,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
         glColor3f(50, 38, 25);

        glVertex3f(rainX,-1.3,0);
        glVertex3f(rainX,-1.4,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,-1.6,0);
        glVertex3f(rainX,-1.7,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,-1.9,0);
        glVertex3f(rainX,-2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
           glColor3f(50, 38, 25);

        glVertex3f(rainX,0.1,0);
        glVertex3f(rainX,0.2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,0.4,0);
        glVertex3f(rainX,0.5,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,0.7,0);
        glVertex3f(rainX,0.8,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
          glColor3f(50, 38, 25);

        glVertex3f(rainX,1,0);
        glVertex3f(rainX,1.1,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
          glColor3f(50, 38, 25);

        glVertex3f(rainX,1.3,0);
        glVertex3f(rainX,1.4,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,1.6,0);
        glVertex3f(rainX,1.7,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;

    for(int i=0;i<100;i++){
        glBegin(GL_LINES);
            glColor3f(50, 38, 25);

        glVertex3f(rainX,1.9,0);
        glVertex3f(rainX,2,0);
        glEnd();
        rainX += 0.1;
    }

    rainX = -6;
}


void drawRedEllipse(void){
    GLint i;
    GLfloat xradius=3.5;
    GLfloat yradius=2;
    const GLfloat DEG2RAD = 3.14159/180;

    glColor3ub(242,46,49);

    glBegin(GL_POLYGON);
    for (i=0; i < 360; i++)
    {
        float degInRad = i*DEG2RAD;
        glVertex2f ( cos (degInRad) *xradius,  sin (degInRad) *yradius);
    }
    glEnd();
}



//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST); //enable a write to the depth buffering
}

//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0); //set up a perspective projection matrix
}

float _angle = 0.0;
//float _cameraAngle = 0.0;
//float _ang_tri = 0.0;



void update(int value){



    glutPostRedisplay(); //Tell GLUT that the display has changed

    //Tell GLUT to call update again in 25 milliseconds
    glutTimerFunc(25, update , 0);
}

void trainAnimation(int value) {

     train += 0.35f;
    if(train>50.0f){
        train = -20.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(25, trainAnimation, 0);
}

void carAnimation1(int value) {


    car1 += 0.03f;
    if(car1>10.0f){
        car1 = -5.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(25, carAnimation1, 0);
}


void flyAnimation(int value) {


    fly += 0.04f;
    if(fly>25.0f){
        //move=true;
        fly = -10.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(25, flyAnimation, 0);
}

void shipAnimation(int value) 
{

	if(ship >= 4.0f)
		revf = 1;

    if(ship < 0.0f)
    	revf = 0;

    if (revf == 0)
   		ship = ship + 0.04f;
   
    else
    	ship = ship - 0.04f;
    

    glutPostRedisplay();
    glutTimerFunc(25, shipAnimation, 0);

}



void rainAnimation(int value) {


    rain += 0.02f;
    if(rain>0.1f){
        //move=true;
        rain = -0.1f;
    }


    glutPostRedisplay();

    glutTimerFunc(25, rainAnimation, 0);
}




void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 'r':
        		
            	Rain = true;
                sky[0] = 128;
                sky[1] = 137;
                sky[2] = 140;
                cloud[0] = 40;
                cloud[1] = 49;
                cloud[2] = 17;
                sun[0] = 128;
                sun[1] = 137;
                sun[2] = 140;
				 water[0] = 102;
                water[1] = 126;
                water[2] = 44;
            


            break;
            case 'd':
            
			 Rain = false;
                sky[0] = 19;
                sky[1] = 190;
                sky[2] = 242;
                cloud[0] = 255;
                cloud[1] = 255;
                cloud[2] = 255;
                sun[0] = 219;
                sun[1] = 230;
                sun[2] = 21;
                soil[0] = 199;
                soil[1] = 192;
                soil[2] = 141;
                water[0] = 152;
                water[1] = 222;
                water[2] = 245;
                break;

    }
}

void drawtext(char *s)
	{ 
		glColor3f(1.0f, 0.0f, 0.0f); 
		glRasterPos2f(0.0f,0.0f);
		int j=0;
		while(s[j]!='\0')
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[j]);
			j++;
		}
	}

void textRedraw(int value)
{	
	if(rain == true)
		{
			drawtext("Before Pollution");
		}
	else{}	
	drawtext("After Pollution");
}


//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //The glClear function clears buffers to preset values.
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //replaces the current matrix with the identity matrix
   // glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units

    //Sky
    glPushMatrix();//glPushMatrix functions push  the current of matrix stack
    glScalef(6,1.4,1);
    glTranslatef(0,1.21,0);
    glColor3ub(sky[0], sky[1], sky[2]);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glPopMatrix(); //glpopmatrix function pop the current of matrix stack





     //Ground
    glPushMatrix();
    glTranslatef(0,-3.68,0);
    glScalef(6,4,1);
    //glColor3ub(209,197,136);
    glColor3ub(soil[0],soil[1],soil[3]);
    glBegin(GL_QUADS);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glPopMatrix();


     //SUN
    glPushMatrix();
    glTranslatef(-6,-_angle,0);
    glTranslatef(3.5,2,0);
    glScalef(1,1,0.1);
    glColor3ub(sun[1], sun[1], sun[2]);
    glutSolidSphere(0.4,40,40);
    glPopMatrix();
    glPushMatrix();

    //Cloud 1
    glPushMatrix();
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glTranslatef(-1,2.3,0);
    drawCloud();
    glPopMatrix();

    //Cloud 2
    glPushMatrix();
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glScalef(0.7,0.7,1);
    glTranslatef(1,2.5,0);
    drawCloud();
    glPopMatrix();

    //Cloud 3
    glPushMatrix();
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glScalef(0.7,0.7,1);
    glTranslatef(1,2.5,0);
   drawCloud();
    glPopMatrix();


    //Cloud 4
    glPushMatrix();
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glScalef(0.7,0.7,1);
    glTranslatef(2.6,2.7,0);
    drawCloud();
    glPopMatrix();


    //Cloud 5
    glPushMatrix();
    glColor3ub(cloud[0], cloud[1], cloud[2]);
    glTranslatef(-3.6,2.0,0);
    drawCloud();
    glPopMatrix();

    glPopMatrix();
    glTranslatef(0,0,0.1);

    //smokey
    glPushMatrix();
    glTranslatef(-4,1.0,0);
    glColor3ub(109, 111, 112);
    glBegin(GL_LINES);
    draw_circle(495, 225, 10);
    draw_circle(495, 230, 8);
    draw_circle(495, 235, 6);
    glEnd();
    glPopMatrix();




    //road
    glPushMatrix();
    drawRoad();
    glPopMatrix();


    //Rail Track
    glPushMatrix();
    glTranslated(0,0.06,0);
    drawRailTrack();
    glPopMatrix();



    //Train
    glPushMatrix();
    glScalef(0.2, 0.2, 0.1);
    glTranslatef(9, 2.5, 1);
    glTranslatef(-train, 0, 0);
    drawTrain();
    glPopMatrix();


     //car
    glPushMatrix();
    glTranslatef(car1,0,0);
    glTranslatef(0,0.15,1);
    glScalef(0.2,0.2,1);
    drawCar();
    glPopMatrix();

    //car
    glPushMatrix();
    glTranslatef(car1,0,0);
    glTranslatef(-2,0.15,1);
    glScalef(0.2,0.2,1);
    drawCar();
    glPopMatrix();

    //car
    glPushMatrix();
    glTranslatef(-car1,0,0);
    glTranslatef(3,0.3,1);
    glScalef(0.2,0.2,1);
    drawCar();
    glPopMatrix();

    //car
    glPushMatrix();
    glTranslatef(-car1,0,0);
    glTranslatef(5,0.3,1);
    glScalef(0.2,0.2,1);
    drawCar();
    glPopMatrix();

    //car
    glPushMatrix();
    glTranslatef(-car1,0,0);
    glTranslatef(3,0.3,1);
    glScalef(0.2,0.2,1);
    drawCar();
    glPopMatrix();

	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(0,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey

	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(-1.2,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(-3.15,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(-2.15,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(-4.15,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(-3.7,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(2,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(3,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey
	//smokeys
	glPushMatrix();
    glColor3ub(smoke[0], smoke[1], smoke[2]);
    glTranslatef(4,car1,0);
    drawSmoke();
    glPopMatrix();
	//smokey


     glPushMatrix();
	    glTranslatef(-3.7,-0.7,-0.5);
    glScalef(0.55,0.55,1);

    glBegin(GL_POLYGON);//volcano
    glColor3ub(164, 176, 178);
    glVertex2i(300, 180);
    glVertex2i(440, 330);
    glVertex2i(490, 330);
    glVertex2i(580, 250);
    glVertex2i(590, 187);
    glEnd();
    glPopMatrix();



    //Building
    glPushMatrix();
    glTranslatef(2.95,-0.01,1);
    glScalef(0.003,0.002,1);
    building();
    glPopMatrix();


    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.61,0.85,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();

    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.35,0.85,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();

    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.61,0.62,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();

    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.35,0.62,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();

    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.61,0.32,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();


    //buiding 1 WIndow
    glPushMatrix();
    glTranslatef(3.35,0.32,1);
    glColor3f(1,1,1);
    glScalef(0.7,0.7,0.1);
    glutSolidCube(0.12);
    glPopMatrix();


    //plane
    glPushMatrix();
    glTranslatef(fly,0,0);
    glTranslatef(-2.5,3,0);//-16
    drawPlane();
    glPopMatrix();


    //house 1
    glPushMatrix();
    glTranslatef(-1.2,-0.9,0.5);
    glScalef(0.55,0.55,1);
    DrawHouse();
    glPopMatrix();

	//house 2
    glPushMatrix();
    glTranslatef(-3.15,-1.7,-0.5);
    glScalef(0.7,0.7,1);
    DrawHouse();
    glPopMatrix();

	//house 2
    glPushMatrix();
    glTranslatef(-2.15,-1.7,-0.5);
    glScalef(0.7,0.7,1);
    DrawHouse();
    glPopMatrix();

	//house 2
    glPushMatrix();
    glTranslatef(-4.15,-1.7,-0.5);
    glScalef(0.7,0.7,1);
    DrawHouse();
    glPopMatrix();

	//house 2
    glPushMatrix();
    glTranslatef(-3.7,-0.7,-0.5);
    glScalef(0.7,0.7,1);
    DrawHouse();
    glPopMatrix();

	//house 2
    glPushMatrix();
    glTranslatef(-3.7,-0.7,-0.5);
    glScalef(0.7,0.7,1);
    DrawHouse();
    glPopMatrix();

     //ship 1
    glPushMatrix();
    glTranslatef(ship,0,0);
    glTranslatef(-1,-1.5,2);
    glScalef(0.05,0.05,1);
    drawBoat();
    glPopMatrix();


	glColor3ub(109, 111, 112);
    glBegin(GL_LINES);
    draw_circle(495, 225, 10);
    draw_circle(495, 230, 8);
    draw_circle(495, 235, 6);
    glEnd();


	 if(Rain){

        //rain
        glPushMatrix();
        glTranslatef(0,-rain,3);
        glRotatef(10,0,0,1);
        drawRain();
        glPopMatrix();


    }



   //water circle
    glPushMatrix();
    glColor3ub(water[0],water[1],water[2]);
    glTranslatef(2.5,-3.05,1.35);
    glScalef(1.3,0.8,0.1);
    glutSolidSphere(3.3,15,15);
     //glutSolidCube(0.5);
    glPopMatrix();

    /*
    glPushMatrix();
    glColor3ub(163,147,135);
    glTranslatef(-1.0,-0.6,1.1);
    glScalef(4.0,0.15,0.1);
     glutSolidCube(2.5);
    glPopMatrix();
   */


    glPushMatrix();
    drawtext("Before Pollution");
    glPopMatrix();

    glutSwapBuffers();  //swaps the buffers of the current window if double buffered
}

int main(int argc, char** argv) {
  //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1270, 690);

    //Create the window
    glutCreateWindow("Transformations");
    initRendering(); //Initializes 3D rendering


    glutDisplayFunc(drawScene);  //Set handler functions

    glutReshapeFunc(handleResize); ////Called when the window is resized

     glutTimerFunc(25, update, 0); //registers a timer callback to be triggered in a specified number of milliseconds.
    glutTimerFunc(25, trainAnimation, 0); //Add a timer
    glutTimerFunc(25, carAnimation1, 0); //Add a timer
    glutTimerFunc(25, flyAnimation, 0); //Add a timer
    glutTimerFunc(25, shipAnimation, 0);
    glutTimerFunc(25, rainAnimation, 0);
    glutTimerFunc(25, textRedraw, 0);
    glutKeyboardFunc(keyboard);  //sets the keyboard callback for the current window.


    glutMainLoop();
}

