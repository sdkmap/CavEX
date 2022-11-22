#ifndef GFX_H
#define GFX_H

#include <stdbool.h>
#include <stdint.h>

#include "../../cglm/cglm.h"

enum gfx_blend {
	MODE_BLEND,
	MODE_INVERT,
	MODE_OFF,
};

enum gfx_texture {
	TEXTURE_TERRAIN,
	TEXTURE_FONT,
	TEXTURE_ANIM,
	TEXTURE_GUI,
	TEXTURE_GUI2,
};

void gfx_setup(void);
void gfx_update_light(float daytime);
void gfx_finish(bool vsync);
void gfx_flip_buffers(float* gpu_wait, float* vsync_wait);
void gfx_bind_texture(enum gfx_texture tex);
void gfx_clear_buffers(uint8_t r, uint8_t g, uint8_t b);
int gfx_width(void);
int gfx_height(void);

void gfx_matrix_projection(mat4 proj, bool is_perspective);
void gfx_matrix_modelview(mat4 mv);
void gfx_matrix_texture(bool enable, mat4 tex);

void gfx_mode_world(void);
void gfx_mode_gui(void);
void gfx_blending(enum gfx_blend mode);
void gfx_alpha_test(bool enable);
void gfx_write_buffers(bool color, bool depth);
void gfx_texture(bool enable);
void gfx_lighting(bool enable);
void gfx_culling(bool enable);

#endif