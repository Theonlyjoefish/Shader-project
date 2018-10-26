#include "rt3d.h"
#include "rt3dObjLoader.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <stack>

using namespace std;

#define DEG_TO_RADIAN 0.017453293

//Globals

GLuint cubeIndexCount = 0;
GLuint bunnyIndexCount = 0;
GLuint meshObjects[3];

//Camera

GLfloat r = 0.0f;

glm::vec3 eye(-2.0f, 10.f, 8.0f);
glm::vec3 at(0.0f, 1.0f, -1.0f);
glm::vec3 up(0.0f, 1.0f, 0.0f);

stack<glm::mat4> mvStack;

GLuint uniformIndex;

//Textures

GLuint textures[3];
GLuint skybox[5];

rt3d::lightStruct light0 = {
	{0.4f, 0.4f, 0.4f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f, 1.0f},
    {-5.0f, 2.0f, 2.0f, 1.0f}
};
glm::vec4 lightPos(-5.0f, 2.0f, 2.0f, 1.0f);

rt3d::materialStruct material0 = {
	{0.2f, 0.4f, 0.2f, 1.0f}, 
	{0.5f, 1.0f, 0.5f, 1.0f}, 
	{0.0f, 0.1f, 0.0f, 1.0f}, 
	2.0f  
};
rt3d::materialStruct material1 = {
	{0.4f, 0.4f, 1.0f, 1.0f}, 
	{0.8f, 0.8f, 1.0f, 1.0f}, 
	{0.8f, 0.8f, 0.8f, 1.0f}, 
	1.0f  
};

float attConstant = 1.0f;
float attLinear = 0.0f;
float attQuadratic = 0.0f;

SDL_Window * setupRC(SDL_GLContext &context)
{
	SDL_Window * window;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		rt3d::exitFatalError("unable to initialize SDL");

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	window = SDL_CreateWindow("shader demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!window)
		rt3d::exitFatalError("unable to create window");

	context = SDL_GL_CreateContext(window);
	SDL_GL_SetSwapInterval(1);
	return window;
}

void init(void)
{

}

void update(void)
{

}

void draw(SDL_Window * window)
{

}

int main(int argc, char *argv[])
{
	SDL_Window * hWindow;
	SDL_GLContext glContext;
	hWindow = setupRC(glContext);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << glGetString(GL_VERSION) << endl;

	init();

	bool running = true;
	SDL_Event sdlEvent;
	while (running)
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		update();
		draw(hWindow);
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(hWindow);
	SDL_Quit();
	return 0;
}