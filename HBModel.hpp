#pragma once

#include <vector>
#include <GLES3/gl3.h>

#include "HBGlobal.hpp"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "HBMesh.hpp"

HONEYBEE_BEGIN_NAMESPACE

class HBModel {
public:
    explicit HBModel(const std::string &path);
    void draw(GLuint programObject);
private:
    void loadModel(const std::string &path);
    void processNode(aiNode *node, const aiScene *scene);
    HBMesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<HBTexture> loadMaterialTextures(aiMaterial *mat,
                                                aiTextureType type,
                                                const std::string &typeName);
    glm::vec4 loadMaterialColor(aiMaterial *mat,
                                const char* pKey,
                                unsigned int type,
                                unsigned int index);
private:
    std::vector<HBMesh> mMeshes;
    std::string mModelDirectory;
    std::vector<HBTexture> mLoadedTextures;
};

HONEYBEE_END_NAMESPACE
