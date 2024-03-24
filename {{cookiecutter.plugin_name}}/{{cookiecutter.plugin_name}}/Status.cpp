#include "pch.h"
#include "Status.h"
#include "IMGUI/imgui.h"

BAKKESMOD_PLUGIN(StatusChanger, "Changes online status", "1.0", PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

StatusChanger::StatusChanger()
    : cvarPlayerStatus(cvarManager->registerCvar(CVAR_PLAYER_STATUS, "", "Player status", true))
{
    // Initialize settings components
    playerStatus = std::make_shared<std::string>("");

    // Bind cvar to playerStatus
    cvarPlayerStatus.bindTo(playerStatus);
    // Register callback for when cvar value changes
    cvarPlayerStatus.addOnValueChanged(std::bind(&StatusChanger::OnPlayerStatusChanged, this));
}

void StatusChanger::onLoad()
{
    // Set the global cvar manager
    _globalCvarManager = cvarManager;
}

void StatusChanger::onUnload()
{
    // Clean up any resources if needed
}
void StatusChanger::ChangeStatus(std::string newStatus)
{
    // Execute logic to change player status
    // For example, you can use gameWrapper to apply the new status
    // BakkesMod::Plugin::BakkesModPlugin::gameWrapper->SetStatus(std::wstring(newStatus.begin(), newStatus.end()));
    cvarManager->log("Status changed to: " + newStatus);
}

void StatusChanger::Render(CanvasWrapper canvas)
{
    // Check if ImGui should capture input
    if (!IsActiveOverlay())
    {
        // Start rendering ImGui window
        if (ImGui::Begin("StatusChanger", nullptr, ImGuiWindowFlags_None))
        {
            // Render the plugin settings
            RenderSettings();
        }
        ImGui::End();
    }
}

void StatusChanger::RenderSettings()
{
    // Render the plugin settings
    ImGui::Text("StatusChanger plugin settings");

    // Input field to enter new status
    ImGui::InputText("New Status", playerStatus->data(), 256);

    // Button to change player status
    if (ImGui::Button("Change Player Status"))
    {
        ChangeStatus(*playerStatus);
    }
}


bool StatusChanger::IsActiveOverlay()
{
    // Return if the window should be interactive
    return true;
}

void StatusChanger::OnPlayerStatusChanged()
{
    // Execute logic when player status changes
    std::string newStatus = *playerStatus;
    // Implement additional logic if needed
}

std::string StatusChanger::GetPluginName()
{
    return "StatusChanger";
}

void StatusChanger::SetImGuiContext(uintptr_t ctx)
{
    // Set ImGui context
}
