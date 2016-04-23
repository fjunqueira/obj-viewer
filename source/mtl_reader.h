//
// Created by fabio on 4/10/16.
//

#ifndef OBJ_READER_MTL_READER_H
#define OBJ_READER_MTL_READER_H

#include <map>
#include <string>
#include "material.h"
#include "vector3.h"
#include <iostream>
#include <fstream>

class MtlReader
{
public:
    std::map<std::string, Material>* ReadMaterials(const std::string& file_path) const;
private:
    math::Vector3<float> ReadVector3(std::ifstream& file) const;
};


#endif //OBJ_READER_MTL_READER_H
