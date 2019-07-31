#include <stdio.h>

#include "application.h"
#include "engine.h"

int main(int argc, char** argv)
{
    auto app = Pidgeot::createApplication();
    app->run();
    return 0;
}