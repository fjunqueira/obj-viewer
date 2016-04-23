//
// Created by fabio on 3/15/16.
//

#include "face.h"

Face::Face(const std::string& material,
           const std::vector<int>& face_vertices,
           const std::vector<int>& face_normals,
           const std::vector<int>& face_mappings) :
                                                material_(material),
                                                face_vertices_(face_vertices),
                                                face_normals_(face_normals),
                                                face_mappings_(face_mappings)
{

}

const std::vector<int>& Face::face_vertices() const
{
    return this->face_vertices_;
}

const std::vector<int>& Face::face_normals() const
{
    return this->face_normals_;
}

const std::vector<int>& Face::face_mappings() const
{
    return this->face_mappings_;
}

const std::string& Face::material() const
{
    return this->material_;
}