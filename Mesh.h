#pragma once

#include <vector>
#include "Vertex.h"
#include "Triangle.h"

class Mesh {
private:
	std::vector<Vertex> vertices;
	std::vector<Triangle> triangles;

public:
	void addVertex(float x, float y, float z) {
		Vertex vertex = { x, y, z };
		vertices.push_back(vertex);
	}
	void addTriangle(int a, int b, int c) {
		Triangle triangle = { a, b, c };
		triangles.push_back(triangle);
	}

	const Vertex& getVertex(size_t index) const {
		return vertices.at(index);
	}

	const Triangle& getTriangle(size_t index) const {
		return triangles.at(index);
	}
};