#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include "ReadBMP.h"
#include "ImageManipulation.h"
#include "spaceship.h"
#include "SpaceStation.h"
#include "Satellite.h"
#include "Meteor.h"

using namespace std;

int ScreenWindowWidth = 800;
int ScreenWindowHeight = 600;
static float fieldOfView= 60.0;
int WorldWidth = 5000;
int WorldHeight = 5000;
int WorldDeep = 5000;
static float aspectRatio = static_cast<GLdouble> (WorldWidth)/WorldHeight;

GLfloat Xpos = 0.0;
GLfloat Ypos = 0.0;
GLfloat Zpos = 0.0;
GLfloat Xangle = 0.0;
GLfloat Yangle = 0.0;
GLfloat XangInc = 5;
GLfloat YangInc = 5;
double scaleX = 1000.0; // Increase the scale to make the box larger
double scaleY = 1000.0; // Increase the scale to make the box larger
double scaleZ = 1000.0; // Increase the scale to make the box larger
static bool mousePanMode = false;
static bool mouseZoomMode = false;
static bool mouseRotationMode = false;
int mouseX, mouseY;

GLuint textureNumber[15];

GLfloat planetRotationAngles[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
GLfloat planetRotationSpeeds[6] = { 0.054, 0.075, 0.035, 0.015, 0.025, 0.095 }; // Adjust individual speeds if needed
// Define the common rotation angle for the group of planets
GLfloat groupRotationAngle = 0.0;
GLfloat groupRotationSpeed = 0.0025;

// Define the common rotation angle for the spaceship
GLfloat spaceShipRotationAngle = 0.0;
GLfloat spaceShipRotationSpeed = 0.015;

// Define the common rotation angle for the spaceship
GLfloat meteorRotationAngle = 0.0;
GLfloat meteorRotationSpeed = 0.05;

void DrawBox()
{
    glBegin(GL_QUADS);

    // Front face
    glBindTexture(GL_TEXTURE_2D, textureNumber[0]);
    glTexCoord2f(0, 0); glVertex3f(-1, -1,  1);
    glTexCoord2f(1, 0); glVertex3f( 1, -1,  1);
    glTexCoord2f(1, 1); glVertex3f( 1,  1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1,  1,  1);

    // Back face
    glBindTexture(GL_TEXTURE_2D, textureNumber[1]);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f( 1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f( 1,  1, -1);
    glTexCoord2f(0, 1); glVertex3f(-1,  1, -1);

    // Top face
    glBindTexture(GL_TEXTURE_2D, textureNumber[2]);
    glTexCoord2f(0, 0); glVertex3f(-1,  1, -1);
    glTexCoord2f(1, 0); glVertex3f( 1,  1, -1);
    glTexCoord2f(1, 1); glVertex3f( 1,  1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1,  1,  1);

    // Bottom face
    glBindTexture(GL_TEXTURE_2D, textureNumber[3]);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f( 1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f( 1, -1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1, -1,  1);

    // Right face
    glBindTexture(GL_TEXTURE_2D, textureNumber[4]);
    glTexCoord2f(0, 0); glVertex3f( 1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f( 1,  1, -1);
    glTexCoord2f(1, 1); glVertex3f( 1,  1,  1);
    glTexCoord2f(0, 1); glVertex3f( 1, -1,  1);

    // Left face
    glBindTexture(GL_TEXTURE_2D, textureNumber[5]);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1,  1, -1);
    glTexCoord2f(1, 1); glVertex3f(-1,  1,  1);
    glTexCoord2f(0, 1); glVertex3f(-1, -1,  1);

    glEnd();
}

// ****************** Planet ****************** //

void DrawSphere(GLfloat radius, GLint slices, GLint stacks, GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    GLUquadric* quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluSphere(quadric, radius, slices, stacks);
    gluDeleteQuadric(quadric);
}

void DrawPlanet(GLfloat radius, GLuint texture, int planetIndex, GLfloat distance) {

    // Rotate the entire group of planets around the common center
    glPushMatrix();
    glRotatef(groupRotationAngle, 0.0, 1.0, 0.0); // Rotate the group around the common center

    // Adjust translation based on planetIndex to position relative to camera
    switch (planetIndex) {
        case 0: // Front of the camera
            glTranslatef(0.0, 0.0, -distance);
            break;
        case 1: // Right side of the camera
            glTranslatef(distance, 0.0, 0.0);
            break;
        case 2: // Left side of the camera
            glTranslatef(-distance, 0.0, 0.0);
            break;
        case 3: // Backside of the camera
            glTranslatef(0.0, 0.0, distance);
            break;
        case 4: // Southeast side of the camera
            glTranslatef(-distance , 0.0 , distance);
            break;
        case 5: // Northwest side of the camera
            glTranslatef(distance , 0.0 , -distance);
            break;
        case 6: // Northwest side of the camera
            glTranslatef(distance , 0.0 , distance);
            break;
        case 7: // Northwest side of the camera
            glTranslatef(distance-6 , 0.0 , distance-7);
            break;
        default:
            break;
    }

    // Rotate the planet itself
    glRotatef(planetRotationAngles[planetIndex], 0.0, 1.0, 0.0); // Rotate the planet around its own axis

    // Draw the planet sphere with the specified texture

    DrawSphere(radius, 50, 50, texture);

    glPopMatrix();

}


// ****************** Meteorite ****************** //


//Global variables to control animation and boundaries
GLfloat boxDepth = 5.0; // Depth of the draw box

void DrawMeteorite() {
glPushMatrix();
    glRotatef(45, 1, 1, 1);

    // Meteorite 1
    glPushMatrix();
    glTranslatef(-10, 0, 3);
    glTranslatef(4, 0, 0);
    glRotatef(meteorRotationAngle+10, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 2
    glPushMatrix();
    glTranslatef(-10, 0, -3);
    glTranslatef(4, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle-20, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 3
    glPushMatrix();
    glTranslatef(-9, 0, 0);
    glTranslatef(6, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+15, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 4
    glPushMatrix();
    glTranslatef(-9, 0, -1);
    glTranslatef(7, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle-15, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 5
    glPushMatrix();
    glTranslatef(-10, -2, -4);
    glTranslatef(6, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle-45, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 6
    glPushMatrix();
    glTranslatef(-13, 0, -1);
    glTranslatef(2, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+180, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 7
    glPushMatrix();
    glTranslatef(-8, -1, -1);
    glTranslatef(3, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+190, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 8
    glPushMatrix();
    glTranslatef(-8, -1, -2);
    glTranslatef(3, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+150, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 9
    glPushMatrix();
    glTranslatef(-9, -2, -3);
    glTranslatef(3, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+200, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

    // Meteorite 10
    glPushMatrix();
    glTranslatef(-10, -2, -3);
    glTranslatef(4, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle+345, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();


    for (int i = 0; i < 4; ++i) {
    glTranslatef(2,0,0);
    glPushMatrix();
      glRotatef(meteorRotationAngle+90, 1, 0, 0.0);
      glTranslatef(0,5,0);
    glScalef(0.2,0.2,0.2);
    Meteor();
    glPopMatrix();
    }

    // Meteorite 14
    glPushMatrix();
    glTranslatef(-20, -2, -3);
    glTranslatef(4, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle-95, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();


    // Meteorite 15
    glPushMatrix();
    glTranslatef(-16, -2, -3);
    glTranslatef(4, 0, 0);  // Adjust X position
    glRotatef(meteorRotationAngle-305, 1, 0, 0);
    glTranslatef(0, 5, 0);
    glScalef(0.2, 0.2, 0.2);
    Meteor();
    glPopMatrix();

}




// ****************** Satellite ****************** //

void DrawSatellite() {

    // Add your code here
    glPushMatrix();
     glRotatef(-spaceShipRotationAngle, 0.0, 1.0, 0.0);
  glTranslatef(0.5,0,0);
    glScalef(0.005,0.005,0.005);
    glRotatef(-45,1,0,1);
    Satellite();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-spaceShipRotationAngle, 0.0, 1.0, 0.0);
  glTranslatef(-0.5,0,0);
    glScalef(0.005,0.005,0.005);
    glRotatef(45,1,0,1);
    Satellite();
    glPopMatrix();

}

// ****************** SpaceStation ****************** //

void DrawSpaceStation() {

    // Add your code here
    glPushMatrix();
    glRotatef(90,0,0,1);
    glScalef(0.04,0.04,0.04);
   SpaceStation();
   glPopMatrix();

}

// ****************** Spaceship ****************** //
void DrawSpaceship() {

glPushMatrix();
 glRotatef(spaceShipRotationAngle, 1.0, 0.0, 0.0);
glTranslatef(0.5,2,0);
 glScalef(0.03,0.03,0.03);
 glRotatef(90,0,1,0);
    spaceShip1();
glPopMatrix();

glPushMatrix();
 glRotatef(-spaceShipRotationAngle, 1.0, 0.0, 0.0);
glTranslatef(3,3,0);
 glScalef(0.03,0.03,0.03);
 glRotatef(-90,0,1,0);
    spaceShip2();
glPopMatrix();


glPushMatrix();
 glRotatef(-spaceShipRotationAngle, 0.0, 1.0, 0.0);
  glTranslatef(2,-2,0);
 glScalef(0.05,0.05,0.05);
 glRotatef(90,0,1,0);
aircraft();
glPopMatrix();

glPushMatrix();
 glRotatef(-spaceShipRotationAngle, 0.0, 1.0, 0.0);
  glTranslatef(3.5,2,0);
 glScalef(0.03,0.03,0.03);
 glRotatef(90,0,1,0);
spaceShipA();
glPopMatrix();
    // Add your code here

}

void updateRotationAngles() {
    for (int i = 0; i < 6; ++i) {
        planetRotationAngles[i] += planetRotationSpeeds[i];
        if (planetRotationAngles[i] >= 360.0) {
            planetRotationAngles[i] -= 360.0;
        }
    groupRotationAngle += groupRotationSpeed;
    if (groupRotationAngle >= 360.0) {
        groupRotationAngle -= 360.0;
    }
    }

    spaceShipRotationAngle += spaceShipRotationSpeed;

    meteorRotationAngle += meteorRotationSpeed;

    glutPostRedisplay();


}


void myDisplay(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Setup gluLookAt,camera at center
    glTranslatef(Xpos, Ypos, Zpos);
    glRotatef(Xangle, -1.0, 0.0, 0.0);
    glRotatef(Yangle, 0.0, 1.0, 0.0);
    gluLookAt(0,0,0, 0,0,1, 0,1,0);

    glPushMatrix();
    glScalef(scaleX, scaleY, scaleZ);

    glEnable(GL_TEXTURE_2D);
    // Apply fog effect
    glEnable(GL_FOG);
    glBindTexture(GL_TEXTURE_2D, textureNumber[0]);
    DrawBox();
    // Disable fog after drawing objects
    glDisable(GL_FOG);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    GLfloat planetDistance = 3.0; // Distance from the center of the box to the planets

    // Draw Planets
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    DrawPlanet(0.4, textureNumber[6], 0, planetDistance);
    DrawPlanet(0.3, textureNumber[12], 1, planetDistance);
    DrawPlanet(0.5, textureNumber[8], 2, planetDistance);
    DrawPlanet(0.4, textureNumber[9], 3, planetDistance);
    DrawPlanet(0.8, textureNumber[10], 4, planetDistance);
    DrawPlanet(0.2, textureNumber[11], 5, planetDistance);
    DrawPlanet(0.45, textureNumber[7], 6, planetDistance);
    DrawPlanet(0.55, textureNumber[14], 7, planetDistance);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    // Draw Meteorites
    glPushMatrix();
    DrawMeteorite();
    glPopMatrix();

    // Draw Satellite
    glPushMatrix();
    DrawSatellite();
    glPopMatrix();

    // Draw Spaceship
    glPushMatrix();
    DrawSpaceship();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2,0,0);
    DrawSpaceStation();
    glPopMatrix();

    //glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void myReshape(int width, int height)
{
    static GLfloat fieldOfViewAngle = 70.0;
    GLfloat windowAspectRatio = (GLfloat)width / (GLfloat)height;
    static GLfloat zNear = 0.1; // Adjust zNear to avoid clipping
    static GLfloat zFar = WorldDeep;

    ScreenWindowWidth = width;
    ScreenWindowHeight = height;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fieldOfViewAngle, windowAspectRatio, zNear, zFar);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myInit(void)
{
    // Enable fog
    glEnable(GL_FOG);
    glFogi(GL_FOG_MODE, GL_EXP2);  // Choose fog mode (exponential square)
    GLfloat fogColor[] = { 1.0f, 1.0f, 1.0f, 0.5f };  // Fog color (black)
    glFogfv(GL_FOG_COLOR, fogColor);
 glFogf(GL_FOG_DENSITY, 0.00045f);  // Adjust fog density

 static GLfloat  ambient[] = { 0.5f,  0.5f,  0.5f, 1.0f };
   static GLfloat  diffuse[] = { 0.05f,  0.05f,  0.05f, 1.0f };
   static GLfloat specular[] = { 0.0f,  0.0f,  0.0f, 1.0f };
   static GLfloat  ref[] = { 0.5f,  0.5f,  0.5f, 1.0f };
   static GLfloat position[] = {10.0f, 10.0f, 10.0f, 1.0f };
   short shininess = 30;

	glEnable(GL_DEPTH_TEST);
	glShadeModel (GL_SMOOTH);
	glClearColor(0.8f, 0.8f, 0.8f, 0.8f);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_FRONT, GL_SPECULAR, ref);
    glMateriali(GL_FRONT, GL_SHININESS, shininess);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,aspectRatio, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    MyImageStruct myImage = { 0, 0, 0 };
    char *fileNames[] = { "SpaceBackground.bmp", "SpaceBackground.bmp", "SpaceBackground.bmp", "SpaceBackground.bmp", "SpaceBackground.bmp", "SpaceBackground.bmp"
    ,"snow.bmp","sea.bmp","oceanplanet.bmp","lua.bmp","diamond.bmp","rainbow.bmp","lava.bmp","comet.bmp","Chenyuvale.bmp" };
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glGenTextures(15, textureNumber);
    for (int j = 0; j < 15; j++)
    {
        ReadBMP(fileNames[j], &myImage);
        if (myImage.Pixels == NULL) {
            cout << "Error loading texture " << fileNames[j] << endl;
            exit(1);
        }
        //CropImageToPowerOf2(&myImage, 128, 128);
        glBindTexture(GL_TEXTURE_2D, textureNumber[j]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, myImage.Width, myImage.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, myImage.Pixels);
        free(myImage.Pixels);
    }


    // Disable backface culling
    glDisable(GL_CULL_FACE);



}

void myKeyboard(unsigned char key, int x, int y)
{
    static const GLdouble posInc = 0.1;

    switch (key)
    {
        case 'x': Xpos -= posInc; break;
        case 'X': Xpos += posInc; break;
        case 'y': Ypos -= posInc; break;
        case 'Y': Ypos += posInc; break;
        case 'z': Zpos -= posInc; break;
        case 'Z': Zpos += posInc; break;
        case 'w': Xangle += XangInc; break;
        case 'W': Xangle -= XangInc; break;
        case 'q': Yangle += YangInc; break;
        case 'Q': Yangle -= YangInc; break;
        case 'l': glDisable(GL_LIGHT0); break;
        case 'L': glEnable(GL_LIGHT0); break;
    }
    glutPostRedisplay();
}

void myMouse(int button, int state, int x, int y)
{
    y = ScreenWindowHeight - y;
    switch (button) {
        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN && !mousePanMode) {
                mouseX = x;
                mouseY = y;
                mousePanMode = true;
            }
            if (state == GLUT_UP && mousePanMode) {
                mousePanMode = false;
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN && !mouseZoomMode) {
                mouseY = y;
                mouseZoomMode = true;
            }
            if (state == GLUT_UP && mouseZoomMode) {
                mouseZoomMode = false;
            }
            break;
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN && !mouseRotationMode) {
                mouseX = x;
                mouseY = y;
                mouseRotationMode = true;
            }
            if (state == GLUT_UP && mouseRotationMode) {
                mouseRotationMode = false;
            }
            break;
    }
}

void myMotion(int x, int y)
{
    y = ScreenWindowHeight - y;
    if (mousePanMode) {
        Xpos += (x - mouseX) * 0.01;
        Ypos += (y - mouseY) * 0.01;
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }
    if (mouseZoomMode) {
        GLdouble inc = (mouseY - y) * 0.01;
        scaleX += inc;
        scaleY += inc;
        scaleZ += inc;
        if (scaleX < 0.1) scaleX = 0.1;
        if (scaleY < 0.1) scaleY = 0.1;
        if (scaleZ < 0.1) scaleZ = 0.1;
        mouseY = y;
        glutPostRedisplay();
    }
    if (mouseRotationMode) {
        Xangle += (mouseY - y) * 0.5;
        Yangle += (x - mouseX) * 0.5;
        mouseX = x;
        mouseY = y;
        glutPostRedisplay();
    }
}

void mySpecialKey(int key, int x, int y)
{
    static const GLfloat angleInc = 2.0;

    switch (key)
    {
        case GLUT_KEY_DOWN: Xangle -= angleInc; break;
        case GLUT_KEY_UP: Xangle += angleInc; break;
        case GLUT_KEY_LEFT: Yangle -= angleInc; break;
        case GLUT_KEY_RIGHT: Yangle += angleInc; break;
        case GLUT_KEY_HOME: glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
        case GLUT_KEY_END: glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // Add GLUT_DEPTH to enable depth testing
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(ScreenWindowWidth, ScreenWindowHeight);
    glutCreateWindow("CGF Assignment");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutMotionFunc(myMotion);
    glutSpecialFunc(mySpecialKey);
    glutIdleFunc(updateRotationAngles); // Register the idle callback
    myInit();
    cout << "Press Fn + Home : To enable the wireframe view of the model" << endl;
    cout << "Press Fn + End : To disable the wireframe view of the model" << endl;
    cout << "Press arrow keys or q,Q,w,W : To rotate the object" << endl;
    cout << "Press x,X,y,Y,z,Z : To translate the object" << endl;
    cout << "Press l,L : To change the lightning of the object" << endl;
    glutMainLoop();
    return 0;
}
