#include "DebugTask.h"

void DebugTask::onRender()
{
    ImGui::Begin("Statistics");
    ImGui::TextWrapped("Average Framerate: %.1f", ImGui::GetIO().Framerate);
    ImGui::Spacing();
    ImGui::TextWrapped("Entities: %i", Pidgeot::Engine::get().getEntityManager().getEntityCount());
    ImGui::TextWrapped("Current Map: %s", Pidgeot::Engine::get().getMapManager().getCurrentMap()->getName().c_str());
    if (ImGui::Button("Quit"))
        Pidgeot::Engine::get().quit();
    ImGui::End();
}