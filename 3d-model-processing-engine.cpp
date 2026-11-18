#include <iostream>
#include "Vertex.h";
#include "Triangle.h";

int main()
{

	Vertex vertexes[3] = {
		{1, 1, 1},
		{2, 2, 2},
		{3, 3, 3}
	};

	Triangle triangle = {0,1,2};

	Vertex a = vertexes[triangle.a];
	Vertex b = vertexes[triangle.b];
	Vertex c = vertexes[triangle.c];

	std::cout << a.x << ", " << a.y << ", " << a.z;

}