#include "spaceship.h"
#include <GL\glut.h>

void spaceShipABody(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1,1,1);


    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(10,-5,0);
    glRotatef(270,0,1,0);
    gluCylinder(pObj, 2.0f, 2.0f, 20.0f, 26, 13);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glTranslatef(0,0,20);
    gluDisk(pObj, 0, 2.0, 26, 13);
    gluCylinder(pObj, 1.5f, 1.5f, 5.0f, 26, 13);
    glColor3f(0,0,0);
    glTranslatef(0,0,5);
    gluDisk(pObj, 0, 1.5, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-8,-4,13);
    glVertex3f(-8,-6,13);
    glVertex3f(8,-6,13);
    glVertex3f(8,-4,13);
    //left
    glVertex3f(-8,-4,13);
    glVertex3f(-8,-4,-13);
    glVertex3f(-8,-6,-13);
    glVertex3f(-8,-6,13);
    //right
    glVertex3f(8,-4,13);
    glVertex3f(8,-6,13);
    glVertex3f(8,-6,-13);
    glVertex3f(8,-4,-13);
    //up
    glVertex3f(8,-4,-13);
    glVertex3f(-8,-4,-13);
    glVertex3f(-8,-4,13);
    glVertex3f(8,-4,13);
    //down
    glVertex3f(8,-6,13);
    glVertex3f(-8,-6,13);
    glVertex3f(-8,-6,-13);
    glVertex3f(8,-6,-13);
    //back
    glVertex3f(8,-6,-13);
    glVertex3f(-8,-6,-13);
    glVertex3f(-8,-4,-13);
    glVertex3f(8,-4,-13);
    glEnd();
    glPopMatrix();

    //core
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,5,0);
    gluSphere(pObj, 8.0f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0,10,0);
    glScalef(5,1,5);
    gluSphere(pObj, 4.0f, 26, 26);
    glColor3f(0,0,1);
    glTranslatef(0,3,0);
    gluSphere(pObj, 3.0f, 26, 26);
    glPopMatrix();
}
void spaceShipASupport(void)
{

    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(0,-5,13);
    glScalef(4,1,1);
    gluSphere(pObj, 3.0f, 26, 26);
    glPopMatrix();

    //center support
    glPushMatrix();
    glColor3f(0.7f,0.7f,0.7f);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-1,10,14);
    glVertex3f(-1,-6,14);
    glVertex3f(1,-6,14);
    glVertex3f(1,10,14);
    //left
    glVertex3f(-1,10,14);
    glVertex3f(-1,10,12);
    glVertex3f(-1,-6,12);
    glVertex3f(-1,-6,14);
    //right
    glVertex3f(1,10,14);
    glVertex3f(1,-6,14);
    glVertex3f(1,-6,12);
    glVertex3f(1,10,12);
    //up
    glVertex3f(1,10,12);
    glVertex3f(-1,10,12);
    glVertex3f(-1,10,14);
    glVertex3f(1,10,14);
    //down
    glVertex3f(1,-6,14);
    glVertex3f(-1,-6,14);
    glVertex3f(-1,-6,12);
    glVertex3f(1,-6,12);
    //back
    glVertex3f(1,-6,12);
    glVertex3f(-1,-6,12);
    glVertex3f(-1,10,12);
    glVertex3f(1,10,12);
    glEnd();
    glPopMatrix();

    //right support
    glPushMatrix();
    glColor3f(0.7f,0.7f,0.7f);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(9,10,14);
    glVertex3f(7,-6,14);
    glVertex3f(9,-6,14);
    glVertex3f(11,10,14);
    //left
    glVertex3f(9,10,14);
    glVertex3f(9,10,12);
    glVertex3f(7,-6,12);
    glVertex3f(7,-6,14);
    //right
    glVertex3f(11,10,14);
    glVertex3f(9,-6,14);
    glVertex3f(9,-6,12);
    glVertex3f(11,10,12);
    //up
    glVertex3f(11,10,12);
    glVertex3f(9,10,12);
    glVertex3f(9,10,14);
    glVertex3f(11,10,14);
    //down
    glVertex3f(9,-6,14);
    glVertex3f(7,-6,14);
    glVertex3f(7,-6,12);
    glVertex3f(9,-6,12);
    //back
    glVertex3f(9,-6,12);
    glVertex3f(7,-6,12);
    glVertex3f(9,10,12);
    glVertex3f(11,10,12);
    glEnd();
    glPopMatrix();

    //left support
    glPushMatrix();
    glColor3f(0.7f,0.7f,0.7f);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-11,10,14);
    glVertex3f(-9,-6,14);
    glVertex3f(-7,-6,14);
    glVertex3f(-9,10,14);
    //left
    glVertex3f(-11,10,14);
    glVertex3f(-11,10,12);
    glVertex3f(-9,-6,12);
    glVertex3f(-9,-6,14);
    //right
    glVertex3f(-9,10,14);
    glVertex3f(-7,-6,14);
    glVertex3f(-7,-6,12);
    glVertex3f(-9,10,12);
    //up
    glVertex3f(-9,10,12);
    glVertex3f(-11,10,12);
    glVertex3f(-11,10,14);
    glVertex3f(-9,10,14);
    //down
    glVertex3f(-7,-6,14);
    glVertex3f(-9,-6,14);
    glVertex3f(-9,-6,12);
    glVertex3f(-7,-6,12);
    //back
    glVertex3f(-7,-6,12);
    glVertex3f(-9,-6,12);
    glVertex3f(-11,10,12);
    glVertex3f(-9,10,12);
    glEnd();
    glPopMatrix();
}
void spaceShipACanon(void)
{
GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(0,0,0);

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1,0.5,0);
    gluCylinder(pObj, 0.1f, 0.1f, 2.0f, 26, 13);
    glTranslatef(0,0,2);
    gluDisk(pObj, 0, 0.1, 26, 13);
    glTranslatef(2,0,0);
    gluDisk(pObj, 0, 0.1, 26, 13);
    glTranslatef(0,0,-2);
    gluCylinder(pObj, 0.1f, 0.1f, 2.0f, 26, 13);

    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-2,1,0.5);
    glVertex3f(-2,-1,0.5);
    glVertex3f(2,-1,0.5);
    glVertex3f(2,1,0.5);
    //left
    glVertex3f(-2,1,0.5);
    glVertex3f(-2,1,-0.5);
    glVertex3f(-2,-1,-0.5);
    glVertex3f(-2,-1,0.5);
    //right
    glVertex3f(2,1,0.5);
    glVertex3f(2,-1,0.5);
    glVertex3f(2,-1,-0.5);
    glVertex3f(2,1,-0.5);
    //up
    glVertex3f(2,1,-0.5);
    glVertex3f(-2,1,-0.5);
    glVertex3f(-2,1,0.5);
    glVertex3f(2,1,0.5);
    //down
    glVertex3f(2,-1,0.5);
    glVertex3f(-2,-1,0.5);
    glVertex3f(-2,-1,-0.5);
    glVertex3f(2,-1,-0.5);
    //back
    glVertex3f(2,-1,-0.5);
    glVertex3f(-2,-1,-0.5);
    glVertex3f(-2,1,-0.5);
    glVertex3f(2,1,-0.5);
    glEnd();
    glPopMatrix();

    gluDeleteQuadric(pObj);
}

void spaceShipAHead(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(10,1,5);
    glVertex3f(-10,1,1);
    glVertex3f(-10,-1,1);
    glVertex3f(10,-1,5);
    //left
    glVertex3f(-10,1,1);
    glVertex3f(-10,1,-1);
    glVertex3f(-10,-1,-1);
    glVertex3f(-10,-1,1);
    //right
    glVertex3f(10,1,-1);
    glVertex3f(10,1,5);
    glVertex3f(10,-1,5);
    glVertex3f(10,-1,-1);
    //up
    glVertex3f(10,1,-1);
    glVertex3f(-10,1,-1);
    glVertex3f(-10,1,1);
    glVertex3f(10,1,5);
    //down
    glVertex3f(10,-1,5);
    glVertex3f(-10,-1,1);
    glVertex3f(-10,-1,-1);
    glVertex3f(10,-1,-1);
    //back
    glVertex3f(10,-1,-1);
    glVertex3f(-10,-1,-1);
    glVertex3f(-10,1,-1);
    glVertex3f(10,1,-1);
    glEnd();
    glPopMatrix();

    //upHead
    glPushMatrix();
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(9.5,1.1,4.5);
    glVertex3f(-9.5,1.1,0.5);
    glVertex3f(-9.5,1,0.5);
    glVertex3f(9.5,1,4.5);
    //left
    glVertex3f(-9.5,1.1,0.5);
    glVertex3f(-9.5,1.1,-0.5);
    glVertex3f(-9.5,1,-0.5);
    glVertex3f(-9.5,1,0.5);
    //right
    glVertex3f(9.5,1.1,-0.5);
    glVertex3f(9.5,1.1,4.5);
    glVertex3f(9.5,1,4.5);
    glVertex3f(9.5,1,-0.5);
    //up
    glVertex3f(9.5,1.1,-0.5);
    glVertex3f(-9.5,1.1,-0.5);
    glVertex3f(-9.5,1.1,0.5);
    glVertex3f(9.5,1.1,4.5);
    //down
    glVertex3f(9.5,1,4.5);
    glVertex3f(-9.5,1,0.5);
    glVertex3f(-9.5,1,-0.5);
    glVertex3f(9.5,1,-0.5);
    //back
    glVertex3f(9.5,1,-0.5);
    glVertex3f(-9.5,1,-0.5);
    glVertex3f(-9.5,1.1,-0.5);
    glVertex3f(9.5,1.1,-0.5);
    glEnd();
    glPopMatrix();

    //downHead
    //upHead
    glPushMatrix();
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(9.5,-1,4.5);
    glVertex3f(-9.5,-1,0.5);
    glVertex3f(-9.5,-1.1,0.5);
    glVertex3f(9.5,-1.1,4.5);
    //left
    glVertex3f(-9.5,-1,0.5);
    glVertex3f(-9.5,-1,-0.5);
    glVertex3f(-9.5,-1.1,-0.5);
    glVertex3f(-9.5,-1.1,0.5);
    //right
    glVertex3f(9.5,-1,-0.5);
    glVertex3f(9.5,-1,4.5);
    glVertex3f(9.5,-1.1,4.5);
    glVertex3f(9.5,-1.1,-0.5);
    //up
    glVertex3f(9.5,-1,-0.5);
    glVertex3f(-9.5,-1,-0.5);
    glVertex3f(-9.5,-1,0.5);
    glVertex3f(9.5,-1,4.5);
    //down
    glVertex3f(9.5,-1.1,4.5);
    glVertex3f(-9.5,-1.1,0.5);
    glVertex3f(-9.5,-1.1,-0.5);
    glVertex3f(9.5,-1.1,-0.5);
    //back
    glVertex3f(9.5,-1.1,-0.5);
    glVertex3f(-9.5,-1.1,-0.5);
    glVertex3f(-9.5,-1,-0.5);
    glVertex3f(9.5,-1,-0.5);
    glEnd();
    glPopMatrix();

    //headCanon
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-1,0,0);
    glRotatef(270,0,1,0);
    gluCylinder(pObj, 0.5f, 0.5f, 20.0f, 26, 13);
    glColor3f(0.3f,0.3f,0.3f);
    glTranslatef(0,0,20);
    gluDisk(pObj, 0, 0.5, 26, 13);
    glPopMatrix();

     gluDeleteQuadric(pObj);
}
void spaceShipA(void)
{
    spaceShipABody();
    spaceShipASupport();

    glPushMatrix();
    glTranslatef(0,0,-26);
    spaceShipASupport();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,12.5,11);
    glRotatef(45,0,1,0);
    spaceShipACanon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,12.5,11);
    glRotatef(315,0,1,0);
    spaceShipACanon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,12.5,-11);
    glRotatef(225,0,1,0);
    spaceShipACanon();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,12.5,-11);
    glRotatef(135,0,1,0);
    spaceShipACanon();
    glPopMatrix();

    glPushMatrix();
    glScalef(1.5,1,1);
    glTranslatef(-20,10,7);
    spaceShipAHead();
    glTranslatef(0,0,-14);
    glRotatef(180,1,0,0);
    spaceShipAHead();

    glPopMatrix();
}

void spaceShip1Engine(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1,1,1);

    glPushMatrix();
    glColor3f(0,0,0);
    glScalef(1,1,3);
    gluSphere(pObj, 1.0f, 26, 26);

    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,0,-3);
    gluCylinder(pObj, 0.5f, 0.5f, 6.0f, 26, 13);
    glTranslatef(0,0,5.8);
    glColor3f(1,0,0);
    gluDisk(pObj, 0, 0.5, 26, 13);

    glPopMatrix();

    gluDeleteQuadric(pObj);
}
void spaceShip1Wing(void)
{
 GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(5,0.5,10);
    glVertex3f(4,0.5,10);
    glVertex3f(4,-0.5,10);
    glVertex3f(5,-0.5,10);
    //left
    glVertex3f(4,0.5,10);
    glVertex3f(0,0.5,0);
    glVertex3f(0,-0.5,0);
    glVertex3f(4,-0.5,10);
    //right
    glVertex3f(5,0.5,0);
    glVertex3f(5,0.5,10);
    glVertex3f(5,-0.5,10);
    glVertex3f(5,-0.5,0);
    //up
    glVertex3f(5,0.5,0);
    glVertex3f(0,0.5,0);
    glVertex3f(4,0.5,10);
    glVertex3f(5,0.5,10);
    //down
    glVertex3f(5,-0.5,10);
    glVertex3f(4,-0.5,10);
    glVertex3f(0,-0.5,0);
    glVertex3f(5,-0.5,0);
    //back
    glVertex3f(5,-0.5,0);
    glVertex3f(0,-0.5,0);
    glVertex3f(0,0.5,0);
    glVertex3f(5,0.5,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(4,0,10);
    glScalef(8,1,1);
    gluSphere(pObj, 0.5f, 26, 26);
    glPopMatrix();
    gluDeleteQuadric(pObj);
}
void spaceShipVerticalWing(void)
{
     GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(5,5,0.5);
    glVertex3f(4,5,0.5);
    glVertex3f(0,0,0.5);
    glVertex3f(5,0,0.5);
    //left
    glVertex3f(4,5,0.5);
    glVertex3f(4,5,-0.5);
    glVertex3f(0,0,-0.5);
    glVertex3f(0,0,0.5);
    //right
    glVertex3f(5,5,-0.5);
    glVertex3f(5,5,0.5);
    glVertex3f(5,0,0.5);
    glVertex3f(5,0,-0.5);
    //up
    glVertex3f(5,5,-0.5);
    glVertex3f(0,0,-0.5);
    glVertex3f(0,0,0.5);
    glVertex3f(5,5,0.5);
    //down
    glVertex3f(5,0,0.5);
    glVertex3f(0,0,0.5);
    glVertex3f(0,0,-0.5);
    glVertex3f(5,0,-0.5);
    //back
    glVertex3f(0,0,-0.5);
    glVertex3f(5,0,-0.5);
    glVertex3f(5,5,-0.5);
    glVertex3f(4,5,-0.5);
    glEnd();
    glPopMatrix();

    gluDeleteQuadric(pObj);
}
void spaceShip1Body(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1,1,1);

    glPushMatrix();
    gluCylinder(pObj, 2.0f, 2.0f, 10.0f, 26, 13);
    glTranslatef(0,0,10);
    gluDisk(pObj, 0, 2.0, 26, 13);

    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(1,1,3);
    gluSphere(pObj, 2.0f, 26, 26);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,1.5,0);
    glScalef(1,1,3);
    gluSphere(pObj, 1.0f, 26, 26);
    glPopMatrix();

    gluDeleteQuadric(pObj);
}
void spaceShip1 (void)
{
    glPushMatrix();
    glTranslatef(4,1,0);
    glRotatef(90,0,1,0);
    spaceShip1Engine();
    glTranslatef(0.8,-1.5,0);
    spaceShip1Engine();
    glTranslatef(-1.6,0,0);
    spaceShip1Engine();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4.5,0,0);
    glRotatef(90,0,1,0);
    spaceShip1Body();
    glPopMatrix();
    spaceShipVerticalWing();
    spaceShip1Wing();
    glPushMatrix();
    glRotated(180,1,0,0);
    spaceShip1Wing();
    glPopMatrix();
}
void spaceShip2Engine(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(0,0,0);
    glScalef(1,1,3);
    gluSphere(pObj, 1.0f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,0,-3);
    gluCylinder(pObj, 0.5f, 0.5f, 6.0f, 26, 13);
    glTranslatef(0,0,5.8);
    glColor3f(1,0,0);
    gluDisk(pObj, 0, 0.5, 26, 13);
    glTranslatef(0,0,-5.6);
    gluDisk(pObj, 0, 0.5, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,1,0);
    glScalef(0.5,0.5,0.5);
    spaceShipVerticalWing();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(0.5,0.5,0.5);
    spaceShipVerticalWing();
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(0.5,0.5,0.5);
    spaceShipVerticalWing();
    glPopMatrix();

    glPushMatrix();
    glRotatef(270,0,0,1);
    glRotatef(90,0,1,0);
    glScalef(0.5,0.5,0.5);
    spaceShipVerticalWing();
    glPopMatrix();

    gluDeleteQuadric(pObj);
}
void spaceShip2Support(void)
{
     GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(8,7,0.5);
    glVertex3f(7,7,0.5);
    glVertex3f(8,-7,0.5);
    glVertex3f(7,-7,0.5);
    //left
    glVertex3f(7,7,0.5);
    glVertex3f(7,7,-0.5);
    glVertex3f(7,-7,-0.5);
    glVertex3f(7,-7,0.5);
    //right
    glVertex3f(8,7,-0.5);
    glVertex3f(8,7,0.5);
    glVertex3f(8,-7,0.5);
    glVertex3f(8,-7,-0.5);
    //up
    glVertex3f(8,7,-0.5);
    glVertex3f(7,7,-0.5);
    glVertex3f(7,7,0.5);
    glVertex3f(8,7,0.5);
    //down
    glVertex3f(8,-7,0.5);
    glVertex3f(7,-7,0.5);
    glVertex3f(7,-7,-0.5);
    glVertex3f(8,-7,-0.5);
    //back
    glVertex3f(8,-7,-0.5);
    glVertex3f(7,-7,-0.5);
    glVertex3f(7,7,-0.5);
    glVertex3f(8,7,-0.5);
    glEnd();
    glPopMatrix();

    gluDeleteQuadric(pObj);

}
void spaceShip2Body(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1,1,1);


    glPushMatrix();
    gluCylinder(pObj, 2.0f, 2.0f, 10.0f, 26, 13);
    glTranslatef(0,0,10);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glScalef(1,1,3);
    gluSphere(pObj, 2.0f, 26, 26);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,1.5,0);
    glScalef(1,1,3);
    gluSphere(pObj, 1.0f, 26, 26);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    spaceShip2Support();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glRotatef(-90,0,1,0);
    spaceShip2Support();
    glPopMatrix();

    gluDeleteQuadric(pObj);
}
void spaceShip2(void)
{
    //body
    glPushMatrix();
    glRotatef(90,0,1,0);
    spaceShip2Body();
    glPopMatrix();

    //engine
    glPushMatrix();
    glTranslatef(9,0,0);
    glRotatef(270,0,1,0);
    spaceShip2Engine();
    glTranslatef(0,7,0);
    spaceShip2Engine();
    glTranslatef(0,-14,0);
    spaceShip2Engine();
    glTranslatef(7,7,0);
    spaceShip2Engine();
    glTranslatef(-14,0,0);
    spaceShip2Engine();
    glPopMatrix();
}
void aircraftSmallDeck(void)
{
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-10,-7,-5.5);
    glVertex3f(-10,-7,-6.5);
    glVertex3f(-10,-8,-6.5);
    glVertex3f(-10,-8,-5.5);
    //left
    glVertex3f(-10,-7,-6.5);
    glVertex3f(0,-7,-8.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(-10,-8,-6.5);
    //right
    glVertex3f(0,-7,-7.5);
    glVertex3f(-10,-7,-5.5);
    glVertex3f(-10,-8,-5.5);
    glVertex3f(0,-8,-7.5);
    //up
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-7,-8.5);
    glVertex3f(-10,-7,-6.5);
    glVertex3f(-10,-7,-5.5);
    //down
    glVertex3f(-10,-8,-5.5);
    glVertex3f(-10,-8,-6.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(0,-8,-7.5);
    //back
    glVertex3f(0,-8,-8.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-7,-8.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-10,-7,-2.5);
    glVertex3f(-10,-7,-3.5);
    glVertex3f(-10,-8,-3.5);
    glVertex3f(-10,-8,-2.5);
    //left
    glVertex3f(-10,-7,-3.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(-10,-8,-3.5);
    //right
    glVertex3f(0,-7,-2.5);
    glVertex3f(-10,-7,-2.5);
    glVertex3f(-10,-8,-2.5);
    glVertex3f(0,-8,-2.5);
    //up
    glVertex3f(0,-7,-2.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(-10,-7,-3.5);
    glVertex3f(-10,-7,-2.5);
    //down
    glVertex3f(-10,-8,-2.5);
    glVertex3f(-10,-8,-3.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(0,-8,-2.5);
    //back
    glVertex3f(0,-8,-2.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-7,-2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-11,-7,-2.5);
    glVertex3f(-11,-7,-5.5);
    glVertex3f(-11,-8,-5.5);
    glVertex3f(-11,-8,-2.5);
    //left
    glVertex3f(-11,-7,-5.5);
    glVertex3f(-10,-7,-6.5);
    glVertex3f(-10,-8,-6.5);
    glVertex3f(-11,-8,-5.5);
    //right
    glVertex3f(-10,-7,-2.5);
    glVertex3f(-11,-7,-2.5);
    glVertex3f(-11,-8,-2.5);
    glVertex3f(-10,-8,-2.5);
    //up
    glVertex3f(-10,-7,-2.5);
    glVertex3f(-10,-7,-6.5);
    glVertex3f(-11,-7,-5.5);
    glVertex3f(-11,-7,-2.5);
    //down
    glVertex3f(-11,-8,-2.5);
    glVertex3f(-11,-8,-5.5);
    glVertex3f(-10,-8,-6.5);
    glVertex3f(-10,-8,-2.5);
    //back
    glVertex3f(-10,-8,-2.5);
    glVertex3f(-10,-8,-6.5);
    glVertex3f(-10,-7,-6.5);
    glVertex3f(-10,-7,-2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-7,-5.5);
    glVertex3f(0,-8,-5.5);
    glVertex3f(0,-8,-3.5);
    //left
    glVertex3f(-10,-7,-5.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(-10,-8,-5.5);
    //right
    glVertex3f(0,-7,-3.5);
    glVertex3f(-10,-7,-3.5);
    glVertex3f(-10,-8,-3.5);
    glVertex3f(0,-8,-3.5);
    //up
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(-10,-7,-5.5);
    glVertex3f(-10,-7,-3.5);
    //down
    glVertex3f(-10,-8,-3.5);
    glVertex3f(-10,-8,-5.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(0,-8,-3.5);
    //back
    glVertex3f(0,-8,-3.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-7,-3.5);
    glEnd();
    glPopMatrix();
}
void aircraftDeck(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,0,-0.5);
    glVertex3f(0,0,-4.5);
    glVertex3f(0,-1,-4.5);
    glVertex3f(0,-1,-0.5);
    //left
    glVertex3f(0,0,-4.5);
    glVertex3f(40,0,-4.5);
    glVertex3f(40,-1,-4.5);
    glVertex3f(0,-1,-4.5);
    //right
    glVertex3f(40,0,-0.5);
    glVertex3f(0,0,-0.5);
    glVertex3f(0,-1,-0.5);
    glVertex3f(40,-1,-0.5);
    //up
    glVertex3f(40,0,-0.5);
    glVertex3f(40,0,-4.5);
    glVertex3f(0,0,-4.5);
    glVertex3f(0,0,-0.5);
    //down
    glVertex3f(0,-1,-0.5);
    glVertex3f(0,-1,-4.5);
    glVertex3f(40,-1,-4.5);
    glVertex3f(40,-1,-0.5);
    //back
    glVertex3f(40,-1,-0.5);
    glVertex3f(40,-1,-4.5);
    glVertex3f(40,0,-4.5);
    glVertex3f(40,0,-0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,0,-6.5);
    glVertex3f(0,0,-10.5);
    glVertex3f(0,-1,-10.5);
    glVertex3f(0,-1,-6.5);
    //left
    glVertex3f(0,0,-10.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(40,-1,-10.5);
    glVertex3f(0,-1,-10.5);
    //right
    glVertex3f(40,0,-6.5);
    glVertex3f(0,0,-6.5);
    glVertex3f(0,-1,-6.5);
    glVertex3f(40,-1,-6.5);
    //up
    glVertex3f(40,0,-6.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(0,0,-10.5);
    glVertex3f(0,0,-6.5);
    //down
    glVertex3f(0,-1,-6.5);
    glVertex3f(0,-1,-10.5);
    glVertex3f(40,-1,-10.5);
    glVertex3f(40,-1,-6.5);
    //back
    glVertex3f(40,-1,-6.5);
    glVertex3f(40,-1,-10.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(40,0,-6.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,0,-4.5);
    glVertex3f(0,0,-6.5);
    glVertex3f(0,-1,-6.5);
    glVertex3f(0,-1,-4.5);
    //left
    glVertex3f(0,0,-6.5);
    glVertex3f(40,0,-6.5);
    glVertex3f(40,-1,-6.5);
    glVertex3f(0,-1,-6.5);
    //right
    glVertex3f(40,0,-4.5);
    glVertex3f(0,0,-4.5);
    glVertex3f(0,-1,-4.5);
    glVertex3f(40,-1,-4.5);
    //up
    glVertex3f(40,0,-4.5);
    glVertex3f(40,0,-6.5);
    glVertex3f(0,0,-6.5);
    glVertex3f(0,0,-4.5);
    //down
    glVertex3f(0,-1,-4.5);
    glVertex3f(0,-1,-6.5);
    glVertex3f(40,-1,-6.5);
    glVertex3f(40,-1,-4.5);
    //back
    glVertex3f(40,-1,-4.5);
    glVertex3f(40,-1,-6.5);
    glVertex3f(40,0,-6.5);
    glVertex3f(40,0,-4.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-7,-2.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(0,-8,-2.5);
    //left
    glVertex3f(0,-7,-3.5);
    glVertex3f(40,-7,-3.5);
    glVertex3f(40,-8,-3.5);
    glVertex3f(0,-8,-3.5);
    //right
    glVertex3f(40,-7,-2.5);
    glVertex3f(0,-7,-2.5);
    glVertex3f(0,-8,-2.5);
    glVertex3f(40,-8,-2.5);
    //up
    glVertex3f(40,-7,-2.5);
    glVertex3f(40,-7,-3.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-7,-2.5);
    //down
    glVertex3f(0,-8,-2.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(40,-8,-3.5);
    glVertex3f(40,-8,-2.5);
    //back
    glVertex3f(40,-8,-2.5);
    glVertex3f(40,-8,-3.5);
    glVertex3f(40,-7,-3.5);
    glVertex3f(40,-7,-2.5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-1,-2.5);
    glVertex3f(0,-1,-8.5);
    glVertex3f(0,-2,-8.5);
    glVertex3f(0,-2,-2.5);
    //left
    glVertex3f(0,-1,-8.5);
    glVertex3f(40,-1,-8.5);
    glVertex3f(40,-2,-8.5);
    glVertex3f(0,-2,-8.5);
    //right
    glVertex3f(40,-1,-2.5);
    glVertex3f(0,-1,-2.5);
    glVertex3f(0,-2,-2.5);
    glVertex3f(40,-2,-2.5);
    //up
    glVertex3f(40,-1,-2.5);
    glVertex3f(40,-1,-8.5);
    glVertex3f(0,-1,-8.5);
    glVertex3f(0,-1,-2.5);
    //down
    glVertex3f(0,-2,-2.5);
    glVertex3f(0,-2,-8.5);
    glVertex3f(40,-2,-8.5);
    glVertex3f(40,-2,-2.5);
    //back
    glVertex3f(40,-2,-2.5);
    glVertex3f(40,-2,-8.5);
    glVertex3f(40,-1,-8.5);
    glVertex3f(40,-1,-2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-8,-2.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(0,-10,-8.5);
    glVertex3f(0,-10,-2.5);
    //left
    glVertex3f(0,-8,-8.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(40,-10,-8.5);
    glVertex3f(0,-10,-8.5);
    //right
    glVertex3f(40,-8,-2.5);
    glVertex3f(0,-8,-2.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(40,-10,-2.5);
    //up
    glVertex3f(40,-8,-2.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(0,-8,-2.5);
    //down
    glVertex3f(0,-10,-2.5);
    glVertex3f(0,-10,-8.5);
    glVertex3f(40,-10,-8.5);
    glVertex3f(40,-10,-2.5);
    //back
    glVertex3f(40,-10,-2.5);
    glVertex3f(40,-10,-8.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(40,-8,-2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-1,-8.5);
    glVertex3f(0,-1,-9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-10,-8.5);
    //left
    glVertex3f(0,-1,-9.5);
    glVertex3f(40,-1,-9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(0,-10,-9.5);
    //right
    glVertex3f(40,-1,-8.5);
    glVertex3f(0,-1,-8.5);
    glVertex3f(0,-10,-8.5);
    glVertex3f(40,-10,-8.5);
    //up
    glVertex3f(40,-1,-8.5);
    glVertex3f(40,-1,-9.5);
    glVertex3f(0,-1,-9.5);
    glVertex3f(0,-1,-8.5);
    //down
    glVertex3f(0,-10,-8.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-10,-8.5);
    //back
    glVertex3f(40,-10,-8.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-1,-9.5);
    glVertex3f(40,-1,-8.5);
    glEnd();
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-1,-1.5);
    glVertex3f(0,-1,-2.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(0,-10,-1.5);
    //left
    glVertex3f(0,-1,-2.5);
    glVertex3f(40,-1,-2.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(0,-10,-2.5);
    //right
    glVertex3f(40,-1,-1.5);
    glVertex3f(0,-1,-1.5);
    glVertex3f(0,-10,-1.5);
    glVertex3f(40,-10,-1.5);
    //up
    glVertex3f(40,-1,-1.5);
    glVertex3f(40,-1,-2.5);
    glVertex3f(0,-1,-2.5);
    glVertex3f(0,-1,-1.5);
    //down
    glVertex3f(0,-10,-1.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(40,-10,-1.5);
    //back
    glVertex3f(40,-10,-1.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(40,-1,-2.5);
    glVertex3f(40,-1,-1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(0,-8,-3.5);
    //left
    glVertex3f(0,-7,-7.5);
    glVertex3f(40,-7,-7.5);
    glVertex3f(40,-8,-7.5);
    glVertex3f(0,-8,-7.5);
    //right
    glVertex3f(40,-7,-3.5);
    glVertex3f(0,-7,-3.5);
    glVertex3f(0,-8,-3.5);
    glVertex3f(40,-8,-3.5);
    //up
    glVertex3f(40,-7,-3.5);
    glVertex3f(40,-7,-7.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-7,-3.5);
    //down
    glVertex3f(0,-8,-3.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(40,-8,-7.5);
    glVertex3f(40,-8,-3.5);
    //back
    glVertex3f(40,-8,-3.5);
    glVertex3f(40,-8,-7.5);
    glVertex3f(40,-7,-7.5);
    glVertex3f(40,-7,-3.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-7,-8.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(0,-8,-7.5);
    //left
    glVertex3f(0,-7,-8.5);
    glVertex3f(40,-7,-8.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(0,-8,-8.5);
    //right
    glVertex3f(40,-7,-7.5);
    glVertex3f(0,-7,-7.5);
    glVertex3f(0,-8,-7.5);
    glVertex3f(40,-8,-7.5);
    //up
    glVertex3f(40,-7,-7.5);
    glVertex3f(40,-7,-8.5);
    glVertex3f(0,-7,-8.5);
    glVertex3f(0,-7,-7.5);
    //down
    glVertex3f(0,-8,-7.5);
    glVertex3f(0,-8,-8.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(40,-8,-7.5);
    //back
    glVertex3f(40,-8,-7.5);
    glVertex3f(40,-8,-8.5);
    glVertex3f(40,-7,-8.5);
    glVertex3f(40,-7,-7.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-2,-1,-0.5);
    glVertex3f(-2,-1,-10.5);
    glVertex3f(-2,-2,-10.5);
    glVertex3f(-2,-2,-0.5);
    //left
    glVertex3f(-2,-1,-10.5);
    glVertex3f(0,0,-10.5);
    glVertex3f(0,-1,-10.5);
    glVertex3f(-2,-2,-10.5);
    //right
    glVertex3f(0,0,-0.5);
    glVertex3f(-2,-1,-0.5);
    glVertex3f(-2,-2,-0.5);
    glVertex3f(0,-1,-0.5);
    //up
    glVertex3f(0,0,-0.5);
    glVertex3f(0,0,-10.5);
    glVertex3f(-2,-1,-10.5);
    glVertex3f(-2,-1,-0.5);
    //down
    glVertex3f(-2,-2,-0.5);
    glVertex3f(-2,-2,-10.5);
    glVertex3f(0,-1,-10.5);
    glVertex3f(0,-1,-0.5);
    //back
    glVertex3f(0,-1,-0.5);
    glVertex3f(0,-1,-10.5);
    glVertex3f(0,-0,-10.5);
    glVertex3f(0,-0,-0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(32,5,-9.5);
    glVertex3f(32,5,-10.5);
    glVertex3f(25,0,-10.5);
    glVertex3f(25,0,-9.5);
    //left
    glVertex3f(32,5,-10.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(25,0,-10.5);
    //right
    glVertex3f(40,5,-9.5);
    glVertex3f(32,5,-9.5);
    glVertex3f(25,0,-9.5);
    glVertex3f(40,0,-9.5);
    //up
    glVertex3f(40,5,-9.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(32,5,-10.5);
    glVertex3f(32,5,-9.5);
    //down
    glVertex3f(25,0,-9.5);
    glVertex3f(25,0,-10.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(40,0,-9.5);
    //back
    glVertex3f(40,0,-9.5);
    glVertex3f(40,0,-10.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(40,5,-9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(32,5,-0.5);
    glVertex3f(32,5,-1.5);
    glVertex3f(25,0,-1.5);
    glVertex3f(25,0,-0.5);
    //left
    glVertex3f(32,5,-1.5);
    glVertex3f(40,5,-1.5);
    glVertex3f(40,0,-1.5);
    glVertex3f(25,0,-1.5);
    //right
    glVertex3f(40,5,-0.5);
    glVertex3f(32,5,-0.5);
    glVertex3f(25,0,-0.5);
    glVertex3f(40,0,-0.5);
    //up
    glVertex3f(40,5,-0.5);
    glVertex3f(40,5,-1.5);
    glVertex3f(32,5,-1.5);
    glVertex3f(32,5,-0.5);
    //down
    glVertex3f(25,0,-0.5);
    glVertex3f(25,0,-1.5);
    glVertex3f(40,0,-1.5);
    glVertex3f(40,0,-0.5);
    //back
    glVertex3f(40,0,-0.5);
    glVertex3f(40,0,-1.5);
    glVertex3f(40,5,-1.5);
    glVertex3f(40,5,-0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(32,6,-0.5);
    glVertex3f(32,6,-10.5);
    glVertex3f(32,5,-10.5);
    glVertex3f(32,5,-0.5);
    //left
    glVertex3f(32,6,-10.5);
    glVertex3f(40,6,-10.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(32,5,-10.5);
    //right
    glVertex3f(40,6,-0.5);
    glVertex3f(32,6,-0.5);
    glVertex3f(32,5,-0.5);
    glVertex3f(40,5,-0.5);
    //up
    glVertex3f(40,6,-0.5);
    glVertex3f(40,6,-10.5);
    glVertex3f(32,6,-10.5);
    glVertex3f(32,6,-0.5);
    //down
    glVertex3f(32,5,-0.5);
    glVertex3f(32,5,-10.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(40,5,-0.5);
    //back
    glVertex3f(40,5,-0.5);
    glVertex3f(40,5,-10.5);
    glVertex3f(40,6,-10.5);
    glVertex3f(40,6,-0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(40,6,-0.5);
    glVertex3f(40,6,-10.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(40,-10,-0.5);
    //left
    glVertex3f(40,6,-10.5);
    glVertex3f(41,6,-10.5);
    glVertex3f(41,-10,-10.5);
    glVertex3f(40,-10,-10.5);
    //right
    glVertex3f(41,6,-0.5);
    glVertex3f(40,6,-0.5);
    glVertex3f(40,-10,-0.5);
    glVertex3f(41,-10,-0.5);
    //up
    glVertex3f(41,6,-0.5);
    glVertex3f(41,6,-10.5);
    glVertex3f(40,6,-10.5);
    glVertex3f(40,6,-0.5);
    //down
    glVertex3f(40,-10,-0.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(41,-10,-10.5);
    glVertex3f(41,-10,-0.5);
    //back
    glVertex3f(41,-10,-0.5);
    glVertex3f(41,-10,-10.5);
    glVertex3f(41,6,-10.5);
    glVertex3f(41,6,-0.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(40,-2,-5);
    glRotatef(90,0,1,0);
    glColor3f(0.8,0.8,0.8);
    gluCylinder(pObj, 3.0, 3.0, 7.0, 26, 13);
    glScalef(1,1,2);
    glTranslatef(0,0,2);
    glColor3f(0,0,0);
    gluSphere(pObj,2.0,26,13);
    glColor3f(1,0,0);
    glTranslatef(0,0,1);
    gluDisk(pObj, 1.0, 3.0, 26, 13);
    glPopMatrix();

     gluDeleteQuadric(pObj);
}
void aircraftBody(void)
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
     glColor3f(0,1,1);
     glRotatef(90,1,0,0);
    gluCylinder(pObj,2.5,2.5,10,26,13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,1);
    glRotatef(90,0,1,0);
    gluCylinder(pObj,2.5,2.5,40,26,13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,1);
    gluSphere(pObj,2.5,26,13);
    glTranslatef(40,0,0);
    gluSphere(pObj,2.5,26,13);
    glRotatef(90,1,0,0);
    gluCylinder(pObj,2.5,2.5,10,26,13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,1,1);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,0,2.5);
    glVertex3f(0,0,-2.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(0,-10,2.5);
    //left
    glVertex3f(0,0,-2.5);
    glVertex3f(40,0,-2.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(0,-10,-2.5);
    //right
    glVertex3f(40,0,2.5);
    glVertex3f(0,0,2.5);
    glVertex3f(0,-10,2.5);
    glVertex3f(40,-10,2.5);
    //up
    glVertex3f(40,0,2.5);
    glVertex3f(40,0,-2.5);
    glVertex3f(0,0,-2.5);
    glVertex3f(0,0,2.5);
    //down
    glVertex3f(0,-10,2.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(40,-10,2.5);
    //back
    glVertex3f(40,-10,2.5);
    glVertex3f(40,-10,-2.5);
    glVertex3f(40,-0,-2.5);
    glVertex3f(40,-0,2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-11,9.5);
    //left
    glVertex3f(0,-10,-9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(0,-11,-9.5);
    //right
    glVertex3f(40,-10,9.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(40,-11,9.5);
    //up
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-10,9.5);
    //down
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-11,9.5);
    //back
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-10,9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-10,-10,1.5);
    glVertex3f(-10,-10,-1.5);
    glVertex3f(-10,-11,-1.5);
    glVertex3f(-10,-11,1.5);
    //left
    glVertex3f(-10,-10,-1.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(-10,-11,-1.5);
    //right
    glVertex3f(0,-10,9.5);
    glVertex3f(-10,-10,1.5);
    glVertex3f(-10,-11,1.5);
    glVertex3f(0,-11,9.5);
    //up
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(-10,-10,-1.5);
    glVertex3f(-10,-10,1.5);
    //down
    glVertex3f(-10,-11,1.5);
    glVertex3f(-10,-11,-1.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-11,9.5);
    //back
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-10,9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-11,9.5);
    //left
    glVertex3f(40,-10,-9.5);
    glVertex3f(45,-10,-1.5);
    glVertex3f(45,-11,-1.5);
    glVertex3f(40,-11,-9.5);
    //right
    glVertex3f(45,-10,1.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(45,-11,1.5);
    //up
    glVertex3f(45,-10,1.5);
    glVertex3f(45,-10,-1.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-10,9.5);
    //down
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(45,-11,-1.5);
    glVertex3f(45,-11,1.5);
    //back
    glVertex3f(45,-11,1.5);
    glVertex3f(45,-11,-1.5);
    glVertex3f(45,-10,-1.5);
    glVertex3f(45,-10,1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(40,-10,10.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-11,10.5);
    //left
    glVertex3f(40,-10,9.5);
    glVertex3f(45,-10,1.5);
    glVertex3f(45,-11,1.5);
    glVertex3f(40,-11,9.5);
    //right
    glVertex3f(45,-10,2.5);
    glVertex3f(40,-10,10.5);
    glVertex3f(40,-11,10.5);
    glVertex3f(45,-11,2.5);
    //up
    glVertex3f(45,-10,2.5);
    glVertex3f(45,-10,1.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-10,10.5);
    //down
    glVertex3f(40,-11,10.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(45,-11,1.5);
    glVertex3f(45,-11,2.5);
    //back
    glVertex3f(45,-11,2.5);
    glVertex3f(45,-11,1.5);
    glVertex3f(45,-10,1.5);
    glVertex3f(45,-10,2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(40,-11,-9.5);
    //left
    glVertex3f(40,-10,-10.5);
    glVertex3f(45,-10,-2.5);
    glVertex3f(45,-11,-2.5);
    glVertex3f(40,-11,-10.5);
    //right
    glVertex3f(45,-10,-1.5);
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-11,-9.5);
    glVertex3f(45,-11,-1.5);
    //up
    glVertex3f(45,-10,-1.5);
    glVertex3f(45,-10,-2.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(40,-10,-9.5);
    //down
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(45,-11,-2.5);
    glVertex3f(45,-11,-1.5);
    //back
    glVertex3f(45,-11,-1.5);
    glVertex3f(45,-11,-2.5);
    glVertex3f(45,-10,-2.5);
    glVertex3f(45,-10,-1.5);
    glEnd();
    glPopMatrix();

    //tail
    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(45,-10,2.5);
    glVertex3f(45,-10,-2.5);
    glVertex3f(45,-11,-2.5);
    glVertex3f(45,-11,2.5);
    //left
    glVertex3f(45,-10,-2.5);
    glVertex3f(46,-10,-1.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(45,-11,-2.5);
    //right
    glVertex3f(46,-10,1.5);
    glVertex3f(45,-10,2.5);
    glVertex3f(45,-11,2.5);
    glVertex3f(46,-11,1.5);
    //up
    glVertex3f(46,-10,1.5);
    glVertex3f(46,-10,-1.5);
    glVertex3f(45,-10,-2.5);
    glVertex3f(45,-10,2.5);
    //down
    glVertex3f(45,-11,2.5);
    glVertex3f(45,-11,-2.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(46,-11,1.5);
    //back
    glVertex3f(46,-11,1.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(46,-10,-1.5);
    glVertex3f(46,-10,1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-10,-10,-1.5);
    glVertex3f(-10,-10,-2.5);
    glVertex3f(-10,-11,-2.5);
    glVertex3f(-10,-11,-1.5);
    //left
    glVertex3f(-10,-10,-2.5);
    glVertex3f(0,-10,-10.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(-10,-11,-2.5);
    //right
    glVertex3f(0,-10,-9.5);
    glVertex3f(-10,-10,-1.5);
    glVertex3f(-10,-11,-1.5);
    glVertex3f(0,-11,-9.5);
    //up
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-10,-10.5);
    glVertex3f(-10,-10,-2.5);
    glVertex3f(-10,-10,-1.5);
    //down
    glVertex3f(-10,-11,-1.5);
    glVertex3f(-10,-11,-2.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(0,-11,-9.5);
    //back
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(0,-10,-1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-10,-10,2.5);
    glVertex3f(-10,-10,1.5);
    glVertex3f(-10,-11,1.5);
    glVertex3f(-10,-11,2.5);
    //left
    glVertex3f(-10,-10,1.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(-10,-11,1.5);
    //right
    glVertex3f(0,-10,10.5);
    glVertex3f(-10,-10,2.5);
    glVertex3f(-10,-11,2.5);
    glVertex3f(0,-11,10.5);
    //up
    glVertex3f(0,-10,10.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(-10,-10,1.5);
    glVertex3f(-10,-10,2.5);
    //down
    glVertex3f(-10,-11,2.5);
    glVertex3f(-10,-11,1.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-11,10.5);
    //back
    glVertex3f(0,-11,10.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-10,10.5);
    glEnd();
    glPopMatrix();

    //head
    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-11,-10,1.5);
    glVertex3f(-11,-10,-1.5);
    glVertex3f(-11,-11,-1.5);
    glVertex3f(-11,-11,1.5);
    //left
    glVertex3f(-11,-10,-1.5);
    glVertex3f(-10,-10,-2.5);
    glVertex3f(-10,-11,-2.5);
    glVertex3f(-11,-11,-1.5);
    //right
    glVertex3f(-10,-10,2.5);
    glVertex3f(-11,-10,1.5);
    glVertex3f(-11,-11,1.5);
    glVertex3f(-10,-11,2.5);
    //up
    glVertex3f(-10,-10,2.5);
    glVertex3f(-10,-10,-2.5);
    glVertex3f(-11,-10,-1.5);
    glVertex3f(-11,-10,1.5);
    //down
    glVertex3f(-11,-11,1.5);
    glVertex3f(-11,-11,-1.5);
    glVertex3f(-10,-11,-2.5);
    glVertex3f(-10,-11,2.5);
    //back
    glVertex3f(-10,-11,2.5);
    glVertex3f(-10,-11,-2.5);
    glVertex3f(-10,-10,-2.5);
    glVertex3f(-10,-10,2.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(-11,-11,1.5);
    glVertex3f(-11,-11,-1.5);
    glVertex3f(-11,-13,-1.5);
    glVertex3f(-11,-13,1.5);
    //left
    glVertex3f(-11,-11,-1.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(46,-13,-1.5);
    glVertex3f(-11,-13,-1.5);
    //right
    glVertex3f(46,-11,1.5);
    glVertex3f(-11,-11,1.5);
    glVertex3f(-11,-13,1.5);
    glVertex3f(46,-13,1.5);
    //up
    glVertex3f(46,-11,1.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(-11,-11,-1.5);
    glVertex3f(-11,-11,1.5);
    //down
    glVertex3f(-11,-13,1.5);
    glVertex3f(-11,-13,-1.5);
    glVertex3f(46,-13,-1.5);
    glVertex3f(46,-13,1.5);
    //back
    glVertex3f(46,-13,1.5);
    glVertex3f(46,-13,-1.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(46,-11,1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-10,10.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-11,10.5);
    //left
    glVertex3f(0,-10,9.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(0,-11,9.5);
    //right
    glVertex3f(40,-10,10.5);
    glVertex3f(0,-10,10.5);
    glVertex3f(0,-11,10.5);
    glVertex3f(40,-11,10.5);
    //up
    glVertex3f(40,-10,10.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(0,-10,9.5);
    glVertex3f(0,-10,10.5);
    //down
    glVertex3f(0,-11,10.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-11,10.5);
    //back
    glVertex3f(40,-11,10.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-10,9.5);
    glVertex3f(40,-10,10.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-10,-10.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(0,-11,-9.5);
    //left
    glVertex3f(0,-10,-10.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(0,-11,-10.5);
    //right
    glVertex3f(40,-10,-9.5);
    glVertex3f(0,-10,-9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(40,-11,-9.5);
    //up
    glVertex3f(40,-10,-9.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(0,-10,-10.5);
    glVertex3f(0,-10,-9.5);
    //down
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(40,-11,-9.5);
    //back
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(40,-10,-10.5);
    glVertex3f(40,-10,-9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-11,10.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-13,1.5);
    glVertex3f(0,-13,2.5);
    //left
    glVertex3f(0,-11,9.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-13,1.5);
    glVertex3f(0,-13,1.5);
    //right
    glVertex3f(40,-11,10.5);
    glVertex3f(0,-11,10.5);
    glVertex3f(0,-13,2.5);
    glVertex3f(40,-13,2.5);
    //up
    glVertex3f(40,-11,10.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(0,-11,9.5);
    glVertex3f(0,-11,10.5);
    //down
    glVertex3f(0,-13,2.5);
    glVertex3f(0,-13,1.5);
    glVertex3f(40,-13,1.5);
    glVertex3f(40,-13,2.5);
    //back
    glVertex3f(40,-13,2.5);
    glVertex3f(40,-13,1.5);
    glVertex3f(40,-11,9.5);
    glVertex3f(40,-11,10.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_QUADS);
    //in front
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(0,-13,-2.5);
    glVertex3f(0,-13,-1.5);
    //left
    glVertex3f(0,-11,-10.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(40,-13,-2.5);
    glVertex3f(0,-13,-2.5);
    //right
    glVertex3f(40,-11,-9.5);
    glVertex3f(0,-11,-9.5);
    glVertex3f(0,-13,-1.5);
    glVertex3f(40,-13,-1.5);
    //up
    glVertex3f(40,-11,-9.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(0,-11,-10.5);
    glVertex3f(0,-11,-9.5);
    //down
    glVertex3f(0,-13,-1.5);
    glVertex3f(0,-13,-2.5);
    glVertex3f(40,-13,-2.5);
    glVertex3f(40,-13,-1.5);
    //back
    glVertex3f(40,-13,-1.5);
    glVertex3f(40,-13,-2.5);
    glVertex3f(40,-11,-10.5);
    glVertex3f(40,-11,-9.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,0.8,0.8);
    glBegin(GL_TRIANGLES);
    glVertex3f(0,-11,10.5);
    glVertex3f(-11,-11,1.5);
    glVertex3f(0,-13,1.5);

    glVertex3f(0,-11,-10.5);
    glVertex3f(-11,-11,-1.5);
    glVertex3f(0,-13,-1.5);

    glVertex3f(40,-11,-10.5);
    glVertex3f(46,-11,-1.5);
    glVertex3f(40,-13,-1.5);

    glVertex3f(40,-11,10.5);
    glVertex3f(46,-11,1.5);
    glVertex3f(40,-13,1.5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0,-1,2.5);
    glVertex3f(0,-10,2.5);
    glVertex3f(0,-1,3.5);
    glVertex3f(0,-10,3.5);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(0,-1,-2.5);
    glVertex3f(0,-10,-2.5);
    glVertex3f(0,-1,-3.5);
    glVertex3f(0,-10,-3.5);
    glEnd();
    glPopMatrix();
    gluDeleteQuadric(pObj);
}
void aircraft(void)
{
    aircraftBody();
   glPushMatrix();
   glTranslatef(0,0,-2);
   aircraftDeck();
   aircraftSmallDeck();
   glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,13);
   aircraftDeck();
   glTranslatef(0,0,-11);
     glTranslatef(0,-15,0);
    glRotatef(180,1,0,0);
    aircraftSmallDeck();
   glPopMatrix();

}
