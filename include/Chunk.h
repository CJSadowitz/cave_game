#ifndef CHUNK_H
#define CHUNK_H

#include <cstdint>

struct vec3_int16
{
	int16_t x;
	int16_t y;
	int16_t z;
	vec3_int16(int16_t x_val, int16_t y_val, int16_t z_val)
		: x(x_val), y(y_val), z(z_val) {}
	vec3_int16()
		: x(0b0000000000000000), y(0b0000000000000000), z(0b0000000000000000) {}
};

struct vec3_int8
{
	int8_t x;
	int8_t y;
	int8_t z;
	vec3_int8(int8_t x_val, int8_t y_val, int8_t z_val)
		: x(x_val), y(y_val), z(z_val) {}
	vec3_int8()
		: x(0b00000000), y(0b00000000), z(0b00000000) {}
};

struct voxel
{
	vec3_int8 pos; // 24 bits
	vec3_int16 diffuse; // 48 bits
	vec3_int16 specular_color; // 48 bits
	int8_t roughness; // 8 bits
	vec3_int16 emissive_color; // 48 bits
	int16_t alpha; // 16 bits
	int16_t metalness; // 16 bits
	vec3_int16 ambient; // 48 bits

	voxel()
		: pos(vec3_int8()), diffuse(vec3_int16()), specular_color(vec3_int16()), roughness(0b00000000),
		emissive_color(vec3_int16()), alpha(0b0000000000000000),
		metalness(0b0000000000000000), ambient(vec3_int16()) {}

}; // 256 bits

struct chunk // size = 8x8x8
{
	static const int chunk_size = 512;
	// --------------------------------------
	// Rendering
	voxel parts[chunk_size]; // 16 kb per chunk
	// --------------------------------------
	// Game Logic
	// --------------------------------------
	// biome ?
	// temperature ?
	// humidity ?
};

// Create a bunch of random data for testing purposes
chunk make_random_chunk();

// Debugging
void print_voxel_data(chunk a_chunk);
void print_vec3(vec3_int8 vec);
void print_vec3(vec3_int16 vec);
#endif
