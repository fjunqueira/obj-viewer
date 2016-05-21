//
// Created by fabio on 3/15/16.
//

#ifndef OBJ_VIEWER_MATERIAL_H
#define OBJ_VIEWER_MATERIAL_H


#include "vector3.h"

class Material
{
public:
    void set_ambient(const math::Vector3<float>& vector);

    void set_diffuse(const math::Vector3<float>& vector);

    void set_specular(const math::Vector3<float>& vector);

    void set_shininess(const float& shininess);

    void set_texture_file(const std::string& texture_file);

    const math::Vector3<float>& ambient() const;

    const math::Vector3<float>& diffuse() const;

    const math::Vector3<float>& specular() const;

    const float& shininess() const;

    const std::string& texture_file() const;

private:

    math::Vector3<float> ambient_;
    math::Vector3<float> diffuse_;
    math::Vector3<float> specular_;
    float shininess_;
    std::string texture_file_;

};


#endif //OBJ_VIEWER_MATERIAL_H
