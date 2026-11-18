#pragma once

#include <vector>;
#include "Vertex.h";
#include "Triangle.h";

class Mesh {
public:
	std::vector<Vertex> vertices;
	std::vector<Triangle> triangles;
};