#include "Chunk.h"
#include <cmath>
#include <iostream>

// Logic for chunk generation
// I cannot wait to be stuck in this file for years :)
// Could do something with wave function collapse
// I am not going to worry about minecraft's ability to generate the same seeds
// It would be kind of cool if I could have the player influence the wavefunction collapse
// such that their actions actively changed the world they play in
// This would be beyond oh I built a cool thing, to oh my action directly changes what things
// are going to be generated, new biomes and such.

chunk make_random_chunk()
{
	// generate 512 voxels to populate this chunk
	chunk new_chunk;

	int size = int(cbrt(new_chunk.chunk_size));
	int voxel_index = 0;
	int8_t x_len = 0b00000000;
	for (int i = 0; i < size; i++)
	{
		int8_t y_len = 0b00000000;
		for (int j = 0; j < size; j++)
		{
			int8_t z_len = 0b00000000;
			for (int k = 0; k < size; k++)
			{
				// Assign properties for each voxel
				new_chunk.parts[voxel_index].pos = vec3_int8(x_len, y_len, z_len);
				voxel_index++;
				z_len++;
			}
			y_len++;
		}
		x_len++;
	}
	return new_chunk;
}

// ------------------------------------------------------------------------------------------------------------------------------------
// Debugging

void print_vec3_int8(vec3_int8 vec)
{
	std::cout << int(vec.x) << ' ' << int(vec.y) << ' ' << int(vec.z) << std::endl;
}

void print_vec3_int16(vec3_int16 vec)
{
	std::cout << int(vec.x) << ' ' << int(vec.y) << ' ' << int(vec.z) << std::endl;
}

void print_voxel_data(chunk a_chunk)
{
	int size = a_chunk.chunk_size;
	for (int i = 0; i < size; i++)
	{
		voxel a_voxel = a_chunk.parts[i];
		std::cout << "Position: ";
		print_vec3_int8(a_voxel.pos);
		std::cout << "Diffuse: ";
		print_vec3_int16(a_voxel.diffuse);
		std::cout << "Specular Color: ";
		print_vec3_int16(a_voxel.specular_color);
		std::cout << "Roughness: " << a_voxel.roughness << std::endl;
		std::cout << "Emissive Color: ";
		print_vec3_int16(a_voxel.emissive_color);
		std::cout << "Alpha: " << a_voxel.alpha << std::endl;
		std::cout << "Metal: " << a_voxel.metalness << std::endl;
		print_vec3_int16(a_voxel.ambient);
	}
}
