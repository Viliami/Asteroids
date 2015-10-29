#include <GL/glut.h>
#include "loaders.h"
#include "textfile.h"
#include <stdio.h>

int numVerts;
GLfloat *vertexArray, *normalArray, *uvArray;

void draw(){
    glLoadIdentity();
    gluLookAt(
    0,-10,-10,//position
    0,0,0,//center
    0,1,0//up
    );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glBindTexture(GL_TEXTURE_2D,texture[textureNumber]);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray);
    glNormalPointer(GL_FLOAT,0,normalArray);

    //glTexCoordPointer(2,GL_FLOAT,0,uvArray);

    glDrawArrays(GL_TRIANGLES,0,numVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glutSwapBuffers();
}

void resize(int w, int h){
    if(h == 0)
        h = 1;
    float ratio = w*1.0f/h;
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glViewport(1,1,w,h);
    gluPerspective(45,ratio,1,100);
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
            printf("UP\n");
            break;
        case GLUT_KEY_DOWN:
            printf("DOWN\n");
            break;
        case GLUT_KEY_LEFT:
            printf("LEFT\n");
            break;
        case GLUT_KEY_RIGHT:
            printf("RIGHT\n");
            break;
    }
}

void initGL(){
    loadOBJ("data/models/ship.dae",vertexArray,normalArray,uvArray,numVerts);
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitWindowPosition(-1,-1);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Asteroids");

    glutDisplayFunc(draw);
    glutReshapeFunc(resize);
    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);

    initGL();

    glutMainLoop();

    return 1;
}
