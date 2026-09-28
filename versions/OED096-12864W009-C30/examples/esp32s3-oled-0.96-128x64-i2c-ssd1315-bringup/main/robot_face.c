#include "robot_face.h"

#include "esp_random.h"

#define EYE_W           36
#define EYE_H           26
#define LOOK_RANGE_X     12
#define LOOK_RANGE_Y      8
#define LEFT_EYE_CX      38
#define RIGHT_EYE_CX     90
#define EYE_CY           32
#define SACCADE_STEP      3

static int isqrt_u32(int n)
{
    if (n <= 0) {
        return 0;
    }

    int res = 0;
    int bit = 1 << 30;
    while (bit > n) {
        bit >>= 2;
    }

    while (bit != 0) {
        if (n >= res + bit) {
            n -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }

    return res;
}

static void draw_stadium_eye(uint8_t *fb, int cx, int cy, int w, int h)
{
    if (h <= 3) {
        ssd1315_fb_fill_rect(fb, cx - w / 2, cy - h / 2, w, h, true);
        return;
    }

    const int r = h / 2;
    const int y0 = cy - h / 2;
    const int cap_l = cx - w / 2 + r;
    const int cap_r = cx + w / 2 - r;
    const int r_sq = r * r;

    for (int y = y0; y < y0 + h; y++) {
        const int dy = y - cy;
        const int dx = isqrt_u32(r_sq - dy * dy);
        const int x = cap_l - dx;
        const int line_w = (cap_r + dx) - x + 1;

        ssd1315_fb_fill_rect(fb, x, y, line_w, 1, true);
    }
}

static void draw_solid_eye(uint8_t *fb, int cx, int cy, int w, int h)
{
    draw_stadium_eye(fb, cx, cy, w, h);
}

static int blink_height(uint8_t phase)
{
    switch (phase) {
    case 1:
    case 5:
        return EYE_H * 2 / 3;
    case 2:
    case 4:
        return EYE_H / 3;
    case 3:
        return 3;
    default:
        return EYE_H;
    }
}

static void draw_electronic_eye(uint8_t *fb, int cx, int cy, uint8_t blink_phase)
{
    const int h = blink_height(blink_phase);
    draw_solid_eye(fb, cx, cy, EYE_W, h);
}

static void pick_look_target(robot_face_state_t *state)
{
    state->target_x = (int8_t)((esp_random() % (LOOK_RANGE_X * 2 + 1)) - LOOK_RANGE_X);
    state->target_y = (int8_t)((esp_random() % (LOOK_RANGE_Y * 2 + 1)) - LOOK_RANGE_Y);
}

static void step_toward(int8_t *value, int8_t target, int step)
{
    if (*value < target) {
        *value += step;
        if (*value > target) {
            *value = target;
        }
    } else if (*value > target) {
        *value -= step;
        if (*value < target) {
            *value = target;
        }
    }
}

static void update_look(robot_face_state_t *state)
{
    const bool at_target =
        (state->look_x == state->target_x && state->look_y == state->target_y);

    if (at_target) {
        if (state->idle_timer > 0) {
            state->idle_timer--;
            return;
        }
        pick_look_target(state);
        return;
    }

    step_toward(&state->look_x, state->target_x, SACCADE_STEP);
    step_toward(&state->look_y, state->target_y, SACCADE_STEP);

    if (state->look_x == state->target_x && state->look_y == state->target_y) {
        state->idle_timer = 18 + (esp_random() % 28);
    }
}

static void draw_eyes(uint8_t *fb, const robot_face_state_t *state)
{
    const int ox = state->look_x;
    const int oy = state->look_y;

    ssd1315_fb_clear(fb);
    draw_electronic_eye(fb, LEFT_EYE_CX + ox, EYE_CY + oy, state->blink_phase);
    draw_electronic_eye(fb, RIGHT_EYE_CX + ox, EYE_CY + oy, state->blink_phase);
}

void robot_face_state_init(robot_face_state_t *state)
{
    state->frame = 0;
    state->blink_phase = 0;
    state->look_x = 0;
    state->look_y = 0;
    state->target_x = 0;
    state->target_y = 0;
    state->idle_timer = 10;
    state->next_blink = 25 + (esp_random() % 35);
}

esp_err_t robot_face_update(ssd1315_t *oled, robot_face_state_t *state)
{
    static uint8_t fb[SSD1315_FRAMEBUFFER_SIZE];

    state->frame++;

    if (state->blink_phase > 0) {
        state->blink_phase++;
        if (state->blink_phase > 5) {
            state->blink_phase = 0;
        }
    } else if (state->frame >= state->next_blink) {
        state->blink_phase = 1;
        state->next_blink = state->frame + 25 + (esp_random() % 40);
    }

    if (state->blink_phase == 0) {
        update_look(state);
    }

    draw_eyes(fb, state);
    return ssd1315_flush(oled, fb);
}
