
#ifndef OBJ_VIEWER_PICKER_H
#define OBJ_VIEWER_PICKER_H

#include <GL/gl.h>
#include <functional>
#include <GL/freeglut.h>
#include <float.h>

class Picker
{
    public:
        static int Pick(int x, int y, std::function<void ()> draw_function);
    private:
        static int ProcessHits(GLint hits, GLuint buffer[]);
};

#endif //OBJ_VIEWER_PICKER_H