// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/shell/launcher_delegate_impl.h"

#include "ash/launcher/launcher_util.h"
#include "ash/shell/toplevel_window.h"
#include "ash/shell/window_watcher.h"
#include "ash/wm/window_util.h"
#include "grit/ash_resources.h"
#include "ui/aura/window.h"

namespace ash {
namespace shell {

LauncherDelegateImpl::LauncherDelegateImpl(WindowWatcher* watcher)
    : watcher_(watcher) {
}

LauncherDelegateImpl::~LauncherDelegateImpl() {
}

void LauncherDelegateImpl::ItemSelected(const ash::LauncherItem& item,
                                       const ui::Event& event) {
  aura::Window* window = watcher_->GetWindowByID(item.id);
  if (window->type() == aura::client::WINDOW_TYPE_PANEL)
    ash::wm::MoveWindowToEventRoot(window, event);
  window->Show();
  ash::wm::ActivateWindow(window);
}

base::string16 LauncherDelegateImpl::GetTitle(const ash::LauncherItem& item) {
  return watcher_->GetWindowByID(item.id)->title();
}

ui::MenuModel* LauncherDelegateImpl::CreateContextMenu(
    const ash::LauncherItem& item,
    aura::RootWindow* root_window) {
  return NULL;
}

ash::LauncherMenuModel* LauncherDelegateImpl::CreateApplicationMenu(
    const ash::LauncherItem& item,
    int event_flags) {
  return NULL;
}

ash::LauncherID LauncherDelegateImpl::GetIDByWindow(aura::Window* window) {
  return watcher_ ? watcher_->GetIDByWindow(window) : 0;
}

bool LauncherDelegateImpl::IsDraggable(const ash::LauncherItem& item) {
  return true;
}

bool LauncherDelegateImpl::ShouldShowTooltip(const ash::LauncherItem& item) {
  return true;
}

void LauncherDelegateImpl::OnLauncherCreated(Launcher* launcher) {
}

void LauncherDelegateImpl::OnLauncherDestroyed(Launcher* launcher) {
}

bool LauncherDelegateImpl::IsPerAppLauncher() {
  return false;
}

LauncherID LauncherDelegateImpl::GetLauncherIDForAppID(
    const std::string& app_id) {
  return 0;
}

void LauncherDelegateImpl::PinAppWithID(const std::string& app_id) {
}

bool LauncherDelegateImpl::IsAppPinned(const std::string& app_id) {
  return false;
}

void LauncherDelegateImpl::UnpinAppsWithID(const std::string& app_id) {
}

}  // namespace shell
}  // namespace ash
