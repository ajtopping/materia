#version 150
// It was expressed that some drivers required this next line to function properly
precision highp float;

in  vec2 TexCoords;
out vec4 gl_FragColor;

uniform float u_runtime_in_seconds = 0.0;
uniform ivec2 u_resolution = ivec2(1,1);
uniform vec2 u_mouse = vec2(0.0,0.0);

uniform sampler2D screenTexture;

void main()
{ 
    gl_FragColor = texture(screenTexture, TexCoords);
}