#pragma once

#include <vector>
#include "Vertex.h"
#include "Triangle.h"
#include "BoundingBox.h"
#include <algorithm>
#include <limits>


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

	Vertex getCenter() const {

		if (vertices.empty()) {
			return { 0.0f, 0.0f, 0.0f };
		}

		float x_count = 0.0f;
		float y_count = 0.0f;
		float z_count = 0.0f;
		for (const Vertex& vertex : vertices) {
			x_count += vertex.x;
			y_count += vertex.y;
			z_count += vertex.z;
		}

		Vertex center;
		center.x = x_count / vertices.size();
		center.y = y_count / vertices.size();
		center.z = z_count / vertices.size();

		return center;
	}

	//BoundingBox getBoundingBox() const{

	//	float minX = 0.0f;
	//	float minY = 0.0f;
	//	float minZ = 0.0f;

	//	float maxX = 0.0f;
	//	float maxY = 0.0f;
	//	float maxZ = 0.0f;

	//	for (const Vertex& vertex : vertices) {
	//		if (vertex.x < minX) {
	//			minX = vertex.x;
	//		} 
	//		if (vertex.y < minY) {
	//			minY = vertex.y;
	//		}
	//		if (vertex.z < minZ) {
	//			minZ = vertex.z;
	//		}

	//		if (vertex.x >= maxX) {
	//			maxX = vertex.x;
	//		}
	//		if (vertex.y >= maxY) {
	//			maxY = vertex.y;
	//		}
	//		if (vertex.z >= maxZ) {
	//			maxZ = vertex.z;
	//		}
	//		
	//	}

	//	Vertex minVertex = { minX, minY, minZ };
	//	Vertex maxVertex = { maxX, maxY, maxZ };

	//	BoundingBox boundingBox = { minVertex, maxVertex };

	//	return boundingBox;
	//}

	BoundingBox getBoundingBox() const {

		if (vertices.empty()) {
			throw std::runtime_error("Cannot calculate bounding box of empty geometry");
		}

		float minX = std::numeric_limits<float>::max();
		float minY = std::numeric_limits<float>::max();
		float minZ = std::numeric_limits<float>::max();

		float maxX = std::numeric_limits<float>::lowest();
		float maxY = std::numeric_limits<float>::lowest();
		float maxZ = std::numeric_limits<float>::lowest();

		for (const Vertex& vertex : vertices) {
			minX = std::min(minX, vertex.x);
			minY = std::min(minY, vertex.y);
			minZ = std::min(minZ, vertex.z);

			maxX = std::max(maxX, vertex.x);
			maxY = std::max(maxY, vertex.y);
			maxZ = std::max(maxZ, vertex.z);
		}

		Vertex minVertex = { minX, minY, minZ };
		Vertex maxVertex = { maxX, maxY, maxZ };

		return { minVertex, maxVertex };
	}

};