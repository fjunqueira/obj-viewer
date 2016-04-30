//
// Created by fabio on 4/24/16.
//

#include "mesh_drawer.h"

void ::MeshDrawer::Draw(Mesh* mesh,
                        std::map<std::string, Material>* materials,
                        std::map<std::string, GLuint>* textures)
{
    auto vertices = mesh->vertices();
    auto normals = mesh->normals();
    auto texture_mappings = mesh->texture_mappings();

    std::for_each(mesh->groups().begin(), mesh->groups().end(), [&](const std::pair<std::string, Group>& group)
    {
        auto group_info = group.second;

        if (!group_info.is_enabled())
            return;

        glLoadName(group_info.group_id());

        std::for_each(group_info.faces().begin(), group_info.faces().end(), [&](const Face& face)
        {
            if (materials != nullptr && materials->count(face.material()))
            {
                Material group_material = materials->at(face.material());

                if (textures != nullptr && textures->count(group_material.texture_file()))
                    glBindTexture(GL_TEXTURE_2D, textures->at(group_material.texture_file()));

                glBegin(GL_POLYGON);

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, group_material.ambient().coords);

                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, group_material.specular().coords);

                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, group_material.diffuse().coords);

                glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, group_material.shininess());
            }
            else glBegin(GL_POLYGON);

            auto mappings_indexes = face.mappings_indexes();
            auto normals_indexes = face.normals_indexes();
            auto vertices_indexes = face.vertices_indexes();

            for (int i = 0; i < face.vertices_indexes().size(); ++i)
            {
                if (mappings_indexes.size() > 0)
                {
                    auto mapping_data = texture_mappings.at(mappings_indexes.at(i));
                    glTexCoord2fv(mapping_data.coords);
                }

                if (normals_indexes.size() > 0)
                {
                    auto normal_data = normals.at(normals_indexes.at(i));
                    glNormal3fv(normal_data.coords);
                }

                auto vertex_data = vertices.at(vertices_indexes.at(i));
                glVertex3fv(vertex_data.coords);
            }

            glEnd();
        });
    });
}

