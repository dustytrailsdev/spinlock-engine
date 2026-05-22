#include "core/core.hpp"
#include "core/log/log.hpp"
#include "core/log/assert.hpp"

int main() {
    PrintPlatform();
    LOG_INFO("This is a test of the logging system");
    LOG_WARN("This is a warning %s", "message");
    ASSERT(true, "This assertion should always pass");
    //ASSERT(false, "This assertion should always fail");
    return 0;
}
