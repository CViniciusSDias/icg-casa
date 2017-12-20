#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <GL/glut.h>
#include <stdlib.h>
#include "Casa.hpp"
#include "Retangulo.hpp"

Casa* casa;
void reshape(int largura, int altura);
void display();
void init();
void projecao();
void special(int tecla, int x, int y);
void timer(int value);
int main(int argc, char* argv[]);

#endif