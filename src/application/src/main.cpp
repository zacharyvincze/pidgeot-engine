#include <stdio.h>

#include "engine.h"
#include "application.h"

int main(int argc, char **argv) {
    auto app = Pidgeot::createApplication();
    app->run();
    return 0;
}