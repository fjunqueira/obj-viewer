#include <iostream>
#include "obj_reader.h"
#include "mtl_reader.h"
#include "texture_reader.h"
#include "mesh_loader.h"
#include <GL/freeglut.h>

using namespace std;

int width = 800, height = 600;

MeshInfo mesh_info;

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

    math::Vector3<float> camera_position(34.0304203, 0, 4.87120724);

    glLoadIdentity();

    gluLookAt(camera_position.x(), camera_position.y(), camera_position.z(), 0, 0, 0, 0.0, 1.0, 0.0);

    mesh_info.mesh->Draw(*mesh_info.materials, *mesh_info.textures);

    glutSwapBuffers();
    glutPostRedisplay();
}

void ResetView()
{
    float diam = mesh_info.mesh->bounding_sphere_radius();

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (double) width / (double) height, 1.0, (1.0 + diam) * 3);

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

    glutDisplayFunc(Render);
    glutReshapeFunc(ResizeHandler);
    //glutKeyboardFunc(KeypressHandler);
    //glutSpecialFunc(SpecialKeyHandler);

    glutMainLoop();

    delete mesh_info.mesh;
    delete mesh_info.materials;
    delete mesh_info.textures;

    return 0;
}