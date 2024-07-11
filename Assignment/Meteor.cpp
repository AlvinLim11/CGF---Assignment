#include "Meteor.h"
#include <GL\glut.h>
#include <cmath>
#include <cstdlib>

void MyOvalSphere(float radiusX, float radiusY, int numSegmentsX, int numSegmentsY)
{
    glPushMatrix();
    glScalef(radiusX, radiusY, radiusX); // Scale the sphere to make it oval
    glutSolidSphere(1.0, numSegmentsX, numSegmentsY);
    glPopMatrix();
    glEnd();
}


void MyCone(float baseRadius, float height, int numSegments)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, height); // Apex of the cone
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = i * 2.0f * M_PI / numSegments;
        float x = baseRadius * cos(angle);
        float y = baseRadius * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, 0.0f, 0.0f); // Center of the base
    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = i * 2.0f * M_PI / numSegments;
        float x = baseRadius * cos(angle);
        float y = baseRadius * sin(angle);
        glVertex3f(x, y, 0.0f);
    }
    glEnd();
}

void MyCube(float size)
{
    size /= 2.0f; // Half size for easier calculations

    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-size, -size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, size, size);
    glVertex3f(-size, size, size);

    // Back face
    glVertex3f(-size, -size, -size);
    glVertex3f(size, -size, -size);
    glVertex3f(size, size, -size);
    glVertex3f(-size, size, -size);

    // Right face
    glVertex3f(size, -size, size);
    glVertex3f(size, -size, -size);
    glVertex3f(size, size, -size);
    glVertex3f(size, size, size);

    // Left face
    glVertex3f(-size, -size, size);
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, size, size);

    // Top face
    glVertex3f(-size, size, size);
    glVertex3f(size, size, size);
    glVertex3f(size, size, -size);
    glVertex3f(-size, size, -size);

    // Bottom face
    glVertex3f(-size, -size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, -size, -size);
    glVertex3f(-size, -size, -size);

    glEnd();
}

void Meteor()
{
    // Draw oval-shaped sphere
    glPushMatrix();
    glColor3f(0.5f, 0.35f, 0.05f);   // brown color
    glTranslatef(0.0f, 0.0f, 0.0f); // Adjust position
    glScalef(1.0f, 2.0f, 1.0f);    // Stretch vertically (y-axis)
    MyOvalSphere(1.5f, 1.0f, 20, 20); // Adjust radiusX and radiusY for size

    glPopMatrix();

    // Draw cone
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);
    glTranslatef(0.0f, 0.0f, 0.0f); // Example position for the cone
    glRotatef(160.0f, -1.0f, 0.0f, 0.0f); // Rotate to point apex up
    MyCone(1.0f, 20.0f, 20); // Base radius 1.0, height 3.0, 20 segments
    glPopMatrix();

    // Example: Draw a cube with size 4
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f); // Rotate around x-axis
    MyCube(2.5f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glRotatef(135.0f, 1.0f, 0.0f, 0.0f); // Rotate around x-axis
    MyCube(2.5f);
    glColor3f(0.5f, 0.5f, 0.5f);
    glRotatef(225.0f, 1.0f, 0.0f, 0.0f); // Rotate around x-axis
    MyCube(2.5f);
    glPopMatrix();
}
