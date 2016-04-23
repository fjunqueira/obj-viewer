//
// Created by fabio on 3/15/16.
//

#ifndef OBJREADER_OBJ_READER_H
#define OBJREADER_OBJ_READER_H


#include "mesh.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "vector3.h"
#include "face.h"
#include "group.h"
#include <regex>
#include <map>

class ObjReader
{
public:
    Mesh* ReadMesh(const std::string& file_path) const;

private:
    math::Vector3<float> ReadVector3(std::ifstream& file) const;

    math::Vector3<float> ReadVector2(std::ifstream& file) const;

    Face ReadFace(std::ifstream& file, const std::string& material) const;
};


#endif //OBJREADER_OBJ_READER_H
