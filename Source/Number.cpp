#include "Number.h"

Number::Number(int n)
{
  num_ = n;
  visible_ = true;
}
void Number::init()
{
  float vertices[] =
  {
    -0.75f, -1.0f,  0.0f,  0.0f, (float)(0 + num_) / 10.0f, // Bottom Left
     0.75f, -1.0f,  0.0f,  1.0f, (float)(0 + num_) / 10.0f, // Bottom Right
     0.75f,  1.0f,  0.0f,  1.0f, (float)(1 + num_) / 10.0f, // Top Right
    -0.75f,  1.0f,  0.0f,  0.0f, (float)(1 + num_) / 10.0f, // Top Left
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
  shader_.setModel(glm::mat4(1.0f));
}
int Number::getNum()
{
  return num_;
}
int Number::isVisible()
{
  return visible_;
}
void Number::setVisible(bool b)
{
  visible_ = b;
}
void Number::transform(float x, float y, float scaleX, float scaleY)
{
  glm::mat4 model(1.0f);
  model = glm::translate(model, glm::vec3(x, y, 0.0f));
  model = glm::scale(model, glm::vec3(scaleX, scaleY, 1.0f));
  shader_.setModel(model);
}
void Number::render(glm::mat4 proj, glm::mat4 view)
{
  shader_.setView(view);
  shader_.setProj(proj);
  renderer_.draw(vertexArray_, indexBuffer_, shader_, GL_TRIANGLES, &texture_);
}
