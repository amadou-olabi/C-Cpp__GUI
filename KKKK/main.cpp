#include <windows.h>
#include <GL/glut.h>

GLfloat gfPosX = 0.0;
GLfloat gfDeltaX = .01;
GLfloat x1=0.25,y1=0.75,x2=0.75,y2=0.25;

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2,0.0);
    glEnd();
    //glRotatef(360,1-gfPosX,gfPosX,0.0f);
    glutSwapBuffers();
    if(x1<=-1)
    {
        x1=x1+gfDeltaX;
    }
    else
    {
        x1=x1-gfDeltaX;
    }
    if(y1<=-1)
    {
        y1=y1+gfDeltaX;
    }
    else
    {
        y1=y1-gfDeltaX;
    }
    if(x2<=-1)
    {
        x2=x2+gfDeltaX;
    }
    else
    {
        x2=x2-gfDeltaX;
    }
    if(y2<=-1)
    {
        y2=y2+gfDeltaX;
    }
    else
    {
        y2=y2-gfDeltaX;
    }

}

void Timer(int iUnused)
{
    glutPostRedisplay();
    glutTimerFunc(20, Timer, 0);
}

void Initialize() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 0.0, 1.0, 0.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("ROTATE");
    Initialize();
    glutDisplayFunc(Draw);
    Timer(0);
    glutMainLoop();
    return 0;
}
