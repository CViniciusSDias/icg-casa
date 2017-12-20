#include "Ponto.hpp"

Ponto::Ponto(int x, int y, int tamanho)
{
    this->x = x;
    this->y = y;
    this->size = tamanho;
};

void Ponto::desenhar()
{
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
};
