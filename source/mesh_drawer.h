//
// Created by fabio on 4/24/16.
//

#ifndef OBJ_VIEWER_MESH_DRAWER_H
#define OBJ_VIEWER_MESH_DRAWER_H


#include "mesh.h"

namespace MeshDrawer
{
    void Draw(Mesh* mesh);

    void Draw(Mesh* mesh, std::map<std::string, Material>* materials, std::map<std::string, GLuint>* textures);
};


#endif //OBJ_VIEWER_MESH_DRAWER_H
