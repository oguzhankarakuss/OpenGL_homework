#include<GL/glew.h>
#include"GLUT/glut.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <array>

using namespace std;
int T = 1200;
#define HEIGHT T
#define WIDTH T*2/3
float xr = 0 ,yr1=0 , dt = 1, seconds = 0;
float recTopL = 0;
float recTopR = 0;
float triRight = 0;
float triBottom = 0;
float triLeft = 0;
float recBottomL = 0;
float recBottomR = 0;
array<float,5> randomNums;
int triangleCount;
int i = 0;
int t1 = 0;
int t2 = 0;
int t3 = 0;
int t4 = 0;
int t5 = 0;
bool a = false;
float yr2 = -0.6;
float yr3 = -1.2;
float yr4 = -1.65;
float yr5 = -2.1;
bool isGameOver = false;
int score = 0;


class Triange{
public:

    //Triange(float x, float y, float z);

    void draw(float x, float yr, float r, float g, float b) {

        glColor3f(r, g, b);
        glBegin(GL_TRIANGLES);
        glVertex2f(x, 1.25 - yr); //sol
        glVertex2f(x+0.25, 1.25 - yr); //sağ
        glVertex2f((x + (x+0.25))/2, 1.0 - yr); //alt
        triBottom = 1.0 - yr;

        //cout << triRightLine << endl;
        //cout << "xin yeri" <<x << "  "<< endl;
        glEnd();
    }
};

int RandomFloat(int min, int max) //range : [min, max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}

float mainConverter(float variable){
    float result = variable/T;
    return result;
}

float normalizeRandom(){
    float x = RandomFloat(0,WIDTH);
    //cout <<"x--"<< x << endl;
    float result = mainConverter(x);
    if (x > T/2){
        float difference = abs(result) - abs(randomNums.back());
        if (difference < 0.35 ){
            normalizeRandom();
        }
        return result;


    }else if (x == T/2){
        float difference = abs(result) - abs(randomNums.back());
        if (difference < 0.35 ){
            normalizeRandom();
        }
        return 0.0;
    }else{
        float difference = abs(result) - abs(randomNums.back());
        if (difference < 0.35 ){
            normalizeRandom();
        }
        return result * -1;
    }

}

void timeFunc(int value) {
     t1 += 10;
    t2 += 10;
    t3 += 10;
    t4 += 10;
    t5 += 10;
            yr1 = yr1 + 0.003;
    yr2 += 0.003;
    yr3 += 0.003;
    yr4 += 0.003;
    yr5 += 0.003;
            if (0.75 - yr1 == -1) {
                yr1 = 0;
            }
            glutTimerFunc(10, timeFunc, 1);
            glutPostRedisplay();
}

void rectangle() {
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    recTopL =  -0.8 + xr;
    recTopR =  -0.3 + xr;
    glVertex2f(-0.8 + xr, -0.7); // sol üst
    glVertex2f(-0.3 + xr, -0.7); //sağ üst
    glVertex2f(-0.3 + xr, -0.9); //sağ alt
    glVertex2f(-0.8 + xr, -0.9); //sol alt

    glEnd();
}



float pointConverter(float x){
    float result = x + (T/8);
    return result;
}


void drawBitmapText(char* string, float x, float y){
    glColor3f(0.0, 0.0, 0.0);
    char* tx;
    glRasterPos2f(x,y);
    for (tx = string; *tx != '\0'; tx++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *tx);
    }

}
void collisionDetection(){
    cout<< "yr"<< yr1 << endl;
    if (yr1 > 2){
        yr1 = 0;
        t1 = 0;
        score += 1;
        if (randomNums[4] == NULL){
            for (int i=0; i<5; i++) {
                randomNums[i] = normalizeRandom();
            }
        }
    }else if (yr2 > 2){
        yr2 = -0.6;
        t2 = 0;
        score += 1;
        //randomNums[1] = normalizeRandom();
    }else if (yr3 > 2){
        yr3 = -1.2;
        t3 = 0;
        score += 1;
        //randomNums[2] = normalizeRandom();
    }else if (yr4 > 2){
        yr4 = -1.65;
        t4 = 0;
        score += 1;
        //randomNums[3] = normalizeRandom();
    }else if (yr5 > 2){
        yr5 = -2.1;
        t5 = 0;
        score += 1;
        //randomNums[4] = normalizeRandom();
    }
    
    
            cout << "içerde"<<endl;
            if  (1-yr1 < -0.7 && recTopL < randomNums[0] && randomNums[0] < recTopR){
                isGameOver = true;
                cout <<"y "<<yr1<< "col1"<<recTopL <<randomNums[0]<<recTopR<<endl;
            }
            else if  (1-yr2 < -0.7 && recTopL < randomNums[1] && randomNums[1] < recTopR){
                isGameOver = true;
                cout <<"y "<<yr2<< "col2"<<recTopL <<randomNums[1]<<recTopR<<endl;
            }
           else if  (1-yr3 < -0.7 && recTopL < randomNums[2] && randomNums[2] < recTopR){
                isGameOver = true;
               cout <<"y "<<yr3<< "col3"<<recTopL <<randomNums[2]<<recTopR<<endl;
            }
           else if  (1-yr4 < -0.7 && recTopL < randomNums[3] && randomNums[3] < recTopR){
                isGameOver = true;
               cout <<"y "<<yr4<< "col4"<<recTopL <<randomNums[3]<<recTopR<<endl;
            }
           else if  (1-yr5 < -0.7 && recTopL < randomNums[4] && randomNums[4] < recTopR){
                isGameOver = true;
               cout <<"y "<<yr5<< "col5"<<recTopL <<randomNums[4]<<recTopR<<endl;
            }
    
}

void messageView(){
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2f(-0.32, 0.25); // sol üst
    glVertex2f(0.35, 0.25); //sağ üst
    glVertex2f(0.35, -0.25); //sağ alt
    glVertex2f(-0.32, -0.25); //sol alt
    glEnd();
    
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    if (isGameOver){
        
        messageView();
        drawBitmapText("Oyun Bitti!", -0.1, 0.1);
        drawBitmapText("Yeniden Baslamak icin Enter'e Basiniz.", -0.3, 0.0);
        drawBitmapText("Cikmak Icin Bosluga Basiniz.", -0.22, -0.1);
        drawBitmapText("Scorunuz: ", -0.1, -0.2);
        char buffer[10]={'\0'};
        sprintf(buffer, "%d", score); //%d is for integers
        drawBitmapText(buffer , 0.1 , -0.2);
        
    }else if(!isGameOver){

    if (randomNums[4] == NULL){
    for (int i=0; i<5; i++) {
        randomNums[i] = normalizeRandom();
        }
    }
    Triange tri;
    Triange tri1;
    Triange tri2;
    Triange tri3;
    Triange tri4;
    if (t1 < 10000){
        if (t2 == 2000){
            a = true;}
            tri.draw(randomNums[0], yr1, 0.4, 0.2,0.3);
    }
    if (t2 > 2000 && a == true){
            tri1.draw(randomNums[1], yr2,0.5,0.2,0.5);
        
    }
  if (t3>4000 &&  a == true){
            tri2.draw(randomNums[2], yr3,0.6,0.2,0.8);
    }  if (t4>5500 && a == true){
            tri3.draw(randomNums[3], yr4,0.7,0.4,0.4);
    }  if(t5>7000 && a == true){
            tri4.draw(randomNums[4], yr5,0.2,0.3,0.5);
    }
        collisionDetection();
    drawBitmapText("Score:" , 0.75 , 0.9);
    char buffer[10]={'\0'};
    sprintf(buffer, "%d", score); //%d is for integers
    drawBitmapText(buffer , 0.89 , 0.9);
        
    rectangle();
    //omer_cetin@outlook.com.tr
    }
    glFlush();
}

void specialkey(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_LEFT:
            xr = xr - 0.1;
            if (xr < -0.2){
                xr = -0.2;
            }
            cout <<"xr  "<< xr << endl;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            xr = xr + 0.1;
            if (xr > 1.29){
                xr = 1.29;
            }

            glutPostRedisplay();
            break;
        case (char)13:
            if (isGameOver){
            isGameOver = false;
            yr1 = 0.0;
            yr2 = -0.6;
            yr3 = -1.2;
            yr4 = -1.65;
            yr5 = -2.1;
            score = 0;
            t1 = 0;
            t2 = 0;
            t3 = 0;
            t4 = 0;
            t5 = 0;
            }
            break;
        case ' ':
            exit(0);
            break;
    }
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(500, 200);
    glutInitWindowSize(HEIGHT, WIDTH);
    glutCreateWindow("OpenGL Projesi");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glutIdleFunc(collisionDetection);
    glutDisplayFunc(display);
    glutSpecialFunc(specialkey);
    glutTimerFunc(1000, timeFunc, 1);
    glutMainLoop();
    return 0;
}
