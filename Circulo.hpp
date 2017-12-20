#ifndef CIRCULO_H
#define CIRCULO_h
#include <GL/glut.h>
#include <math.h>
#include "IForma.hpp"

class Circulo : public IForma
{
    private:
        float x, y;
        float raio;
    public:
        Circulo(float x, float y, float raio);
        void desenhar();
};

#endif