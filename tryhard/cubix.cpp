

#include "cubix.h"
#define BLUE 0
#define GREEN 1
#define ORANGE 2
#define RED 3
#define YELLOW 4
#define WHITE 5


float angleX = 0.0;
float angleY = 0.0;
float angleZ = 0.0;
const float rotationSpeed = 8.0;
Cube cube;


Cube::Cube()
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<9;j++)
        {
            colors[i][j]=i;
        }
    }
}

void Cube::logger(const std::string &filename)
{
    if (!logging)
    {
        std::cout << "logs are off\n";
        return;
    }
    std::ofstream file(filename,std::ios::out);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (const std::string& i:logs)
    {
        file << i << " ";
    }
    file.close();
}

void Cube::saveCube(const std::string &filename)
{
    std::ofstream file(filename, std::ios::out);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<9;j++)
        {
            file << colors[i][j] << " ";
        }
        file << "\n";
    }
    file.close();
}

void Cube::loadCube(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    for (int i=0;i<6;i++)
    {
        for (int j=0;j<9;j++)
        {
            file >> colors[i][j];
        }
    }
    file.close();
}

void Cube::checkStatus()
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<9;j++)
        {
            std::cout << colors[i][j] << " ";
        }
        std::cout << "\n";
    }
}


void drawCube() {
    glBegin(GL_QUADS);
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<9;j++)
        {
            if (cube.colors[i][j]==0)
                glColor3f(0.0, 0.0, 1.0);// Blue
            else if (cube.colors[i][j]==1)
                glColor3f(0.0, 1.0, 0.0);// Green
            else if (cube.colors[i][j]==2)
                glColor3f(1.0, 0.67, 0.0);// Orange
            else if (cube.colors[i][j]==3)
                glColor3f(1.0, 0.0, 0.0);// Red
            else if (cube.colors[i][j]==4)
                glColor3f(1.0, 1.0, 0.0);// Yellow
            else if (cube.colors[i][j]==5)
                glColor3f(1.0, 1.0, 1.0);// White



            int row=j/3;
            int col=j%3;
            double x=col*0.3333-0.5;
            double y=row*0.3333-0.5;
            double z=0.5;
            if (i==0)
            {
                glVertex3f(x,y,-z);
                glVertex3f(x+0.3333,y,-z);
                glVertex3f(x+0.3333,y+0.3333,-z);
                glVertex3f(x,y+0.3333,-z);
            }
            else if (i==1)
            {
                glVertex3f(x,y,z);
                glVertex3f(x+0.3333,y,z);
                glVertex3f(x+0.3333,y+0.3333,z);
                glVertex3f(x,y+0.3333,z);
            }
            else if (i==2)
            {
                glVertex3f(-z,y,x);
                glVertex3f(-z,y,x + 0.3333);
                glVertex3f(-z,y+0.3333,x+0.3333);
                glVertex3f(-z,y+0.3333,x);
            }
            else if (i==3)
            {
                glVertex3f(z,y,x);
                glVertex3f(z,y,x+0.3333);
                glVertex3f(z,y+0.3333,x+0.3333);
                glVertex3f(z,y+0.3333,x);
            }
            else if (i==4)
            {
                glVertex3f(x,-z,y);
                glVertex3f(x+0.3333,-z,y);
                glVertex3f(x+0.3333,-z,y+0.3333);
                glVertex3f(x,-z,y+0.3333);
            }
            else if (i==5)
            {
                glVertex3f(x,z,y);
                glVertex3f(x+0.3333,z,y);
                glVertex3f(x+0.3333,z,y+0.3333);
                glVertex3f(x,z,y+0.3333);
            }
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    drawCube();
}

void keyCallback(GLFWwindow *window,int key,int scancode,int action,int mods)
{
    if (action==GLFW_PRESS || action==GLFW_REPEAT)
    {
        switch (key)
        {
            case GLFW_KEY_UP:
                angleX+=rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                angleX-=rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                angleY-=rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                angleY+=rotationSpeed;
                break;
            case GLFW_KEY_S:
                cube.Drev();
                break;
            case GLFW_KEY_2:
                cube.rotateMiddle();
                break;
            case GLFW_KEY_U:
                cube.U();
                break;
            case GLFW_KEY_K:
                cube.Lrev();
                break;
            case GLFW_KEY_5:
                cube.rotateMiddleUp();
                break;
            case GLFW_KEY_R:
                cube.R();
                break;
            case GLFW_KEY_L:
                cube.L();
                break;
            case GLFW_KEY_8:
                cube.rotateMiddleDown();
                break;
            case GLFW_KEY_E:
                cube.Rrev();
                break;
            case GLFW_KEY_D:
                cube.D();
                break;
            case GLFW_KEY_W:
                cube.rotateMiddleRev();
                break;
            case GLFW_KEY_I:
                cube.Urev();
                break;
            case GLFW_KEY_G:
                cube.Frev();
                break;
            case GLFW_KEY_F:
                cube.F();
                break;
            case GLFW_KEY_B:
                cube.B();
                break;
            case GLFW_KEY_V:
                cube.Brev();
                break;
            case GLFW_KEY_ENTER:
                cube.solve();
                break;
            case GLFW_KEY_TAB:
                cube.saveCube("cube.txt");
                break;
            case GLFW_KEY_ESCAPE:
                cube.loadCube("cube.txt");
                break;
            case GLFW_KEY_X:
                cube.checkStatus();
                break;
            case GLFW_KEY_EQUAL:
                cube.logger("logs.txt");
                break;
        }
    }
}

void Cube::randomize()
{
    logging=false;
    std::random_device rng;
    std::mt19937 gen(rng());
    std::uniform_int_distribution<> dis(1, 16);

    for (int i=0;i<100;i++)
    {
        int change=dis(gen);
        if (change==1)
            R();
        else if (change==2)
            Rrev();
        else if (change==3)
            F();
        else if (change==4)
            Frev();
        else if (change==5)
            L();
        else if (change==6)
            Lrev();
        else if (change==7)
            B();
        else if (change==8)
            Brev();
        else if (change==9)
            U();
        else if (change==10)
            Urev();
        else if (change==11)
            D();
        else if (change==12)
            Drev();
        else if (change==13)
            rotateMiddle();
        else if (change==14)
            rotateMiddleUp();
        else if (change==15)
            rotateMiddleDown();
        else if (change==16)
            rotateMiddleRev();
    }
    logging=true;
}