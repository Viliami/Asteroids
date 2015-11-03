#include "ship.h"

Ship::Ship(){
    loadOBJ("data/models/ship.dae",vertexArray,normalArray,uvArray,numVerts);
}

Ship::~Ship(){
    
}

void Ship::draw(){
    //glLoadIdentity();
    gluLookAt(
    0,-1,1.5,//position
    0,15,0.99f,//center
    0,1,0//up
    );
    /*gluLookAt(
    0,5,5,//position
    0,0,0.0f,//center
    0,1,0//up
    );*/
    glPushMatrix();
    glScalef(0.5f,0.5f,0.5f);
    glRotatef(180,0,0,1);
    glRotatef(rotation,0,1,0);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertexArray);
    glNormalPointer(GL_FLOAT,0,normalArray);

    glDrawArrays(GL_TRIANGLES,0,numVerts);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glPopMatrix();
    //glutSwapBuffers();
}

void Ship::rotate_left(){
    rotation+=1.0f;
}

void Ship::rotate_right(){
    rotation-=1.0f;
}
