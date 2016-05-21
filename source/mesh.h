//
// Created by fabio on 3/15/16.
//

#ifndef OBJ_VIEWER_MESH_H
#define OBJ_VIEWER_MESH_H


#include <map>
#include "vector3.h"
#include <algorithm>
#include "face.h"
#include <GL/gl.h>
#include "group.h"
#include "material.h"

class Mesh
{
public:
    Mesh(const float& bounding_sphere_radius,
         const std::string& material_lib,
         const std::vector<math::Vector3<float>>& vertices,
         const std::vector<math::Vector3<float>>& normals,
         const std::vector<math::Vector3<float>>& texture_mappings,
         const std::map<std::string, Group>& groups);

    const std::vector<math::Vector3<float>>& vertices() const;

    const std::vector<math::Vector3<float>>& normals() const;

    const std::vector<math::Vector3<float>>& texture_mappings() const;

    const std::map<std::string, Group>& groups() const;

    const float& bounding_sphere_radius() const;

    const std::string& material_lib() const;

    virtual ~Mesh();

    void DisableGroup(const int& group_index);

    void renable_last_group();

private:
    float bounding_sphere_radius_;
    std::string material_lib_;
    std::vector<math::Vector3<float>> vertices_;
    std::vector<math::Vector3<float>> normals_;
    std::vector<math::Vector3<float>> texture_mappings_;
    std::map<std::string, Group> groups_;
    std::vector<std::string> disabled_groups_;
};


#endif //OBJ_VIEWER_MESH_H
