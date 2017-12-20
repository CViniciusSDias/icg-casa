#include "callbacks.hpp"

int esquerda = -10;
int direita  = 10;
int baixo    = -10;
int topo     = 10;
float dx = 0;
float dy = 0;
float escala = 1;

float translacaoX = 0;
float translacaoY = 0;
float translacaoZ = 0;
float escalaX = 1;
float escalaY = 1;
float escalaZ = 1;
float angulo  = 0;

#define TIMER 50

int main(int argc, char *argv[])
{
    casa = new Casa();
    glutInit(&argc, argv);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Desenho de Casa");

    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutDisplayFunc(display);
    glutTimerFunc(TIMER, timer, 0);

    glClearColor(1, 1, 1, 1);

    init();
    glutMainLoop();

    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    casa->desenhar();

    glPushMatrix();
    glTranslatef(translacaoX, translacaoY, translacaoZ);
    glScalef(escalaX, escalaY, escalaZ);
    glRotatef(angulo, 0, 0, 1);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int largura, int altura)
{
    glViewport(0, 0, largura, altura);
    if (largura <= altura) {
        esquerda = -10;
        direita  = 10;
        baixo = -10 * altura / largura;
        topo  = 10 * altura / largura;
    } else {
        esquerda = -10 * largura / altura;
        direita = 10 * largura / altura;
        topo = 10;
        baixo = -10;
    }
    projecao();
}

void init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void projecao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(escala * esquerda + dx, escala * direita + dx, escala * baixo + dy, escala * topo + dy, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void special(int tecla, int x, int y)
{
    switch (tecla) {
        case GLUT_KEY_LEFT:
            if (dx < 10)
                dx++;
            break;
        case GLUT_KEY_RIGHT:
            if (dx > -10)
                dx--;
            break;
        case GLUT_KEY_UP:
            if (dy > -10)
                dy--;
            break;
        case GLUT_KEY_DOWN:
            if (dy < 10)
                dy++;
            break;
        case GLUT_KEY_PAGE_UP:
            escala += 0.1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            if (escala >= 0.1)
                escala -= 0.1;
            break;
    }
    projecao();
    glutPostRedisplay();
}

void timer(int value)
{
    glutTimerFunc(TIMER, timer, 0);
    casa->escurece();
    glutPostRedisplay();
}