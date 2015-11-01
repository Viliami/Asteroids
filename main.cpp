#include <GL/glut.h>
#include "loaders.h"
#include <stdio.h>
#include "ship.h"

Ship* ship = new Ship();

void draw(){
    ship->draw();
}

void resize(int w, int h){
    if(h == 0)
        h = 1;
    float ratio = w*1.0f/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,w,h);
    gluPerspective(90,ratio,0.1f,100);
    glMatrixMode(GL_MODELVIEW);
}

void normalKeys(unsigned char key, int x, int y){
    switch(key){
        case 27: //escape key
            exit(0);
            break;
    }
}

void specialKeys(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            printf("Fire\n");
            break;
        case GLUT_KEY_DOWN:
            printf("DOWN\n");
            break;
        case GLUT_KEY_LEFT:
            ship->rotate_left();
            break;
        case GLUT_KEY_RIGHT:
            ship->rotate_right();
            break;
    }
}

void initGL(){
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat light_ambient[] = { 0.3f, 0.3f, 0.3f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitWindowPosition(-1,-1);
    glutInitWindowSize(700,700);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Asteroids");

    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);

    initGL();

    glutMainLoop();

    return 1;
}
