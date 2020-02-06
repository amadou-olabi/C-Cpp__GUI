#include <windows.h>
#include <GL/glut.h>

GLfloat gfPosX = 0.0;
GLfloat gfDeltaX = .01;

void Draw() {
    glClearColor(0.0,0.5,0.1,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(0.75,0.75,0.0);
        glVertex3f(0.95,0.95,0.0);
    glEnd();
    glutSwapBuffers();
    gfPosX += gfDeltaX;
    if (gfPosX >= 1.0 || gfPosX <= 0.0) {
        gfDeltaX = -gfDeltaX;
    }
}

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(10, Timer, 0);
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("double buffer");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    return 0;
}

