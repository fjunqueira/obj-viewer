//
// Created by fabio on 3/15/16.
//

#include "mesh.h"

Mesh::Mesh(const float& bounding_sphere_radius,
           const std::string& material_lib,
           const std::vector<math::Vector3<float>>& vertices,
           const std::vector<math::Vector3<float>>& normals,
           const std::vector<math::Vector3<float>>& texture_mappings,
           const std::map<std::string, Group>& groups)
        : bounding_sphere_radius_(bounding_sphere_radius), material_lib_(material_lib), vertices_(vertices),
          normals_(normals), texture_mappings_(texture_mappings),
          groups_(groups)
{

}

void Mesh::Draw(const std::map<std::string, Material>& materials, const std::map<std::string, GLuint>& textures)
{
    std::for_each(this->groups_.begin(), this->groups_.end(),
                  [&](std::pair<const std::string, Group>& group)
                  {
                      auto faces = group.second.faces();

                      //oh sheeeeit

                      if (faces.size() > 0)
                      {
                          std::for_each(faces.begin(), faces.end(), [&](const Face& face)
                          {
                              bool has_material = materials.count(face.material()) == 1;

                              if (textures.count(materials.at(face.material()).texture_file()) == 1)
                              {
                                  GLuint texid = textures.at(materials.at(face.material()).texture_file());
                                  glBindTexture(GL_TEXTURE_2D, texid);
                              }

                              glBegin(GL_POLYGON);

                              if (has_material)
                              {
                                  Material group_material = materials.at(face.material());

                                  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, group_material.ambient().coords);

                                  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, group_material.specular().coords);

                                  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, group_material.diffuse().coords);

                                  glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, group_material.shininess());
                              }

                              auto normals = face.face_normals();
                              auto vertices = face.face_vertices();
                              auto mappings = face.face_mappings();

                              for (int i = 0; i < vertices.size(); ++i)
                              {
                                  auto mapping_data = texture_mappings_.at(mappings.at(i) - 1);
                                  glTexCoord2fv(mapping_data.coords);

                                  auto normal_data = normals_.at(normals.at(i) - 1);
                                  glNormal3fv(normal_data.coords);

                                  auto vertex_data = vertices_.at(vertices.at(i) - 1);
                                  glVertex3fv(vertex_data.coords);
                              }

                              glEnd();
                          });
                      }
                  });
}

Mesh::~Mesh()
{
}

const float& Mesh::bounding_sphere_radius() const
{
    return this->bounding_sphere_radius_;
}

const std::string& Mesh::material_lib() const
{
    return this->material_lib_;
}
