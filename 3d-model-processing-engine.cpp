#include <iostream>
#include "Vertex.h"
#include "Triangle.h"
#include "Mesh.h"

int main()
{

	//Vertex vertices[3] = {
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 9}
	//};

	Mesh mesh;

	mesh.vertices.push_back({1, 2, 3});
	mesh.vertices.push_back({4, 5, 6});
	mesh.vertices.push_back({7, 8, 9});

	Triangle triangle = { 0,1,2 };
	mesh.triangles.push_back(triangle);

	std::cout << "Vertices: " << mesh.vertices.size() << ". \n";
	std::cout << "Triangles: " << mesh.triangles.size() << ". \n";

}