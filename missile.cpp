#include "missile.h"

Missile::Missile(){
    loadOBJ("data/models/missile.dae",vertexArray,normalArray,uvArray,numVerts);
}

Missile::~Missile(){
    
}

void Missile::draw(){
    //glLoadIdentity();
    /*gluLookAt(
    0,5,5,//position
    0,0,0.0f,//center
    0,1,0//up
    );*/
    glPushMatrix();
    glScalef(0.5f,0.5f,0.5f);
    //glRotatef(180,0,0,1);
    //glRotatef(rotation,0,1,0);
    glTranslatef(x,y,z);

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
