//
// Created by fabio on 3/15/16.
//

#ifndef OBJ_VIEWER_FACE_H
#define OBJ_VIEWER_FACE_H

#include <vector>
#include "vector3.h"

class Face
{
public:
    Face(const std::string& material,
         const std::vector<int>& face_vertices,
         const std::vector<int>& face_normals,
         const std::vector<int>& face_mappings);

    const std::string& material() const;

    const std::vector<int>& vertices_indexes() const;

    const std::vector<int>& normals_indexes() const;

    const std::vector<int>& mappings_indexes() const;

private:
    std::string material_;
    std::vector<int> vertices_indexes_;
    std::vector<int> normals_indexes_;
    std::vector<int> mappings_indexes_;
};

#endif //OBJ_VIEWER_FACE_H
