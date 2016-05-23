//
// Created by fabio on 3/15/16.
//

#ifndef OBJ_VIEWER_GROUP_H
#define OBJ_VIEWER_GROUP_H


#include <GL/gl.h>
#include "face.h"
#include "group.h"

class Group
{
public:
    Group(const std::string& name);

    const std::string& name() const;

    const std::vector<Face>& faces() const;

    const GLuint& group_id() const;

    void add_face(const Face& face);

    void disable();

    void enable();

    const bool& is_enabled() const;

private:
    bool is_enabled_;
    std::string name_;
    std::vector<Face> faces_;
    GLuint group_id_;
};


#endif //OBJ_VIEWER_GROUP_H
