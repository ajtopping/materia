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

// template includes
#include "amUuid_T.tpp"
#include "am_S_Uuid_T.tpp"
#include "shUniformT.tpp"

//custom #includes
#include "shGlobalUniformMap.h"
#include "entDraw.h"
#include "entScene.h"
#include "opMouseDragTransform.h"
#include "i_S_MouseValues.h"
#include "iMouseDragOperationsHandler.h"
#include "am_S_UniqueUuidAssociator.h"
#include "am_S_Guid_entComposition.h"
#include "entComposition.hpp"
#include "entDebugger.h"
#include "ssRectangleSpace.h"
#include "rProjectionMatrixFactory.h"
#include "filetobuf.h"
#include "missing_resource_error.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "ShaderProgram.h"
#include "ShaderProgramFactory.h"
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
shGlobalUniformMap __Uniforms;

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

	// Test pyramid
	entComposition entity_diamond;
	mMesh * mDiamond = mMeshPrimitiveFactory::DefaultPyramid();
	rMesh rDiamond;
	rDiamond.SetMesh(*mDiamond);
	util::AttachComponent<Renderer *>(entity_diamond.get_uuid(), &rDiamond);
	mTransform entity_diamond_transform;
	entity_diamond_transform.scaleX(0.5);
	entity_diamond_transform.scaleY(0.5);
	entity_diamond_transform.scaleZ(0.5);
	util::AttachComponent<mTransform *>(entity_diamond.get_uuid(), &entity_diamond_transform);

	// Test points
	entComposition entity_points;
	glPointSize(5.0f);
	mMesh mPoints;
	fprintf(stdout, "Generating mPoints: Pos Bytes: %d   Color Bytes: %d\n", dPointsPosition.get_size_in_bytes(), dPointsColor.get_size_in_bytes());
	mPoints.setVPosition(2, dPointsPosition_dictionary_ptr->get_data_pointer(), dPointsPosition.get_size_in_bytes());
	mPoints.setVColor(3, dPointsColor_dictionary_ptr->get_data_pointer(), dPointsColor.get_size_in_bytes());
	mPoints.set_vertex_count(num_points);
	rPoints rrPoints;
	rrPoints.SetMesh(mPoints);
	rrPoints.set_projection_matrix(rProjectionMatrixFactory::WindowOrtho(win));
	util::AttachComponent<Renderer *>(entity_points.get_uuid(), &rrPoints);
	
	// Test Ngon
	entComposition entity_ngon;
	mMesh mNgon;
	fprintf(stdout, "Generating mNgon: Pos Bytes: %d   Color Bytes: %d\n", dNgonPosition.get_size_in_bytes(), dNgonColor.get_size_in_bytes());
	mNgon.setVPosition(2, dNgonPosition_dictionary_ptr->get_data_pointer(), dNgonPosition.get_size_in_bytes());
	mNgon.setVColor(3, dNgonColor_dictionary_ptr->get_data_pointer(), dNgonColor.get_size_in_bytes());
	mNgon.set_vertex_count(num_sides);
	rPoints rrNgon;
	rrNgon.SetMesh(mNgon);
	rrNgon.set_projection_matrix(rProjectionMatrixFactory::WindowOrtho(win));
	util::AttachComponent<Renderer *>(entity_ngon.get_uuid(), &rrNgon);

	// NDC Panel
	mMesh * mNdcPanel = mMeshPrimitiveFactory::NdcPanel();
	rNdcPanel rrNdcPanel = rNdcPanel();
	rrNdcPanel.SetMesh(*mNdcPanel);
	rrNdcPanel.set_projection_matrix(rProjectionMatrixFactory::WindowOrthoNdc(win));
	mTransform ndcPanelTransform;
	
	// ShaderProgram objects with fully compiled shaders
	ShaderProgram * spUniform = ShaderProgramFactory::Uniform(__Paths["res"]);
	ShaderProgram * spNdc = ShaderProgramFactory::NdcPanel(__Paths["res"]);

	/* Link our program */
	/* At this stage, the vertex and fragment programs are inspected, optimized and a binary code is generated for the shader. */
	/* The binary code is uploaded to the GPU, if there is no error. */
	spUniform->linkProgram();
	spNdc->linkProgram();
	//glLinkProgram(shaderprogram);

	rDiamond.SetShaderProgram(spUniform);
	rrPoints.SetShaderProgram(spUniform);
	rrNgon.SetShaderProgram(spUniform);
	rrNdcPanel.SetShaderProgram(spNdc);

	// Global uniforms
	shUniformT<GLfloat> u_runtime_seconds( "u_runtime_in_seconds" );
	shUniformT<glm::ivec2> u_resolution("u_resolution");
	shGlobalUniformMap global_uniform_map;
	global_uniform_map.add_uniform(&u_runtime_seconds);
	global_uniform_map.add_uniform(&u_resolution);
	global_uniform_map.add_uniform_to_shaderprogram(spUniform->getShaderProgramUUID(), "u_runtime_in_seconds");
	global_uniform_map.add_uniform_to_shaderprogram(spUniform->getShaderProgramUUID(), "u_resolution");
	global_uniform_map.add_uniform_to_shaderprogram(spNdc->getShaderProgramUUID(), "u_runtime_in_seconds");
	global_uniform_map.add_uniform_to_shaderprogram(spNdc->getShaderProgramUUID(), "u_resolution");
	global_uniform_map.update_uniform("u_resolution", glm::ivec2(640, 480));

	

	// Test diamond
	entComposition entDefaultDiamond;
	mMesh * mDefaultDiamond = mMeshPrimitiveFactory::DefaultDiamond();
	rMesh rDefaultDiamond;
	rDefaultDiamond.SetMesh(*mDefaultDiamond);
	rDefaultDiamond.SetShaderProgram(spUniform);
	mTransform transformDefaultDiamond;
	transformDefaultDiamond.scaleX(0.25);
	transformDefaultDiamond.scaleY(0.25);
	util::AttachComponent<Renderer *>(entDefaultDiamond.get_uuid(), &rDefaultDiamond);
	util::AttachComponent<mTransform *>(entDefaultDiamond.get_uuid(), &transformDefaultDiamond);
	//am_S_Uuid_T<Renderer *>::insert(entDefaultDiamond.get_uuid(), &rDefaultDiamond);
	//am_S_Uuid_T<mTransform *>::insert(entDefaultDiamond.get_uuid(), &transformDefaultDiamond);

	// Default scene
	entScene defaultScene;
	defaultScene.addCompositionEntity(entity_diamond);
	defaultScene.addCompositionEntity(entity_ngon);
	defaultScene.addCompositionEntity(entity_points);

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
	ssRectangle ssNdcPanel(0, 0, 320, 240); // Screen space coordinate system probably not so hot
	ssRectangle ssNdcPanelNoEnt(100,100,200,200);
	space.insert_rectangle(ssNdcPanel);
	space.insert_rectangle(ssNdcPanelNoEnt);
	std::forward_list<ssRectangle> rectangles;
	//// Association Model
	////// Parenting
	am_S_UniqueUuidAssociator::get_instance()->insert(ssNdcPanel.get_uuid(), entNdcPanel.get_uuid());
	
	// Entity mTransform component
	util::AttachComponent<mTransform *>(entNdcPanel.get_uuid(), &ndcPanelTransform);

	// Mouse things
	i_S_MouseValues::get_instance();

	// Op things
	ndcPanelTransform.posX(0.0);
	ndcPanelTransform.posY(0.0);
	opMouseDragTransform ndcPanelOp(*i_S_MouseValues::get_instance(), ndcPanelTransform);
	amUuid_T<opMouseDragTransform *> operations;
	operations.insert(entNdcPanel.get_uuid(), &ndcPanelOp);

	// Handler things
	iMouseDragOperationsHandler mouseDragHandler(space, operations);
	opOperation * found_operation = nullptr;

	// SDL WINDOW dimensions
	int window_width = 0;
	int window_height = 0;
	SDL_GetWindowSize(win, &window_width, &window_height);

	int mx_cartesian = 0;
	int my_cartesian = 0;

	while (!quit)
	{
		SDL_WaitEvent(&windowEvent);

		tick_clock.tick();

		mx = windowEvent.motion.x;
		my = windowEvent.motion.y;

		mx_cartesian = mx;
		my_cartesian = window_height - my;

		i_S_MouseValues::set_mousehover(mx, my);

		if (found_operation != nullptr)
		{
			found_operation->operate();
		}

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
			case SDL_BUTTON_RIGHT:
				
				break;
			case SDL_BUTTON_LEFT:
				i_S_MouseValues::set_mousedown(mx, my);

				//SDL_GetWindowSize(win, &window_width, &window_height);

				found_operation = mouseDragHandler.find_operation_from_screen_coordinates(mx_cartesian, my_cartesian);
				if (found_operation != nullptr)
				{
					found_operation->reinitialize();
				}
				break;
			default:
				SDL_ShowSimpleMessageBox(0, "Mouse", "Some other button was pressed!", win);
				break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (windowEvent.button.button)
			{
			case SDL_BUTTON_LEFT:
				found_operation = nullptr;
				i_S_MouseValues::set_mouseup(mx, my);
				break;
			case SDL_BUTTON_RIGHT:
				
				break;
			}
			break;
		}

		// Update global uniforms
		global_uniform_map.update_uniform("u_runtime_in_seconds", tick_clock.get_seconds_duration_since_start());
		global_uniform_map.send_data_to_uniforms();

		//
		// Bind to the framebuffer that will be used for texturing an NdcPanel
		//
		glBindFramebuffer(GL_FRAMEBUFFER, fbo);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		glViewport(0,0,640, 480);

		entity_diamond_transform.rotY(tick_clock.get_seconds_duration_since_start() * 2);
		entity_diamond_transform.rotX(tick_clock.get_seconds_duration_since_start() * 2);
		entity_diamond_transform.rotZ(tick_clock.get_seconds_duration_since_start() * 2);
		//entDraw::Draw(entity_diamond.get_uuid());

		glPointSize(5.0f);
		//rrPoints.set_u_runtime_seconds(tick_clock.get_seconds_duration_since_start());
		//entDraw::Draw(entity_points.get_uuid());

		glPointSize(15.0f);
		//rrNgon.set_u_runtime_seconds(tick_clock.get_seconds_duration_since_start());
		//rrNgon.set_u_resolution(640, 480);
		//entDraw::Draw(entity_ngon.get_uuid());
		entDraw::DrawScene(defaultScene);

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
		ndcPanelTransform.scaleX(320.0f);
		ndcPanelTransform.scaleY(240.0f);
		glm::mat4 ndcPanelMvp = rProjectionMatrixFactory::WindowOrthoNdc(win) * ndcPanelTransform.get_composition_matrix();

		rrNdcPanel.Draw(ndcPanelMvp);

		transformDefaultDiamond.rotY(tick_clock.get_seconds_duration_since_start() * 2);
		entDraw::Draw(entDefaultDiamond.get_uuid());

		SDL_GL_SwapWindow(win);
	}

	/* Cleanup all the things we bound and allocated */
	glUseProgram(0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	spUniform->detachAttachedShaders();
	spUniform->deleteShaderProgram();
	spNdc->detachAttachedShaders();
	spNdc->deleteShaderProgram();

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
