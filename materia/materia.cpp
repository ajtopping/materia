// materia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#define GLEW_STATIC
#include "GL/glew.h"

#include <GL/GL.h>
#include <GL/GLU.h>

//#include "pch.h"
#include <iostream>
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_opengl.h"

//custom #includes
#include "am_S_UniqueUuidAssociator.h"
#include "am_S_Guid_entComposition.h"
#include "entComposition.h"
#include "entDebugger.h"
#include "ssRectangleSpace.h"
#include "rProjectionMatrixFactory.h"
#include "filetobuf.h"
#include "missing_resource_error.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include "mMesh.h"
#include "mMeshPrimitiveFactory.h"
#include "rMesh.h"
#include "rPoints.h"
#include "rNdcPanel.h"
#include "Clock.h"
#include "oRenderableMesh.h"
#include "RandomGenerator.h"
#include "PolygonGenerator.h"

// singleton
#include "dDataDictionary.h"

//system
#include <unordered_map>
#include <direct.h>
#include <chrono>
//#include <unistd.h> // LINUX

void _CollectPaths( char * argv0 );
int _SDLSetOpenGLCompatibility();

//Globals
std::unordered_map<std::string, std::string> __Paths;

int main( int argc, char** argv )
{
	SDL_SetMainReady();

    std::cout << "Hello World!\n";

	_CollectPaths(argv[0]);

	Clock tick_clock = Clock::Clock();

	int cwdLength = 0;
	char * currentWorkingDir = _getcwd(NULL, 0);
	fprintf(stdout, "%s %d\n", currentWorkingDir, strlen(currentWorkingDir));

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	_SDLSetOpenGLCompatibility();
	
	SDL_Window *win = SDL_CreateWindow("Hellow World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	
	if (win == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	
	SDL_GLContext context = SDL_GL_CreateContext(win);
	if (context == NULL)
	{
		printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
		//success = false;
	}

	
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	
	//SDL_GL_MakeCurrent(win, context);

	

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	//printf("GL_RENDERER: %s\nGL_VERSION: %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION));

	//SDL_Surface* surface = SDL_GetWindowSurface(win);

	bool quit = false;
	SDL_Event windowEvent;

	SDL_Texture * diamondTexture = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 128, 128);

	
	// Framebuffer offscreen rendering test
	GLuint fbo;
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	// generate texture
	unsigned int texColorBuffer;
	glGenTextures(1, &texColorBuffer);
	glBindTexture(GL_TEXTURE_2D, texColorBuffer);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	// attach it to currently bound framebuffer object
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texColorBuffer, 0);

	unsigned int rbo;
	glGenRenderbuffers(1, &rbo);
	glBindRenderbuffer(GL_RENDERBUFFER, rbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 800, 600);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		fprintf(stdout, "Generating offscreen framebuffer failed! Code: %d\n", glCheckFramebufferStatus(GL_FRAMEBUFFER));
	}
	else
	{
		fprintf(stdout, "Generated offscreen framebuffer with id: %d\n", fbo);
	}

	// Back to default (window) framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Test pyramid
	mMesh * mDiamond = mMeshPrimitiveFactory::DefaultPyramid();
	rMesh rDiamond;
	oRenderableMesh oDiamond;
	oDiamond.set_mesh(mDiamond);
	oDiamond.set_renderer(&rDiamond);
	mTransform halfScale;
	halfScale.scaleX(0.5);
	halfScale.scaleY(0.5);
	halfScale.scaleZ(0.5);
	oDiamond.transform = halfScale;

	// Test dDataDictionary
	GLuint num_points = 80;
	dDataBlock dPointsPosition = RandomGenerator::Floats(2 * num_points, -1.0f, 1.0f);
	dDataBlock dPointsColor = RandomGenerator::Floats(3 * num_points, 0.0f, 1.0f);
	dDataDictionary::get_instance()->add_datablock("dPointsPosition", &dPointsPosition);
	dDataDictionary::get_instance()->add_datablock("dPointsColor", &dPointsColor);
	dDataBlock * dPointsPosition_dictionary_ptr = dDataDictionary::get_instance()->get_datablock("dPointsPosition");
	dDataBlock * dPointsColor_dictionary_ptr = dDataDictionary::get_instance()->get_datablock("dPointsColor");
	dDataDictionary::get_instance()->get_datablock("This dDataBlock does not exist!");

	GLuint num_sides = 12;
	dDataBlock dNgonPosition = PolygonGenerator::Ngon(num_sides);
	dDataBlock dNgonColor = RandomGenerator::Floats(3 * num_sides, 0.0f, 1.0f);
	dDataDictionary::get_instance()->add_datablock("dNgonPosition", &dNgonPosition);
	dDataDictionary::get_instance()->add_datablock("dNgonColor", &dNgonColor);
	dDataBlock * dNgonPosition_dictionary_ptr = dDataDictionary::get_instance()->get_datablock("dNgonPosition");
	dDataBlock * dNgonColor_dictionary_ptr = dDataDictionary::get_instance()->get_datablock("dNgonColor");

	// Test points
	glPointSize(5.0f);
	mMesh mPoints;
	fprintf(stdout, "Generating mPoints: Pos Bytes: %d   Color Bytes: %d\n", dPointsPosition.get_size_in_bytes(), dPointsColor.get_size_in_bytes());
	mPoints.setVPosition(2, dPointsPosition_dictionary_ptr->get_data_pointer(), dPointsPosition.get_size_in_bytes());
	mPoints.setVColor(3, dPointsColor_dictionary_ptr->get_data_pointer(), dPointsColor.get_size_in_bytes());
	mPoints.set_vertex_count(num_points);
	rPoints rrPoints;
	rrPoints.SetMesh(mPoints);
	rrPoints.set_projection_matrix(rProjectionMatrixFactory::WindowOrtho(win));
	
	// Test Ngon
	mMesh mNgon;
	fprintf(stdout, "Generating mNgon: Pos Bytes: %d   Color Bytes: %d\n", dNgonPosition.get_size_in_bytes(), dNgonColor.get_size_in_bytes());
	mNgon.setVPosition(2, dNgonPosition_dictionary_ptr->get_data_pointer(), dNgonPosition.get_size_in_bytes());
	mNgon.setVColor(3, dNgonColor_dictionary_ptr->get_data_pointer(), dNgonColor.get_size_in_bytes());
	mNgon.set_vertex_count(num_sides);
	rPoints rrNgon;
	rrNgon.SetMesh(mNgon);
	rrNgon.set_projection_matrix(rProjectionMatrixFactory::WindowOrtho(win));

	// NDC Panel
	mMesh * mNdcPanel = mMeshPrimitiveFactory::NdcPanel();
	rNdcPanel rrNdcPanel = rNdcPanel();
	rrNdcPanel.SetMesh(*mNdcPanel);
	rrNdcPanel.set_projection_matrix(rProjectionMatrixFactory::WindowOrthoNdc(win));
	mTransform ndcPanelTransform;
	

	//
	// Typical shader
	//
	VertexShader vs;
	std::string vertexsourcepath = __Paths["res"] + "\\shaders\\uniform.vert";
	vs.setPath(vertexsourcepath);
	vs.compileShader();

	FragmentShader fs;
	std::string fragmentsourcepath = __Paths["res"] + "\\shaders\\uniform.frag";
	fs.setPath(fragmentsourcepath);
	fs.compileShader();

	/* If we reached this point it means the vertex and fragment shaders compiled and are syntax error free. */
	/* We must link them together to make a GL shader program */
	/* GL shader programs are monolithic. It is a single piece made of 1 vertex shader and 1 fragment shader. */
	/* Assign our program handle a "name" */
	ShaderProgram shaderProgram;

	/* Attach our shaders to our program */
	shaderProgram.attachShader(&vs);
	shaderProgram.attachShader(&fs);

	/* Bind attribute index 0 (coordinates) to in_Position and attribute index 1 (color) to in_Color */
	/* Attribute locations must be setup before calling glLinkProgram. */
	shaderProgram.bindAttribLocation(0, "in_Position");
	shaderProgram.bindAttribLocation(1, "in_Color");

	//
	// NDC Panel shader
	//
	VertexShader vsNdcPanel;
	vertexsourcepath = __Paths["res"] + "\\shaders\\ndcPanel.vert";
	vsNdcPanel.setPath(vertexsourcepath);
	vsNdcPanel.compileShader();

	FragmentShader fsNdcPanel;
	fragmentsourcepath = __Paths["res"] + "\\shaders\\ndcPanel.frag";
	fsNdcPanel.setPath(fragmentsourcepath);
	fsNdcPanel.compileShader();

	ShaderProgram spNdcPanel;

	spNdcPanel.attachShader(&vsNdcPanel);
	spNdcPanel.attachShader(&fsNdcPanel);

	spNdcPanel.bindAttribLocation(0, "in_Position");
	spNdcPanel.bindAttribLocation(1, "in_TexCoords");

	/* Link our program */
	/* At this stage, the vertex and fragment programs are inspected, optimized and a binary code is generated for the shader. */
	/* The binary code is uploaded to the GPU, if there is no error. */
	shaderProgram.linkProgram();
	spNdcPanel.linkProgram();
	//glLinkProgram(shaderprogram);

	rDiamond.SetShaderProgram(&shaderProgram);
	rrPoints.SetShaderProgram(&shaderProgram);
	rrNgon.SetShaderProgram(&shaderProgram);
	rrNdcPanel.SetShaderProgram(&spNdcPanel);

	quit = false;

	int mx = 0;
	int my = 0;
	int mx2 = 10;
	int my2 = 10;

	// Clickable rectangle things
	//// Entities
	entComposition entNdcPanel;
	am_S_Guid_entComposition::get_instance()->insert(entNdcPanel);
	//// Spatial Search
	ssRectangleSpace space;
	ssRectangle ssNdcPanel(0, 0, 100, 100);
	ssRectangle ssNdcPanelNoEnt(100,100,200,200);
	space.insert_rectangle(ssNdcPanel);
	space.insert_rectangle(ssNdcPanelNoEnt);
	std::forward_list<ssRectangle> rectangles;
	//// Association Model
	am_S_UniqueUuidAssociator::get_instance()->insert(ssNdcPanel.get_uuid(), entNdcPanel.get_uuid());
	
	while (!quit)
	{
		SDL_WaitEvent(&windowEvent);

		tick_clock.tick();

		switch (windowEvent.type)
		{

		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYUP:
			switch (windowEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (windowEvent.button.button)
			{
			case SDL_BUTTON_LEFT:
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Left button was pressed!", win);
				fprintf(stdout, "Elapsed time: %f seconds\n", tick_clock.get_seconds_duration_since_start());
				mx = windowEvent.motion.x;
				my = windowEvent.motion.y;
				break;
			case SDL_BUTTON_RIGHT:
				//SDL_ShowSimpleMessageBox(0, "Mouse", "Right button was pressed!", win);
				mx2 = windowEvent.motion.x;
				my2 = windowEvent.motion.y;

				rectangles = space.find_rectangles_containing_point(mx2, my2);
				if (rectangles.empty())
				{
					fprintf(stdout, "No ssRectangle was clicked!");
				}
				else
				{
					int num_rectangles = 0;
					for (auto it = rectangles.begin(); it != rectangles.end(); it++)
					{
						num_rectangles++;
						amUuid rectangle_uuid = it->get_uuid();
						fprintf(stdout, "Clicked on ssRectangle:%llX\n", rectangle_uuid.get_data());

						amUuid composition_uuid = am_S_UniqueUuidAssociator::get_instance()->find(rectangle_uuid);
						if (composition_uuid == amUuid(0))
						{
							fprintf(stdout, "    but found no associated entComposition...");
						}
						else
						{
							fprintf(stdout, "    and found an associated entComposition:%llX\n", composition_uuid.get_data());
						}
					}
				}
				break;
			default:
				SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", win);
				break;
			}
		}
	
		
		/*
		SDL_SetRenderDrawColor(ren, 0x30, 0x30, 0x30, 0xFF);
		SDL_RenderClear(ren);

		//Render red filled quad
		SDL_Rect fillRect = { mx, my, mx2-mx, my2-my };
		SDL_SetRenderDrawColor(ren, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(ren, &fillRect);

		SDL_RenderPresent(ren);
		*/

		//
		// Bind to the framebuffer that will be used for texturing an NdcPanel
		//
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		glViewport(0,0,640, 480);

		rDiamond.set_u_runtime_seconds(tick_clock.get_seconds_duration_since_start());
		rDiamond.set_u_resolution(640, 480);
		oDiamond.transform.rotY(tick_clock.get_seconds_duration_since_start() * 2);
		oDiamond.transform.rotX(tick_clock.get_seconds_duration_since_start() * 2);
		oDiamond.transform.rotZ(tick_clock.get_seconds_duration_since_start() * 2);
		oDiamond.render();

		glPointSize(5.0f);
		rrPoints.set_u_runtime_seconds(tick_clock.get_seconds_duration_since_start());
		rrPoints.Draw();

		glPointSize(15.0f);
		rrNgon.set_u_runtime_seconds(tick_clock.get_seconds_duration_since_start());
		rrNgon.set_u_resolution(640, 480);
		rrNgon.Draw();

		//
		// Change back to the default (window) framebuffer and render the NdcPanel with the texture
		//
		glBindFramebuffer(GL_FRAMEBUFFER, 0); // back to default
		glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glViewport(mx, 480 - my, 320, 240);
		glViewport(0, 0, 640, 480);

		glDisable(GL_DEPTH_TEST);
		glBindTexture(GL_TEXTURE_2D, texColorBuffer);

		//ndcPanelTransform.rotZ(tick_clock.get_seconds_duration_since_start());
		ndcPanelTransform.posX(mx);
		ndcPanelTransform.posY(480-my);
		ndcPanelTransform.scaleX(320.0f);
		ndcPanelTransform.scaleY(240.0f);
		glm::mat4 ndcPanelMvp = rProjectionMatrixFactory::WindowOrthoNdc(win) * ndcPanelTransform.get_composition_matrix();

		rrNdcPanel.Draw(ndcPanelMvp);

		SDL_GL_SwapWindow(win);
	}

	/* Cleanup all the things we bound and allocated */
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	shaderProgram.detachAttachedShaders();
	shaderProgram.deleteShaderProgram();
	vs.deleteShader();
	fs.deleteShader();

	mDiamond->~mMesh();

	SDL_GL_DeleteContext(context);

	return 0;

}

void _CollectPaths( char * argv0 )
{
	std::string fullpath(argv0);
	size_t index = fullpath.find_last_of("\\");
	std::string exepath = fullpath.substr(0, index);

	__Paths.emplace("root", exepath);
	__Paths.emplace("res", exepath + "\\res");

	fprintf(stdout, "%s\n", __Paths["root"].c_str());
	fprintf(stdout, "%s\n", __Paths["res"].c_str());
}

int _SDLSetOpenGLCompatibility() {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
