#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>


#include "wnd.h"


static unsigned int ShaderID = 0;


void Shader_Use(){
	if (ShaderID == 0) {
		printf("%s\n", "Shader not initialized");
		glfwTerminate();
	}
	glUseProgram(ShaderID);
}

void Shader_Cleanup() {
	if (ShaderID != 0) {
		glDeleteProgram(ShaderID);
		ShaderID = 0;
	}
}

unsigned int Shader_Get(){
	return ShaderID;
}


unsigned int CreateAndCompile(char *fName, GLenum type ){

	unsigned int shObj = glCreateShader(type);

	FILE *fp;
	fp = fopen(fName, "rb");
	if (fp == NULL){
			printf("%s\n", "failed to open shader file");
			glfwTerminate();
		}

	fseek(fp, 0, SEEK_END);
	long length = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *Src = (char *)malloc(length + 1);
	fread(Src, 1, length, fp);
	Src[length] = '\0';
	fclose(fp);

	const char *shSrc = Src;

	glShaderSource(shObj, 1, &shSrc, (void*)0);
	glCompileShader(shObj);

	int ok = 0;
	glGetShaderiv(shObj, GL_COMPILE_STATUS, &ok);
	if(!ok){
		glDeleteShader(shObj);
		printf("%s\n", "Shader failed to compile");
		glfwTerminate();
	}
	free(Src);
	return shObj;
}

void Shader_Init() {
    unsigned int FragID = CreateAndCompile("./bin/shaders/main.frag.glsl", GL_FRAGMENT_SHADER);
    unsigned int VertID = CreateAndCompile("./bin/shaders/main.vert.glsl", GL_VERTEX_SHADER);

    ShaderID = glCreateProgram();
    glAttachShader(ShaderID, FragID);
    glAttachShader(ShaderID, VertID);
    glLinkProgram(ShaderID);
    
    int ok;
    glGetProgramiv(ShaderID, GL_LINK_STATUS, &ok);
    if (!ok) {
        printf("%s\n", "Shader program failed to link");
        glfwTerminate();
    }
    glDeleteShader(FragID);
    glDeleteShader(VertID);
}
