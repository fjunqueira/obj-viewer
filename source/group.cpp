//
// Created by fabio on 3/15/16.
//

#include "group.h"

Group::Group(const std::string& name, const std::vector<Face>& faces) : name_(name),
                                                                        faces_(faces)
{

}

Group::Group(const std::string& name) : name_(name)
{

}

void Group::add_face(const Face& face)
{
    this->faces_.push_back(face);
}

const std::vector<Face>& Group::faces() const
{
    return this->faces_;
}