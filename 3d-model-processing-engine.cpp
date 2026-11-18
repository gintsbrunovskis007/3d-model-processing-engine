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

	mesh.addVertex(10, 11, 12);
	mesh.addVertex(13, 14, 15);
	mesh.addVertex(16, 17, 18);

	mesh.addTriangle(0, 1, 2);
	mesh.addTriangle(3, 4, 5);

	BoundingBox box = mesh.getBoundingBox();

	std::cout << "Min: "
		<< box.minVertex.x << ", "
		<< box.minVertex.y << ", "
		<< box.minVertex.z << '\n';

	std::cout << "Max: "
		<< box.maxVertex.x << ", "
		<< box.maxVertex.y << ", "
		<< box.maxVertex.z << '\n';
		
}