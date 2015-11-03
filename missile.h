#include <GL/glut.h>
#include "loaders.h"

class Missile{
    public:
        float x = 0, y = 0, z = 0;
        Missile();
        ~Missile();
        void draw();
    private:
        int numVerts;
        GLfloat *vertexArray, *normalArray, *uvArray;
        float rotation = 90.0f;
};
