//
// Created by fabio on 4/23/16.
//

#ifndef OBJ_READER_MESH_LOADER_H
#define OBJ_READER_MESH_LOADER_H

#include "mesh.h"
#include "obj_reader.h"
#include "mtl_reader.h"
#include "texture_reader.h"

struct MeshInfo
{
    Mesh* mesh;
    std::map<std::string, Material>* materials;
    std::map<std::string, GLuint>* textures;
};

class MeshLoader
{
public:
    MeshInfo LoadMesh(const std::string& mesh_path, const std::string& mesh_name);

private:
    std::vector<std::string> GetTexturesToLoad(const std::string& mesh_path,
                                               std::map<std::string, Material>* materials);
};


#endif //OBJ_READER_MESH_LOADER_H
