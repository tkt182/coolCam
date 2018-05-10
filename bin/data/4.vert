
attribute float vertexId;

uniform vec2 mouse;
uniform vec2 resolution;
uniform vec4 background;
uniform float time;
uniform float vertexCount;
uniform sampler2D sound;
uniform sampler2D floatSound;
uniform sampler2D touch;
uniform vec2 soundRes;
uniform float _dontUseDirectly_pointSize;
uniform mat4 rotation;

varying vec4 v_color;

#define PI 3.14159

//float hash( float n ) { return fract(sin(n)*753.5453123); }
float hash( float n ) { return fract(sin(n)); }

void main() {
 
  float i = hash(vertexId);
  float f = hash(i);

  float ang = vertexId / 1000.;
  float perspective = .3 * (1.);
  float t = time * (f + .1);

  float x = i * sin(ang + t) * .8; 
  float y = i * cos(ang + t);
  y +=  .1 * (1. - y); 
  y *= perspective;

  gl_Position = vec4(x, y, 0., 1.);

  v_color = vec4(1.0);

}