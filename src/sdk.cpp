#include "sdk/sdk.h"
#include "sdk/log.h"

void SDK::Init() {
    Log::Info("SDK initialized");
}

void SDK::Shutdown() {
    Log::Info("SDK shutdown");
}
