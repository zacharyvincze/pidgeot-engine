#pragma once

#include "engine.h"
#include "imgui/imgui.h"

class DebugTask : public Pidgeot::Task {
public:
    void onRender()
    {
        ImGui::Begin("Statistics");
        ImGui::TextWrapped("Average Framerate: %.1f", ImGui::GetIO().Framerate);
        ImGui::Spacing();
        ImGui::TextWrapped("Entities: %i", Pidgeot::Engine::get().getEntityManager().getEntityCount());
        if (ImGui::Button("Quit"))
            Pidgeot::Engine::get().quit();
        ImGui::End();
    }
};