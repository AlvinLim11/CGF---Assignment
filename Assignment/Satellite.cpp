#include "Satellite.h"
#include <GL\glut.h>

void SatelliteBody()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(1,1,1);

    glPushMatrix();
    gluCylinder(pObj, 3.0f, 3.0f, 7.5f, 26, 13);
    glTranslatef(0,0,7.5);
    gluDisk(pObj, 0, 3.0, 26, 13);
    glTranslatef(0,0,-6.9);
    gluDisk(pObj, 0, 3.0, 26, 13);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    gluCylinder(pObj, 0.5f, 0.5f, 0.5f, 26, 13);
    glColor3f(1,0,0);
    glTranslatef(0,0,0.5);
    gluDisk(pObj, 0, 0.5, 26, 13);
    glPopMatrix();

    gluDeleteQuadric(pObj);
}

void SolarPanel()
{
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(0, 2, 0);
    glVertex3f(15, 2, 0);
    glVertex3f(15, -2, 0);
    glVertex3f(0, -2, 0);
    glEnd();
}

void RadarDish()
{
    GLUquadricObj *pObj;
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);
    glColor3f(0.7, 0.7, 0.7);

    // Radar dish
    glPushMatrix();
    gluCylinder(pObj, 0.0f, 4.0f, 2.0f, 26, 13);
    glTranslatef(0, 0, 1);
    glRotatef(90, 1, 0, 0);
    //gluDisk(pObj, 0, 2, 26, 13);
    glPopMatrix();

    // Add Main Support arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, 0, -2);
    glRotatef(90, 0, 0, 1);
    gluCylinder(pObj, 0.1f, 0.1f, 6.0f, 26, 13);
    glPopMatrix();

    // Add Top Support arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, 3.8, 1.9);
    glRotatef(60, 1, 0, 0);
    gluCylinder(pObj, 0.1f, 0.1f, 4.5f, 26, 13);
    glPopMatrix();

    // Add Bottom Support arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(0, -3.8, 1.9);
    glRotatef(-60, 1, 0, 0);
    gluCylinder(pObj, 0.1f, 0.1f, 4.5f, 26, 13);
    glPopMatrix();

    // Left Support arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(-3.8, 0, 1.9);
    glRotatef(60, 0, 1, 0);
    gluCylinder(pObj, 0.1f, 0.1f, 4.5f, 26, 13);
    glPopMatrix();

    // Right Support arm
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    glTranslatef(3.8, 0, 1.9);
    glRotatef(-60, 0, 1, 0);
    gluCylinder(pObj, 0.1f, 0.1f, 4.5f, 26, 13);
    glPopMatrix();


    gluDeleteQuadric(pObj);
}

void Satellite()
{
    glPushMatrix();
        SatelliteBody();
        glTranslatef(0, 0, 2.5);
        glPushMatrix();
            glTranslatef(1, 0, 0);
            SolarPanel();
            glTranslatef(-2, 0, 0);
            glRotatef(180, 0, 1, 0);
            SolarPanel();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0, 0, 5);
            RadarDish();
        glPopMatrix();
    glPopMatrix();
}
