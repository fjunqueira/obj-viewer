//
// Created by fabio on 3/15/16.
//

#include "group.h"

Group::Group(const GLuint& group_id, const std::string& name, const std::vector<Face>& faces) :
        group_id_(group_id), faces_(faces), name_(name), is_enabled_(true)
{

}

Group::Group(const GLuint& group_id, const std::string& name) : group_id_(group_id), name_(name), is_enabled_(true)
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

const std::string& Group::name() const
{
    return this->name_;
}

const GLuint& Group::group_id() const
{
    return this->group_id_;
}

void Group::disable()
{
    this->is_enabled_ = false;
}

void Group::enable()
{
    this->is_enabled_ = true;
}

const bool& Group::is_enabled() const
{
    return this->is_enabled_;
}





