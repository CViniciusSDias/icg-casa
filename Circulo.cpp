#include "Circulo.hpp"

Circulo::Circulo(float x, float y, float raio)
{
    this->x = x;
    this->y = y;
    this->raio = raio;
};

void Circulo::desenhar()
{
    glBegin(GL_POLYGON);
    float rad, xAtual, yAtual;
    for (int i = 0; i < 360; i += 10) {
        rad = (i * M_PI) / 180.0f;
        xAtual = cos(rad) * raio + x;
        yAtual = sin(rad) * raio + y;
        glVertex2f(xAtual, yAtual);
    }
    glEnd();
};