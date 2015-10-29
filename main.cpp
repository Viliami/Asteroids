#include <GL/glut.h>
#include "loaders.h"
#include "textfile.h"
#include <stdio.h>

int numVerts;
GLfloat *vertexArray, *normalArray, *uvArray;
float rotation = 0.0f;

void draw(){
    glLoadIdentity();
    gluLookAt(
    0,0,1,//position
    0,15,0.99f,//center
    0,1,0//up
    );
    glScalef(0.5f,0.5f,0.5f);
    glRotatef(180,0,0,1);
    glRotatef(rotation,0,1,0);
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
    //rotation+=1.0f;
    glutSwapBuffers();
}

void resize(int w, int h){
    if(h == 0)
        h = 1;
    float ratio = w*1.0f/h;
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glViewport(1,1,w,h);
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
            printf("UP\n");
            break;
        case GLUT_KEY_DOWN:
            printf("DOWN\n");
            break;
        case GLUT_KEY_LEFT:
            //printf("LEFT\n");
            rotation += 2.0f;
            break;
        case GLUT_KEY_RIGHT:
            //printf("RIGHT\n");
            rotation -= 2.0f;
            break;
    }
}

void initGL(){
    loadOBJ("data/models/ship.dae",vertexArray,normalArray,uvArray,numVerts);
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
