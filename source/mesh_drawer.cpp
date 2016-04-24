//
// Created by fabio on 4/24/16.
//

#include "mesh_drawer.h"

void ::MeshDrawer::Draw(Mesh* mesh)
{
    std::map<std::string, Group> group = mesh->groups();

    auto vertices = mesh->vertices();

    std::for_each(group.begin(), group.end(), [&](std::pair<const std::string, Group>& group)
    {
        std::for_each(group.second.faces().begin(), group.second.faces().end(), [&](const Face& face)
        {
            auto vertices_indexes = face.vertices_indexes();

            glBegin(GL_POLYGON);

            for (int i = 0; i < vertices_indexes.size(); ++i)
            {
                auto vertex_data = vertices.at(vertices_indexes.at(i));
                glVertex3fv(vertex_data.coords);
            }

            glEnd();
        });
    });
}

void ::MeshDrawer::Draw(Mesh* mesh,
                        std::map<std::string, Material>* materials,
                        std::map<std::string, GLuint>* textures)
{
    std::map<std::string, Group> group = mesh->groups();

    auto vertices = mesh->vertices();
    auto normals = mesh->normals();
    auto texture_mappings = mesh->texture_mappings();

    std::for_each(group.begin(), group.end(), [&](std::pair<const std::string, Group>& group)
    {
        std::for_each(group.second.faces().begin(), group.second.faces().end(), [&](const Face& face)
        {
            if (materials->count(face.material()))
            {
                Material group_material = materials->at(face.material());

                if (textures->count(group_material.texture_file()))
                    glBindTexture(GL_TEXTURE_2D, textures->at(group_material.texture_file()));

                glBegin(GL_POLYGON);

                glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, group_material.ambient().coords);

                glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, group_material.specular().coords);

                glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, group_material.diffuse().coords);

                glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, group_material.shininess());
            }
            else glBegin(GL_POLYGON);

            //testar se tem normais, texturas
            for (int i = 0; i < face.vertices_indexes().size(); ++i)
            {
                auto mapping_data = texture_mappings.at(face.mappings_indexes().at(i));
                glTexCoord2fv(mapping_data.coords);

                auto normal_data = normals.at(face.normals_indexes().at(i));
                glNormal3fv(normal_data.coords);

                auto vertex_data = vertices.at(face.vertices_indexes().at(i));
                glVertex3fv(vertex_data.coords);
            }

            glEnd();
        });
    });
}

