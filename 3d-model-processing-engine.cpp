#include <iostream>
#include "Vertex.h"
#include "Triangle.h"
#include "Mesh.h"

int main()
{

	Mesh mesh;

	mesh.addVertex(1, 2, 3);
	mesh.addVertex(4, 5, 6);
	mesh.addVertex(7, 8, 9);

	mesh.addTriangle(0, 1, 2);

	const Vertex& v = mesh.getVertex(0);
	std::cout << v.x << v.y << v.z << std::endl;

	const Triangle& t = mesh.getTriangle(0);
	std::cout << t.a << t.b << t.c << std::endl;



}