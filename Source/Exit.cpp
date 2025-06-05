#include "Exit.h"

void Exit::init()
{
  float vertices[] =
  {
    -1.0f, 0.85f,  0.0f,  0.0f, 0.0f, // Bottom Left
    -0.5f, 0.85f,  0.0f,  1.0f, 0.0f, // Bottom Right
    -0.5f, 1.0f,  0.0f,  1.0f, 1.0f, // Top Right
    -1.0f, 1.0f,  0.0f,  0.0f, 1.0f, // Top Left
  };
  unsigned int indices[] =
  {
    0, 1, 2,
    2, 3, 0,
  };
  vertexArray_.init();
  vertexBuffer_.init(vertices, sizeof(vertices));
  indexBuffer_.init(indices, sizeof(indices));
  vertexArray_.linkAttrib(vertexBuffer_, 0, 3, GL_FLOAT, 5, (void*)0);
  vertexArray_.linkAttrib(vertexBuffer_, 1, 2, GL_FLOAT, 5, (void*)(3 * sizeof(float)));
  shader_.setTexture();
  shader_.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
}
void Exit::render(float aspect)
{
  shader_.setView(glm::mat4(1.0f));
  shader_.setProj(glm::ortho(-aspect, aspect, -1.0f, 1.0f));
  shader_.setModel(glm::translate(glm::mat4(1.0f), glm::vec3(1.0f - aspect, 0.0f, 0.0f)));
  renderer_.draw(vertexArray_, indexBuffer_, shader_, GL_TRIANGLES, &texture_);
}
