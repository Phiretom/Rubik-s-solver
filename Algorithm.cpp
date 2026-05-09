#include "cubix.h"
#define BLUE 0
#define GREEN 1
#define ORANGE 2
#define RED 3
#define YELLOW 4
#define WHITE 5

void Cube::solve()
{
    step1();
    step2();
    step3();
    step4();
    step5();
    step6();
    step7();
}

void Cube::step1()
{
    std::cout << "\n1)";

    int i;
    if(colors[5][4]!=YELLOW)
    {
        for (i=0;i<5;i++)
        {
            if (colors[i][4]==YELLOW)
                break;
        }
        if (i==0)
            rotateMiddleUp();
        else if (i==1)
            rotateMiddleDown();
        else if (i==2 || i==3)
        {
            rotateMiddleRev();
            if (i==2)
                rotateMiddleUp();
            else
                rotateMiddleDown();
        }
        else if (i==4)
        {
            rotateMiddleUp();
            rotateMiddleUp();
        }
    }


    int count=0;
    int j;

    if (colors[5][1]==WHITE)
        count++;
    if (colors[5][3]==WHITE)
        count++;
    if (colors[5][5]==WHITE)
        count++;
    if (colors[5][7]==WHITE)
        count++;

    bool flag;
    while (count<4)
    {
        flag=false;
        for (i=0;i<5;i++)
        {
            for (j=1;j<8;j+=2)
            {
                if (colors[i][j]==WHITE)
                {
                    flag=true;
                    break;
                }
            }
            if (flag)
                break;
        }


        if (i==4)
        {
            while (colors[5][j]==WHITE)
                U();
            for (int k=0;k<2;k++)
            {
                if (j==1)
                    F();
                else if (j==3)
                    L();
                else if (j==5)
                    R();
                else if (j==7)
                    B();
            }
            count++;
        }
        else if ((j==3 || j==5) && colors[i][j]==WHITE)
        {
            if (j==3 && i==0)
            {
                while (colors[5][3]==WHITE)
                    U();
                Lrev();
            }
            else if (j==5 && i==0)
            {
                while (colors[5][5]==WHITE)
                    U();
                R();
            }
            else if (j==3 && i==1)
            {
                while (colors[5][3]==WHITE)
                    U();
                L();
            }
            else if (j==5 && i==1)
            {
                while (colors[5][5]==WHITE)
                    U();
                Rrev();
            }
            else if (j==3 && i==2)
            {
                while (colors[5][1]==WHITE)
                    U();
                F();
            }
            else if (j==5 && i==2)
            {
                while (colors[5][7]==WHITE)
                    U();
                Brev();
            }
            else if (j==3 && i==3)
            {
                while (colors[5][1]==WHITE)
                    U();
                Frev();
            }
            else if (j==5 && i==3)
            {
                while (colors[5][7]==WHITE)
                    U();
                B();
            }
            count++;
        }
        else if (j==1 || j==7)
        {
            if (j==1 && i==0)
            {
                while (colors[5][1]==WHITE)
                    U();
                Frev();
                while (colors[5][5]==WHITE)
                    U();
                R();
            }
            else if (j==7 && i==0)
            {
                while (colors[5][1]==WHITE)
                    U();
                Frev();
                while (colors[5][3]==WHITE)
                    U();
                Lrev();
            }
            else if (j==1 && i==1)
            {
                while (colors[5][7]==WHITE)
                    U();
                B();
                while (colors[5][5]==WHITE)
                    U();
                Rrev();
            }
            else if (j==7 && i==1)
            {
                while (colors[5][7]==WHITE)
                    U();
                B();
                while (colors[5][3]==WHITE)
                    U();
                L();
            }
            else if (j==1 && i==2)
            {
                while (colors[5][3]==WHITE)
                    U();
                L();
                while (colors[5][7]==WHITE)
                    U();
                Brev();
            }
            else if (j==7 && i==2)
            {
                while (colors[5][3]==WHITE)
                    U();
                L();
                while (colors[5][1]==WHITE)
                    U();
                F();
            }
            else if (j==1 && i==3)
            {
                while (colors[5][5]==WHITE)
                    U();
                R();
                while (colors[5][1]==WHITE)
                    U();
                Frev();
            }
            else if (j==7 && i==3)
            {
                while (colors[5][5]==WHITE)
                    U();
                R();
                while (colors[5][7]==WHITE)
                    U();
                B();
            }
            count++;
        }
    }
    if (colors[5][1]!=WHITE || colors[5][3]!=WHITE || colors[5][5]!=WHITE || colors[5][7]!=WHITE)
    {
        std::cout << "ERROR\n";
        return;
    }
    else
    {
        std::cout << "\n";
    }

    //first and second center
    while (colors[0][7]!=colors[0][4] || colors[5][1]!=WHITE)
        Urev();
    F();
    F();
    while (colors[3][7]!=colors[3][4] || colors[5][5]!=WHITE)
        Urev();
    Rrev();
    Rrev();

    //third and fourth center
    rotateFull();
    rotateFull();
    while (colors[0][7]!=colors[0][4] || colors[5][1]!=WHITE)
        Urev();
    F();
    F();
    while (colors[3][7]!=colors[3][4] || colors[5][5]!=WHITE)
        Urev();
    Rrev();
    Rrev();
}

void Cube::algo1()
{
    R();U();Rrev();Urev();
}

std::pair<char,int> Cube::find(int color1,int color2)
{
    if (colors[0][0]==WHITE || colors[0][0]==color1 || colors[0][0]==color2)
    {
        if (colors[2][0]==WHITE || colors[2][0]==color1 || colors[2][0]==color2)
        {
            if (colors[4][0]==WHITE || colors[4][0]==color1 || colors[4][0]==color2)
                return {'d',0};
        }
    }
    if (colors[0][2]==WHITE || colors[0][2]==color1 || colors[0][2]==color2)
    {
        if (colors[3][0]==WHITE || colors[3][0]==color1 || colors[3][0]==color2)
        {
            if (colors[4][2]==WHITE || colors[4][2]==color1 || colors[4][2]==color2)
                return {'d',2};
        }
    }
    if (colors[0][6]==WHITE || colors[0][6]==color1 || colors[0][6]==color2)
    {
        if (colors[2][6]==WHITE || colors[2][6]==color1 || colors[2][6]==color2)
        {
            if (colors[5][0]==WHITE || colors[5][0]==color1 || colors[5][0]==color2)
                return {'u',0};
        }
    }
    if (colors[0][8]==WHITE || colors[0][8]==color1 || colors[0][8]==color2)
    {
        if (colors[3][6]==WHITE || colors[3][6]==color1 || colors[3][6]==color2)
        {
            if (colors[5][2]==WHITE || colors[5][2]==color1 || colors[5][2]==color2)
            {
                return {'u',2};
            }
        }
    }
    if (colors[1][0]==WHITE || colors[1][0]==color1 || colors[1][0]==color2)
    {
        if (colors[2][2]==WHITE || colors[2][2]==color1 || colors[2][2]==color2)
        {
            if (colors[4][6]==WHITE || colors[4][6]==color1 || colors[4][6]==color2)
                return {'d',6};
        }
    }
    if (colors[1][2]==WHITE || colors[1][2]==color1 || colors[1][2]==color2)
    {
        if (colors[3][2]==WHITE || colors[3][2]==color1 || colors[3][2]==color2)
        {
            if (colors[4][8]==WHITE || colors[4][8]==color1 || colors[4][8]==color2)
                return {'d',8};
        }
    }
    if (colors[1][6]==WHITE || colors[1][6]==color1 || colors[1][6]==color2)
    {
        if (colors[2][8]==WHITE || colors[2][8]==color1 || colors[2][8]==color2)
        {
            if (colors[5][6]==WHITE || colors[5][6]==color1 || colors[5][6]==color2)
                return {'u',6};
        }
    }
    if (colors[1][8]==WHITE || colors[1][8]==color1 || colors[1][8]==color2)
    {
        if (colors[3][8]==WHITE || colors[3][8]==color1 || colors[3][8]==color2)
        {
            if (colors[5][8]==WHITE || colors[5][8]==color1 || colors[5][8]==color2)
            {
                return {'u',8};
            }
        }
    }
    return {'Z',99};
}

void Cube::step2()
{
    std::cout << "\n2)";
    int actual1;
    int actual2;
    for (int i=0;i<4;i++)
    {
        actual1=colors[0][4];
        actual2=colors[3][4];
        std::pair<char,int> angle;
        angle=find(actual1,actual2);
        if (angle.first=='u')
        {
            if (angle.second==0)
                Urev();
            else if (angle.second==6)
            {
                U();U();
            }
            else if (angle.second==8)
                U();


            while (colors[0][2]!=actual1 || colors[3][0]!=actual2 || colors[4][2]!=WHITE)
                algo1();

            rotateFull();
        }
        else if (angle.first=='d')
        {
            if (angle.second==0)
            {
                rotateFull();
                rotateFull();
                rotateFull();
            }
            else if (angle.second==6)
            {
                rotateFull();
                rotateFull();
            }
            else if (angle.second==8)
                rotateFull();


            algo1();
            while (actual1!=colors[0][4] || actual2!=colors[3][4])
            {
                rotateFull();
                Urev();
            }
            while (colors[0][2]!=actual1 || colors[3][0]!=actual2 || colors[4][2]!=WHITE)
                algo1();

            rotateFull();
        }
    }
}

void Cube::algo2()
{
    R();Urev();Rrev();Urev();Frev();U();F();
}

void Cube::algo3()
{
    U();R();Urev();Rrev();Urev();Frev();U();F();
}

void Cube::algo4()
{
    Rrev();Urev();Rrev();Urev();Rrev();U();R();U();R();
}

void Cube::step3()
{
    std::cout << "\n3)";
    int counter=0;
    int i=0;
    for (int j=0;j<4;j++)
    {
        if (colors[0][5]==colors[0][4] && colors[3][3]==colors[3][4])
            counter++;
        rotateFull();
    }
    int j=0;
    while (counter<4)
    {
        if (j>=4)
            return;
        int central=colors[0][4];
        int right=colors[3][4];
        if (colors[0][5]==colors[0][4] && colors[3][3]==colors[3][4])
        {
            rotateFull();
            j++;
            continue;
        }
        if (colors[0][5]==YELLOW || colors[3][3]==YELLOW)
        {
            while ((colors[0][7]!=central || colors[5][1]!=right) && i<4)
            {
                Urev();
                i++;
            }
            if (i>=4)
            {
                i=0;
                while ((colors[3][7]!=right || colors[5][5]!=central) && i<4)
                {
                    Urev();
                    i++;
                }
                if (i>=4)
                {
                    rotateFull();
                    j=0;
                    continue;
                }
            }
            i=0;
            if (colors[0][7]==central && colors[5][1]==right)
            {
                algo3();
                counter++;
                rotateFull();
            }
            else if (colors[3][7]==right && colors[5][5]==central)
            {
                algo4();
                counter++;
                rotateFull();
            }
        }
        else
        {
            algo2();
        }
        j=0;
    }
}

void Cube::algo5()
{
    F();R();U();Rrev();Urev();Frev();
}

void Cube::step4()
{
    std::cout <<"\n4)";
    if (colors[5][3]==YELLOW && colors[5][5]==YELLOW && colors[5][1]==YELLOW && colors[5][7]==YELLOW)
        return;
    for (int i=0;i<4;i++)
    {
        if (colors[5][3]==YELLOW && colors[5][5]==YELLOW)
        {
            algo5();
            return;
        }
        else if (colors[5][3]==YELLOW && colors[5][7]==YELLOW)
        {
            algo5();
            algo5();
            return;
        }
        rotateFull();
    }
    algo5();
    algo5();
    U();
    algo5();
}

void Cube::algo6()
{
    Rrev();U();U();R();U();Rrev();U();R();
}

void Cube::algo7()
{
    Urev();R();Urev();Urev();Rrev();Urev();R();Urev();Rrev();
}

void Cube::step5()
{
    std::cout << "\n5)";

    if (colors[5][2]==YELLOW && colors[5][0]==YELLOW && colors[5][6]==YELLOW && colors[5][8]==YELLOW)
        return;
    for (int i=0;i<4;i++)
    {
        if (colors[5][2]==YELLOW && colors[2][6]==YELLOW && colors[1][6]==YELLOW && colors[3][8]==YELLOW)
        {
            algo6();
            return;
        }
        else if (colors[5][2]==YELLOW && colors[0][6]==YELLOW && colors[2][8]==YELLOW && colors[1][8]==YELLOW)
        {
            algo7();
            return;
        }
        else if (colors[5][0]==YELLOW && colors[5][8]==YELLOW && colors[1][6]==YELLOW && colors[3][6]==YELLOW)
        {
            algo6();
            algo7();
            return;
        }
        else if (colors[0][6]==YELLOW && colors[0][8]==YELLOW && colors[1][6]==YELLOW && colors[1][8]==YELLOW)
        {
            algo6();
            algo6();
            return;
        }
        else if (colors[5][0]==YELLOW && colors[5][6]==YELLOW && colors[0][8]==YELLOW && colors[1][8]==YELLOW)
        {
            algo7();
            algo6();
            return;
        }
        else if (colors[0][6]==YELLOW && colors[0][8]==YELLOW && colors[2][8]==YELLOW && colors[3][8]==YELLOW)
        {
            algo6();
            Urev();
            algo6();
            return;
        }
        else if (colors[5][6]==YELLOW && colors[5][8]==YELLOW && colors[0][6]==YELLOW && colors[0][8]==YELLOW)
        {
            algo7();
            U();
            U();
            algo6();
            return;
        }
        Urev();
    }
    std::cout << "ERROR DIDNT FOUND";
}

void Cube::algo8()
{
    R();Brev();R();F();F();Rrev();B();R();F();F();R();R();
}

void Cube::step6()
{
    if (colors[0][6]==colors[0][4] && colors[0][8]==colors[0][4] && colors[1][6]==colors[1][4] && colors[1][8]==colors[1][4] && colors[2][6]==colors[2][4] && colors[2][8]==colors[2][4] && colors[3][6]==colors[3][4] && colors[3][8]==colors[3][4])
        return;
    std::cout << "\n6)";
    bool flag=false;
    for (int j=0;j<4;j++)
    {
        for (int i=0;i<4;i++)
        {
            if (colors[0][6]==colors[3][4] && colors[0][8]==colors[3][4])
            {
                flag=true;
                break;
            }
            Urev();
        }
        if (flag)
            break;
        rotateFull();
    }

    algo8();
    step6();
}

void Cube::algo9()
{
    R();Urev();R();U();R();U();R();Urev();Rrev();Urev();R();R();
}

void Cube::algo10()
{
    R();R();U();R();U();Rrev();Urev();Rrev();Urev();Rrev();U();Rrev();
}

void Cube::step7()
{
    std::cout << "\n7)";
    for (int i=0;i<4;i++)
    {
        if (colors[1][7]==colors[1][4] && colors[2][7]==colors[0][4] && colors[3][7]==colors[2][4] && colors[0][7]==colors[3][4])
        {
            algo9();
            return;
        }
        else if (colors[1][7]==colors[1][4] && colors[2][7]==colors[3][4] && colors[3][7]==colors[0][4] && colors[0][7]==colors[2][4])
        {
            algo10();
            return;
        }
        else if (colors[1][7]==colors[0][4] && colors[2][7]==colors[3][4] && colors[3][7]==colors[2][4] && colors[0][7]==colors[1][4])
        {
            algo9();
            U();
            algo9();
            Urev();
            return;
        }
        else if (colors[1][7]==colors[2][4] && colors[2][7]==colors[1][4] && colors[3][7]==colors[0][4] && colors[0][7]==colors[3][4])
        {
            algo9();
            Urev();
            algo9();
            U();
            return;
        }
        rotateFull();
    }
    std::cout << "the end\n";
}