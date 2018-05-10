
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

varying vec4 v_color;
  #define PI 3.14159

vec3 hsv2rgb(vec3 c) {
  c = vec3(c.x, clamp(c.yz, 0.0, 1.0));
  vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
  vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
  return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main() {gl_PointSize=1.0;
  float NUM_SEGMENTS = floor(mix(3., 10., 0.5 + 0.5 * sin(PI * 2. * fract(time * 0.1))));
  float NUM_POINTS = NUM_SEGMENTS * 2.;
  float STEP = 1.;
  float point = mod(floor(vertexId / 2.0) + mod(vertexId, 2.0) * STEP, NUM_SEGMENTS);
  float count = floor(vertexId / NUM_POINTS);
  float snd = texture2D(sound, vec2(0.05, count * 0.0)).a;
  float offset = count * 0.0;
  float angle = point * PI * 2.0 / NUM_SEGMENTS + offset  + time * 0.2;
  float radius = 2.5;
  float c = cos(angle) * radius;
  float s = sin(angle) * radius;
  float orbitAngle =  count * 0.0;
  float innerRadius = count * 0.0;
  float oC = cos(orbitAngle + time * 0.4 + count * 0.1) * innerRadius;
  float oS = sin(orbitAngle + time + count * 0.1) * innerRadius;

  vec2 aspect = vec2(resolution.y / resolution.x, 1);

  vec4 m = texture2D(touch, vec2(0.0, count * 0.00));
  vec2 xy = vec2(c, s) + vec2(oC, oS) + m.xy * .5;// + vec2(2. * snd, 0.);
  gl_Position = vec4(xy * aspect, count * 0.1, count * 0.2);

  float stripe = 
    mix(0.0, 1.5, step(
      0.5, fract(time * 4. + count * .025)));
  float hue = time * 0.25;
  float sat = 1. - snd;
  float val = stripe;
  v_color = vec4(hsv2rgb(vec3(hue, sat, val)), 0.1);
;gl_PointSize = max(0., gl_PointSize*_dontUseDirectly_pointSize);
}