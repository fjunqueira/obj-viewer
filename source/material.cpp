//
// Created by fabio on 3/15/16.
//

#include "material.h"

void Material::set_ambient(const math::Vector3<float>& vector)
{
    this->ambient_ = vector;
}

void Material::set_diffuse(const math::Vector3<float>& vector)
{
    this->diffuse_ = vector;
}

void Material::set_specular(const math::Vector3<float>& vector)
{
    this->specular_ = vector;
}

void Material::set_shininess(const float& shininess)
{
    this->shininess_ = shininess;
}

void Material::set_texture_file(const std::string& texture_file)
{
    this->texture_file_ = texture_file;
}

const math::Vector3<float>& Material::ambient() const
{
    return this->ambient_;
}

const math::Vector3<float>& Material::diffuse() const
{
    return this->diffuse_;
}

const math::Vector3<float>& Material::specular() const
{
    return this->specular_;
}

const float& Material::shininess() const
{
    return this->shininess_;
}

const std::string& Material::texture_file() const
{
    return this->texture_file_;
}
