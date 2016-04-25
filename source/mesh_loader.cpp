//
// Created by fabio on 4/23/16.
//

#include "mesh_loader.h"

MeshInfo MeshLoader::LoadMesh(const std::string& mesh_path, const std::string& mesh_name) const
{
    ObjReader obj_reader;
    MtlReader mtl_reader;
    TextureReader texture_reader;

    MeshInfo mesh_info;

    mesh_info.mesh = obj_reader.ReadMesh(mesh_path + mesh_name);

    if (!mesh_info.mesh->material_lib().empty())
    {
        mesh_info.materials = mtl_reader.ReadMaterials(mesh_path + mesh_info.mesh->material_lib());

        auto textures_to_load = this->GetTexturesToLoad(mesh_path, mesh_info.materials);

        if (textures_to_load.size() > 0)
            mesh_info.textures = texture_reader.ReadTextures(mesh_path, textures_to_load);
    }

    return mesh_info;
}

std::vector<std::string> MeshLoader::GetTexturesToLoad(const std::string& mesh_path,
                                                       std::map<std::string, Material>* materials) const
{
    std::vector<std::string> textures_to_load;

    std::for_each(materials->begin(), materials->end(), [&](const std::pair<std::string, Material>& material)
    {
        auto texture_file = material.second.texture_file();

        if (!texture_file.empty())
            textures_to_load.push_back(texture_file);
    });

    return textures_to_load;
}

