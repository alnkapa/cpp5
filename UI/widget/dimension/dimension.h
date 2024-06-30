#pragma once

struct Dimension {
    Dimension operator+=(const Dimension& other) {
        return Dimension{};
    }
};
