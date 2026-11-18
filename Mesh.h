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
		if (a >= 0 && b >= 0 && c >= 0 && a < vertices.size() && b < vertices.size() && c < vertices.size()) {
			Triangle triangle = { a, b, c };
			triangles.push_back(triangle);
		}
	}

	const Vertex& getVertex(size_t index) const {
		return vertices.at(index);
	}

	const Triangle& getTriangle(size_t index) const {
		return triangles.at(index);
	}

	void printVertices() const {
		for (const Vertex& vertex : vertices) {
			std::cout << vertex.x << ", " << vertex.y << ", " << vertex.z << ". " << std::endl;
		}
	}

	void printTriangles() const {
		for (const Triangle& triangle : triangles) {
			std::cout << triangle.a << ", " << triangle.b << ", " << triangle.c << ". " << std::endl;
		}
	}

	const std::vector<Vertex>& getVertices() const {
		return vertices;
	}

	const std::vector<Triangle>& getTriangles() const{
		return triangles;
	}

};