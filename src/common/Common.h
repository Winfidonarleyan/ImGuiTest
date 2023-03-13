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

#ifndef WARHEAD_COMMON_H_
#define WARHEAD_COMMON_H_

#include "Define.h"
#include "imgui.h"
#include <chrono>

constexpr auto GENERAL_WINDOW_WIDTH = 1920;
constexpr auto GENERAL_WINDOW_HEIGHT = 1080;

constexpr auto TEST_WINDOW_NAME_FMT = "Test window {:d}";
constexpr auto TEST_WINDOW_SIZE_X = 140;
constexpr auto TEST_WINDOW_SIZE_Y = 50;

constexpr auto MAX_WINDOWS_IN_ROW = GENERAL_WINDOW_WIDTH / TEST_WINDOW_SIZE_X;

/// time_point shorthand typedefs
using TimePoint = std::chrono::steady_clock::time_point;

using namespace std::chrono_literals;

inline TimePoint GetApplicationStartTime()
{
    static const TimePoint ApplicationStartTime = std::chrono::steady_clock::now();
    return ApplicationStartTime;
}

inline std::chrono::milliseconds GetTimeMS()
{
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now() - GetApplicationStartTime());
}

inline std::chrono::milliseconds GetMSTimeDiff(std::chrono::milliseconds oldMSTime, std::chrono::milliseconds newMSTime)
{
    if (oldMSTime > newMSTime)
        return oldMSTime - newMSTime;

    return newMSTime - oldMSTime;
}

void PrintTestWindows(ImGuiIO& io, std::size_t count);
void PrintLogWindow();

#endif
