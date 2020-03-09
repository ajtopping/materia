#version 150
// It was expressed that some drivers required this next line to function properly
precision highp float;

in  vec3 ex_Color;
out vec4 gl_FragColor;

uniform float u_runtime_in_seconds = 0.0;
uniform ivec2 u_resolution = ivec2(1,1);
uniform vec2 u_mouse = vec2(0.0,0.0);

void main(void) {
    // Pass through our original color with full opacity.
	//vec3 sin_Color = vec3((sin(u_runtime_in_seconds)+1.0)/2.0, 1.0, 1.0);
	vec3 sin_Color = ex_Color * sin(u_runtime_in_seconds) + 0.5;
    gl_FragColor = vec4(sin_Color,1.0);
}