#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

constexpr auto CVAR_PLAYER_STATUS = "player_status";

class StatusChanger : public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginSettingsWindow
{
public:
    StatusChanger();

    virtual void onLoad() override;
    virtual void onUnload() override;

    void ChangeStatus(std::string newStatus);
    void Render(CanvasWrapper canvas);
    void RenderSettings() override;
    bool IsActiveOverlay();
    void OnPlayerStatusChanged();

    virtual std::string GetPluginName() override;
    virtual void SetImGuiContext(uintptr_t ctx) override;

private:
    std::shared_ptr<std::string> playerStatus;
    CVarWrapper cvarPlayerStatus;
};
