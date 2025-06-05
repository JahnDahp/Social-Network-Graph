#include "Shader.h"

std::string getFileContents(const std::string& fileName)
{
	std::ifstream in(fileName);
	std::ostringstream contents;
	contents << in.rdbuf();
	in.close();
	return contents.str();
}
Shader::Shader()
{
	ID_ = 0;
}
Shader::Shader(std::string vertexFile, std::string fragmentFile)
{
	std::string vertexCode = getFileContents(vertexFile);
	std::string fragmentCode = getFileContents(fragmentFile);
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

	int success;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) std::cout << "Vertex Shader Compilation Failed\n";
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) std::cout << "Fragment Shader Compilation Failed\n";

	ID_ = glCreateProgram();
	glAttachShader(ID_, vertexShader);
	glAttachShader(ID_, fragmentShader);
	glLinkProgram(ID_);

	glGetProgramiv(ID_, GL_LINK_STATUS, &success);
	if (!success) std::cout << "Shader Linking Failed\n";

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
Shader::~Shader() 
{
	glDeleteProgram(ID_);
}
void Shader::bind() 
{
	glUseProgram(ID_);
}
void Shader::unbind()
{
	glUseProgram(0);
}
unsigned int Shader::getID() 
{
	return ID_;
}
void Shader::setColor(glm::vec4 color)
{
	bind();
	glUniform4f(glGetUniformLocation(ID_, "u_color"), color[0], color[1], color[2], color[3]);
	unbind();
}
void Shader::setTexture()
{
	bind();
	glUniform1i(glGetUniformLocation(ID_, "u_tex"), 0);
	unbind();
}
void Shader::setModel(glm::mat4 model)
{
	bind();
	glUniformMatrix4fv(glGetUniformLocation(ID_, "u_model"), 1, GL_FALSE, glm::value_ptr(model));
	unbind();
}
void Shader::setView(glm::mat4 view)
{
	bind();
	glUniformMatrix4fv(glGetUniformLocation(ID_, "u_view"), 1, GL_FALSE, glm::value_ptr(view));
	unbind();
}
void Shader::setProj(glm::mat4 proj)
{
	bind();
	glUniformMatrix4fv(glGetUniformLocation(ID_, "u_proj"), 1, GL_FALSE, glm::value_ptr(proj));
	unbind();
}
