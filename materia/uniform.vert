#version 150
// in_Position was bound to attribute index 0 and in_Color was bound to attribute index 1
in  vec3 in_Position;
in  vec3 in_Color;

// Identity matrix
uniform mat4 u_mvp = mat4(1.0);

uniform float u_runtime_in_seconds = 0.0;
uniform ivec2 u_resolution = ivec2(1,1);

// We output the ex_Color variable to the next shader in the chain
out vec3 ex_Color;
void main(void) {
    // Since we are using flat lines, our input only had two points: x and y.
    // Set the Z coordinate to 0 and W coordinate to 1
	//float xy_window_ratio = u_resolution.x / u_resolution.y;
	//vec3 normalized_position = in_Position / vec3(1.0,xy_window_ratio, 1.0);

	vec4 model_to_world_position = u_mvp * vec4(in_Position, 1.0);
    gl_Position = model_to_world_position;

    // GLSL allows shorthand use of vectors too, the following is also valid:
    // gl_Position = vec4(in_Position, 0.0, 1.0);

    // We're simply passing the color through unmodified
	vec3 new_Color = gl_Position.xyz;
    ex_Color = new_Color;
}