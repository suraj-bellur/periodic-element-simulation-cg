#include<windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle1 = 10;
static GLfloat angle2 = 20;
static GLfloat angle3 = 30;

static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void circle1(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(0, 0.7, 0);
    for (float i = 0; i < (2 * pi); i += 0.0001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glRotatef(10,0,0,1);
    glEnd();
}
void circle2(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(0.8, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.0001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void circle3(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(0, 0, 0.8);
    for (float i = 0; i < (2 * pi); i += 0.0001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(float x, float y, float z, char *string)
{
    glColor3f(0, 0, 0);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawhead(float x, float y, float z, char *string)
{
    glColor3f(0, 0.2, 0.8);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawhead2(float x, float y, float z, char *string)
{
    glColor3f(1, 0.2, 0);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawsubhead(float x, float y, float z, char *string)
{
    glColor3f(0.1, 0.6, 0);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void drawsubstring(float x, float y, float z, char *string)
{
    glColor3f(0, 0, 0);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0.8, 1);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void nuc1(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.2, 0.7);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void nuc2(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.1, 0.9);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void nuc3(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.9, 0);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}

void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 30 * cos(i), 30 * sin(i));
    }
    glEnd();
}
void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 30 * cos(i)), 30 * sin(i));
    }
    glEnd();
}
void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(30 * cos(i), rad + 30 * sin(i));
    }
    glEnd();
}
void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(30 * cos(i), -(rad + 30 * sin(i)));
    }
    glEnd();
}
void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 30 * cos(i)), ((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void eletl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 30 * cos(i)), ((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void eledl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 30 * cos(i)), -((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void eledr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 30 * cos(i)), -((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void elef(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 30 * cos(i)), -((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void elen(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 30 * cos(i)), -((rad - 175) + 30 * sin(i)));
    }
    glEnd();
}
void eles(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 235) + 30 * cos(i)), ((rad - 235) + 30 * sin(i)));
    }
    glEnd();
}
void elem(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 235) + 30 * cos(i)), ((rad - 235) + 30 * sin(i)));
    }
    glEnd();
}
void elea(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 235) + 30 * cos(i)), -((rad - 235) + 30 * sin(i)));
    }
    glEnd();
}

void elesi(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 235) + 30 * cos(i)), -((rad - 235) + 30 * sin(i)));
    }
    glEnd();
}
void display()
{
    glClearColor(1, 1, 0.9, 1);

    if (value == -1)
    {
        char cn[] = "DAYANANDA SAGAR ACADEMY OF TECHNOLOGY AND MANAGEMENT";
        drawhead(-900, 900, 0, cn);
        char pn[] = "KANAKPURA ROAD,BANGALORE-560082";
        drawsubhead(-400, 850, 0, pn);

        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawhead(-750, 650, 0, dn);

        char prn[] = "A Mini Project On";
        drawsubhead(-180, 450, 0, prn);
        char pro[] = "PERIODIC REPRESENTATION OF ELEMENTS IN MODEL";
        drawhead(-700, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-890, -150, 0, pb);

        char p1[] = "SURAJ B PRAKASH";
        drawhead(-890, -250, 0, p1);
        char p1u[] = "1DT19CS60";
        drawsubhead(-890, -300, 0, p1u);

        char p2[] = "VIBHA S";
        drawhead(-890, -400, 0, p2);
        char p2u[] = "1DT19CS174";
        drawsubhead(-890, -450, 0, p2u);

        char gb[] = "GUIDED BY: ";
        drawhead(290, -150, 0, gb);

        char g1[] = "Mrs. APOORVA BUSAD";
        drawhead(290, -250, 0, g1);
        char d1[] = "Professor, Dept. Of CSE";
        drawsubhead(290, -300, 0, d1);

        char in[] = "Press enter to Continue";
        drawhead(-320, -700, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(280);
        char n[] = "NUCLEUS";
        drawString(-120, -10, 0, n);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT USING MENU";
            drawhead(-490, 900, 0, nu);
            char h1[]="NUCLEUS AND PROTON WAS DISCOVERED BY : ERNEST RUTHERFORD";
            drawhead2(-900,-725,0,h1);
            char h2[]="ELECTRON WAS DISCOVERED BY                        : J.J THOMSON";
            drawhead2(-900,-825,0,h2);
        }
    }
    if (value == 1)
    {
        char n[] = "HYDROGEN ATOM";
        drawhead(-220, 900, 0, n);
        char p1[]="HYDROGEN ATOM WAS DISCOVERED BY HENRY CAVENDISH";
        drawhead2(-800,-925,0,p1);
        nuc1(280);
        char nH[] = "HYDROGEN";
        drawString(-130, -10, 0, nH);
        char nH1[] = "1 - ELECTRON";
        drawsubstring(-120,-60,0,nH1);
        circle1(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        char e[] = "ELECTRON";
        drawString(430, 10, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        char n[] = "HELIUM ATOM";
        drawhead(-220, 900, 0, n);
        char p2[]="HELIUM ATOM WAS DISCOVERED BY PIERRE JANSEN";
        drawhead2(-700,-925,0,p2);
        nuc1(280);
        char nHe[] = "HELIUM";
        drawString(-100, -10, 0, nHe);
        char nHe1[] = "2 - ELECTRON";
        drawsubstring(-120,-60,0,nHe1);
        circle1(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        char e1[] = "ELECTRON 1";
        drawString(-430, 0, 0, e1);
        eleleft(400);
        char e2[] = "ELECTRON 2";
        drawString(430, 0, 0, e2);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM ATOM";
        drawhead(-220, 900, 0, n);
        char p3[]="LITHIUM ATOM WAS DISCOVERED BY JOHAN AUGUST";
        drawhead2(-700,-925,0,p3);
        nuc2(280);
        char nL[] = "LITHIUM";
        drawString(-100, -10, 0, nL);
        char nL1[] = "3 - ELECTRON";
        drawsubstring(-120,-60,0,nL1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM ATOM";
        drawhead(-230, 900, 0, n);
        char p4[]="BERYLLIUM ATOM WAS DISCOVERED BY LOUIS NICOLAS VAUQUELIN";
        drawhead2(-900,-925,0,p4);
        nuc2(280);
        char nB[] = "BERYLLIUM";
        drawString(-140, -10, 0, nB);
        char nB1[] = "4 - ELECTRON";
        drawsubstring(-120,-60,0,nB1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON ATOM";
        drawhead(-220, 900, 0, n);
        char p5[]="BORON ATOM WAS DISCOVERED BY LOUIS GAY-LUSSAC";
        drawhead2(-750,-925,0,p5);
        nuc2(280);
        char nBo[] = "BORON";
        drawString(-100, -10, 0, nBo);
        char nBo1[] = "5 - ELECTRON";
        drawsubstring(-120,-60,0,nBo1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON ATOM";
        drawhead(-220, 900, 0, n);
        char p6[]="CARBON ATOM WAS DISCOVERED BY ANTOINE LAVOISIER";
        drawhead2(-750,-925,0,p6);
        nuc2(280);
        char nC[] = "CARBON";
        drawString(-100, -10, 0, nC);
        char nC1[] = "6 - ELECTRON";
        drawsubstring(-120,-60,0,nC1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN ATOM";
        drawhead(-220, 900, 0, n);
        char p7[]="NITROGEN ATOM WAS DISCOVERED BY DANIEL RUTHERFORD";
        drawhead2(-800,-925,0,p7);
        nuc2(280);
        char nN[] = "NITROGEN";
        drawString(-120, -10, 0, nN);
        char nN1[] = "7 - ELECTRON";
        drawsubstring(-120,-60,0,nN1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);\
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN ATOM";
        drawhead(-220, 900, 0, n);
        char p8[]="OXYGEN ATOM WAS DISCOVERED BY JOSEPH PRIESTLEY";
        drawhead2(-750,-925,0,p8);
        nuc2(280);
        char nO[] = "OXYGEN";
        drawString(-110, -10, 0, nO);
        char nO1[] = "8 - ELECTRON";
        drawsubstring(-120,-60,0,nO1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE ATOM";
        drawhead(-220, 900, 0, n);
        char p9[]="FLUORINE ATOM WAS DISCOVERED BY HENRY MOISSAN";
        drawhead2(-750,-925,0,p9);
        nuc2(280);
        char nF[] = "FLUORINE";
        drawString(-120, -10, 0, nF);
        char nFF[] = "9 - ELECTRON";
        drawsubstring(-120,-60,0,nFF);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON ATOM";
        drawhead(-220, 900, 0, n);
        char p10[]="NEON ATOM WAS DISCOVERED BY WILLIAM RAMSEY";
        drawhead2(-700,-925,0,p10);
        nuc2(280);
        char nNE[] = "NEON";
        drawString(-60, -10, 0, nNE);
        char nNE1[] = "10 - ELECTRON";
        drawsubstring(-120,-60,0,nNE1);
        circle1(400);
        circle2(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        glRotatef(angle1, 0, 0, 1);
        elen(600);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 15)
    {
        char n[] = "SODIUM ATOM";
        drawhead(-220, 900, 0, n);
        char p11[]="SODIUM ATOM WAS DISCOVERED BY HUMPHRY DAVY";
        drawhead2(-750,-925,0,p11);
        nuc3(280);
        char nS[] = "SODIUM";
        drawString(-110, -10, 0, nS);
        char nS1[] = "11 - ELECTRON";
        drawsubstring(-120,-60,0,nS1);
        circle1(400);
        circle2(600);
        circle3(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        glRotatef(angle1, 0, 0, 1);
        elen(600);
        glRotatef(angle3, 0, 0, 1);
        eles(800);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 16)
    {
        char n[] = "MAGNESIUM ATOM";
        drawhead(-220, 900, 0, n);
        char p12[]="MAGNESIUM ATOM WAS DISCOVERED BY JOSEPH BLACK";
        drawhead2(-750,-925,0,p12);
        nuc3(280);
        char nM[] = "MAGNESIUM";
        drawString(-150, -10, 0, nM);
        char nM1[] = "12 - ELECTRON";
        drawsubstring(-120,-60,0,nM1);
        circle1(400);
        circle2(600);
        circle3(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        glRotatef(angle1, 0, 0, 1);
        elen(600);
        glRotatef(angle3, 0, 0, 1);
        eles(800);
        elem(800);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 17)
    {
        char n[] = "ALUMINIUM ATOM";
        drawhead(-220, 900, 0, n);
        char p13[]="ALUMINIUM ATOM WAS DISCOVERED BY HANS CHRISTIAN ORSTED";
        drawhead2(-875,-925,0,p13);
        nuc3(280);
        char nA[] = "ALUMINIUM";
        drawString(-130, -10, 0, nA);
        char nA1[] = "13 - ELECTRON";
        drawsubstring(-120,-60,0,nA1);
        circle1(400);
        circle2(600);
        circle3(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        glRotatef(angle1, 0, 0, 1);
        elen(600);
        glRotatef(angle3, 0, 0, 1);
        eles(800);
        elem(800);
        elea(800);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if(value == 18)
    {
        char n[] = "SILICON ATOM";
        drawhead(-220, 900, 0, n);
        char p14[]="SILICON ATOM WAS DISCOVERED BY JONS JACOB BERZELIUS";
        drawhead2(-825,-925,0,p14);
        nuc3(280);
        char nSE[] = "SILICON";
        drawString(-100, -10, 0, nSE);
        char nSE1[] = "14 - ELECTRON";
        drawsubstring(-120,-60,0,nSE1);
        circle1(400);
        circle2(600);
        circle3(800);
        char o[] = "ORBIT";
        drawString(810, 0, 0, o);
        glPushMatrix();
        glRotatef(angle1, 0, 0, 1);
        eleright(400);
        eleleft(400);
        glRotatef(angle2, 0, 0, 1);
        eletop(600);
        eledown(600);
        eletr(600);
        eledl(600);
        eletl(600);
        eledr(600);
        glRotatef(angle1, 0, 0, 1);
        elef(600);
        glRotatef(angle1, 0, 0, 1);
        elen(600);
        glRotatef(angle3, 0, 0, 1);
        eles(800);
        elem(800);
        elea(800);
        elesi(800);
        char e[] = "ELECTRON";
        drawString(0, 620, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

    glutSwapBuffers();
}
void rotate()
{
    angle1 = angle1 + 20.0;
    if (angle1 > 360.0)
    {
        angle1 = angle1 - 360.0;
    }
    angle2 = angle2 + 9.0;
    if (angle1 > 360.0)
    {
        angle2 = angle2 - 360.0;
    }
    angle3 = angle3 + 4.5;
    if (angle3 > 360.0)
    {
        angle3 = angle3 - 360.0;
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 'r')
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 'w')
    {
        glutReshapeWindow(700, 700);
    }
}
void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}
void menu(int option)
{
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if(option==14){
        value=-1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}
void createMenu(void)
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    glutAddMenuEntry("SODIUM", 15);
    glutAddMenuEntry("MAGNESIUM", 16);
    glutAddMenuEntry("ALUMINIUM", 17);
    glutAddMenuEntry("SILICON", 18);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN",14);
    glutAddMenuEntry("EXIT", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(700, 700);
    glutCreateWindow("PERIODIC REPRESENTATION OF ELEMENTS IN MODEL");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(fkey);
    createMenu();
    glutMainLoop();
    return 0;
}
