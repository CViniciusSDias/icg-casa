#include "Retangulo.hpp"

Retangulo::Retangulo(int x, int y, int l, int a)
    : x(x), y(y), largura(l), altura(a)
{ };

void Retangulo::desenhar()
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + largura, y);
    glVertex2f(x + largura, y - altura);
    glVertex2f(x, y - altura);
    glEnd();
};