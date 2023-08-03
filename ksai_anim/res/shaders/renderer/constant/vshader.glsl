#version 450
#pragma shader_stage(vertex)
#extension GL_EXT_debug_printf : enable

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormal;
layout(location = 2) in vec3 inColor;
layout(location = 3) in vec3 inTangent;
layout(location = 4) in vec3 inBitTangent;
layout(location = 5) in vec2 inTexCoord;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 vert_texcoord;
layout(location = 2) out vec3 vert_normal;
layout(location = 3) out vec3 vert_color;
layout(location = 4) out vec3 vert_position;
layout(location = 5) out vec3 vert_tangent;
layout(location = 6) out vec3 vert_bitangent;

layout(binding = 0) uniform uniform_buffer_object
{
	vec3			v1;
	vec3			v2;
	vec3			v3;
	mat4			model;
	mat4			view;
	mat4			proj;
} ubo;

layout(push_constant, std430) uniform pc {
    mat4 mvp;
    vec3 v1;
} push;


void main() {
    gl_Position = push.mvp * vec4(inPosition, 1.0);
    gl_Position.y = - gl_Position.y;
    vert_color = ubo.v1;
}
