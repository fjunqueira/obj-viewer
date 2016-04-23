//
// Created by fabio on 3/15/16.
//

#ifndef OBJREADER_FACE_H
#define OBJREADER_FACE_H

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

    const std::vector<int>& face_vertices() const;

    const std::vector<int>& face_normals() const;

    const std::vector<int>& face_mappings() const;

private:
    std::string material_;
    std::vector<int> face_vertices_;
    std::vector<int> face_normals_;
    std::vector<int> face_mappings_;
};

#endif //OBJREADER_FACE_H