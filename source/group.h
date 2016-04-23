//
// Created by fabio on 3/15/16.
//

#ifndef OBJREADER_GROUP_H
#define OBJREADER_GROUP_H


#include "face.h"
#include "group.h"

class Group
{
public:
    Group(const std::string& name);

    Group(const std::string& name, const std::vector<Face>& faces);

    const std::vector<Face>& faces() const;

    void add_face(const Face& face);

private:
    std::string name_;
    std::vector<Face> faces_;
};


#endif //OBJREADER_GROUP_H
