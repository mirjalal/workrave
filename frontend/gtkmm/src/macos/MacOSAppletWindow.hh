// MacOSAppletWindow.hh --- Applet window
//
// Copyright (C) 2009, 2011 Rob Caelers <robc@krandor.nl>
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef MacOSAPPLETWINDOW_HH
#define MacOSAPPLETWINDOW_HH

#include "preinclude.h"
#include <string>

#include "TimerBoxViewBase.hh"
#include "ITimeBar.hh"
#include "AppletWindow.hh"

#import "ColorId.h"

@class MacOSStatusBarView;

class MacOSAppletWindow
  : public AppletWindow
  , public TimerBoxViewBase
{
public:
  MacOSAppletWindow();
  virtual ~MacOSAppletWindow();

  bool is_visible() const override;

  void set_slot(BreakId id, int slot) override;
  void set_time_bar(BreakId id,
                    std::string text,
                    ITimeBar::ColorId primary_color,
                    int primary_value,
                    int primary_max,
                    ITimeBar::ColorId secondary_color,
                    int secondary_value,
                    int secondary_max) override;

private:
  ColorId convertColorId(ITimeBar::ColorId colorId);
  MacOSStatusBarView *view;
};

#endif // MacOSAPPLETWINDOW_HH
