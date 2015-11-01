#include <GL/glut.h>
#include "loaders.h"

class Ship{
    public:
        Ship();
        ~Ship();
        void draw();
        void rotate_left();
        void rotate_right();
    private:
        int numVerts;
        GLfloat *vertexArray, *normalArray, *uvArray;
        float rotation = 0.0f;
};
