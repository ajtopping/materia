#include "mMeshPrimitiveFactory.h"

mMesh * mMeshPrimitiveFactory::DefaultDiamond()
{
	mMesh * mesh = new mMesh();

	//96 48 16 4

	/*
	const GLfloat big[2][3][4] = {};
	int elementSize = sizeof(big[0][0][0]);
	int totalElements = sizeof(big) / elementSize;
	int z = sizeof(big[0][0]) / elementSize;
	int y = sizeof(big[0]) / z / elementSize;
	int x = sizeof(big) / z / y / elementSize;
	*/

	// POSITION
	const GLfloat diamond[4][2] = {
		{  0.0,  1.0  }, /* Top point */
		{  1.0,  0.0  }, /* Right point */
		{  0.0, -1.0  }, /* Bottom point */
		{ -1.0,  0.0  } }; /* Left point */
	int elementSize = sizeof(diamond[0][0]);
	int totalElements = sizeof(diamond) / elementSize;

	mesh->setVPosition(2, *diamond, totalElements * elementSize);

	// TRIANGLE INDEX
	const GLuint index[6] = {
		0,
		1,
		2,
		0,
		2,
		3	}; 
	elementSize = sizeof(index[0]);
	totalElements = sizeof(index) / elementSize;

	mesh->setVIndex(1, index, totalElements * elementSize);

	// COLOR
	const GLfloat colors[4][3] = {
	{  1.0,  0.0,  0.0  }, /* Red */
	{  0.0,  1.0,  0.0  }, /* Green */
	{  0.0,  0.0,  1.0  }, /* Blue */
	{  1.0,  1.0,  1.0  } }; /* White */
	elementSize = sizeof(colors[0][0]);
	totalElements = sizeof(colors) / elementSize;
	
	mesh->setVColor(3, *colors, totalElements * elementSize);

	mesh->set_vertex_count(4);
	mesh->set_triangle_count(2);

	//fprintf(stdout, "DefaultDiamond: [%d][%d][%d] = %d\n", x, y, z, totalElements );

	

	return mesh;
}

mMesh * mMeshPrimitiveFactory::DefaultPyramid()
{
	mMesh * mesh = new mMesh();

	// POSITION
	const GLfloat diamond[5][3] = {
		{ 0.0,  0.0, 0.5  },
		{ -0.5,  0.5, -0.5 },
		{ 0.5,  0.5, -0.5 },
		{ 0.5,  -0.5, -0.5 },
		{ -0.5,  -0.5, -0.5 } };
	int elementSize = sizeof(diamond[0][0]);
	int totalElements = sizeof(diamond) / elementSize;

	mesh->setVPosition(3, *diamond, totalElements * elementSize);

	// TRIANGLE INDEX
	const GLuint index[6*3] = {
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,1,
		1,2,3,
		1,3,4 };
	elementSize = sizeof(index[0]);
	totalElements = sizeof(index) / elementSize;

	mesh->setVIndex(1, index, totalElements * elementSize);

	// COLOR
	const GLfloat colors[5][3] = {
	{  1.0,  0.0,  0.0  },
	{  0.0,  1.0,  0.0  },
	{  0.0,  0.0,  1.0  },
	{  1.0,  1.0,  0.0  },
	{  0.0,  1.0,  1.0  } };
	elementSize = sizeof(colors[0][0]);
	totalElements = sizeof(colors) / elementSize;

	mesh->setVColor(3, *colors, totalElements * elementSize);

	mesh->set_vertex_count(5);
	mesh->set_triangle_count(6);

	//fprintf(stdout, "DefaultDiamond: [%d][%d][%d] = %d\n", x, y, z, totalElements );



	return mesh;
}

mMesh * mMeshPrimitiveFactory::PlusSign()
{
	mMesh * mesh = new mMesh();

	//96 48 16 4

	/*
	const GLfloat big[2][3][4] = {};
	int elementSize = sizeof(big[0][0][0]);
	int totalElements = sizeof(big) / elementSize;
	int z = sizeof(big[0][0]) / elementSize;
	int y = sizeof(big[0]) / z / elementSize;
	int x = sizeof(big) / z / y / elementSize;
	*/
	
	// POSITION
	const GLfloat vPosition[5][2] = {
		{  0.0, 0.0  },
		{ 0.0,  0.5 },
		{ 0.5, 0.0 },
		{ 0.0,  -0.5 },
		{ -0.5,  0.0 } };
	int elementSize = sizeof(vPosition[0][0]);
	int totalElements = sizeof(vPosition) / elementSize;

	mesh->setVPosition(2, *vPosition, totalElements * elementSize);

	// LINE INDEX
	const GLuint index[8] = {
		0,
		1,
		0,
		2,
		0,
		3,
		0,
		4 };
	elementSize = sizeof(index[0]);
	totalElements = sizeof(index) / elementSize;

	mesh->setVIndex(1, index, totalElements * elementSize);

	// COLOR
	const GLfloat colors[5][3] = {
	{  1.0,  1.0,  1.0  }, 
	{  0.0,  1.0,  1.0  },
	{  1.0,  0.0,  1.0  },
	{  1.0,  1.0,  0.0  },
	{  0.0,  0.0,  0.0  } };
	elementSize = sizeof(colors[0][0]);
	totalElements = sizeof(colors) / elementSize;

	mesh->setVColor(3, *colors, totalElements * elementSize);
	mesh->set_vertex_count(5);

	//fprintf(stdout, "DefaultDiamond: [%d][%d][%d] = %d\n", x, y, z, totalElements );



	return mesh;
}

mMesh * mMeshPrimitiveFactory::NdcPanel()
{
	mMesh * mesh = new mMesh();

	// POSITION
	const GLfloat position[4][3] = {
		{ 0.0,  0.0, 0.0  },
		{ 0.0,  1.0, 0.0 },
		{ 1.0,  0.0, 0.0 },
		{ 1.0,  1.0, 0.0 } };
	int elementSize = sizeof(position[0][0]);
	int totalElements = sizeof(position) / elementSize;

	mesh->setVPosition(3, *position, totalElements * elementSize);

	// TRIANGLE INDEX
	const GLuint index[2 * 3] = {
		0,1,2,
		1,2,3 };
	elementSize = sizeof(index[0]);
	totalElements = sizeof(index) / elementSize;

	mesh->setVIndex(1, index, totalElements * elementSize);

	mesh->set_vertex_count(4);
	mesh->set_triangle_count(2);

	return mesh;
}