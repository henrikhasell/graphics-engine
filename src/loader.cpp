#include "loader.hpp"
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#define MODEL_IMPORT_FLAGS (\
    aiProcess_GenSmoothNormals |\
    aiProcess_Triangulate |\
    aiProcess_GenUVCoords |\
    aiProcess_SortByPType |\
    aiProcess_FlipUVs |\
    aiProcess_CalcTangentSpace)

bool Model_Load(Model *model, const aiScene *scene)
{
	for (unsigned int i = 0; i < scene->mNumMeshes; i++)
	{
		const aiMesh* mesh = scene->mMeshes[i];

		Vertex3D* vertices = new Vertex3D[mesh->mNumVertices];

		for (unsigned int j = 0; j < mesh->mNumVertices; j++)
		{
			Vertex3D* current_vertex = vertices + j;

			const aiVector3D* position = mesh->mVertices + j;

			current_vertex->position.x = position->x;
			current_vertex->position.y = position->y;
			current_vertex->position.z = position->z;

			if (*mesh->mColors)
			{
				const aiColor4D* colour = *mesh->mColors + j;

				current_vertex->colour.r = colour->r;
				current_vertex->colour.g = colour->g;
				current_vertex->colour.b = colour->b;
			}
			else
			{
				current_vertex->colour.r = 1.0f;
				current_vertex->colour.g = 1.0f;
				current_vertex->colour.b = 1.0f;
			}

			if (*mesh->mTextureCoords)
			{
				const aiVector3D* uv = *mesh->mTextureCoords + j;

				current_vertex->uv.x = uv->x;
				current_vertex->uv.y = uv->y;
			}
			else
			{
				current_vertex->uv.x = 0.0f;
				current_vertex->uv.y = 0.0f;
			}

			if (mesh->mNormals)
			{
				const aiVector3D* normal = mesh->mNormals + j;

				current_vertex->normal.x = normal->x;
				current_vertex->normal.y = normal->y;
			}
			else
			{
				current_vertex->normal.x = 0.0f;
				current_vertex->normal.y = 0.0f;
			}
		}

		GLuint* indices = new GLuint[mesh->mNumFaces * 3];

		for (unsigned int j = 0; j < mesh->mNumFaces; j++)
		{
			const aiFace* face = mesh->mFaces + j;

			assert(face->mNumIndices == 3);

			for (unsigned int k = 0; k < face->mNumIndices; k++)
			{
				indices[j * 3 + k] = face->mIndices[k];
			}
		}

		model->data(vertices, indices, mesh->mNumVertices, mesh->mNumFaces * 3);

		delete[] vertices;
		delete[] indices;

		return true; // Ignore all but first mesh.
	}

	return true;
}

bool Model_Load(Model *model, const char path[])
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path, MODEL_IMPORT_FLAGS);

	if (scene)
	{
		return Model_Load(model, scene);
	}

	std::cerr << "Failed to load " << path << std::endl;

	return false;
}