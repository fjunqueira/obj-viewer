#include <iostream>
#include "obj_reader.h"
#include "mesh_loader.h"
#include "mesh_drawer.h"
#include <GL/freeglut.h>
#include <float.h>
#include "picker.h"

using namespace std;

int width = 800, height = 600;

MeshInfo mesh_info;

math::Vector3<float> camera_position;
float rotation_around_y_axis = 0;
float camera_height = 0;
float zoom = 2;
float diameter = 0;

void Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(camera_position.x(), camera_position.y(), camera_position.z(), 0, camera_height, 0, 0.0, 1.0, 0.0);

    MeshDrawer::Draw(mesh_info.mesh, mesh_info.materials, mesh_info.textures);

    float light_position[4] = {camera_position.x() / 2, camera_position.y() / 2, camera_position.z() / 2, 0};

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glutSwapBuffers();
    glutPostRedisplay();
}

void ResetView()
{
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
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDepthRange(0.0, 1.0);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);

    GLfloat light_ambient[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

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
        case 'z':
        case 'Z':
            mesh_info.mesh->renable_last_group();
    }
}

void SpecialKeyHandler(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_PAGE_UP:
            zoom += 0.1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            zoom -= 0.1;
            break;
        case GLUT_KEY_LEFT:
            rotation_around_y_axis -= 0.1;
            break;
        case GLUT_KEY_RIGHT:
            rotation_around_y_axis += 0.1;
            break;
        case GLUT_KEY_UP:
            camera_height += diameter / 10;
            break;
        case GLUT_KEY_DOWN:
            camera_height -= diameter / 10;
            break;
    }

    camera_position =
            math::Vector3<float>(cos(rotation_around_y_axis), 0, sin(rotation_around_y_axis)) *
            diameter * zoom + math::Vector3<float>(0, camera_height, 0);
}

void PickFace(int button, int state, int x, int y)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    auto group_id = Picker::Pick(x,y,[&] () {
        gluPerspective(60.0, (double) width / (double) height, 1.0, (1.0 + diameter) * 3);
        MeshDrawer::Draw(mesh_info.mesh, mesh_info.materials, mesh_info.textures);
    } );

    mesh_info.mesh->DisableGroup(group_id);

    ResetView();
}

int main(int argc, char** argv)
{
    if (argc < 3)
        return 0;

    std::string mesh_path(argv[1]);
    std::string mesh_name(argv[2]);

    glutInit(&argc, argv);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);

    glutCreateWindow("obj-viewer");

    InitializeOpenGL();

    MeshLoader mesh_loader;
    mesh_info = mesh_loader.LoadMesh(mesh_path, mesh_name);

    diameter = mesh_info.mesh->bounding_sphere_radius();

    ResetView();

    camera_position =
            math::Vector3<float>(cos(rotation_around_y_axis), 0.0f, sin(rotation_around_y_axis)).normalized() *
            diameter * zoom;

    glutDisplayFunc(Render);
    glutReshapeFunc(ResizeHandler);
    glutKeyboardFunc(KeypressHandler);
    glutSpecialFunc(SpecialKeyHandler);
    glutMouseFunc(PickFace);

    glutMainLoop();

    delete mesh_info.mesh;
    delete mesh_info.materials;
    delete mesh_info.textures;

    return 0;
}