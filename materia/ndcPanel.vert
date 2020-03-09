#version 150
// in_Position was bound to attribute index 0 and in_Color was bound to attribute index 1
in  vec3 in_Position;
in  vec2 in_TexCoords;

// Identity matrix
uniform mat4 u_mvp = mat4(1.0);

uniform float u_runtime_in_seconds = 0.0;
uniform ivec2 u_resolution = ivec2(1,1);

out vec2 TexCoords;

void main()
{
    //gl_Position = vec4(in_Position.x, in_Position.y, in_Position.z, 1.0);
	vec4 model_to_world_position = u_mvp * vec4(in_Position, 1.0);
    gl_Position = model_to_world_position;
    TexCoords = vec2(in_Position.x, in_Position.y);
}  