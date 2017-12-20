#ifndef RETANGULO_H
#define RETANGULO_H
#include <GL/glut.h>
#include "IForma.hpp"

class Retangulo : public IForma
{
    private:
        int x;
        int y;
        int largura;
        int altura;
    public:
        Retangulo(int x, int y, int l, int a);
        void desenhar();
};

#endif