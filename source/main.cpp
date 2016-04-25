#include <iostream>
#include "obj_reader.h"
#include "mtl_reader.h"
#include "texture_reader.h"
#include "mesh_loader.h"
#include "mesh_drawer.h"
#include <GL/freeglut.h>

using namespace std;

int width = 800, height = 600;

MeshInfo mesh_info;

math::Vector3<float> camera_position;
float rotation_around_y_axis = 0;
float camera_heigt = 0;
float zoom = 2;

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    float l = 200;
    float o = 200;
    float u = 0;
    float g_lightPos[4] = {u, o, l, 0};
    //setar info da luz
    glLightfv(GL_LIGHT0, GL_POSITION, g_lightPos);

    glLoadIdentity();

    gluLookAt(camera_position.x(), camera_position.y(), camera_position.z(), 0, 0, 0, 0.0, 1.0, 0.0);

    MeshDrawer::Draw(mesh_info.mesh, mesh_info.materials, mesh_info.textures);

    glutSwapBuffers();
    glutPostRedisplay();
}

void ResetView()
{
    float diameter = mesh_info.mesh->bounding_sphere_radius();

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (double) width / (double) height, 1.0, (1.0 + diameter) * 3);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void ResizeHandler(int w, int h)
{
    if (h < 1) h = 1;
    width = w;
    height = h;

    ResetView();
}

void InitializeOpenGL()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDisable(GL_COLOR_MATERIAL);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClearDepth(1.0);
}

void KeypressHandler(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'q':
        case 'Q':
            exit(0);
    }
}

void SpecialKeyHandler(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            rotation_around_y_axis -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            rotation_around_y_axis += 0.1;
            break;
        case GLUT_KEY_UP:
            camera_heigt += 0.1;
            break;
        case GLUT_KEY_DOWN:
            camera_heigt -= 0.1;
            break;
    }

    camera_position =
            math::Vector3<float>(cos(rotation_around_y_axis), camera_heigt, sin(rotation_around_y_axis)).normalized() *
            mesh_info.mesh->bounding_sphere_radius() * zoom;
}

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    std::string mesh_path(argv[1]);
    std::string mesh_name(argv[2]);

    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("obj-viewer");

    InitializeOpenGL();

    MeshLoader mesh_loader;
    mesh_info = mesh_loader.LoadMesh(mesh_path, mesh_name);

    ResetView();

    camera_position =
            math::Vector3<float>(cos(rotation_around_y_axis), 0.0f, sin(rotation_around_y_axis)).normalized() *
            mesh_info.mesh->bounding_sphere_radius() * zoom;

    glutDisplayFunc(Render);
    glutReshapeFunc(ResizeHandler);
    glutKeyboardFunc(KeypressHandler);
    glutSpecialFunc(SpecialKeyHandler);

    glutMainLoop();

    delete mesh_info.mesh;
    delete mesh_info.materials;
    delete mesh_info.textures;

    return 0;
}