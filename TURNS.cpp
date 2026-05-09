#include "cubix.h"

void Cube::Drev() //D'
{
    if (logging)
    {
        logs.emplace_back("D'");
    }
    int down[3][3] =
            {
            {colors[4][0], colors[4][1], colors[4][2]},
            {colors[4][3], colors[4][4], colors[4][5]},
            {colors[4][6], colors[4][7], colors[4][8]}
            };

    colors[4][0] = down[0][2];
    colors[4][1] = down[1][2];
    colors[4][2] = down[2][2];
    colors[4][3] = down[0][1];
    colors[4][4] = down[1][1];
    colors[4][5] = down[2][1];
    colors[4][6] = down[0][0];
    colors[4][7] = down[1][0];
    colors[4][8] = down[2][0];
    int front[3] = {colors[0][0], colors[0][1], colors[0][2]};
    int right[3] = {colors[3][0], colors[3][1], colors[3][2]};
    int back[3] = {colors[1][0], colors[1][1], colors[1][2]};
    int left[3] = {colors[2][0], colors[2][1], colors[2][2]};

    colors[0][0] = right[0];
    colors[0][1] = right[1];
    colors[0][2] = right[2];

    colors[3][0] = back[2];
    colors[3][1] = back[1];
    colors[3][2] = back[0];

    colors[1][0] = left[0];
    colors[1][1] = left[1];
    colors[1][2] = left[2];

    colors[2][0] = front[2];
    colors[2][1] = front[1];
    colors[2][2] = front[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::D() //D
{
    if (logging)
    {
        logs.emplace_back("D");
    }
    int down[3][3] =
            {
            {colors[4][0], colors[4][1], colors[4][2]},
            {colors[4][3], colors[4][4], colors[4][5]},
            {colors[4][6], colors[4][7], colors[4][8]}
    };

    colors[4][0] = down[2][0];
    colors[4][1] = down[1][0];
    colors[4][2] = down[0][0];
    colors[4][3] = down[2][1];
    colors[4][4] = down[1][1];
    colors[4][5] = down[0][1];
    colors[4][6] = down[2][2];
    colors[4][7] = down[1][2];
    colors[4][8] = down[0][2];
    int front[3] = {colors[0][0], colors[0][1], colors[0][2]};
    int right[3] = {colors[3][0], colors[3][1], colors[3][2]};
    int back[3] = {colors[1][0], colors[1][1], colors[1][2]};
    int left[3] = {colors[2][0], colors[2][1], colors[2][2]};

    colors[0][0] = left[2];
    colors[0][1] = left[1];
    colors[0][2] = left[0];

    colors[3][0] = front[0];
    colors[3][1] = front[1];
    colors[3][2] = front[2];

    colors[1][0] = right[2];
    colors[1][1] = right[1];
    colors[1][2] = right[0];

    colors[2][0] = back[0];
    colors[2][1] = back[1];
    colors[2][2] = back[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

}

void Cube::rotateMiddle() {
    if (logging)
    {
        logs.emplace_back("rotMid");
    }
    int tempFront[3] = {colors[0][3], colors[0][4], colors[0][5]};
    int tempRight[3] = {colors[3][3], colors[3][4], colors[3][5]};
    int tempBack[3] = {colors[1][3], colors[1][4], colors[1][5]};
    int tempLeft[3] = {colors[2][3], colors[2][4], colors[2][5]};

    colors[0][3] = tempRight[0];
    colors[0][4] = tempRight[1];
    colors[0][5] = tempRight[2];

    colors[3][3] = tempBack[2];
    colors[3][4] = tempBack[1];
    colors[3][5] = tempBack[0];

    colors[1][3] = tempLeft[0];
    colors[1][4] = tempLeft[1];
    colors[1][5] = tempLeft[2];

    colors[2][3] = tempFront[2];
    colors[2][4] = tempFront[1];
    colors[2][5] = tempFront[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::rotateMiddleRev() {
    if (logging)
    {
        logs.emplace_back("rotMidRev");
    }
    int tempFront[3] = {colors[0][3], colors[0][4], colors[0][5]};
    int tempRight[3] = {colors[3][3], colors[3][4], colors[3][5]};
    int tempBack[3] = {colors[1][3], colors[1][4], colors[1][5]};
    int tempLeft[3] = {colors[2][3], colors[2][4], colors[2][5]};

    colors[0][3] = tempLeft[2];
    colors[0][4] = tempLeft[1];
    colors[0][5] = tempLeft[0];

    colors[3][3] = tempFront[0];
    colors[3][4] = tempFront[1];
    colors[3][5] = tempFront[2];

    colors[1][3] = tempRight[2];
    colors[1][4] = tempRight[1];
    colors[1][5] = tempRight[0];

    colors[2][3] = tempBack[0];
    colors[2][4] = tempBack[1];
    colors[2][5] = tempBack[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::U() //U
{
    if (logging)
    {
        logs.emplace_back("U");
    }
    int up[3][3] = {
            {colors[5][0], colors[5][1], colors[5][2]},
            {colors[5][3], colors[5][4], colors[5][5]},
            {colors[5][6], colors[5][7], colors[5][8]}
    };

    colors[5][0] = up[0][2];
    colors[5][1] = up[1][2];
    colors[5][2] = up[2][2];
    colors[5][3] = up[0][1];
    colors[5][4] = up[1][1];
    colors[5][5] = up[2][1];
    colors[5][6] = up[0][0];
    colors[5][7] = up[1][0];
    colors[5][8] = up[2][0];
    int front[3] = {colors[0][6], colors[0][7], colors[0][8]};
    int right[3] = {colors[3][6], colors[3][7], colors[3][8]};
    int back[3] = {colors[1][6], colors[1][7], colors[1][8]};
    int left[3] = {colors[2][6], colors[2][7], colors[2][8]};

    colors[0][6] = right[0];
    colors[0][7] = right[1];
    colors[0][8] = right[2];

    colors[3][6] = back[2];
    colors[3][7] = back[1];
    colors[3][8] = back[0];

    colors[1][6] = left[0];
    colors[1][7] = left[1];
    colors[1][8] = left[2];

    colors[2][6] = front[2];
    colors[2][7] = front[1];
    colors[2][8] = front[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::Urev() //U'
{
    if (logging)
    {
        logs.emplace_back("U'");
    }
    int up[3][3] = {
            {colors[5][0], colors[5][1], colors[5][2]},
            {colors[5][3], colors[5][4], colors[5][5]},
            {colors[5][6], colors[5][7], colors[5][8]}
    };

    colors[5][0] = up[2][0];
    colors[5][1] = up[1][0];
    colors[5][2] = up[0][0];
    colors[5][3] = up[2][1];
    colors[5][4] = up[1][1];
    colors[5][5] = up[0][1];
    colors[5][6] = up[2][2];
    colors[5][7] = up[1][2];
    colors[5][8] = up[0][2];

    int front[3] = {colors[0][6], colors[0][7], colors[0][8]};
    int right[3] = {colors[3][6], colors[3][7], colors[3][8]};
    int back[3] = {colors[1][6], colors[1][7], colors[1][8]};
    int left[3] = {colors[2][6], colors[2][7], colors[2][8]};

    colors[0][6] = left[2];
    colors[0][7] = left[1];
    colors[0][8] = left[0];

    colors[3][6] = front[0];
    colors[3][7] = front[1];
    colors[3][8] = front[2];

    colors[1][6] = right[2];
    colors[1][7] = right[1];
    colors[1][8] = right[0];

    colors[2][6] = back[0];
    colors[2][7] = back[1];
    colors[2][8] = back[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::Lrev() //L'
{
    if (logging)
    {
        logs.emplace_back("L'");
    }
    int down[3][3] = {
            {colors[2][0], colors[2][1], colors[2][2]},
            {colors[2][3], colors[2][4], colors[2][5]},
            {colors[2][6], colors[2][7], colors[2][8]}
    };

    colors[2][0] = down[0][2];
    colors[2][1] = down[1][2];
    colors[2][2] = down[2][2];
    colors[2][3] = down[0][1];
    colors[2][4] = down[1][1];
    colors[2][5] = down[2][1];
    colors[2][6] = down[0][0];
    colors[2][7] = down[1][0];
    colors[2][8] = down[2][0];
    int temp[3] = {colors[0][0], colors[0][3], colors[0][6]};

    colors[0][0] = colors[4][6];
    colors[0][3] = colors[4][3];
    colors[0][6] = colors[4][0];

    colors[4][0] = colors[1][0];
    colors[4][3] = colors[1][3];
    colors[4][6] = colors[1][6];

    colors[1][0] = colors[5][6];
    colors[1][3] = colors[5][3];
    colors[1][6] = colors[5][0];

    colors[5][0] = temp[0];
    colors[5][3] = temp[1];
    colors[5][6] = temp[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::L() //L
{
    if (logging)
    {
        logs.emplace_back("L");
    }
    int down[3][3] = {
            {colors[2][0], colors[2][1], colors[2][2]},
            {colors[2][3], colors[2][4], colors[2][5]},
            {colors[2][6], colors[2][7], colors[2][8]}
    };

    colors[2][0] = down[2][0];
    colors[2][1] = down[1][0];
    colors[2][2] = down[0][0];
    colors[2][3] = down[2][1];
    colors[2][4] = down[1][1];
    colors[2][5] = down[0][1];
    colors[2][6] = down[2][2];
    colors[2][7] = down[1][2];
    colors[2][8] = down[0][2];
    int temp[3] = {colors[0][0], colors[0][3], colors[0][6]};

    colors[0][0] = colors[5][0];
    colors[0][3] = colors[5][3];
    colors[0][6] = colors[5][6];

    colors[5][0] = colors[1][6];
    colors[5][3] = colors[1][3];
    colors[5][6] = colors[1][0];

    colors[1][0] = colors[4][0];
    colors[1][3] = colors[4][3];
    colors[1][6] = colors[4][6];

    colors[4][0] = temp[2];
    colors[4][3] = temp[1];
    colors[4][6] = temp[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::rotateMiddleUp() {
    if (logging)
    {
        logs.emplace_back("rotMidUp");
    }
    int temp[3] = {colors[0][1], colors[0][4], colors[0][7]};

    colors[0][1] = colors[4][7];
    colors[0][4] = colors[4][4];
    colors[0][7] = colors[4][1];

    colors[4][1] = colors[1][1];
    colors[4][4] = colors[1][4];
    colors[4][7] = colors[1][7];

    colors[1][1] = colors[5][7];
    colors[1][4] = colors[5][4];
    colors[1][7] = colors[5][1];

    colors[5][1] = temp[0];
    colors[5][4] = temp[1];
    colors[5][7] = temp[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::rotateMiddleDown() {
    if (logging)
    {
        logs.emplace_back("rotMidDown");
    }

    int temp[3] = {colors[0][1], colors[0][4], colors[0][7]};

    colors[0][1] = colors[5][1];
    colors[0][4] = colors[5][4];
    colors[0][7] = colors[5][7];

    colors[5][1] = colors[1][7];
    colors[5][4] = colors[1][4];
    colors[5][7] = colors[1][1];

    colors[1][1] = colors[4][1];
    colors[1][4] = colors[4][4];
    colors[1][7] = colors[4][7];

    colors[4][1] = temp[2];
    colors[4][4] = temp[1];
    colors[4][7] = temp[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::R() //R
{
    if (logging)
    {
        logs.emplace_back("R");
    }
    int up[3][3] = {
            {colors[3][0], colors[3][1], colors[3][2]},
            {colors[3][3], colors[3][4], colors[3][5]},
            {colors[3][6], colors[3][7], colors[3][8]}
    };

    colors[3][0] = up[0][2];
    colors[3][1] = up[1][2];
    colors[3][2] = up[2][2];
    colors[3][3] = up[0][1];
    colors[3][4] = up[1][1];
    colors[3][5] = up[2][1];
    colors[3][6] = up[0][0];
    colors[3][7] = up[1][0];
    colors[3][8] = up[2][0];
    int temp[3] = {colors[0][2], colors[0][5], colors[0][8]};

    colors[0][2] = colors[4][8];
    colors[0][5] = colors[4][5];
    colors[0][8] = colors[4][2];

    colors[4][2] = colors[1][2];
    colors[4][5] = colors[1][5];
    colors[4][8] = colors[1][8];

    colors[1][2] = colors[5][8];
    colors[1][5] = colors[5][5];
    colors[1][8] = colors[5][2];

    colors[5][2] = temp[0];
    colors[5][5] = temp[1];
    colors[5][8] = temp[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::Rrev() //R'
{
    if (logging)
    {
        logs.emplace_back("R'");
    }
    int up[3][3] = {
            {colors[3][0], colors[3][1], colors[3][2]},
            {colors[3][3], colors[3][4], colors[3][5]},
            {colors[3][6], colors[3][7], colors[3][8]}
    };

    colors[3][0] = up[2][0];
    colors[3][1] = up[1][0];
    colors[3][2] = up[0][0];
    colors[3][3] = up[2][1];
    colors[3][4] = up[1][1];
    colors[3][5] = up[0][1];
    colors[3][6] = up[2][2];
    colors[3][7] = up[1][2];
    colors[3][8] = up[0][2];
    int temp[3] = {colors[0][2], colors[0][5], colors[0][8]};

    colors[0][2] = colors[5][2];
    colors[0][5] = colors[5][5];
    colors[0][8] = colors[5][8];

    colors[5][2] = colors[1][8];
    colors[5][5] = colors[1][5];
    colors[5][8] = colors[1][2];

    colors[1][2] = colors[4][2];
    colors[1][5] = colors[4][5];
    colors[1][8] = colors[4][8];

    colors[4][2] = temp[2];
    colors[4][5] = temp[1];
    colors[4][8] = temp[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::Frev() //F'
{
    if (logging)
    {
        logs.emplace_back("F'");
    }
    int front[3][3] = {
            {colors[0][0], colors[0][1], colors[0][2]},
            {colors[0][3], colors[0][4], colors[0][5]},
            {colors[0][6], colors[0][7], colors[0][8]}
    };

    colors[0][0] = front[2][0];
    colors[0][1] = front[1][0];
    colors[0][2] = front[0][0];
    colors[0][3] = front[2][1];
    colors[0][4] = front[1][1];
    colors[0][5] = front[0][1];
    colors[0][6] = front[2][2];
    colors[0][7] = front[1][2];
    colors[0][8] = front[0][2];
    int temp[3] = {colors[5][0], colors[5][1], colors[5][2]};

    colors[5][0] = colors[3][6];
    colors[5][1] = colors[3][3];
    colors[5][2] = colors[3][0];

    colors[3][6] = colors[4][2];
    colors[3][3] = colors[4][1];
    colors[3][0] = colors[4][0];

    colors[4][2] = colors[2][0];
    colors[4][1] = colors[2][3];
    colors[4][0] = colors[2][6];

    colors[2][0] = temp[0];
    colors[2][3] = temp[1];
    colors[2][6] = temp[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::F() //F
{
    if (logging)
    {
        logs.emplace_back("F");
    }
    int front[3][3] = {
            {colors[0][0], colors[0][1], colors[0][2]},
            {colors[0][3], colors[0][4], colors[0][5]},
            {colors[0][6], colors[0][7], colors[0][8]}
    };

    colors[0][0] = front[0][2];
    colors[0][1] = front[1][2];
    colors[0][2] = front[2][2];
    colors[0][3] = front[0][1];
    colors[0][4] = front[1][1];
    colors[0][5] = front[2][1];
    colors[0][6] = front[0][0];
    colors[0][7] = front[1][0];
    colors[0][8] = front[2][0];
    int temp[3] = {colors[5][0], colors[5][1], colors[5][2]};

    colors[5][0] = colors[2][0];
    colors[5][1] = colors[2][3];
    colors[5][2] = colors[2][6];

    colors[2][6] = colors[4][0];
    colors[2][3] = colors[4][1];
    colors[2][0] = colors[4][2];

    colors[4][0] = colors[3][0];
    colors[4][1] = colors[3][3];
    colors[4][2] = colors[3][6];

    colors[3][0] = temp[2];
    colors[3][3] = temp[1];
    colors[3][6] = temp[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::B() //B
{
    if (logging)
    {
        logs.emplace_back("B");
    }
    int back[3][3] = {
            {colors[1][0], colors[1][1], colors[1][2]},
            {colors[1][3], colors[1][4], colors[1][5]},
            {colors[1][6], colors[1][7], colors[1][8]}
    };

    colors[1][0] = back[2][0];
    colors[1][1] = back[1][0];
    colors[1][2] = back[0][0];
    colors[1][3] = back[2][1];
    colors[1][4] = back[1][1];
    colors[1][5] = back[0][1];
    colors[1][6] = back[2][2];
    colors[1][7] = back[1][2];
    colors[1][8] = back[0][2];
    int temp[3] = {colors[5][6], colors[5][7], colors[5][8]};

    colors[5][6] = colors[3][8];
    colors[5][7] = colors[3][5];
    colors[5][8] = colors[3][2];

    colors[3][8] = colors[4][8];
    colors[3][5] = colors[4][7];
    colors[3][2] = colors[4][6];

    colors[4][6] = colors[2][8];
    colors[4][7] = colors[2][5];
    colors[4][8] = colors[2][2];

    colors[2][8] = temp[2];
    colors[2][5] = temp[1];
    colors[2][2] = temp[0];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::Brev() //B'
{
    if (logging)
    {
        logs.emplace_back("B'");
    }
    int back[3][3] = {
            {colors[1][0], colors[1][1], colors[1][2]},
            {colors[1][3], colors[1][4], colors[1][5]},
            {colors[1][6], colors[1][7], colors[1][8]}
    };

    colors[1][0] = back[0][2];
    colors[1][1] = back[1][2];
    colors[1][2] = back[2][2];
    colors[1][3] = back[0][1];
    colors[1][4] = back[1][1];
    colors[1][5] = back[2][1];
    colors[1][6] = back[0][0];
    colors[1][7] = back[1][0];
    colors[1][8] = back[2][0];
    int temp[3] = {colors[5][6], colors[5][7], colors[5][8]};

    colors[5][6] = colors[2][2];
    colors[5][7] = colors[2][5];
    colors[5][8] = colors[2][8];

    colors[2][8] = colors[4][6];
    colors[2][5] = colors[4][7];
    colors[2][2] = colors[4][8];

    colors[4][8] = colors[3][8];
    colors[4][7] = colors[3][5];
    colors[4][6] = colors[3][2];

    colors[3][8] = temp[0];
    colors[3][5] = temp[1];
    colors[3][2] = temp[2];

    display();
    glfwSwapBuffers(glfwGetCurrentContext());
    glfwPollEvents();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Cube::rotateFull()
{
    U();
    rotateMiddle();
    Drev();
}