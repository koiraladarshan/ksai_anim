#pragma once
#include <stdalign.h>
#include <vendor/cglm/cglm.h>
#include <string.h>
#include "init.h"


struct push_constants
{
	alignas(16) mat4		mvp;
	alignas(16) vec3		v1;
};

typedef struct l_vbs_vrtx
{
	 vec3		pos;
	 vec3		normal;
	 vec2		tex_coords;
} l_vbs_vrtx;

typedef struct uniforms
{
	alignas(16) vec3			v1;
	alignas(16) vec3			v2;
	alignas(16) vec3			v3;

	alignas(16) vec3			light0;
	alignas(16) vec3			light1;
	alignas(16) vec3			light2;
	alignas(16) vec3			light3;
	alignas(16) vec3			light4;
	alignas(16) vec3			light5;
	alignas(16) vec3			light6;
	alignas(16) vec3			light7;
	alignas(16) vec3			light8;

	alignas(4) float			lint0;
	alignas(4) float			lint1;
	alignas(4) float			lint2;
	alignas(4) float			lint3;
	alignas(4) float			lint4;
	alignas(4) float			lint5;
	alignas(4) float			lint6;
	alignas(4) float			lint7;
	alignas(4) float			lint8;


	alignas(16) mat4			model;
	alignas(16) mat4			view;
	alignas(16) mat4			proj;

	alignas(16) vec3 			view_dir;
	alignas(4) float			line_thickness;
} uniforms;

typedef enum mem_operations
{
	STAGING_BUFFER_VERTEX_ON = 1 << 0,
	STAGING_BUFFER_INDEX_ON = 1 << 1,
	STAGING_BUFFER_TEXTURE_ON = 1 << 2,
} mem_operations;



typedef 
struct pipeline_vk
{
	VkDescriptorSetLayout vk_descriptor_set_layout_;
	VkPipelineLayout vk_pipeline_layout_;
	VkPipeline vk_pipeline_;
	VkPipeline vk_pipeline_compute_;
	VkCommandPool vk_command_pool_;
	VkImage vk_texture_image_;
	VkDeviceMemory vk_texture_image_memory_;
	VkImageView vk_texture_image_view_;
	VkSampler vk_texture_image_sampler_;
	VkBuffer vk_vertex_buffer_;
	VkDeviceMemory vk_vertex_buffer_memory_;
	VkBuffer vk_index_buffer_;
	VkDeviceMemory vk_index_buffer_memory_;
	VkBuffer vk_uniform_buffer_[MAX_FRAMES_IN_FLIGHT];
	VkDeviceMemory vk_uniform_buffer_memory_[MAX_FRAMES_IN_FLIGHT];
	void* vk_uniform_buffer_mapped_region_data_[MAX_FRAMES_IN_FLIGHT];
	VkDescriptorPool vk_descriptor_pool_;
	VkDescriptorSet vk_descriptor_sets_[MAX_FRAMES_IN_FLIGHT];
	VkCommandBuffer vk_command_buffer_[MAX_FRAMES_IN_FLIGHT];
	struct uniforms ubo;
	struct l_vbs_vrtx *vertices;
	int vertices_count;
	struct push_constants pconstant;
	uint32_t* indcs;
	int indices_count;
} pipeline_vk;

void create_vulkan_pipeline(vk_rsrs* _rsrs, pipeline_vk* ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding* _descriptor_layout_binding, const char* _vshader_path, const char* _fshader_path, VkVertexInputBindingDescription* _vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription* _vertex_input_attribute_description, int _vertex_input_attribute_description_count, int _no_of_texture_images, VkImage* _texture_images, VkDeviceMemory* _texture_image_memory, VkSampler* _texture_image_sampler, VkImageView* _texture_image_view, const char** _texture_image_path, int _no_of_pool_sizes, VkDescriptorPoolSize* _pool_sizes, char staging_buffer_memory, int initial_size_factor);
void create_vulkan_pipeline2(vk_rsrs* _rsrs, pipeline_vk* ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding* _descriptor_layout_binding, const char* _vshader_path, const char* _fshader_path, VkVertexInputBindingDescription* _vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription* _vertex_input_attribute_description, int _vertex_input_attribute_description_count, int _no_of_texture_images, VkImage* _texture_images, VkDeviceMemory* _texture_image_memory, VkSampler* _texture_image_sampler, VkImageView* _texture_image_view, const char** _texture_image_path, int _no_of_pool_sizes, VkDescriptorPoolSize* _pool_sizes);
void create_vulkan_pipeline2_compute(vk_rsrs *_rsrs, pipeline_vk *ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding *_descriptor_layout_binding, const char *_vshader_path, const char *_fshader_path, const char *_cshader_path, VkVertexInputBindingDescription *_vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription *_vertex_input_attribute_description, int _vertex_input_attribute_description_count, int _no_of_texture_images, VkImage *_texture_images, VkDeviceMemory *_texture_image_memory, VkSampler *_texture_image_sampler, VkImageView *_texture_image_view, const char **_texture_image_path, int _no_of_pool_sizes, VkDescriptorPoolSize *_pool_sizes);

void pipeline_vk_destroy(pipeline_vk* _ppln);
void pipeline_vk_destroy2(pipeline_vk *_ppln);

void create_vulkan_pipeline3(vk_rsrs *_rsrs, pipeline_vk *ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding *_descriptor_layout_binding, const char *_vshader_path, const char *_fshader_path, VkVertexInputBindingDescription *_vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription *_vertex_input_attribute_description, int _vertex_input_attribute_description_count, int _no_of_pool_sizes, VkDescriptorPoolSize *_pool_sizes);

void create_vulkan_pipeline3_skybox(vk_rsrs *_rsrs, pipeline_vk *ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding *_descriptor_layout_binding, const char *_vshader_path, const char *_fshader_path, VkVertexInputBindingDescription *_vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription *_vertex_input_attribute_description, int _vertex_input_attribute_description_count, int _no_of_pool_sizes, VkDescriptorPoolSize *_pool_sizes);

void pipeline_vk_destroy3(pipeline_vk *_ppln);

void create_vulkan_pipeline3_compute(vk_rsrs *_rsrs, pipeline_vk *ppln, int _descriptor_set_layout_binding_count, VkDescriptorSetLayoutBinding *_descriptor_layout_binding, const char *_vshader_path, const char *_fshader_path, const char *_cshader_path, VkVertexInputBindingDescription *_vertex_input_binding_description, int _vertex_input_binding_description_count, VkVertexInputAttributeDescription *_vertex_input_attribute_description, int _vertex_input_attribute_description_count);

void pipeline_vk_destroy3_compute(pipeline_vk *_ppln);
