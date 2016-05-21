#include "picker.h"

int Picker::Pick(int x, int y, std::function<void ()> draw_function) 
{
    GLuint select_buff[1024];
    GLint viewport[4];

    glGetIntegerv(GL_VIEWPORT, viewport);

    glSelectBuffer(1024, select_buff);
    (void) glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(0);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    
    gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3] - y), 5.0, 5.0, viewport);
    
    draw_function();
    
    glPopMatrix();
    glFlush();

    GLint hits = glRenderMode(GL_RENDER);
    
    return ProcessHits(hits, select_buff);
}

int Picker::ProcessHits(GLint hits, GLuint buffer[]) 
{
    int pick_id = 0;

    float nearest_depth = FLT_MAX;

    GLuint* ptr;

    ptr = (GLuint*) buffer;

    for (int i = 0; i < hits; i++)
    {  
        ptr++;
        float depth_1 = (float) *ptr / 0x7fffffff;

        ptr++;
        float depth_2 = (float) *ptr / 0x7fffffff;

        ptr++;
        int current_hit = *ptr;

        if (depth_1 <= nearest_depth || depth_2 <= nearest_depth)
        {
            nearest_depth = depth_1 < depth_2 ? depth_1 : depth_2;
            pick_id = current_hit;
        }
        
        ptr++;
    }
        
    return pick_id;
}