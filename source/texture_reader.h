//
// Created by fabio on 4/23/16.
//

#ifndef OBJ_VIEWER_TEXTURE_READER_H
#define OBJ_VIEWER_TEXTURE_READER_H


#include <GL/gl.h>
#include <string>
#include <map>
#include <algorithm>
#include "lodepng.h"

class TextureReader
{
public:
    std::map<std::string, GLuint>* ReadTextures(const std::string& mesh_path,
                                                const std::vector<std::string>& files) const;
};


#endif //OBJ_VIEWER_TEXTURE_READER_H
