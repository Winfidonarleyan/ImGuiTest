/*
 * This file is part of the WarheadCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Common.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_stdlib.h"
#include <fmt/format.h>

void PrintTestWindows(ImGuiIO& io, std::size_t count)
{
    if (!count)
        return;

    for (std::size_t index{}; index < count;)
    {
        if (index)
        {
            if (auto window = ImGui::FindWindowByName(fmt::format(TEST_WINDOW_NAME_FMT, index).c_str()))
            {
                if (index % MAX_WINDOWS_IN_ROW == 0)
                    ImGui::SetNextWindowPos(ImVec2(window->Pos.x - (TEST_WINDOW_SIZE_X * (MAX_WINDOWS_IN_ROW - 1)), window->Pos.y + TEST_WINDOW_SIZE_Y), ImGuiCond_FirstUseEver);
                else
                    ImGui::SetNextWindowPos(ImVec2(window->Pos.x + TEST_WINDOW_SIZE_X, window->Pos.y /*+ TEST_WINDOW_SIZE_Y*/), ImGuiCond_FirstUseEver);

                ImGui::SetNextWindowSize(ImVec2(TEST_WINDOW_SIZE_X, TEST_WINDOW_SIZE_Y), ImGuiCond_FirstUseEver);
            }
        }
        else
        {
            // We specify a default position/size in case there's no data in the .ini file.
            // We only do it to make the demo applications a little more welcoming, but typically this isn't required.
            const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y + 197), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowSize(ImVec2(TEST_WINDOW_SIZE_X, TEST_WINDOW_SIZE_Y), ImGuiCond_FirstUseEver);
        }

        index++;

        ImGui::Begin(fmt::format(TEST_WINDOW_NAME_FMT, index).c_str(), nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
        ImGui::Text("%s", fmt::format("Framerate: {:0.2f}", io.Framerate).c_str());
        ImGui::End();
    }
}

void PrintLogWindow()
{
    static std::string testLogs{ "Test logs\n" };
    if (!testLogs.empty())
        testLogs.clear();

    ImGui::Begin("Test logs");

    static ImGuiInputTextFlags flags = ImGuiInputTextFlags_ReadOnly;
    ImGui::CheckboxFlags("ReadOnly", &flags, ImGuiInputTextFlags_ReadOnly);
    ImGui::SameLine();

    // Add 100k logs
    for (std::size_t i{}; i < 100000; i++)
        testLogs.append(fmt::format("Test logs: {} ...\n", i));

    ImGui::InputTextMultiline("##source", &testLogs, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
    ImGui::End();
}