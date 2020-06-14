#pragma once

float mf_lerp(float from, float to, float weight) {
    return from + (weight * (to - from));
}
