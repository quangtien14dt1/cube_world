// #ifndef MODEL_H_INCLUDED
// #define MODEL_H_INCLUDED

// #include <vector>
// #include <string>
// #include "mesh.h"

// class Model {
//     public:
//         Model(char *path) {
//             loadModel(path);
//         }
//         void Draw(Shader &shader);
//     private:
//         // model data
//         std::vector<Mesh> meshes;
//         std::string directory;

//         void loadModel(std::string path);
//         void processNode(aiNode *node, const aiScene *scene);
//         Mesh processMesh(aiMesh *mesh, const aiScene *scene);
//         vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
//                                              string typeName);
// };
// #endif
