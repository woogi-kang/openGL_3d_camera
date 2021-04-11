/*------------------------------------------------------------------------
Copyright (C) 2019 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: CS250 Project1
Project: 3D Meshes
Author: Kang Tae Wook
Created: 10/04/19
------------------------------------------------------------------------*/

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <ctime>
#include <vector>
#include <iostream>
#include <sstream>
#include "Affine.h"
#include "Mesh.h"
#include "Render.h"
#include "Camera.h"
#include "SnubDodecMesh.h"
#include "CubeMesh.h"
#include "Projection.h"

using namespace std;

const Point Origin(0, 0, 0);

const Vector EX(1, 0, 0),
             EY(0, 1, 0),
             EZ(0, 0, 1);

const float PI = 4.0f * atan(1.0f);

Vector  WHITE(1, 1, 1),
		PURPLE(1, 0, 1),
		BLACK(0, 0, 0),
		RED(1, 0, 0),
		GREEN(0, 1, 0),
		PINK(255, -1.5, 255),
		YELLOW(255,255,0),
		ORANGE(255,102,51);

class SunStar : public Mesh
{
public:
	int VertexCount(void) { return 118; }
	Point GetVertex(int i) { return vertices[i]; }
	Vector Dimensions(void) { return Vector(2, 2, 2); }
	Point Center(void) { return Point(0, 0, 0); };
	int FaceCount(void) { return 224; }
	Face GetFace(int i) { return faces[i]; }
	int EdgeCount(void) { return 0; }
	Edge GetEdge(int /*i*/) { return Edge(); }

private:
    const Point vertices[118] =
	{
		Point(2.70271e-08f, 1.05146f, -3.33206e-06f), Point(0.552784f, 0.894424f, -3.33206e-06f),
		Point(0.170819f, 0.894424f, -0.525732f), Point(0.940454f, 0.470224f, -3.33206e-06f),
		Point(0.723608f, 0.552781f, -0.525732f), Point(0.290615f, 0.470224f, -0.89443f),
		Point(-0.447216f, 0.894424f, -0.324923f), Point(-0.276392f, 0.552781f, -0.850651f),
		Point(-0.760848f, 0.470224f, -0.552787f), Point(-0.447216f, 0.894424f, 0.324916f),
		Point(-0.894427f, 0.552781f, -3.33206e-06f), Point(-0.760848f, 0.470224f, 0.552786f),
		Point(0.170819f, 0.894424f, 0.525731f), Point(-0.276392f, 0.552781f, 0.850651f),
		Point(0.290615f, 0.470224f, 0.894423f), Point(0.723608f, 0.552781f, 0.525731f),
		Point(1.f, -2.72691e-06f, 0.324916f), Point(1.f, -2.72691e-06f, -0.324923f),
		Point(0.760842f, -0.47023f, 0.552786f), Point(0.894427f, -0.552786f, -3.33206e-06f),
		Point(0.760842f, -0.47023f, -0.552787f), Point(0.618035f, -2.72691e-06f, -0.850651f),
		Point(2.70271e-08f, -2.72691e-06f, -1.05147f), Point(0.276392f, -0.552786f, -0.850651f),
		Point(-0.290621f, -0.47023f, -0.89443f), Point(-0.618035f, -2.72691e-06f, -0.850651f),
		Point(-1.f, -2.72691e-06f, -0.324923f), Point(-0.723608f, -0.552786f, -0.525732f),
		Point(-0.94046f, -0.47023f, -3.33206e-06f), Point(-1.f, -2.72691e-06f, 0.324916f),
		Point(-0.618035f, -2.72691e-06f, 0.850651f), Point(-0.723608f, -0.552786f, 0.525731f),
		Point(-0.290615f, -0.47023f, 0.894423f), Point(2.70271e-08f, -2.72691e-06f, 1.05146f),
		Point(0.618035f, -2.72691e-06f, 0.850651f), Point(0.276392f, -0.552786f, 0.850651f),
		Point(2.70271e-08f, -1.05147f, -3.33206e-06f), Point(-0.170819f, -0.89443f, -0.525732f),
		Point(0.447211f, -0.89443f, -0.324923f), Point(-0.552789f, -0.89443f, -3.33206e-06f),
		Point(-0.170819f, -0.89443f, 0.525731f), Point(0.447211f, -0.89443f, 0.324916f),

		Point(-0.00569445f, 2.58421f, -5.49617e-06f), Point(2.70449f, 2.91886f, -5.49617e-06f),
		Point(-0.00569445f, 2.23786f, -0.500005f), Point(2.91412f, 2.70923f, -5.49617e-06f),
		Point(1.9143f, 2.21606f, -0.54772f), Point(-0.00569445f, 1.29163f, -0.866019f),
		Point(2.57945f, -0.000939539f, -5.49617e-06f), Point(2.23311f, -0.000939539f, -0.500005f),
		Point(1.74701f, -0.000939539f, -0.866033f), Point(-0.00569445f, -0.000939539f, -1.f),
		Point(-2.72724f, 2.90749f, -5.49617e-06f), Point(-1.92567f, 2.21606f, -0.54772f),
		Point(-2.91412f, 2.72061f, -5.49617e-06f), Point(-1.75838f, -0.000939539f, -0.866033f),
		Point(-2.24449f, -0.000939539f, -0.500005f), Point(-2.59083f, -0.000939539f, -5.49617e-06f),
		Point(-0.00569445f, 2.23786f, 0.499994f), Point(-1.92567f, 2.21606f, 0.547723f),
		Point(-0.00569445f, 1.29163f, 0.866022f), Point(-2.24449f, -0.000939539f, 0.499994f),
		Point(-1.75838f, -0.000939539f, 0.866022f), Point(-0.00569445f, -0.000939539f, 0.999993f),
		Point(1.9143f, 2.21606f, 0.547723f), Point(1.74701f, -0.000939539f, 0.866022f),
		Point(2.23311f, -0.000939539f, 0.499994f), Point(-0.00569445f, -2.58609f, -5.49617e-06f),
		Point(-0.00569445f, -2.23974f, -0.500005f), Point(2.70635f, -2.91888f, -5.49617e-06f),
		Point(-0.00569445f, -1.29351f, -0.866019f), Point(1.9143f, -2.21794f, -0.54772f),
		Point(2.91225f, -2.71298f, -5.49617e-06f), Point(-2.73137f, -2.90524f, -5.49617e-06f),
		Point(-2.90999f, -2.72662f, -5.49617e-06f), Point(-1.92567f, -2.21794f, -0.54772f),
		Point(-0.00569445f, -2.23974f, 0.499994f), Point(-0.00569445f, -1.29351f, 0.866022f),
		Point(-1.92567f, -2.21794f, 0.547723f), Point(1.9143f, -2.21794f, 0.547723f),

		Point(-1.82798f, 1.82796f, -5.49617e-06f), Point(-0.148236f, 3.98099f, -5.49617e-06f),
		Point(-1.58307f, 1.58306f, -0.500005f), Point(0.148236f, 3.98099f, -5.49617e-06f),
		Point(-0.210024f, 2.92528f, -0.54772f), Point(-0.913991f, 0.913975f, -0.866019f),
		Point(1.82798f, 1.82796f, -5.49617e-06f), Point(1.58307f, 1.58306f, -0.500005f),
		Point(1.23933f, 1.23933f, -0.866033f), Point(-6.97088e-06f, -9.53909e-06f, -1.f),
		Point(-3.981f, 0.132144f, -5.49617e-06f), Point(-2.92529f, 0.210022f, -0.54772f),
		Point(-3.981f, -0.132163f, -5.49617e-06f), Point(-1.23935f, -1.23935f, -0.866033f),
		Point(-1.58307f, -1.58308f, -0.500005f), Point(-1.82798f, -1.82798f, -5.49617e-06f),
		Point(-1.58307f, 1.58306f, 0.499994f), Point(-2.92529f, 0.210022f, 0.547723f),
		Point(-0.913991f, 0.913975f, 0.866022f), Point(-1.58307f, -1.58308f, 0.499994f),
		Point(-1.23935f, -1.23935f, 0.866022f), Point(-6.97088e-06f, -9.53909e-06f, 0.999993f),
		Point(-0.210024f, 2.92528f, 0.547723f), Point(1.23933f, 1.23933f, 0.866022f),
		Point(1.58307f, 1.58306f, 0.499994f), Point(1.82798f, -1.82798f, -5.49617e-06f),
		Point(1.58307f, -1.58308f, -0.500005f), Point(3.981f, -0.145597f, -5.49617e-06f),
		Point(0.913991f, -0.913994f, -0.866019f), Point(2.92528f, -0.210041f, -0.54772f),
		Point(3.981f, 0.145578f, -5.49617e-06f), Point(0.126296f, -3.981f, -5.49617e-06f),
		Point(-0.12631f, -3.981f, -5.49617e-06f), Point(0.210024f, -2.9253f, -0.54772f),
		Point(1.58307f, -1.58308f, 0.499994f), Point(0.913991f, -0.913994f, 0.866022f),
		Point(0.210024f, -2.9253f, 0.547723f), Point(2.92528f, -0.210041f, 0.547723f),
	};
	const Face faces[224] = 
	{
		Face(0, 1, 2), Face(1, 3, 4), Face(1, 4, 2),
		Face(2, 4, 5), Face(0, 2, 6), Face(2, 5, 7),
		Face(2, 7, 6), Face(6, 7, 8), Face(0, 6, 9),
		Face(6, 8, 10), Face(6, 10, 9), Face(9, 10, 11),
		Face(0, 9, 12), Face(9, 11, 13), Face(9, 13, 12),
		Face(12, 13, 14), Face(0, 12, 1), Face(12, 14, 15),
		Face(12, 15, 1), Face(1, 15, 3), Face(3, 16, 17),
		Face(16, 18, 19), Face(16, 19, 17), Face(17, 19, 20),
		Face(5, 21, 22), Face(21, 20, 23), Face(21, 23, 22),
		Face(22, 23, 24), Face(8, 25, 26), Face(25, 24, 27),
		Face(25, 27, 26), Face(26, 27, 28), Face(11, 29, 30),
		Face(29, 28, 31), Face(29, 31, 30), Face(30, 31, 32),
		Face(14, 33, 34), Face(33, 32, 35), Face(33, 35, 34),
		Face(34, 35, 18), Face(20, 21, 17), Face(21, 5, 4),
		Face(21, 4, 17), Face(17, 4, 3), Face(24, 25, 22),
		Face(25, 8, 7), Face(25, 7, 22), Face(22, 7, 5),
		Face(28, 29, 26), Face(29, 11, 10), Face(29, 10, 26),
		Face(26, 10, 8), Face(32, 33, 30), Face(33, 14, 13),
		Face(33, 13, 30), Face(30, 13, 11), Face(18, 16, 34),
		Face(16, 3, 15), Face(16, 15, 34), Face(34, 15, 14),
		Face(36, 37, 38), Face(37, 24, 23), Face(37, 23, 38),
		Face(38, 23, 20), Face(36, 39, 37), Face(39, 28, 27),
		Face(39, 27, 37), Face(37, 27, 24), Face(36, 40, 39),
		Face(40, 32, 31), Face(40, 31, 39), Face(39, 31, 28),
		Face(36, 41, 40), Face(41, 18, 35), Face(41, 35, 40),
		Face(40, 35, 32), Face(36, 38, 41), Face(38, 20, 19),
		Face(38, 19, 41), Face(41, 19, 18),

		Face(42, 43, 44), Face(43, 45, 46), Face(43, 46, 44),
		Face(44, 46, 47), Face(45, 48, 49), Face(45, 49, 46),
		Face(46, 49, 50), Face(46, 50, 47), Face(47, 50, 51),
		Face(42, 44, 52), Face(44, 47, 53), Face(44, 53, 52),
		Face(52, 53, 54), Face(47, 51, 55), Face(47, 55, 53),
		Face(53, 55, 56), Face(53, 56, 54), Face(54, 56, 57),
		Face(42, 52, 58), Face(52, 54, 59), Face(52, 59, 58),
		Face(58, 59, 60), Face(54, 57, 61), Face(54, 61, 59),
		Face(59, 61, 62), Face(59, 62, 60), Face(60, 62, 63),
		Face(42, 58, 43), Face(58, 60, 64), Face(58, 64, 43),
		Face(43, 64, 45), Face(60, 63, 65), Face(60, 65, 64),
		Face(64, 65, 66), Face(64, 66, 45), Face(45, 66, 48),
		Face(67, 68, 69), Face(68, 70, 71), Face(68, 71, 69),
		Face(69, 71, 72), Face(70, 51, 50), Face(70, 50, 71),
		Face(71, 50, 49), Face(71, 49, 72), Face(72, 49, 48),
		Face(67, 73, 68), Face(73, 74, 75), Face(73, 75, 68),
		Face(68, 75, 70), Face(74, 57, 56), Face(74, 56, 75),
		Face(75, 56, 55), Face(75, 55, 70), Face(70, 55, 51),
		Face(67, 76, 73), Face(76, 77, 78), Face(76, 78, 73),
		Face(73, 78, 74), Face(77, 63, 62), Face(77, 62, 78),
		Face(78, 62, 61), Face(78, 61, 74), Face(74, 61, 57),
		Face(67, 69, 76), Face(69, 72, 79), Face(69, 79, 76),
		Face(76, 79, 77), Face(72, 48, 66), Face(72, 66, 79),
		Face(79, 66, 65), Face(79, 65, 77), Face(77, 65, 63),

		Face(80, 81, 82), Face(81, 83, 84), Face(81, 84, 82),
		Face(82, 84, 85), Face(83, 86, 87), Face(83, 87, 84),
		Face(84, 87, 88), Face(84, 88, 85), Face(85, 88, 89),
		Face(80, 82, 90), Face(82, 85, 91), Face(82, 91, 90),
		Face(90, 91, 92), Face(85, 89, 93), Face(85, 93, 91),
		Face(91, 93, 94), Face(91, 94, 92), Face(92, 94, 95),
		Face(80, 90, 96), Face(90, 92, 97), Face(90, 97, 96),
		Face(96, 97, 98), Face(92, 95, 99), Face(92, 99, 97),
		Face(97, 99, 100), Face(97, 100, 98), Face(98, 100, 101),
		Face(80, 96, 81), Face(96, 98, 102), Face(96, 102, 81),
		Face(81, 102, 83), Face(98, 101, 103), Face(98, 103, 102),
		Face(102, 103, 104), Face(102, 104, 83), Face(83, 104, 86),
		Face(105, 106, 107), Face(106, 108, 109), Face(106, 109, 107),
		Face(107, 109, 110), Face(108, 89, 88), Face(108, 88, 109),
		Face(109, 88, 87), Face(109, 87, 110), Face(110, 87, 86),
		Face(105, 111, 106), Face(111, 112, 113), Face(111, 113, 106),
		Face(106, 113, 108), Face(112, 95, 94), Face(112, 94, 113),
		Face(113, 94, 93), Face(113, 93, 108), Face(108, 93, 89),
		Face(105, 114, 111), Face(114, 115, 116), Face(114, 116, 111),
		Face(111, 116, 112), Face(115, 101, 100), Face(115, 100, 116),
		Face(116, 100, 99), Face(116, 99, 112), Face(112, 99, 95),
		Face(105, 107, 114), Face(107, 110, 117), Face(107, 117, 114),
		Face(114, 117, 115), Face(110, 86, 104), Face(110, 104, 117),
		Face(117, 104, 103), Face(117, 103, 115), Face(115, 103, 101),
	};
};

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

class CameraRender
{
public:
	CameraRender(Render &r);
	~CameraRender(void);
	void SetCamera(const Camera &cam);
	void DisplayEdges(Mesh& m, const Affine& A, const Vector& color);
	void DisplayFaces(Mesh& m, const Affine& A, const Vector& color);
private:
	Render &render;
	Affine world2camera;
	Matrix camera2ndc;
	std::vector<Point> cam_vertices;
	std::vector<Point> ndc_vertices;
};

CameraRender::CameraRender(Render& r)
	: render(r)
{
}

CameraRender::~CameraRender()
{
	cam_vertices.clear();
	ndc_vertices.clear();
}

void CameraRender::SetCamera(const Camera& cam)
{
	world2camera = WorldToCamera(cam);
	camera2ndc = CameraToNDC(cam);
}

void CameraRender::DisplayEdges(Mesh& m, const Affine& A, const Vector& color)
{
	const Affine wToc = world2camera * A;
	render.SetColor(color);

	for (int i = 0; i < m.EdgeCount(); ++i)
	{
		Hcoord first = m.GetVertex(m.GetEdge(i).index1);
		Hcoord second = m.GetVertex(m.GetEdge(i).index2);

		first = wToc * first;
		second = wToc * second;

		if (first.z >= 0 || second.z >= 0)
			continue;

		first = camera2ndc * first;
		second = camera2ndc * second;

		first = (1.0f / first.w)*first;
		second = (1.0f / second.w)*second;

		render.DrawLine(first, second);
	}
}

void CameraRender::DisplayFaces(Mesh& m, const Affine& A, const Vector& color)
{
	const Affine cam2w = inverse(world2camera);
	const Point eye{ cam2w.row[0].w, cam2w.row[1].w, cam2w.row[2].w };
	const Vector light{ cam2w.row[0].z, cam2w.row[1].z, cam2w.row[2].z };

	for (int i = 0; i < m.FaceCount(); ++i)
	{
		Hcoord P = m.GetVertex(m.GetFace(i).index1);
		Hcoord Q = m.GetVertex(m.GetFace(i).index2);
		Hcoord R = m.GetVertex(m.GetFace(i).index3);

		P = A * P;
		Q = A * Q;
		R = A * R;

		Vector mVector = cross(Q - P, R - P);

		if (dot((eye - P), mVector) > 0)
		{
			P = world2camera * P;
			Q = world2camera * Q;
			R = world2camera * R;

			if (P.z >= 0 || Q.z >= 0 || R.z >= 0)
				continue;

			float mu = std::abs(dot(mVector, light)) / (abs(mVector) * abs(light));

			P = camera2ndc * P;
			P = (1.0f / P.w) * P;
			Q = camera2ndc * Q;
			Q = (1.0f / Q.w) * Q;
			R = camera2ndc * R;
			R = (1.0f / R.w) * R;

			render.SetColor(mu*color);
			render.FillTriangle(P, Q, R);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

class Client
{
public:
	Client(SDL_Window* window);
	~Client(void);
	void draw(double dt);
	void keypress(SDL_Keycode kc);
	void resize(int W, int H);

private:
	// variables for frame rate:
	SDL_Window* window;
	int frame_count;
	double frame_time;

private:
	Camera cam1, cam2, cam3, cam2_0, current_cam;
	SnubDodecMesh snub_mesh;
	CubeMesh cube_mesh;
	SunStar sun_star;
	Affine orbit2world[2], snub2world, cube2world[9];
	float snub_rot_rate;
	Vector snub_rot_axis;
	Point snub_center, orbit_center, cam2_center, cam3_center, cam3_prev_center;
	Render* render;
	CameraRender* crender;

	std::vector<Affine> polygon2world_container;
	std::vector<Affine> sunstar2world_container;

	bool x_check = false;
	bool z_check = false;

	int camera_count = 0;
	float cam3_movement = 0.f;
	float aspect = 1.f;
};

Client::Client(SDL_Window* win) : window(win)
{
	frame_count = 0;
	frame_time = 0;

	render = new Render();
	crender = new CameraRender(*render);

	snub_rot_rate = 2 * PI / 10.0f;
	snub_rot_axis = EY;
	snub_center = Point(0, 0, -3);
	
	cam2_center = Point(2, 2, -3);
	cam3_center = Point(0, 0, 0);

	cam1 = Camera(Origin + EZ, -EZ, EY, 0.5f * PI, 1, 0.01f, 10);
	cam2_0 = Camera(cam2_center, -normalize(cam2_center - snub_center), EY, 0.5f * PI, 1, 0.01f, 10);
	cam3 = Camera(cam3_center, 3 * EX, 2 * EY, 0.5f, 1, 0.001f, 20);
	cam2 = cam2_0;

	snub2world = translate(snub_center - Origin);

	for(int i =0; i < 2; ++i)
	{
		orbit2world[i] = translate(Vector(float((i % 4) - 1), 0.1f + static_cast<float>(i), -3.f))
			* scale(0.1f, 0.1f, 0.1f);
	}

	for(int i =0; i < 9; ++i)
	{
		cube2world[i] = translate(Vector(float((i % 3) - 1), -1.1f, float(-(i / 3) - 1)))
		* scale(0.375f, 0.05f, 0.375f);
	}

	Affine sunstar2world;
	for(int i = 0; i < 5; ++i)
	{
		float x = static_cast<float>(std::rand() % 7 - 5);
		float y = static_cast<float>(std::rand() % 7 - 5);
		float z = static_cast<float>(std::rand() % 7 - 7);

		sunstar2world = translate(Vector(x, y, z))
			* scale(0.2f, 0.2f, 0.2f);

		sunstar2world_container.push_back(sunstar2world);
	}

	for (int i = 0; i < 5; ++i)
	{
		float x = static_cast<float>(std::rand() % 5 );
		float y = static_cast<float>(std::rand() % 5);
		float z = static_cast<float>(std::rand() % 5 - 5);

		sunstar2world = translate(Vector(x, y, z))
			* scale(0.2f, 0.2f, 0.2f);

		sunstar2world_container.push_back(sunstar2world);
	}

	Affine polygon2world;

	for(int i = 0; i < 30; ++i)
	{
		float x = static_cast<float>(std::rand()% 5 );
		float y = static_cast<float>(std::rand()% 5 );
		float z = static_cast<float>(std::rand()% 5 -5);

		polygon2world = translate(Vector(x,y,z))
							 * scale(0.2f, 0.2f, 0.2f);

		polygon2world_container.push_back(polygon2world);
	}

	for (int i = 0; i < 30; ++i)
	{
		float x = static_cast<float>(std::rand() % 5 - 5);
		float y = static_cast<float>(std::rand() % 5 - 5);
		float z = static_cast<float>(std::rand() % 5 - 5);

		polygon2world = translate(Vector(x, y, z))
			* scale(0.2f, 0.2f, 0.2f);

		polygon2world_container.push_back(polygon2world);
	}

	for (int i = 0; i < 30; ++i)
	{
		float x = static_cast<float>(std::rand() % 5-5);
		float y = static_cast<float>(std::rand() % 5);
		float z = static_cast<float>(std::rand() % 5 - 5);

		polygon2world = translate(Vector(x, y, z))
			* scale(0.2f, 0.2f, 0.2f);

		polygon2world_container.push_back(polygon2world);
	}

	for (int i = 0; i < 30; ++i)
	{
		float x = static_cast<float>(std::rand() % 5);
		float y = static_cast<float>(std::rand() % 5-5);
		float z = static_cast<float>(std::rand() % 5 - 5);

		polygon2world = translate(Vector(x, y, z))
			* scale(0.2f, 0.2f, 0.2f);

		polygon2world_container.push_back(polygon2world);
	}
}


Client::~Client(void)
{
	polygon2world_container.clear();
	sunstar2world_container.clear();
	delete crender;
	delete render;
}


void Client::draw(double dt)
{
	++frame_count;
	frame_time += dt;
	if (frame_time >= 0.5)
	{
		double fps = frame_count / frame_time;
		frame_count = 0;
		frame_time = 0;
		stringstream ss;
		ss << "CS 250: Project #1 [fps=" << int(fps) << "]";
		SDL_SetWindowTitle(window, ss.str().c_str());
	}

	// drawing code:
	render->ClearBuffers(WHITE);

	///////////////////////////
	///////////////////////////
	//cam2 movement
	if (cam2_center.x <= -5.f)
		x_check = true;

	if (cam2_center.x >= 5.f)
		x_check = false;

	if (cam2_center.z <= -5.f)
		z_check = true;

	if (cam2_center.z >= 5.f)
		z_check = false;

	if (x_check)
		cam2_center.x += static_cast<float>(dt);
	else
		cam2_center.x -= static_cast<float>(dt);
	
	if (z_check)
		cam2_center.z += static_cast<float>(dt) / 2;
	else
		cam2_center.z -= static_cast<float>(dt) / 2;

	///////////////////////////
	//cam3 movement
	cam3_movement += static_cast<float>(dt) +0.03f;

	cam3_prev_center = cam3_center;

	cam3_center.x = sin(PI*cam3_movement / 10 + PI);
	cam3_center.y = sin(PI*cam3_movement / 15 - PI / 2);
	cam3_center.z = -sin(PI*cam3_movement / 20) -3;

	// Camera calls
	cam2 = Camera(cam2_center, -normalize(cam2_center - snub_center), EY, 0.5f * PI, aspect, 0.01f, 10);
	cam3 = Camera(cam3_center, -normalize(cam3_prev_center - cam3_center), EY, 0.5f * PI, aspect, 0.01f, 10);

	crender->DisplayFaces(sun_star, CameraToWorld(cam3)* scale(0.035f, 0.035f, 0.035f), RED);
	crender->DisplayFaces(sun_star, CameraToWorld(cam2)* scale(0.035f, 0.035f, 0.035f), RED);

	switch (camera_count)
	{
		case 0:
		{
			crender->SetCamera(cam1);
			break;
		}
		case 1:
		{
			crender->SetCamera(cam2);
			break;
		}
		case 2:
		{
			crender->SetCamera(cam3);
			break;
		}
		default:
			break;
	};


	///////////////////////////
	///////////////////////////
	// Draw calls

	orbit2world[0] = translate(snub_center - Origin)
		* rotate(3 * static_cast<float>(dt), EY)
		* translate(Origin - snub_center)
		* orbit2world[0];

	orbit2world[1] = translate(snub_center - Origin)
		* rotate(3 * static_cast<float>(dt), EZ)
		* translate(Origin - snub_center)
		* orbit2world[1];

	for (int i = 0; i < 2; ++i)
	{
		crender->DisplayFaces(cube_mesh, orbit2world[i], PURPLE);
	}

	for (int i = 0; i < 9; ++i)
	{
		crender->DisplayFaces(cube_mesh, cube2world[i], PINK);
	}

	snub2world = translate(snub_center - Origin)
			   * rotate(snub_rot_rate * static_cast<float>(dt), snub_rot_axis)
			   * translate(Origin - snub_center)
			   * snub2world;

	crender->DisplayFaces(snub_mesh, snub2world, WHITE);

	for (int i = 0; i < 120; ++i)
	{
		if (i % 2 == 1)
			crender->DisplayFaces(cube_mesh, polygon2world_container[i], PURPLE);
		if (i % 3 == 1)
			crender->DisplayFaces(cube_mesh, polygon2world_container[i], GREEN);
	}

	for(int i = 0; i < 10; ++i)
	{
		crender->DisplayFaces(sun_star, sunstar2world_container[i], RED);
	}
}

void Client::keypress(SDL_Keycode kc)
{
	switch (kc) 
	{
	case SDLK_SPACE:
	{
		++camera_count;
		if (camera_count == 3)
			camera_count = 0;
		break;
	}
	case SDLK_4:
		cam2 = cam2_0;
	}
}

void Client::resize(int W, int H)
{
	glViewport(0, 0, W, H);
	aspect = float(W) / float(H);
}

/////////////////////////////////////////////////////////////////
int main(int /*argc*/, char* /*argv*/[])
{
	srand(unsigned(time(nullptr)));

	// SDL: initialize and create a window
	SDL_Init(SDL_INIT_VIDEO);
	const char* title = "CS250: Project #1";
	int width = 1280, height = 1024;
	SDL_Window* window =
		SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		                 width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	SDL_GLContext context = SDL_GL_CreateContext(window);

	// GLEW: get function bindings (if possible)
	glewInit();
	if (!GLEW_VERSION_2_0)
	{
		cout << "needs OpenGL version 3.0 or better" << endl;
		return -1;
	}

	// animation loop
	try
	{
		bool done = false;
		Client* client = new Client(window);
		Uint32 ticks_last = SDL_GetTicks();
		while (!done)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					done = true;
					break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
						done = true;
					else
						client->keypress(event.key.keysym.sym);
					break;
				case SDL_WINDOWEVENT:
					if (event.window.event == SDL_WINDOWEVENT_RESIZED)
						client->resize(event.window.data1, event.window.data2);
					break;
				}
			}
			Uint32 ticks = SDL_GetTicks();
			double dt = 0.001 * (ticks - ticks_last);
			ticks_last = ticks;
			client->draw(dt);
			SDL_GL_SwapWindow(window);
		}
		delete client;
	}

	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}
