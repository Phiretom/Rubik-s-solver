

#ifndef TRYHARD_CUBIX_H
#define TRYHARD_CUBIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <thread>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


class Cube
{
public:
    int colors[6][9];
    std::vector<std::string> logs;
    bool logging=true;

    void solve();
    void algo1();
    std::pair<char,int> find(int color1,int color2);
    void algo2();
    void algo3();
    void algo4();
    void algo5();
    void algo6();
    void algo7();
    void algo8();
    void algo9();
    void algo10();

    void step1();
    void step2();
    void step3();
    void step4();
    void step5();
    void step6();
    void step7();

    Cube();

    void rotateFull();

    void B();
    void Brev();
    void F();
    void Frev();
    void Drev();
    void D();
    void rotateMiddle();
    void rotateMiddleRev();
    void U();
    void Urev();
    void Lrev();
    void L();
    void rotateMiddleUp();
    void rotateMiddleDown();
    void R();
    void Rrev();

    void saveCube(const std::string &filename);
    void loadCube(const std::string &filename);
    void logger(const std::string &filename);
    void checkStatus();
    void randomize();
};

extern float angleX, angleY, angleZ;
extern Cube cube;

void drawCube();
void display();
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mod);
#endif //TRYHARD_CUBIX_H
