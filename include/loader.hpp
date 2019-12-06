#ifndef LOADER_HPP
#define LOADER_HPP

#include <assimp/scene.h>
#include "model.hpp"

bool Model_Load(Model *model, const aiScene *scene);

bool Model_Load(Model *model, const char path[]);

#endif