#include <GL/glut.h>
#include "loaders.h"

class Missile{
    public:
        Missile();
        ~Missile();
        void draw();
    private:
        int numVerts;
        GLfloat *vertexArray, *normalArray, *uvArray;
        float rotation = 0.0f;
};
