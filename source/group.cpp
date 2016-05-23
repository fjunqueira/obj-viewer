//
// Created by fabio on 3/15/16.
//

#include "group.h"

Group::Group(const std::string& name) :  name_(name), is_enabled_(true)
{
    static GLuint group_id = 1;

    this->group_id_ = group_id++;
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





