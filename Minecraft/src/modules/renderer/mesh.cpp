#include "mesh.h"
#include "glad/glad.h"

Mesh::Mesh(uint8_t* blocks) : blocks(blocks)
{

}

Mesh::~Mesh()
{

}

void Mesh::createMesh()
{
    for (int x = 0; x < 16; x++)
    {
        for (int y = 0; y < 16; y++)
        {
            for (int z = 0; z < 16; z++)
            {
                if (blocks[getBlockIndex(x, y, z)] == 0) continue;

                float u = (blocks[getBlockIndex(x, y, z)] % 16) * UV_SIZE;
                float v = (blocks[getBlockIndex(x, y, z)] / 16) * UV_SIZE;

                if (blocks[getBlockIndex(x, y, z - 1)] == 0)
                {
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }

                if (blocks[getBlockIndex(x, y, z + 1)] == 0) {
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }

                if (blocks[getBlockIndex(x, y + 1, z)] == 0)
                {
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }

                if (blocks[getBlockIndex(x, y - 1, z)] == 0) {
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }

                if (blocks[getBlockIndex(x + 1, y, z)] == 0) {
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x + 1.0f); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }

                if (blocks[getBlockIndex(x - 1, y, z)] == 0) {
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x); vertices.push_back(y); vertices.push_back(z); vertices.push_back(u + UV_SIZE); vertices.push_back(v);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z); vertices.push_back(u); vertices.push_back(v + UV_SIZE);
                    vertices.push_back(x); vertices.push_back(y + 1.0f); vertices.push_back(z + 1.0f); vertices.push_back(u + UV_SIZE); vertices.push_back(v + UV_SIZE);
                }
            }
        }
    }

    glGenBuffers(1, &TBO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Mesh::renderMesh()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 5);
}

glm::mat4 Mesh::getModelMatrix()
{
    glm::mat4 matrix = glm::mat4(1.0f);
    matrix = glm::translate(matrix, glm::vec3(0.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix = glm::rotate(matrix, glm::radians(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    matrix = glm::scale(matrix, glm::vec3(1.0f, 1.0f, 1.0f));
    return matrix;
}