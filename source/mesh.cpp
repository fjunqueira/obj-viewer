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
        : bounding_sphere_radius_(bounding_sphere_radius),
          material_lib_(material_lib),
          vertices_(vertices),
          normals_(normals),
          texture_mappings_(texture_mappings),
          groups_(groups)
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

const std::map<std::string, Group>& Mesh::groups() const
{
    return this->groups_;
}

const std::vector<math::Vector3<float>>& Mesh::texture_mappings() const
{
    return this->texture_mappings_;
}

const std::vector<math::Vector3<float>>& Mesh::normals() const
{
    return this->normals_;
}

const std::vector<math::Vector3<float>>& Mesh::vertices() const
{
    return this->vertices_;
}

Mesh::~Mesh()
{
}

void Mesh::DisableGroup(const int& group_index)
{
    std::for_each(this->groups_.begin(), this->groups_.end(),
                  [&](const std::pair<std::string, Group>& group)
                  {
                      auto group_data = group.second;
                      if (group_data.group_id() == group_index)
                      {
                          this->disabled_groups_.push_back(group_data.name());
                          this->groups_.at(group_data.name()).disable();
                      }
                  });
}

void Mesh::renable_last_group()
{
    if (this->disabled_groups_.size() > 0)
    {
        auto group_name = this->disabled_groups_.back();
        this->groups_.at(group_name).enable();
        this->disabled_groups_.pop_back();
    }
}



