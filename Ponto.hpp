#ifndef PONTO_H
#define PONTO_h
#include <GL/glut.h>
#include <math.h>
#include "IForma.hpp"

class Ponto : public IForma
{
    private:
        int x, y, size;
    public:
        Ponto(int x, int y, int tamanho);
        void desenhar();
};

#endif