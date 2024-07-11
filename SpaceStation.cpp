#include "SpaceStation.h"
#include <GL\glut.h>

void SpaceStationBody()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1, 1, 1);

    // Central sphere
    gluSphere(pObj, 3.0f, 26, 13);

    // Cylinder 1 (Right Side)
    glPushMatrix();
    glTranslatef(2.0, 0, 0);
    glRotatef(90, 0, 1, 0);
    gluCylinder(pObj, 2.0f, 2.0, 10.0f, 26, 13);
    glTranslatef(0, 0, 10.0);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glPopMatrix();

    // Cylinder 2 (Left Side)
    glPushMatrix();
    glTranslatef(-2.0, 0, 0);
    glRotatef(90, 0, -1, 0);
    gluCylinder(pObj, 2.0f, 2.0f, 10.0f, 26, 13);
    glTranslatef(0, 0, 10.0);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glPopMatrix();


    // Cylinder 3 (Top)
    glPushMatrix();
    glTranslatef(0, 4.5, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(pObj, 2.5f, 1.0f, 2.0f, 26, 13);
    glTranslatef(0, 0, 0);
    glRotatef(180, 1, 0, 0);
    gluCylinder(pObj, 2.5f, 2.5f, 4.0f, 26, 13);
    glTranslatef(0, 0, 4);
    gluDisk(pObj, 0, 2.5, 26, 13);
    glPopMatrix();


    // Cylinder 4 (Bottom)
    glPushMatrix();
    glTranslatef(0, -4.5, 0);
    glRotatef(90, -1, 0, 0);
    gluCylinder(pObj, 2.5f, 1.0f, 2.0f, 26, 13);
    glTranslatef(0, 0, 0);
    glRotatef(180, 1, 0, 0);
    gluCylinder(pObj, 2.5f, 2.5f, 4.0f, 26, 13);
    glTranslatef(0, 0, 4);
    gluDisk(pObj, 0, 2.5, 26, 13);
    glPopMatrix();


    // Cylinder 5 (Front)
    glPushMatrix();
    glTranslatef(0, 0, 2);
    gluCylinder(pObj, 2.0f, 2.0f, 12.0f, 26, 13);
    glTranslatef(0, 0, 12.0);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glPopMatrix();

    // Cylinder 6 (Back)
    glPushMatrix();
    glTranslatef(0, 0, -18);
    gluCylinder(pObj, 2.0f, 2.0f, 16.0f, 26, 13);
    glTranslatef(0, 0, 0);
    gluDisk(pObj, 0, 2.0, 26, 13);
    glPopMatrix();



    gluDeleteQuadric(pObj);
}

// Function to draw a Decoration
void Decoration()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(0.5, 0.5, 0.5);

    // Top Decorate
    glPushMatrix();
    glTranslatef(0, 8, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(pObj, 2.6f, 2.6f, 1.0f, 26, 13);
    glTranslatef(0, 0, 3);
    glRotatef(180, 0, 0, 0);
    gluCylinder(pObj, 2.6f, 2.6f, 1.0f, 26, 13);
    glPopMatrix();

    // Bottom Decorate
    glPushMatrix();
    glTranslatef(0, -5, 0);
    glRotatef(90, 1, 0, 0);
    gluCylinder(pObj, 2.6f, 2.6f, 3.0f, 26, 13);
    glPopMatrix();

    // Bottom Decorate
    glPushMatrix();
    glTranslatef(0, 0, 14);
    glRotatef(90, 0, 0, 1);
    glColor3f(0, 0, 0);
    gluCylinder(pObj, 2.0f, 1.0f, 3.0f, 26, 13);
    glTranslatef(0, 0, 2);
    gluDisk(pObj, 0, 1.3, 26, 13);
    glPopMatrix();


    // Front & Back Decorate
    glPushMatrix();
    glTranslatef(0, 0, 3);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.5, 0, 0);
    gluCylinder(pObj, 2.1f, 2.1f, 5.0f, 26, 13);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, -20);
    glRotatef(90, 0, 0, 1);
    glColor3f(0, 0, 0);
    gluCylinder(pObj, 3.0f, 1.0f, 2.0f, 26, 13);
    glTranslatef(0, 0, 2);
    gluDisk(pObj, 0, 1.3, 26, 13);
    glPopMatrix();

    // Right Side Decorate
    glPushMatrix();
    glTranslatef(12, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(0, 0, 0);
    gluCylinder(pObj, 2.0f, 1.0f, 1.0f, 26, 13);
    glTranslatef(0, 0, 1);
    glColor3f(0, 1, 1);
    gluDisk(pObj, 0, 1.0, 26, 13);
    glPopMatrix();

    // Left Side Decorate
    glPushMatrix();
    glTranslatef(-13, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(0, 0, 0);
    gluCylinder(pObj, 1.0f, 2.0f, 1.0f, 26, 13);
    glTranslatef(0, 0, 0);
    glColor3f(0, 1, 1);
    gluDisk(pObj, 0, 1.0, 26, 13);
    glPopMatrix();

}

// Function to draw a Solar Panel
void solarPanel()
{
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex3f(0, 2, 0);
    glVertex3f(10, 2, 0);
    glVertex3f(10, -2, 0);
    glVertex3f(0, -2, 0);
    glEnd();
}

// Function to draw a Support Arm
void SupportArm()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1, 1, 1);

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    gluCylinder(pObj, 0.1f, 0.1f, 6.5f, 26, 13);
    glPopMatrix();
    gluDeleteQuadric(pObj);
}

// Function to draw a Mirror
void Mirror()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glTranslatef(0, -8.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
    gluCylinder(pObj, 2.0f, 1.0f, 2.0f, 26, 13);
    glTranslatef(0, 0, 1.8); // Position it at the bottom of the cylinder
    glRotatef(90, 1, 0, 0); // Flip the sphere to form a semi-sphere
    glColor3f(0.0, 1.0, 1.0); // Light blue color
    gluSphere(pObj, 1.0f, 26, 13);
    glPopMatrix();
}

// Function to draw a rocket booster
void RocketBooster() {
    GLUquadricObj *pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(0.5, 0.5, 0.5);

    // Rocket booster body
    gluCylinder(pObj, 1.0f, 0.5f, 1.0f, 26, 13);
    glTranslatef(0.0, 0.0, 0.5f);
    glColor3f(1, 0, 0);
    gluDisk(pObj, 0.0, 0.7f, 26, 13);
    glTranslatef(0.0, 0.0, -2.0f);

}

void SpaceStation()
{
    glPushMatrix();
    SpaceStationBody();
    Mirror();
    Decoration();

    // Add five rocket boosters around the top cylinder
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        glTranslatef(0.0, 4.5, 0.0);
        glRotatef(90, 1, 0, 0);
        glTranslatef(0.0, 0.0, -5.0); // Adjust the distance from the center as needed
        glRotatef(i * 72.0, 0, 0, 1); // Rotate around the top cylinder
        glTranslatef(1.8, 0.0, 0.0); // Move outwards to position the rocket booster
        RocketBooster();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(7, -3, 0);
    glRotatef(90, 0, 0, 1);
    SupportArm();
    glTranslatef(0, -3, 0);
    SupportArm();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-7, -3, 0);
    glRotatef(90, 0, 0, 1);
    SupportArm();
    glTranslatef(0, 3, 0);
    SupportArm();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2, 0, 8.5);
    SupportArm();
    glTranslatef(0, 0, 5);
    SupportArm();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-3.2, 0, -16);
    SupportArm();
    glTranslatef(0, 0, 6);
    SupportArm();
    glPopMatrix();

    // Solar panels for Cylinder 1
    glPushMatrix();
    glTranslatef(4.0, -5.0, 0);
    solarPanel();
    glTranslatef(0, 10.0, 0);
    solarPanel();
    glPopMatrix();

    // Solar panels for Cylinder 2
    glPushMatrix();
    glTranslatef(-14.0, 5.0, 0);
    solarPanel();
    glTranslatef(0, -10.0, 0);
    solarPanel();
    glPopMatrix();

    // Solar panels for Cylinder 3 & 4
    glPushMatrix();
    glTranslatef(3.0, 0, 15);
    glRotatef(90, 1, 0, 0);
    solarPanel();
    glTranslatef(0, -6.0, 0);
    solarPanel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13.0, 0, 15);
    glRotatef(90, 1, 0, 0);
    solarPanel();
    glTranslatef(0, -6.0, 0);
    solarPanel();
    glPopMatrix();

    // Solar panels for Cylinder 5 & 6
    glPushMatrix();
    glTranslatef(3.0, 0.0, -10);
    glRotatef(90, 1, 0, 0);
    solarPanel();
    glTranslatef(0, -6.0, 0);
    solarPanel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-13.0, 0.0, -10);
    glRotatef(90, 1, 0, 0);
    solarPanel();
    glTranslatef(0, -6.0, 0);
    solarPanel();
    glPopMatrix();

    glPopMatrix();
}
