//
// Created by fabio on 4/23/16.
//

#ifndef OBJ_VIEWER_MESH_LOADER_H
#define OBJ_VIEWER_MESH_LOADER_H

#include "mesh.h"
#include "obj_reader.h"
#include "mtl_reader.h"
#include "texture_reader.h"

struct MeshInfo
{
    Mesh* mesh = nullptr;
    std::map<std::string, Material>* materials = nullptr;
    std::map<std::string, GLuint>* textures = nullptr;
};

class MeshLoader
{
public:
    MeshInfo LoadMesh(const std::string& mesh_path, const std::string& mesh_name) const;

private:
    std::vector<std::string> GetTexturesToLoad(const std::string& mesh_path,
                                               std::map<std::string, Material>* materials) const;
};


#endif //OBJ_VIEWER_MESH_LOADER_H
