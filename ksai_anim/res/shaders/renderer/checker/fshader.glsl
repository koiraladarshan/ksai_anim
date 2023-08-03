#version 450
#pragma shader_stage(fragment)
#extension GL_EXT_debug_printf : enable

layout(location = 0) in vec3 frag_color;
layout(location = 1) in vec2 vert_texcoord;
layout(location = 2) in vec3 vert_normal;
layout(location = 3) in float vert_color;
layout(location = 4) in vec3 vert_position;
layout(location = 5) in vec3 vert_tangent;
layout(location = 6) in vec3 vert_bitangent;

layout(location = 0) out vec4 out_color;


layout(binding = 0) uniform uniform_buffer_object
{
	vec3			v1;
	vec3			v2;
	vec3			v3;

	vec3			light0;
	vec3			light1;
	vec3			light2;
	vec3			light3;
	vec3			light4;
	vec3			light5;
	vec3			light6;
	vec3			light7;
	vec3			light8;

	float			lint0;
	float			lint1;
	float			lint2;
	float			lint3;
	float			lint4;
	float			lint5;
	float			lint6;
	float			lint7;
	float			lint8;

	mat4			model;
	mat4			view;
	mat4			proj;
	vec3			view_dir;
	vec3			viwp;
} ubo;


layout(binding = 1) uniform sampler2D texSampler;


float calc_point_light(float light_intensity, vec3 light_position, vec3 frag_position, vec3 normal)
{
    float light_constant = 1.0f;
    float light_linear = 0.09f;
    float light_quadratic = 0.032f;
    float distance    = length(light_position - frag_position);
    float attenuation = 1.0 / (light_constant + light_linear * distance + light_quadratic * (distance * distance));    
    vec3 lightDir = normalize(light_position - frag_position) * light_intensity;
    float diff = max(dot(normal, lightDir), 0.0) * attenuation;
    return diff;
}


void main()
{
	/* Diffuse */
	float diffuse = 0;
	vec3 normal_vector = normalize(vert_normal);

	diffuse += calc_point_light(1.5, vec3( 4, 4, 4), vert_position, normal_vector);
	diffuse += calc_point_light(1.5, vec3( -4, 4, -4), vert_position, normal_vector);
	
	out_color = (texture(texSampler, vert_texcoord)) * diffuse;
	out_color.r += 0.5 * ubo.v2.x;
	//out_color.a += 0.5 * ubo.v2.x + 0.8;
	out_color.a = 1;
}
