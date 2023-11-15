#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

static int slices = 32;
static int stacks = 32;

int z_axis = -35;

/*CAMERA CONTROLS*/
float camX = -0.0f;float camY = -0.0f;float camZ = -0.0f;
float lookX = 0.0f;float lookY = 1.0f;float lookZ = z_axis;
float upX = 0.0f;float upY = 1.0f;float upZ = 0.0f;
float movementSpeed = 0.6f;
double rotateA = 0;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}


void drawBody() {

    glPushMatrix(); glColor3d(0.5,0.5,0.5); glTranslated(0,0,z_axis); glScalef(1.2,2,1); glutSolidSphere(1.0, slices, stacks); glPopMatrix();


    glPushMatrix(); glColor3d(1,1,1); glTranslated(0,0.22,z_axis+0.34); glScalef(1.2,2,1); glutSolidSphere(0.75, slices, stacks); glPopMatrix();

    glColor3d(0.5,0.5,0.5);
    glPushMatrix(); glTranslated(1,1.4,z_axis); glRotated(30,0,0,-1); glScalef(0.85,0.325,0.325); glutSolidSphere(1, slices, stacks); glPopMatrix();
    glPushMatrix(); glTranslated(1.5,1.115,z_axis); glRotated(90,1,1,0); glScalef(1,1,1);gluCylinder(gluNewQuadric(),0.225,0.2,0.8,slices,stacks); glPopMatrix();
    glPushMatrix(); glTranslated(2.1,0.45,z_axis); glScalef(0.8,0.8,0.8); glutSolidSphere(0.3, slices, stacks); glPopMatrix();

    glColor3d(0.5,0.5,0.5);
    glPushMatrix(); glTranslated(-1,1.4,z_axis); glRotated(30,0,0,1); glScalef(0.85,0.325,0.325); glutSolidSphere(1, slices, stacks); glPopMatrix();
    glPushMatrix(); glTranslated(-1.5,1.115,z_axis); glRotated(90,1,-1,0); glScalef(1,1,1);gluCylinder(gluNewQuadric(),0.225,0.2,0.8,slices,stacks); glPopMatrix();
    glPushMatrix(); glTranslated(-2.1,0.45,z_axis); glScalef(0.8,0.8,0.8); glutSolidSphere(0.3, slices, stacks); glPopMatrix();

    glColor3d(0.5,0.5,0.5);
    glPushMatrix(); glTranslated(0.5,-2,z_axis); glRotated(90,0,0,1); glScalef(1,0.4,0.4); glutSolidSphere(1, slices, stacks); glPopMatrix();
    glPushMatrix(); glTranslated(0.5,-2.3,z_axis); glRotated(90,1,0,0); glScalef(1,1,1);gluCylinder(gluNewQuadric(),0.35,0.2,1.2,slices,stacks); glPopMatrix();
    glPushMatrix(); glTranslated(0.5,-3.6,z_axis); glScalef(0.3,0.2,0.3); glutSolidSphere(1, slices, stacks); glPopMatrix();

    glPushMatrix(); glTranslated(-0.5,-2,z_axis); glRotated(90,0,0,1); glScalef(1,0.4,0.4); glutSolidSphere(1, slices, stacks); glPopMatrix();
    glPushMatrix(); glTranslated(-0.5,-2.3,z_axis); glRotated(90,1,0,0); glScalef(1,1,1);gluCylinder(gluNewQuadric(),0.35,0.2,1.2,slices,stacks); glPopMatrix();
    glPushMatrix(); glTranslated(-0.5,-3.6,z_axis); glScalef(0.3,0.2,0.3); glutSolidSphere(1, slices, stacks); glPopMatrix();

}

void drawHead() {

    glPushMatrix();
        glColor3d(0.5,0.5,0.5);
        glTranslated(0,3.1,z_axis); glScalef(0.8,0.8,0.5); glutSolidSphere(1.0, slices, stacks);
    glPopMatrix();


    glPushMatrix();
        glColor3d(0.5,0.5,0.5);
        glTranslated(0.8,4,z_axis); glScalef(1,1,0.4); glRotated(90,1,-1,0); gluCylinder(gluNewQuadric(),0.1,0.4,0.6,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0.5,0.5);
        glTranslated(0.8,4,z_axis); glScalef(0.9,0.9,0.4); glRotated(90,1,-1,0); gluCylinder(gluNewQuadric(),0.095,0.4,0.6,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glColor3d(0.5,0.5,0.5);
        glTranslated(-0.8,4,z_axis); glScalef(1,1,0.4); glRotated(90,1,1,0); gluCylinder(gluNewQuadric(),0.1,0.4,0.6,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0.5,0.5);
        glTranslated(-0.8,4,z_axis); glScalef(0.9,0.9,0.4); glRotated(90,1,1,0); gluCylinder(gluNewQuadric(),0.095,0.4,0.6,slices,stacks);
    glPopMatrix();


    glPushMatrix();
        glColor3d(0.8,0.8,0.8);
        glTranslated(0,2.7,z_axis); glScalef(1,0.6,0.5); glutSolidSphere(1.0, slices, stacks);
    glPopMatrix();

    glPushMatrix();
        glColor3d(1,0.5,0.5);
        glTranslated(0,2.7,z_axis+0.4); glScalef(1,0.5,1); glutSolidSphere(0.15, slices, stacks);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0,2.65,z_axis+0.4); glScalef(0.5,1,1); glutSolidSphere(0.125, slices, stacks);
    glPopMatrix();


    glPushMatrix();
        glColor3d(0.4,0.4,0.4);
        glTranslated(0,2.45,z_axis+0.38); glScalef(1.5,0.2,1); glutSolidSphere(0.15, slices, stacks);
    glPopMatrix();


    glColor3d(0.4,0.4,0.4);

        glPushMatrix(); glTranslated(0.455,2.6,z_axis+0.42); glRotated(100,0,1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.4,slices,stacks); glPopMatrix();
        glPushMatrix(); glTranslated(0.46,2.5,z_axis+0.42); glRotated(100,0,1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.72,slices,stacks); glPopMatrix();
        glPushMatrix(); glTranslated(0.475,2.4,z_axis+0.42); glRotated(100,0,1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.75,slices,stacks); glPopMatrix();
        glPushMatrix(); glTranslated(-0.455,2.6,z_axis+0.42); glRotated(100,0,-1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.4,slices,stacks); glPopMatrix();
        glPushMatrix(); glTranslated(-0.46,2.5,z_axis+0.42); glRotated(100,0,-1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.72,slices,stacks); glPopMatrix();
        glPushMatrix(); glTranslated(-0.475,2.4,z_axis+0.42); glRotated(100,0,-1,0); glRotated(15,1,0,0); gluCylinder(gluNewQuadric(),0.0125,0.001,0.75,slices,stacks); glPopMatrix();

    glColor3d(1,1,0.4); glPushMatrix(); glTranslated(0.261,3.05,z_axis+0.42);glScaled(0.8,1.3,0.5);glutSolidSphere(0.2,slices,stacks); glPopMatrix(); //socket
    glColor3d(0,0,0);  glPushMatrix(); glTranslated(0.28,2.95,z_axis+0.49);glScaled(0.5,0.7,0.5);glutSolidSphere(0.15,slices,stacks); glPopMatrix(); //pulp
    glColor3d(1,1,0.4); glPushMatrix(); glTranslated(-0.261,3.05,z_axis+0.42);glScaled(0.8,1.3,0.5);glutSolidSphere(0.2,slices,stacks); glPopMatrix(); //socket
    glColor3d(0,0,0);  glPushMatrix(); glTranslated(-0.28,2.95,z_axis+0.49);glScaled(0.5,0.7,0.5);glutSolidSphere(0.15,slices,stacks); glPopMatrix(); //pulp



    glPushMatrix();
        glColor3d(0.5,0.5,0.5);
        glTranslated(0,1.6,z_axis); glScalef(1,1,1); glRotated(-90,1,0,0); gluCylinder(gluNewQuadric(),0.5,0.3,1,slices,stacks);
    glPopMatrix();



}



void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    }

    // Request a redraw of the scene.
    glutPostRedisplay();
}




static void display(void)
{

glPushMatrix();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, upX, upY, upZ);
    gluLookAt(0, 0, -20, lookX, lookY, lookZ, upX, upY, upZ);

    drawBody();
    drawHead();






   glPopMatrix();
    glFlush();


    glutSwapBuffers();
}



static void idle(void)
{
    //glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,640);
    glutInitWindowPosition(108,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);

    glClearColor(0,0,0.9,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return EXIT_SUCCESS;
}


