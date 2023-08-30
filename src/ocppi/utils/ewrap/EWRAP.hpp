#pragma once

#ifdef DEBUG
#define EWRAP(e, nested) e
#else
#define EWRAP(e, nested)                                \
        []() -> std::exception {                        \
                try {                                   \
                        std::throw_with_nested(nested); \
                } catch (const std::exception &e) {     \
                        return e;                       \
                }                                       \
        }()
#endif
