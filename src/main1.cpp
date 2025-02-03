#include <vector>
#include <cstdint>
#include <iostream>
#include <math.h>
#include <fstream>
#include "geometry.h"

using std::vector;

static const float inchToMM = 25.4;


float near_plane = 1.0;
float filmApertureWidth = 0.980;
float filmApertureHeight = 0.735;
const unsigned int width = 800;
const unsigned int height = 600;
float focal_length = 20; // mm


template<typename T>
class Vec3 {
    private:
        T x,y,z;
    public:
        Vec3() {};
        Vec3(T e) : x(e), y(e), z(e) {};
        Vec3(T e0, T e1, T e2) : x(e0), y(e1), z(e2) {};

        T& operator[] (uint8_t i) {return (&x)[i]; }

        Vec3<T> operator- (Vec3<T> rhs) {
            Vec3<T> tmp;
            tmp[0] = x - rhs[0];
            tmp[1] = y - rhs[1];
            tmp[2] = z - rhs[2];
            return tmp;
        }

        float magnitude() {
            return std::sqrt(x*x + y*y + z*z);
        }

        Vec3<T> normalize() {
            Vec3<T> tmp;
            float mag = magnitude();
            tmp[0] = x/mag;
            tmp[1] = y/mag;
            tmp[2] = z/mag;
            return tmp;
        }

        Vec3<T> crossProduct(Vec3<T> &rhs) { // passing in a reference
            Vec3<T> tmp;
            tmp[0] = y * rhs[2] - z * rhs[1];
            tmp[1] = z * rhs[0] - x * rhs[2];
            tmp[2] = x * rhs[1] - y * rhs[0];
            return tmp;
        }

        float dotProduct(Vec3<T> &rhs) {
            // need angle between them
            // this assumes that thye come from teh same origin
            // component-wise multiplication then add together. 
            return x * rhs[0] + y * rhs[1] + z * rhs[2];
        }

        void print() {
            std::cout << x <<std::endl;
            std::cout << y <<std::endl;
            std::cout << z <<std::endl;
        } 

        T getX() {
            return x;
        }

        T getY() {
            return y;
        }

        T getZ() {
            return z;
        }
};

template<typename T>
class Vec4 {
    private:
        T x,y,z,w;
    public:
        Vec4() {};
        Vec4(Vec3<T> v, T e3) : x(v.getX()), y(v.getY()), z(v.getZ()), w(e3) {};
        Vec4(T e0, T e1, T e2, T e3) : x(e0), y(e1), z(e2), w(e3)  {};
        T& operator [] (uint8_t i) {return (&x)[i]; }
        void print() {
            std::cout << x <<std::endl;
            std::cout << y <<std::endl;
            std::cout << z <<std::endl;
            std::cout << w <<std::endl;
        }
};



template<typename T>
class Mat4 {
    private:
    // need to be a 4 x 4 array
    // lets build a translation and rotation matrix, then multiply...
    // how to contructor a 4 x 4...
    // overload the index operator
    // overload multiplication
    // multplication for vectors
        T matrix[16];
    public:

        void identity() {
            matrix[0] = 1;
            matrix[1] = 0;
            matrix[2] = 0;
            matrix[3] = 0;
            matrix[4] = 0;
            matrix[5] = 1;
            matrix[6] = 0;
            matrix[7] = 0;
            matrix[8] = 0;
            matrix[9] = 0;
            matrix[10] = 1;
            matrix[11] = 0;
            matrix[12] = 0;
            matrix[13] = 0;
            matrix[14] = 0;
            matrix[15] = 1;
        }

        T& operator[] (uint8_t i) {return (matrix)[i];}

        // hould this be a reference type?
        Mat4<T> operator* (Mat4<T> rhs) {


            Mat4<T> tmp;

            // 1st col
            tmp[0] = matrix[0] * rhs[0] + matrix[1] * rhs[4] + matrix[2] * rhs[8] + matrix[3] * rhs[12];
            tmp[4] = matrix[4] * rhs[0] + matrix[5] * rhs[4] + matrix[6] * rhs[8] + matrix[7] * rhs[12];
            tmp[8] = matrix[8] * rhs[0] + matrix[9] * rhs[4] + matrix[10] * rhs[8] + matrix[11] * rhs[12];
            tmp[12] = matrix[12] * rhs[0] + matrix[13] * rhs[4] + matrix[14] * rhs[8] + matrix[15] * rhs[12];

            // 2nd col
            tmp[1] = matrix[0] * rhs[1] + matrix[1] * rhs[5] + matrix[2] * rhs[9] + matrix[3] * rhs[13];
            tmp[5] = matrix[4] * rhs[1] + matrix[5] * rhs[5] + matrix[6] * rhs[9] + matrix[7] * rhs[13];
            tmp[9] = matrix[8] * rhs[1] + matrix[9] * rhs[5] + matrix[10] * rhs[9] + matrix[11] * rhs[13];
            tmp[13] = matrix[12] * rhs[1] + matrix[13] * rhs[5] + matrix[14] * rhs[9] + matrix[15] * rhs[13];

            // 3nd col
            tmp[2] = matrix[0] * rhs[2] + matrix[1] * rhs[6] + matrix[2] * rhs[10] + matrix[3] * rhs[14];
            tmp[6] = matrix[4] * rhs[2] + matrix[5] * rhs[6] + matrix[6] * rhs[10] + matrix[7] * rhs[14];
            tmp[10] = matrix[8] * rhs[2] + matrix[9] * rhs[6] + matrix[10] * rhs[10] + matrix[11] * rhs[14];
            tmp[14] = matrix[12] * rhs[2] + matrix[13] * rhs[6] + matrix[14] * rhs[10] + matrix[15] * rhs[14];
 
            // 4th col
            tmp[3] = matrix[0] * rhs[3] + matrix[1] * rhs[7] + matrix[2] * rhs[11] + matrix[3] * rhs[15];
            tmp[7] = matrix[4] * rhs[3] + matrix[5] * rhs[7] + matrix[6] * rhs[11] + matrix[7] * rhs[15];
            tmp[11] = matrix[8] * rhs[3] + matrix[9] * rhs[7] + matrix[10] * rhs[11] + matrix[11] * rhs[15];
            tmp[15] = matrix[12] * rhs[3] + matrix[13] * rhs[7] + matrix[14] * rhs[11] + matrix[15] * rhs[15];

            return tmp;
        }

        Vec4<T> operator* (Vec4<T> rhs) {
            // returning new with move vs by refernce. less dependence on compiler implementation.

            Vec4<T> tmp;

            tmp[0] = rhs[0] * matrix[0] + rhs[1] * matrix[1] + rhs[2]  * matrix[2] + rhs[3] * matrix[3];
            tmp[1] = rhs[0] * matrix[4] + rhs[1] * matrix[5] + rhs[2]  * matrix[6] + rhs[3] * matrix[7];
            tmp[2] = rhs[0] * matrix[8] + rhs[1] * matrix[9] + rhs[2]  * matrix[10] + rhs[3] * matrix[11];
            tmp[3] = rhs[0] * matrix[12] + rhs[1] * matrix[13] + rhs[2]  * matrix[14] + rhs[3] * matrix[15];

            // might divide all by vector

            return tmp;
        }

        Mat4<T> invert() {
            // rows be come columns and columns become rows.
            Mat4<T> tmp;

            tmp[0] = matrix[0];
            tmp[1] = matrix[4];
            tmp[2] = matrix[8];
            tmp[3] = matrix[12];
            tmp[4] = matrix[1];
            tmp[5] = matrix[5];
            tmp[6] = matrix[9];
            tmp[7] = matrix[13];
            tmp[8] = matrix[2];
            tmp[9] = matrix[6];
            tmp[10] = matrix[10];
            tmp[11] = matrix[14];
            tmp[12] = matrix[3];
            tmp[13] = matrix[7];
            tmp[14] = matrix[11];
            tmp[15] = matrix[15];

            return tmp;
        }

        void print() {
            for (int i = 0; i < 16; ++i) {
                std::cout << matrix[i] << "\t"; // Print the element with a tab
                if ((i + 1) % 4 == 0) {   // Move to the next line after every 4 elements
                    std::cout << std::endl;
                }
            }
        }
};

class Triangle {
    private:
        Vec3<float> v1,v2,v3;
    public:
        Triangle(Vec3<float> e0, Vec3<float> e1, Vec3<float> e2) : v1(e0), v2(e1), v3(e2) {};
        Vec3<float> getV1() { return v1 ;}
        Vec3<float> getV2() { return v2 ;}
        Vec3<float> getV3() { return v3 ;}
};

void computeScreenBoundaries(
    const float &filmApertureHeight,
    const float &filmApertureWidth,
    const float &nearClippingPlane,
    const float &focalLength,
    float &top, float &bottom, float &right, float& left
) {

    top = ((filmApertureHeight * inchToMM / 2) / focalLength) * nearClippingPlane;
    right = ((filmApertureWidth * inchToMM / 2) / focalLength) * nearClippingPlane;
    bottom = -top;
    left = -right;
}

void computeRasterCoordinates (
    Vec2<float>& vScreen,
    Vec2<float>& vRaster,
    float& r,
    float& l,
    float& t,
    float& b
) {
        Vec2<float> vNDC = Vec2<float>(
            (2 * vScreen[0] / (r - l)) - (l + r) / (r-l),
            (2 * vScreen[1] / (t - b)) - (t + b) / (t-b)
        );

        vRaster[0] = (vNDC[0] + 1) / 2 * width;
        vRaster[1] = (1 - vNDC[1]) / 2 * height;
}

void computePerspectiveDivide(Vec4<float>& vCamera, Vec2<float>& vScreen) {
        vScreen[0] = -near_plane * vCamera[0] / vCamera[2];
        vScreen[1] = -near_plane * vCamera[1] / vCamera[2];
}

bool edgeFunction(Vec2<float> &a, Vec2<float> &b, Vec2<float> &c) {
    return ((c[0] - a[0]) * (b[1]-a[1]) - (c[1] -a[1]) * (b[0] - a[0]) >= 0);
}


vector<Triangle> triangles;
Vec3<float> camera_pos = Vec3<float>(0.0, 0.0, 3.0); // posotive z-axis points twoard the viewer...? 

int main() {

/*
    Rastierzation is the process of solving the hidden body pr
    blem. We are trying to determine what can we see from the perspective 
    of our camera. 

    breaking this down further, its clear that there are a few componenets: the mesh of triangles that make up our object and the camera object itself.
    These exist in 3D world space.     

    I think usually you would import your verticies from a list or object file.
*/


    // heap allocated framebuffer
    Vec3<unsigned char> *frameBuffer = new Vec3<unsigned char>[width * height];
    for (uint32_t i = 0; i < width * height; ++i) {
		frameBuffer[i] = Vec3<unsigned char>(255);
	}

    // world space
    Triangle t1 = Triangle(
        Vec3<float>(1.0, -0.5, 0),
        Vec3<float>(0, 1.0, 0),
        Vec3<float>(-1.0, -0.5, 0)
    );

    Triangle t2 = Triangle(
        Vec3<float>(-1.25, 0.0, 0.0),
        Vec3<float>(-1.5, 0.5, 0.0),
        Vec3<float>(-1.75, 0.0, 0.0)
    );

    triangles.push_back(t1);
    triangles.push_back(t2);

    /*
        1. build the view matrix
            - translation matrix -> inverted eye position

    */

   // maybe throw in a camera class ?

   Mat4<float> view_translation;
   view_translation.identity();
   view_translation[3] = -camera_pos[0];
   view_translation[7] = -camera_pos[1];
   view_translation[11] = -camera_pos[2];

   Mat4<float> view_rotate;
   view_rotate.identity();
   Vec3<float> forward = (camera_pos - Vec3<float>(0.0,0.0,0.0)).normalize();
   Vec3<float> left = Vec3<float>(0.0,1.0,0.0).crossProduct(forward);
   Vec3<float> up = forward.crossProduct(left);
   view_rotate[0] = left[0];
   view_rotate[1] = up[0];
   view_rotate[2] = forward[0];
   view_rotate[4] = left[1];
   view_rotate[5] = up[1];
   view_rotate[6] = forward[1];
   view_rotate[8] = left[2];
   view_rotate[9] = up[2];
   view_rotate[10] = forward[2];
   view_rotate = view_rotate.invert();
   Mat4<float> view = view_rotate * view_translation;

    for (Triangle triangle : triangles) {

        /*
            1. convert the verticies from world space, to camera space (withing the frustum)
                * why do we do this? why not just leave the cooridnates in world space? 
                * because of perspective divide. It only makes sense from the perspective of the camera (similarity of triangles)
                * we need the to multiply by the view matrix (worldToView)
        
        */

        Vec4<float> v0camera = view * Vec4<float>(triangle.getV1(), 1.0);
        Vec4<float> v1camera = view * Vec4<float>(triangle.getV2(), 1.0);
        Vec4<float> v2camera = view * Vec4<float>(triangle.getV3(), 1.0);

        Vec2<float> v0Screen;
        Vec2<float> v1Screen;
        Vec2<float> v2Screen;

        computePerspectiveDivide(v0camera, v0Screen);
        computePerspectiveDivide(v1camera, v1Screen);
        computePerspectiveDivide(v2camera, v2Screen);


        float t,b,r,l;
        computeScreenBoundaries(filmApertureHeight, filmApertureWidth, near_plane, focal_length, t,b,r,l);


        Vec2<float> v0Raster;
        Vec2<float> v1Raster;
        Vec2<float> v2Raster;
        computeRasterCoordinates(v0Screen, v0Raster, r, l, t ,b);
        computeRasterCoordinates(v1Screen, v1Raster, r, l, t ,b);
        computeRasterCoordinates(v2Screen, v2Raster, r, l, t ,b);

        float xmin = std::min(v2Raster[0], std::min(v0Raster[0], v1Raster[0]));
        float ymin = std::min(v2Raster[1], std::min(v0Raster[1], v1Raster[1]));
        float xmax = std::max(v2Raster[0], std::max(v0Raster[0], v1Raster[0]));
        float ymax = std::max(v2Raster[1], std::max(v0Raster[1], v1Raster[1]));

        std::cout << "width: " << width << std::endl;
        std::cout << "height: " << height << std::endl;
        std::cout << "xmin: " << xmin << " ymin: " << ymin << std::endl;
        std::cout << "xmax: " << xmax << " ymax: " << ymax << std::endl;

        if (xmax < 0 || ymax < 0 || xmin > width - 1 || ymin > height) {continue;}


        // iterating through a bounding box to perform a sligh optimization on the overall rasterization process
        uint32_t x0 = std::max(int32_t(0), (int32_t)(std::floor(xmin)));
        uint32_t x1 = std::min(int32_t(width) - 1, (int32_t)(std::floor(xmax)));
        uint32_t y0 = std::max(int32_t(0), (int32_t)(std::floor(ymin)));
        uint32_t y1 = std::min(int32_t(height) - 1, (int32_t)(std::floor(ymax)));

        int count = 0;

        std::cout << "y0: " << y0 << " y1: " << y1 << std::endl;
        std::cout << "x0: " << x0 << " x1: " << x1 << std::endl;

        int32_t maxy = 0;
        // those points are not passing hte edge funciton for some reason

        for (uint32_t y = y0; y <= y1; ++y) {
            for (uint32_t x = x0; x <= x1; ++x) {
                Vec2<float> sample(x + 0.5, y + 0.5);
                bool inside = true;
                inside &= edgeFunction(v0Raster, v1Raster, sample);
                inside &= edgeFunction(v1Raster, v2Raster, sample);
                inside &= edgeFunction(v2Raster, v0Raster, sample);
                if (inside) {
                    maxy = std::max(int32_t(y), maxy);
                    frameBuffer[y * width + x][0] = 124;
                    frameBuffer[y * width + x][1] = 252;
                    frameBuffer[y * width + x][2] = 0;
                }

            }
        }
        std::cout << "max passing y: " << maxy << std::endl;

    }

    std::cout << "done" << std::endl;


    std::ofstream ofs;
	ofs.open("./output.ppm", std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	ofs.write((char*)frameBuffer, width * height * 3);
	ofs.close();

}